//
// Created by Patricia on 10/12/17.
//

#ifndef MYREADYQUEUE_H
#define MYREADYQUEUE_H

#include "myProcess.h"

//This class is a custom queue which holds data of Process type
class ReadyQueue{
public:
    //Size of the queue
    int size;
    Process *head;
    Process *tail;

    ReadyQueue();
    //Method to add process to the queue
    void enqueue(Process *process);
    //Method to remove process (tail) from the queue
    Process* dequeue();

};

#endif //MYREADYQUEUE_H
