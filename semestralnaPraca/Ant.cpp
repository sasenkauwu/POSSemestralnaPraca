#include "Ant.h"

Ant::Ant(int row, int column) {
    actualRow = row;
    actualColumn = column;
    currentDirection = UP;
    isDestroyed = false;
}

void Ant::move() {
    switch (currentDirection) {
        case UP:
            --actualRow;
            break;
        case DOWN:
            ++actualRow;
            break;
        case LEFT:
            --actualColumn;
            break;
        case RIGHT:
            ++actualColumn;
            break;
    }
}

void Ant::turnRight() {
    switch (currentDirection) {
        case UP: currentDirection = RIGHT;
            break;
        case RIGHT: currentDirection = DOWN;
            break;
        case DOWN: currentDirection = LEFT;
            break;
        case LEFT: currentDirection = UP;
            break;
    }
}

void Ant::turnLeft() {
    switch (currentDirection) {
        case UP: currentDirection = LEFT;
            break;
        case LEFT: currentDirection = DOWN;
            break;
        case DOWN: currentDirection = RIGHT;
            break;
        case RIGHT: currentDirection = UP;
            break;
    }
}

int Ant::getActualRow() {
    return actualRow;
}

int Ant::getActualColumn() {
    return actualColumn;
}

void Ant::setPosition(int row, int column) {
    actualRow = row;
    actualColumn = column;
}

void Ant::destroySelf() {
    isDestroyed = true;
}

bool Ant::getIsDestroyed() {
    return isDestroyed;
}


direction Ant::getCurrentDirection() {
    return currentDirection;
}
