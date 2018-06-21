cmake_minimum_required(VERSION 3.8)
project(4)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES  main.cpp  Observer.cpp Observer.h MotherShip.cpp MotherShip.h menu.h)
add_executable(4 ${SOURCE_FILES})