#include <random>
#include "ThreadSimulation.h"

ThreadSimulation::ThreadSimulation(World &parWorld, int numberOfAnts, const string& parMovementMethod, int parSteps, const string& parCollisionMethod)
    : world(parWorld), movementMethod(parMovementMethod), collisionMethod(parCollisionMethod) {

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distributionRows(0, world.getRows() - 1);
    uniform_int_distribution<> distributionColumns(0, world.getColumns() - 1);

    for (int i = 0; i < numberOfAnts; ++i) {
        ants.emplace_back( distributionRows(gen),  distributionColumns(gen));
    }
    steps = parSteps;
    isRunning = false;
    isStopping = false;
}

void ThreadSimulation::runSimulation(Ant &ant) {
    int currentStep = 0;
    mutex worldMutex;
    world.setMutex(&worldMutex);
    unique_lock<mutex> worldLock(*world.getMutex());
    worldLock.unlock();
    while (currentStep < steps) {
        worldLock.lock();
        conditionVariable.wait(worldLock, [this] { return isRunning || isStopping; });

        if (isStopping) {
            return;
        }

        thread_local random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distribution(0, 1);

        if (!ant.getIsDestroyed()) {
            {
                lock_guard<std::mutex> lock(consoleMutex);
                clearConsole();
                world.draw(ants);
            }
            int currentState = world.getCellState(ant.getActualRow(), ant.getActualColumn());

            if (movementMethod == "inverse") {
                if (currentState == 0) {
                    ant.turnLeft();
                } else {
                    ant.turnRight();
                }
            } else {
                if (currentState == 0) {
                    ant.turnRight();
                } else {
                    ant.turnLeft();
                }
            }
            world.flipState(ant.getActualRow(), ant.getActualColumn());
            ant.move();

            if (ant.getActualRow() < 0) {
                ant.setPosition(world.getRows() - 1, ant.getActualColumn());
            }
            if (ant.getActualColumn() < 0) {
                ant.setPosition(ant.getActualRow(), world.getColumns() - 1);
            }
            if (ant.getActualRow() >= world.getRows()) {
                ant.setPosition(0, ant.getActualColumn());
            }
            if (ant.getActualColumn() >= world.getColumns()) {
                ant.setPosition(ant.getActualRow(), 0);
            }
            worldLock.unlock();

            for (Ant &otherAnt : ants) {
                if (&ant != &otherAnt && ant.getActualRow() == otherAnt.getActualRow()
                    && ant.getActualColumn() == otherAnt.getActualColumn() && !ant.getIsDestroyed() && !otherAnt.getIsDestroyed()) {
                    if (collisionMethod == "all")  {
                        ant.destroySelf();
                        otherAnt.destroySelf();
                    } else if (collisionMethod == "only") {
                        if (distribution(gen) == 0) {
                            ant.destroySelf();
                        } else {
                            otherAnt.destroySelf();
                        }
                    } else if (collisionMethod == "logic") {
                       if (distribution(gen) == 0) {
                           if (distribution(gen) == 0)
                           {
                               ant.turnLeft();
                           } else {
                               ant.turnRight();
                           }
                       } else {
                           if (distribution(gen) == 0)
                           {
                               otherAnt.turnLeft();
                           } else {
                               otherAnt.turnRight();
                           }
                       }
                    }
                }
            }
        } else {
            worldLock.unlock();
        }
        this_thread::sleep_for(chrono::milliseconds (1000));
        ++currentStep;
    }
}

void ThreadSimulation::runParallel() {
    for (Ant &ant: ants) {
        threads.emplace_back(&ThreadSimulation::runSimulation, this, ref(ant));
    }

    for (std::thread& thread : threads) {
        if (thread.joinable()) {
            thread.join();
        }
    }
    cout << "The end of the simulation." << endl;
    isStopping = true;
}

void ThreadSimulation::clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void ThreadSimulation::pause() {
    isRunning = false;
    conditionVariable.notify_all();
}

void ThreadSimulation::resume() {
    isRunning = true;
    conditionVariable.notify_all();
}

void ThreadSimulation::quit() {
    isStopping = true;
    isRunning = false;
    conditionVariable.notify_all();
}

unsigned long ThreadSimulation::getNumberOfAnts() {
    return ants.size();
}

const string &ThreadSimulation::getMovementMethod() {
    return movementMethod;
}

const string &ThreadSimulation::getCollisionMethod() {
    return collisionMethod;
}

int ThreadSimulation::getSteps() {
    return steps;
}
