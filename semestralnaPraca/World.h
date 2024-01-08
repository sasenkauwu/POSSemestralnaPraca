#ifndef SEMESTRALNAPRACA_WORLD_H
#define SEMESTRALNAPRACA_WORLD_H

#include <iostream>
#include <vector>
#include <sstream>
#include <mutex>
#include <random>
#include "Ant.h"

using namespace std;

class World {
private:
    int rows;
    int columns;
    vector<vector<int>> field;
    vector<pair<int, int>> blackCells;
    mutex* worldMutex;

public:
    World(int parRows, int parColumns, vector<pair<int, int>>& blackCells);
    void draw(vector<Ant>& ants);
    void flipState(int row, int column);
    int getCellState(int row, int column);
    int getRows();
    int getColumns();
    void setMutex(mutex* parWorldMutex);
    mutex* getMutex();
    vector<pair<int, int>>& getBlackCells();
};

#endif

