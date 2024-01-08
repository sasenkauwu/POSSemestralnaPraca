#ifndef SEMESTRALNAPRACA_ANT_H
#define SEMESTRALNAPRACA_ANT_H

using namespace std;

enum direction { UP, DOWN, LEFT, RIGHT };

class Ant {
private:
    int actualRow;
    int actualColumn;
    direction currentDirection;
    bool isDestroyed;
public:
    Ant(int row, int column);
    void move();
    void turnRight();
    void turnLeft();
    int getActualRow();
    int getActualColumn();
    void setPosition(int row, int column);
    direction getCurrentDirection();
    void destroySelf();
    bool getIsDestroyed();
};

#endif
