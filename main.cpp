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
#include "Scheduler.h"

using namespace std;



int main(){
    ReadyQueue *readyQueue = new ReadyQueue();
    Process *p1 = new Process(1,0,10,1);
    Process *p2 = new Process(2,1,2,5);
    Process *p3 = new Process(3,2,9,0);
    Process *p4 = new Process(4,3,5,10);

    readyQueue->enqueue(p1);
    readyQueue->enqueue(p2);
    readyQueue->enqueue(p3);
    readyQueue->enqueue(p4);
    Scheduler scheduler;
    cout << "********************************** ROUND ROBIN **********************************"<<endl;
    //scheduler.sort(readyQueue,"arrival_time");
    scheduler.rrSchedule(readyQueue,4);

    cout << "********************************** ROUND ROBIN **********************************"<<endl;
    scheduler.ppSchedule(readyQueue,4);



}

