
// Created by Patricia on 10/12/17.
// Program to mimic a Process Control Block (PCB)

#ifndef MYPROCESS_H
#define MYPROCESS_H

#include <vector>

class ProcessControlBlock {

public:
    ProcessControlBlock();   //Constructor to initialize PCB contents
    //ProcessControlBlock(std::vector<int> values);



private:
    int ProcessID;      //Unique identifier of a  processes
    int BurstTime;      //Time to finish a process execution
    int ArrivalTime;





};






#endif
