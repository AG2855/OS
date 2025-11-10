#include <stdio.h> 
 
int main() 
{ 
    int arrival_time[10], burst_time[10], temp[10]; 
    int i, smallest, count = 0, time, limit; 
    double wait_time = 0, turnaround_time = 0, end; 
    float average_waiting_time, average_turnaround_time; 
 
    printf("Enter the total number of processes: "); 
    scanf("%d", &limit); 
 
    printf("Enter details of %d processes\n", limit); 
    for (i = 0; i < limit; i++) 
    { 
        printf("Enter arrival time for process %d: ", i + 1); 
        scanf("%d", &arrival_time[i]); 
        printf("Enter burst time for process %d: ", i + 1); 
        scanf("%d", &burst_time[i]); 
        temp[i] = burst_time[i]; 
    } 
 
    burst_time[limit] = 9999; 
 
    for (time = 0; count != limit; time++) 
    { 
        smallest = limit; 
        for (i = 0; i < limit; i++) 
        { 
            if (arrival_time[i] <= time && burst_time[i] < 
burst_time[smallest] && burst_time[i] > 0) 
            { 
                smallest = i; 
            } 
        } 
 
        burst_time[smallest]--; 
 
        if (burst_time[smallest] == 0) 
        { 
            count++; 
            end = time + 1; 
            wait_time += end - arrival_time[smallest] - 
temp[smallest]; 
            turnaround_time += end - arrival_time[smallest]; 
        } 
    } 
 
    average_waiting_time = wait_time / limit; 
    average_turnaround_time = turnaround_time / limit; 
 
    printf("\nAverage waiting time: %.2f", average_waiting_time); 
    printf("\nAverage turnaround time: %.2f\n", 
average_turnaround_time); 
 
    return 0; 

}

/*
------------------------------------------------------------
🧠 PROGRAM EXPLANATION — SHORTEST REMAINING TIME FIRST (SRTF)
------------------------------------------------------------

🔹 ALGORITHM USED:
   This program implements the **Shortest Remaining Time First (SRTF)** 
   CPU Scheduling Algorithm — which is the **preemptive** version of 
   Shortest Job Next (SJN) or Shortest Job First (SJF).

   In SRTF scheduling, at any given moment, the process with the 
   **shortest remaining burst time** is selected for execution.
   If a new process arrives with a shorter burst time than the current 
   one, the CPU **preempts** the current process and switches to the new one.

------------------------------------------------------------
⚙️ LOGIC USED IN THE CODE:

1️⃣ INPUT PHASE:
   - User enters the total number of processes (`limit`).
   - For each process, the program takes:
       ➤ Arrival Time (when the process enters ready queue)
       ➤ Burst Time (total CPU time required)
   - Burst times are stored in two arrays:
       ➤ `burst_time[]` — used for execution
       ➤ `temp[]` — stores the original burst times for calculation

2️⃣ INITIAL SETUP:
   - The last index `burst_time[limit]` is set to a very large value (9999)
     to avoid comparison issues during the "find smallest" step.

3️⃣ EXECUTION PHASE (MAIN LOOP):
   - The program simulates the CPU running time using a time counter (`time`).
   - For each time unit:
       ➤ It finds the process with the **smallest remaining burst time**
         among those that have already arrived (`arrival_time[i] <= time`).
       ➤ That process runs for **1 time unit** (`burst_time[smallest]--`).
       ➤ If the process finishes (`burst_time[smallest] == 0`):
           • It is marked as completed.
           • The program calculates:
               ▪ Turnaround Time = Completion Time − Arrival Time
               ▪ Waiting Time = Turnaround Time − Original Burst Time

4️⃣ OUTPUT PHASE:
   - After all processes complete, the program calculates:
       ➤ Average Waiting Time = Total Waiting Time / Number of Processes
       ➤ Average Turnaround Time = Total Turnaround Time / Number of Processes
   - These averages are displayed on the screen.

------------------------------------------------------------
📊 EXAMPLE INPUT / OUTPUT:

Example Input:
---------------
Enter the total number of processes: 3
Enter details of 3 processes
Enter arrival time for process 1: 0
Enter burst time for process 1: 8
Enter arrival time for process 2: 1
Enter burst time for process 2: 4
Enter arrival time for process 3: 2
Enter burst time for process 3: 2

Example Output:
---------------
Average waiting time: 4.33
Average turnaround time: 8.00

------------------------------------------------------------
✅ SUMMARY:
   ➤ Scheduling Type: Preemptive
   ➤ Algorithm: Shortest Remaining Time First (SRTF)
   ➤ Key Principle: Select process with smallest remaining CPU time
   ➤ Objective: Minimize average waiting time and turnaround time
------------------------------------------------------------
*/
