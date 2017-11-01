//
// Created by Patricia on 10/12/17.
// Program to mimic a Process Control Block (PCB)


#include "myProcess.h"
//Constructor to initialize a process with the given parameters
Process::Process(int pid, int arrival_time, int burst_time, int priority) {
    processID = pid;
    arrivalTime = arrival_time;
    burstTime = burst_time;
    this->priority = priority;
    //next = nullptr;
    num_contexts = 0;
    remaining_time = burst_time;
}

Process::Process() {
    processID = -1;
    next = nullptr;
    num_contexts = 0;
}
