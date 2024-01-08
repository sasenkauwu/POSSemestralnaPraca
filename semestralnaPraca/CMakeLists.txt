cmake_minimum_required(VERSION 3.18)
project(semestralnaPraca)

set(CMAKE_CXX_STANDARD 17)

add_executable(semestralnaPraca main.cpp
        Ant.cpp
        Ant.h
        World.cpp
        World.h
        ThreadSimulation.cpp
        FileHandler.cpp
        my_socket.h
        my_socket.cpp)
target_link_libraries(semestralnaPraca ws2_32)

