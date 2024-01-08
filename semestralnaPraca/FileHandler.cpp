#include "FileHandler.h"

bool FileHandler::loadDataFromFile(const string& filePath, int& rows, int& columns, int& countAnts, string& movementMethod, int& steps, string& collisionMethod, vector<pair<int, int>>& blackCells) {
    ifstream inputFile(filePath);
    if (!inputFile.is_open()) {
        cerr << "Unable to open the file." << endl;
        return false;
    }

    inputFile >> rows >> columns >> countAnts >> movementMethod >> steps >> collisionMethod;

    int row, column;
    while (inputFile >> row >> column) {
        blackCells.emplace_back(row, column);
    }
    return true;
}

bool FileHandler::saveDataToFile(const string &filePath, World &world, ThreadSimulation &threadSimulation) {
    ofstream outputFile(filePath);
    if (!outputFile.is_open()) {
        cerr << "Unable to open the file." << endl;
        return false;
    }
    outputFile << world.getRows() << " " << world.getColumns() << " " << threadSimulation.getNumberOfAnts() << " " << threadSimulation.getMovementMethod() << " " << threadSimulation.getSteps() << " " << threadSimulation.getCollisionMethod() << endl;
    vector<pair<int, int>>& cells = world.getBlackCells();
    for (const auto& pair : cells) {
        outputFile << pair.first << " " << pair.second << endl;
    }
    outputFile.close();
    return true;
}

bool FileHandler::loadDataFromServer(const string& filePath, const string& data) {
    ofstream outputFile(filePath);

    if (!outputFile.is_open()) {
        cerr << "Unable to open file." << endl;
        return false;
    }

    outputFile << data;
    outputFile.close();
    return true;
}

bool FileHandler::saveDataToString(string& outputString, World &world, ThreadSimulation &threadSimulation) {
    ostringstream oss;

    oss << " " << world.getRows() << " " << world.getColumns() << " " << threadSimulation.getNumberOfAnts() << " " << threadSimulation.getMovementMethod() << " " << threadSimulation.getSteps() << " " << threadSimulation.getCollisionMethod() << endl;

    vector<pair<int, int>>& cells = world.getBlackCells();
    for (const auto& pair : cells) {
        oss << pair.first << " " << pair.second << endl;
    }

    outputString = oss.str();
    return true;
}

