// Created by patricia on 10/09/17.


/*
 * A C++ program to simulate a CPU scheduler which selects a processor from a ready queue and executes the process by
 * a given scheduling algorithm, displays its activities and evaluates its performance based on a collection of  some
 * measurements such as average turn-around time, average waiting time, average response time.
 * When a process is scheduled, the simulator will simply print what the process is running at what time,
 * collecting some measurement data and producing Gantt Chart-like outputs.
 *
 */


#include <iostream>      // used for I/O
#include <fstream>       // used for file input
#include <string>        // used for string operations


#include "myReadyQueue.h"
#include "myProcess.h"

using namespace std;

