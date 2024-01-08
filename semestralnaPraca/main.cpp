#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "my_socket.h"
#include <iostream>
#include <sstream>
#include <thread>
#include <queue>
#include <string>
#include "ThreadSimulation.h"
#include "FileHandler.h"

using namespace std;

int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    std::locale::global(std::locale(""));
    int rows, columns, countAnts, steps;
    string inputBlackCellsAnswer, movementMethod, collisionMethod, inputBlackCells, inputLoadFileAnswer, nameLocalFile1, inputSaveFileAnswerLocal, nameLocalFile2, nameLocalFile3, serverDownloadAnswer, localOrServerAnswer2, inputSaveFileAnswerServer, dataFile, temp;
    vector<pair<int, int>> blackCells;

    MySocket* mySocket = MySocket::createConnection("frios2.fri.uniza.sk", 16873);

    cout << "Do you want to download world settings from server? [ yes / no ]" << endl;
    while (!(cin >> serverDownloadAnswer) || (serverDownloadAnswer != "yes" && serverDownloadAnswer != "no")) {
        cout << "Invalid input. Please enter either 'yes' or 'no'." << endl;
        cin.clear();
        cin.ignore(9223372036854775807, '\n');
    }
    if (serverDownloadAnswer == "yes") {
        cout << "Enter the name of the file (e.g. dataFile.txt)." << endl;
        cin >> nameLocalFile1;

        temp = "load " + nameLocalFile1;
        mySocket->sendData(temp);
        string serverResponse = mySocket->readData();
        if (!FileHandler::loadDataFromServer(nameLocalFile1, serverResponse)) {
            cerr << "Unable to create file." << endl;
            return 1;
        }
    }

    cout << "Do you want to load world settings from the file? [ yes / no ]" << endl;
    while (!(cin >> inputLoadFileAnswer) || (inputLoadFileAnswer != "yes" && inputLoadFileAnswer != "no")) {
        cout << "Invalid input. Please enter either 'yes' or 'no'." << endl;
        cin.clear();
        cin.ignore(9223372036854775807, '\n');
    }
    if (inputLoadFileAnswer == "yes") {
        cout << "Enter the name of the file (e.g. dataFile.txt)." << endl;
        cin >> nameLocalFile2;
        if (!FileHandler::loadDataFromFile(nameLocalFile2, rows, columns, countAnts, movementMethod, steps, collisionMethod, blackCells)) {
            cerr << "Unable to load data from this file." << endl;
            return 1;
        }
    } else {
        cout << "Enter number of rows." << endl;
        while (!(cin >> rows) || rows <= 0) {
            cout << "Invalid input. Please enter a positive integer for rows." << endl;
            cin.clear();
            cin.ignore(9223372036854775807, '\n');
        }
        cout << "Enter number of columns." << endl;
        while (!(cin >> columns) || columns <= 0) {
            cout << "Invalid input. Please enter a positive integer for columns." << endl;
            cin.clear();
            cin.ignore(9223372036854775807, '\n');
        }
        cout << "Enter number of ants." << endl;
        while (!(cin >> countAnts) || countAnts <= 0) {
            cout << "Invalid input. Please enter a positive integer for the number of ants." << endl;
            cin.clear();
            cin.ignore(9223372036854775807, '\n');
        }
        cout << "Enter method of ants movement [ direct / inverse ]" << endl;
        while (!(cin >> movementMethod) || (movementMethod != "direct" && movementMethod != "inverse")) {
            cout << "Invalid input. Please enter either 'direct' or 'inverse'." << endl;
            cin.clear();
            cin.ignore(9223372036854775807, '\n');
        }
        cout << "Enter number of simulations steps." << endl;
        while (!(cin >> steps) || steps <= 0) {
            cout << "Invalid input. Please enter a positive integer for the number of steps." << endl;
            cin.clear();
            cin.ignore(9223372036854775807, '\n');
        }
        cout << "Enter method of collisions." << endl;
        cout << "Extinction of all ants. [ all ]" << endl;
        cout << "Only one ant survive. [ only ]" << endl;
        cout << "Half of the ants will start to behave according to complementary logic. [ logic ]" << endl;
        while (!(cin >> collisionMethod) || (collisionMethod != "all" && collisionMethod != "only" && collisionMethod != "logic")) {
            cout << "Invalid input. Please enter 'all' or 'only' or 'logic'." << endl;
            cin.clear();
            cin.ignore(9223372036854775807, '\n');
        }
        cout << "Do you wish to define black cells manually? [ yes / no ]" << endl;
        while (!(cin >> inputBlackCellsAnswer) || (inputBlackCellsAnswer != "yes" && inputBlackCellsAnswer != "no")) {
            cout << "Invalid input. Please enter either 'yes' or 'no'." << endl;
            cin.clear();
            cin.ignore(9223372036854775807, '\n');
        }
        cin.ignore();
        if (inputBlackCellsAnswer == "yes") {
            cout << "Enter coordinates for black field in the format - 'x y' (e.g. 2 5)." << endl;
            cout << "If you want to stop - write [ STOP ]" << endl;
            while (true) {
                getline(cin, inputBlackCells);
                if (inputBlackCells == "STOP") {
                    break;
                }
                istringstream iss(inputBlackCells);
                int startRow = 0;
                int startColumn = 0;
                if (iss >> startRow >> startColumn) {
                    if (startRow >= 0 && startRow < rows && startColumn >= 0 && startColumn < columns)
                    {
                        blackCells.emplace_back(startRow, startColumn);
                    } else {
                        cout << "Invalid input. Please enter valid coordinates." << endl;
                    }
                } else {
                    cout << "Invalid input. Please enter valid coordinates." << endl;
                }
            }
        }
    }

    World world(rows, columns, blackCells);
    ThreadSimulation simulation(world, countAnts, movementMethod, steps, collisionMethod);

    thread simulationThread([&simulation]() {
        simulation.runParallel();
    });

    char userInput;
    while (true) {
        cout << "Enter 'p' to pause, 'r' to resume/start, or 'q' to quit: ";
        cin >> userInput;

        if (userInput == 'q') {
            simulation.quit();
            break;
        } else if (userInput == 'p') {
            simulation.pause();
        } else if (userInput == 'r') {
            simulation.resume();
        } else {
            cout << "Invalid input. Please enter 'p', 'r', or 'q'." << endl;
        }
    }

    simulationThread.join();

    cout << "Do you wish to save world settings to local file? [ yes / no ]" << endl;
    while (!(cin >> inputSaveFileAnswerLocal) || (inputSaveFileAnswerLocal != "yes" && inputSaveFileAnswerLocal != "no")) {
        cout << "Invalid input. Please enter either 'yes' or 'no'." << endl;
        cin.clear();
        cin.ignore(9223372036854775807, '\n');
    }
    if (inputSaveFileAnswerLocal == "yes") {
        cout << "Enter the name of the file (e.g. dataFile.txt)." << endl;
        cin >> nameLocalFile3;
        if (!FileHandler::saveDataToFile(nameLocalFile3, world, simulation)) {
            cerr << "Unable to save data to this file." << endl;
            return 1;
        }
    }
    cout << "Do you wish to save world settings to server? [ yes / no ]" << endl;
    while (!(cin >> inputSaveFileAnswerServer) || (inputSaveFileAnswerServer != "yes" && inputSaveFileAnswerServer != "no")) {
        cout << "Invalid input. Please enter either 'yes' or 'no'." << endl;
        cin.clear();
        cin.ignore(9223372036854775807, '\n');
    }
    if (inputSaveFileAnswerServer == "yes") {
        cout << "Enter the name of the file (e.g. dataFile.txt)." << endl;
        cin >> dataFile;
        string worldSettings;
        if (!FileHandler::saveDataToString(worldSettings, world, simulation)) {
            cerr << "Unable to save data to this file." << endl;
            return 1;
        }
        dataFile = "save " + dataFile;
        mySocket->sendData(dataFile + worldSettings);
        string serverResponse = mySocket->readData();
        cout << serverResponse;
    }

    delete mySocket;
    return 0;
}