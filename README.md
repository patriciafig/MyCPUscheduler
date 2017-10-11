
**CSCI 3415 – Principles of Programming Languages**

Lab Assignment 2

Due Date  :  Oct. 30, 2017

-----------------

# 1. Goal of this assignment

> 
The primary goal of this lab assignment is to understand various CPU scheduling algorithms and gain some experience building 
a simulator for CPU scheduling algorithm to evaluate their performances.
>

-----------------

# 2. Lab assignment description

> 
Write a C/C++ program to simulate a CPU scheduler which selects a processor from a ready queue and executes the process by a 
given scheduling algorithm, display its actives and evaluate its performance based on collected some measurements such 
as average turn-around time, average waiting time, average response time. When a process is scheduled, the simulator will 
simply print what the process is running at what time, collecting some measurement data and producing Gantt Chart-like outputs. 
>

-----------------

# 3. Specification 

> 
- Implement FCFS ( First Come First Serve)
- SRTF ( Shortest Remaining Task First)
- RR (Round Robin), PP(Preemptive Priority) scheduling algorithms
- Must create a PCB Structure 
- Cannot use any STD library for building queue and managing the ready queue. 
For example, you cannot use STD/STL for queue or linked list, 
>

-----------------

# Assumptions 
There is only one CPU
- All processes perform only CPU operations
- 0 Highest Priority and 100 lowest priority 
- The new arrival process is directly stored at the ready queue.
- We use only ready queue for this simulation.
- We take into consideration of context switching cost. 
- We assume the context switching cost is 0.5 milliseconds when a context switching is occurred.
- Context switch is performed only when a current process is moved to the ready queue.  
- The time of unit is milliseconds.
- We use FCFS policy for breaking the tie. (For SRFT, Round-Robin, and PP case)
 
-----------------



      
      
      
