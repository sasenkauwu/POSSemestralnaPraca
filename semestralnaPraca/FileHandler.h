#ifndef SEMESTRALNAPRACA_FILEHANDLER_H
#define SEMESTRALNAPRACA_FILEHANDLER_H

#include <string>
#include <vector>
#include <fstream>
#include "ThreadSimulation.h"

using namespace std;

class FileHandler {
public:
    static bool loadDataFromFile(const string& filePath, int& rows, int& columns, int& countAnts, string& movementMethod, int& steps, string& collisionMethod, vector<pair<int, int>>& blackCells);
    static bool saveDataToFile(const string& filePath, World& world, ThreadSimulation& threadSimulation);
    static bool loadDataFromServer(const string& filePath, const string& data);
    static bool saveDataToString(string& outputString, World &world, ThreadSimulation &threadSimulation);
};


#endif
