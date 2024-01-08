#include "World.h"

World::World(int parRows, int parColumns, vector<pair<int, int>>& blackCells) {
    rows = parRows;
    columns = parColumns;
    worldMutex = nullptr;

    for (int i = 0; i < rows; ++i) {
        vector<int> row(columns, 0);
        field.push_back(row);
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distributionBlackCells(0, 10);

    if (blackCells.empty()) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                if (distributionBlackCells(gen) == 1) {
                    field[i][j] = 1; // black
                }
            }
        }
    } else {
        for (const auto& pair : blackCells) {
            field[pair.second][pair.first] = 1; // black
        }
    }
}

void World::draw(vector<Ant>& ants) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            bool antPresent = false;
            char direction = ' ';
            for (Ant& ant : ants) {
                if (ant.getActualRow() == i && ant.getActualColumn() == j && !ant.getIsDestroyed())
                {
                    antPresent = true;
                    switch (ant.getCurrentDirection()) {
                        case UP: direction = '^';
                            break;
                        case DOWN: direction = 'V';
                            break;
                        case LEFT: direction = '<';
                            break;
                        case RIGHT: direction = '>';
                            break;
                    }
                    break;
                }
            }
            if (antPresent) {
                cout << direction << " ";
            } else {
                if (field[i][j] == 1)
                {
                    cout << "O ";
                } else {
                    cout << "  ";
                }
            }
        }
        cout << endl;
    }
}

void World::flipState(int row, int column) {
    if (field[row][column] == 0) {
        field[row][column] = 1; // black
    } else {
        field[row][column] = 0;
    }
}

int World::getCellState(int row, int column) {
    return field[row][column];
}

int World::getRows() {
    return rows;
}

int World::getColumns() {
    return columns;
}

vector<pair<int, int>>& World::getBlackCells() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (field[i][j] == 1)
            {
                blackCells.emplace_back(i, j);
            }
        }
    }
    return blackCells;
}

void World::setMutex(mutex* parWorldMutex) {
    worldMutex = parWorldMutex;
}

mutex* World::getMutex() {
    return worldMutex;
}


