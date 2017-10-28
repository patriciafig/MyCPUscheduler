
// Created by Patricia on 10/12/17.
// Program to mimic a Process Control Block (PCB)

#ifndef MYPROCESS_H
#define MYPROCESS_H
//This class holds all the attributes of a process
class Process {
public:
    int burstTime;
    int processID;
    int arrivalTime;
    int priority;
    int comp_data;
    int num_contexts;
    int remaining_time;
    Process *next;
    //Constructor to initialize the values read from the file
    Process(int pid, int arrival_time, int burst_time, int priority);
    Process();
};





#endif
