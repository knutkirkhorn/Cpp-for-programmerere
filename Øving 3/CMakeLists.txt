cmake_minimum_required(VERSION 2.8)

project(Øving_3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

add_executable(Oppgave2 oppgave2.cpp)
add_executable(Oppgave4 oppgave4.cpp)
add_executable(vareTest VareTest.cpp vare.cpp)