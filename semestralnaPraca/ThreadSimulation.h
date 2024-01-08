#ifndef SEMESTRALNAPRACA_THREADSIMULATION_H
#define SEMESTRALNAPRACA_THREADSIMULATION_H

#include "World.h"
#include <condition_variable>
#include <thread>
#include <random>

class ThreadSimulation {
private:
    World& world;
    vector<thread> threads;
    condition_variable conditionVariable;
    mutex consoleMutex;
    vector<Ant> ants;
    string movementMethod;
    string collisionMethod;
    bool isRunning;
    bool isStopping;
    int steps;


public:
    ThreadSimulation(World& parWorld, int numberOfAnts, const string& parMovementMethod, int parSteps, const string& parCollisionMethod);
    void runSimulation(Ant& ant);
    static void clearConsole();
    void runParallel();
    void pause();
    void resume();
    void quit();
    unsigned long getNumberOfAnts();
    const string& getMovementMethod();
    const string& getCollisionMethod();
    int getSteps();
};

#endif
