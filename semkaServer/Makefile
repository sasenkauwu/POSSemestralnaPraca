CC = gcc
CFLAGS = -Wall -pthread -Wunused-function

SRC_DIR = src
BUILD_DIR = build

SRC = main.c \
      pos_sockets/passive_socket.c \
      pos_sockets/char_buffer.c \
      pos_sockets/active_socket.c

OBJ = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC))
TARGET = $(BUILD_DIR)/semkaServer

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR) $(TARGET)
