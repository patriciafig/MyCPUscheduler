cmake_minimum_required(VERSION 3.7)
project(Lab02)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp myReadyQueue.cpp myReadyQueue.h myProcess.cpp myProcess.h)
add_executable(Lab02 ${SOURCE_FILES} myProcess.cpp myProcess.h)