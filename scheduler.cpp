
#include <cstring>
#include <iostream>
#include "Scheduler.h"
using namespace std;

const char* ARRIVAL_TIME = "arrival_time";
const char* PRIORITY = "priority";

//Clears the data of the scheduler
void Scheduler::clearStats() {
    avg_cpu_burst_time = 0;
    avg_response_time = 0;
    avg_turn_around_time = 0;
    avg_waiting_time = 0;
    n_context_switches = 0;
}

Process *getTail(Process *cur) {
    while (cur != NULL && cur->next != NULL)
        cur = cur->next;
    return cur;
}

// Partitions the list taking the last element as the pivot
Process *partition(Process *head, Process *end,
                   Process **newHead, Process **newEnd) {
    Process *pivot = end;
    Process *prev = NULL, *cur = head, *tail = pivot;

    // During partition, both the head and end of the list might change
    // which is updated in the newHead and newEnd variables
    while (cur != pivot)
    {
        if (cur->comp_data < pivot->comp_data)
        {
            // First node that has a value less than the pivot - becomes
            // the new head
            if ((*newHead) == NULL)
                (*newHead) = cur;

            prev = cur;
            cur = cur->next;
        }
        else // If cur node is greater than pivot
        {
            // Move cur node to next of tail, and change tail
            if (prev)
                prev->next = cur->next;
            Process *tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    // If the pivot data is the smallest element in the current list,
    // pivot becomes the head
    if ((*newHead) == NULL)
        (*newHead) = pivot;

    // Update newEnd to the current last node
    (*newEnd) = tail;

    // Return the pivot node
    return pivot;
}
//here the sorting happens exclusive of the end node
Process *quickSortRecur(Process *head, Process *end) {
    // base condition
    if (!head || head == end)
        return head;

    Process *newHead = NULL, *newEnd = NULL;

    // Partition the list, newHead and newEnd will be updated
    // by the partition function
    Process *pivot = partition(head, end, &newHead, &newEnd);

    // If pivot is the smallest element - no need to recur for
    // the left part.
    if (newHead != pivot)
    {
        // Set the node before the pivot node as NULL
        Process *tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;

        // Recur for the list before pivot
        newHead = quickSortRecur(newHead, tmp);

        // Change next of last node of the left half to pivot
        tmp = getTail(newHead);
        tmp->next =  pivot;
    }

    // Recur for the list after the pivot element
    pivot->next = quickSortRecur(pivot->next, newEnd);

    return newHead;
}
// The main function for quick sort. This is a wrapper over recursive
// function quickSortRecur()
void quickSort(Process **headRef) {
    (*headRef) = quickSortRecur(*headRef, getTail(*headRef));
    return;
}

//Converts the readyQueue to an array and returns it
Process* toArray(ReadyQueue *readyQueue){
    Process* temp = readyQueue->head;
    Process *processArray = new Process[readyQueue->size];
    int i=0;
    while(temp != nullptr){
        processArray[i] = *temp;
        temp = temp->next;
        i++;
    }
    return processArray;
}

void Scheduler::printStats(){
    cout << "Average CPU burst time = "<<avg_cpu_burst_time << endl;
    cout << "Average waiting time = "<<avg_waiting_time << endl;
    cout << "Average turn around time = "<<avg_turn_around_time << endl;
    cout << "Average response time = "<<avg_response_time << endl;
    cout << "Total No. of Context Switching Performed = "<<n_context_switches<<endl;
}
//FCFS Scheduler
void Scheduler::fcfsSchedule(ReadyQueue *readyQueue) {
    clearStats();
    cout << "PID\tArrival\tCPU-burst\tPriority\tFinish\tWaiting Time\tTurn around\tResponse Time\tNo.of Context"<<endl;
    //Sort the queue with respect to arrival time
    sort(readyQueue,ARRIVAL_TIME);
    int current_time = 0;
    int n_process = readyQueue->size;
    //Dequeue processes from the queue one-by-one and update the times; Do this until the queue is empty
    while(readyQueue->head != nullptr){
        //Dequeue
        Process *process = readyQueue->dequeue();
        //The finishing time of this process is current time + burst time
        int finish_time = current_time + process->burstTime;
        //The waiting time is the duration it waited before being served. This is current time - arrival time
        int waiting_time = current_time - process->arrivalTime;
        //Turn around time is the wait time + burst time
        int turn_around_time = waiting_time + process->burstTime;
        int response_time = waiting_time;

        avg_waiting_time += waiting_time;
        avg_cpu_burst_time += process->burstTime;
        avg_response_time += response_time;
        avg_turn_around_time += turn_around_time;
        cout<<process->processID<<"\t"<<process->arrivalTime<<"\t"<<process->burstTime<<"\t\t"<<process->priority<<"\t\t"
                                <<finish_time<<"\t"<<waiting_time<<"\t\t"<<turn_around_time<<"\t\t"<<response_time<<"\t\t"<<0<<endl;
        current_time += process->burstTime;
    }
    //Calculate the averages
    avg_response_time /= n_process;
    avg_turn_around_time /= n_process;
    avg_cpu_burst_time /= n_process;
    avg_waiting_time /= n_process;
    printStats();

}


//Preemptive Priority

void Scheduler::ppSchedule(ReadyQueue *readyQueue) {
    clearStats();
    cout << "PID\tArrival\tCPU-burst\tPriority\tFinish\tWaiting Time\tTurn around\tResponse Time\tNo.of Context"<<endl;
    //Sort the queue with respect to arrival time
    sort(readyQueue,PRIORITY);
    int current_time = 0;
    int n_process = readyQueue->size;
    while(readyQueue->head != nullptr){
        Process *process = readyQueue->dequeue();
        //The finishing time of this process is current time + burst time
        int finish_time = current_time + process->burstTime;
        //The waiting time is the duration it waited before being served. This is current time - arrival time
        int waiting_time = current_time - process->priority;
        //Turn around time is the wait time + burst time
        int turn_around_time = waiting_time + process->burstTime;
        int response_time = waiting_time;

        avg_waiting_time += waiting_time;
        avg_cpu_burst_time += process->burstTime;
        avg_response_time += response_time;
        avg_turn_around_time += turn_around_time;
        cout<<process->processID<<"\t"<<process->arrivalTime<<"\t"<<process->burstTime<<"\t\t"<<process->priority<<"\t\t"
            <<finish_time<<"\t"<<waiting_time<<"\t\t"<<turn_around_time<<"\t\t"<<response_time<<"\t\t"<<0<<endl;
        current_time += process->burstTime;
    }
    //Calculate the averages
    avg_response_time /= n_process;
    avg_turn_around_time /= n_process;
    avg_cpu_burst_time /= n_process;
    avg_waiting_time /= n_process;
    printStats();

}
void Scheduler::srtfSchedule(ReadyQueue *readyQueue) {
    clearStats();
    sort(readyQueue,ARRIVAL_TIME);
    int current_time=0;
    while(readyQueue->size > 0){
        Process *head = readyQueue->head;
        head->remaining_time--;
        current_time++;
        Process *temp = head->next;
        if(temp != nullptr){
            if(temp->arrivalTime <= current_time){

            }
            temp = temp->next;

        }

    }


}

void Scheduler::rrSchedule(ReadyQueue *readyQueue, int quantum_size) {
    sort(readyQueue,ARRIVAL_TIME);
    cout << "PID\tArrival\tCPU-burst\tPriority\tFinish\tWaiting Time\tTurn around\tResponse Time\tNo.of Context"<<endl;
    Process *processList = toArray(readyQueue);
    float finishTimes[readyQueue->size];
    float responseTimes[readyQueue->size];

    int n_process = readyQueue->size;
    int n_complete = 0;
    float current_time = 0;
    //Until all the processes are complete
    while(n_complete != n_process){
        //Poll the queue
        for(int i=0; i<n_process; i++){
            //If the process's arrival time is in the future, start polling from the first
            if(processList[i].arrivalTime > current_time){
                //Check if the previous processes are complete
                int prev_complete = 0;
                for(int j=0; j<i; j++){
                    if(processList[j].remaining_time == 0){
                        prev_complete++;
                    }
                }
                //If all the previous processe's are complete. The scheduler is waiting, so forward time
                if(prev_complete == i){
                    current_time = processList[i].arrivalTime;
                }
                break;
            }
            //If the current process is finished. Move to the next one
            if(processList[i].remaining_time <= 0){
                continue;
            }
            //If the process is being served for the first time
            if(processList[i].remaining_time == processList[i].burstTime){
                responseTimes[i] = current_time - processList[i].arrivalTime;
            }
            //IF the remaining time of the current process is less than the quantum size, complete this process.
            if(processList[i].remaining_time <= quantum_size){
                current_time += processList[i].remaining_time;
                processList[i].remaining_time = 0;
                finishTimes[i] = current_time;
                n_complete++;
            }
            else{
                //When the remaining time is greater than the quantum size
                //0.5 for context switching
                current_time += (quantum_size + 0.5);
                processList[i].remaining_time -= quantum_size;
                processList[i].num_contexts++;
            }
        }
    }
    int total_contexts = 0;
    for(int i=0; i<readyQueue->size; i++){
        float turn_around_time = finishTimes[i]-processList[i].arrivalTime;
        float waiting_time = finishTimes[i] - (processList[i].arrivalTime+processList[i].burstTime);
        float finish_time = finishTimes[i];
        float response_time = responseTimes[i];
        avg_waiting_time += waiting_time;
        avg_cpu_burst_time += processList[i].burstTime;
        avg_response_time += responseTimes[i];
        avg_turn_around_time += turn_around_time;

        total_contexts += processList[i].num_contexts;
        cout<<processList[i].processID<<"\t"<<processList[i].arrivalTime<<"\t"<<processList[i].burstTime<<"\t\t"<<processList[i].priority<<"\t\t"
            <<finish_time<<"\t"<<waiting_time<<"\t\t"<<turn_around_time<<"\t\t"<<response_time<<"\t\t"<<processList[i].num_contexts<<endl;
        //cout << finishTimes[i]<<"\t"<<waiting_time<<"\t"<<turn_around_time<<"\t"<<responseTimes[i]<<"\t"<<processList[i].num_contexts<<endl;
    }

    n_context_switches = total_contexts;

    avg_response_time /= n_process;
    avg_turn_around_time /= n_process;
    avg_cpu_burst_time /= n_process;
    avg_waiting_time /= n_process;
    printStats();
}

void Scheduler::sort(ReadyQueue *readyQueue, const char *comparator){
    //Sorting based on arrival_time

    if(strcmp(comparator,ARRIVAL_TIME) == 0){
        Process *temp = readyQueue->head;
        while (temp != nullptr){
            temp->comp_data = temp->arrivalTime;
            temp = temp->next;
        }

        quickSort(&readyQueue->head);
    }
}


