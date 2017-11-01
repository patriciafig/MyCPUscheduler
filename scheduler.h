

#ifndef SCHEDULER_H
#define SCHEDULER_H


#include "myReadyQueue.h"

class Scheduler {
public:

    void fcfsSchedule(ReadyQueue *readyQueue);
    void srtfSchedule(ReadyQueue *readyQueue);
    void rrSchedule(ReadyQueue *readyQueue, int quantum_size);
    void ppSchedule(ReadyQueue *readyQueue);




private:
    void printStats();
    void sort(ReadyQueue *readyQueue, const char* comparator);
    void clearStats();
    float avg_cpu_burst_time;
    float avg_turn_around_time;
    float avg_waiting_time;
    float avg_response_time;
    int n_context_switches;
};


#endif //LAB_PS_SCHEDULER_H
