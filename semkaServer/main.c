#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "pos_sockets/char_buffer.h"
#include "pos_sockets/active_socket.h"
#include "pos_sockets/passive_socket.h"
#include "buffer.h"

typedef struct thread_data {
    bool clientConnected;
    pthread_mutex_t mutex;
    pthread_cond_t connected;
    CHAR_BUFFER receivedData;
    short port;
    ACTIVE_SOCKET* my_socket;
} THREAD_DATA;

void* process_client_data(void* thread_data) {
    THREAD_DATA *data = (THREAD_DATA *)thread_data;
    PASSIVE_SOCKET p_socket;
    passive_socket_init(&p_socket);
    passive_socket_start_listening(&p_socket, data->port);
    passive_socket_wait_for_client(&p_socket, data->my_socket);
    passive_socket_stop_listening(&p_socket);
    passive_socket_destroy(&p_socket);

    printf("connected \n");
    pthread_mutex_lock(&data->mutex);
    data->clientConnected = true;
    pthread_cond_signal(&data->connected);
    pthread_mutex_unlock(&data->mutex);

    active_socket_start_reading(data->my_socket);

    pthread_mutex_lock(&data->mutex);
    data->clientConnected = false;
    pthread_mutex_unlock(&data->mutex);

    return NULL;
}

void thread_data_destroy(struct thread_data* data) {
    pthread_mutex_destroy(&data->mutex);
    pthread_cond_destroy(&data->connected);

    data->port = 0;
    data->my_socket = NULL;
    char_buffer_destroy(&data->receivedData);
}

_Bool try_get_client_data(struct active_socket* my_sock, struct thread_data* data, char* command, size_t commandSize, char* fileName, size_t fileNameSize, char* buffer, size_t bufferSize) {
    CHAR_BUFFER r_buf;
    char_buffer_init(&r_buf);

    if (active_socket_try_get_read_data(my_sock, &r_buf)) {
        if (r_buf.size > 0) {
            // Získať dáta zo štruktúry r_buf
            sscanf(r_buf.data, "%s %s", command, fileName);
            snprintf(buffer, bufferSize, "%s", r_buf.data + strlen(command) + strlen(fileName) + 2);  // Získať obsah súboru (za názvom)
            data->receivedData = r_buf;
            return true;
        }
    }
    char_buffer_destroy(&r_buf);
    return false;
}


bool save_data_to_file(const char* fileName, const char* data) {
    char path[256];
    const char* savePath = "/home/mokosova1/worldSave/";
    snprintf(path, sizeof(path), "%s%s", savePath, fileName);

    FILE* file = fopen(path, "w");

    if (file != NULL) {
        fputs(data, file);
        fclose(file);
        printf("Data saved to: %s\n", path);
        return true;
    } else {
        fprintf(stderr, "Unable to open the file: %s\n", path);
        return false;
    }
}

bool load_file_from_server(const char* fileName, char* buffer, size_t bufferSize) {
    char path[256];
    const char* savePath = "/home/mokosova1/worldSave/";
    snprintf(path, sizeof(path), "%s%s", savePath, fileName);

    FILE* file = fopen(path, "r");

    if (file != NULL) {
        fseek(file, 0, SEEK_END);
        size_t file_size = ftell(file);
        rewind(file);

        if (file_size < bufferSize) {
            fread(buffer, 1, file_size, file);
            fclose(file);
            printf("Data loaded from: %s\n", path);
            printf("Data: %s|\n", buffer);
            return true;
        } else {
            fprintf(stderr, "Buffer size is not sufficient for file: %s\n", path);
        }
        fclose(file);
    } else {
        fprintf(stderr, "Unable to open the file: %s\n", path);
    }
    return false;
}

void load_or_save_file_from_server(struct thread_data* data, const char* command, const char* fileName, const char* fileContent) {
    char buffer[1024];
    if (strcasecmp(command, "load") == 0) {
        if (load_file_from_server(fileName, buffer, sizeof(buffer))) {
            active_socket_write_data(data->my_socket, buffer);
        } else {
            active_socket_write_data(data->my_socket, "Failed to load file from server. :(\n");
        }
    } else if (strcasecmp(command, "save") == 0) {
        if (save_data_to_file(fileName, fileContent)) {
            active_socket_write_data(data->my_socket, "Data successfully saved on server. \n");
        } else {
            active_socket_write_data(data->my_socket, "Failed to save data on server. :(\n");
        }
    } else {
        active_socket_write_data(data->my_socket, "Invalid command. Use 'load' or 'save'.\n");
    }
}

void* process_incoming_data(void* thread_data) {
    THREAD_DATA* data = (THREAD_DATA*)thread_data;

    pthread_mutex_lock(&data->mutex);
    while (!data->clientConnected) {
        pthread_cond_wait(&data->connected, &data->mutex);
    }
    pthread_mutex_unlock(&data->mutex);

    while (data->clientConnected == true) {
        pthread_mutex_lock(&data->mutex);

            char receivedCommand[16];
            char receivedFileName[256];
            char receivedData[1024];

            if (try_get_client_data(data->my_socket, data, receivedCommand, sizeof(receivedCommand), receivedFileName, sizeof(receivedFileName), receivedData, sizeof(receivedData))) {
                printf("Received command from client: %s\n", receivedCommand);
                printf("Received file name from client: %s\n", receivedFileName);
                printf("Received data from client: %s\n", receivedData);
                load_or_save_file_from_server(data, receivedCommand, receivedFileName, receivedData);
            }
        pthread_mutex_unlock(&data->mutex);

    }
}

void thread_data_init(struct thread_data *data, ACTIVE_SOCKET *socket, short port) {
    data->my_socket = socket;
    data->port = port;
}

int main() {
    pthread_t threadClient;
    pthread_t threadProcessor;

    struct thread_data data;
    struct active_socket socket;

    pthread_mutex_init(&data.mutex, NULL);
    pthread_cond_init(&data.connected, NULL);


    data.clientConnected = false;

    active_socket_init(&socket);
    thread_data_init(&data, &socket, 16873);

    pthread_create(&threadClient, NULL, process_client_data, &data);
    pthread_create(&threadProcessor, NULL, process_incoming_data, &data);

    pthread_join(threadClient, NULL);
    pthread_join(threadProcessor, NULL);

    thread_data_destroy(&data);
    active_socket_destroy(&socket);

    return 0;
}