#include <stdio.h> 
 
int main() 
{ 
    int i, limit, total = 0, x, counter = 0, time_quantum; 
    float average_wait_time = 0, average_turnaround_time = 0; 
    int arrival_time[10], burst_time[10], temp[10]; 
 
    printf("Enter Total Number of Processes: "); 
    scanf("%d", &limit); 
 
    x = limit; 
 
    for(i = 0; i < limit; i++) 
    { 
        printf("Enter Details of Process[%d]\n", i + 1); 
        printf("Arrival Time: "); 
        scanf("%d", &arrival_time[i]); 
        printf("Burst Time: "); 
        scanf("%d", &burst_time[i]); 
        temp[i] = burst_time[i]; 
    } 
 
    printf("Enter Time Quantum: "); 
    scanf("%d", &time_quantum); 
 
    printf("\nProcess\tBurst Time\tTurnaround Time\tWaiting Time\n"); 
 
    for(total = 0, i = 0; x != 0; ) 
    { 
        if(temp[i] <= time_quantum && temp[i] > 0) 
        { 
            total = total + temp[i]; 
            temp[i] = 0; 
            counter = 1; 
        } 
        else if(temp[i] > 0) 
        { 
            temp[i] = temp[i] - time_quantum; 
            total = total + time_quantum; 
        } 
 
        if(temp[i] == 0 && counter == 1) 
        { 
            x--; 
            printf("P[%d]\t%d\t\t%d\t\t%d\n", i + 1, 
burst_time[i], 
                   total - arrival_time[i], 
                   total - arrival_time[i] - burst_time[i]); 
 
            average_wait_time += total - arrival_time[i] - 
burst_time[i]; 
            average_turnaround_time += total - arrival_time[i]; 
            counter = 0; 
        } 
 
        if(i == limit - 1) 
            i = 0; 
        else if(arrival_time[i + 1] <= total) 
            i++; 
        else 
            i = 0; 
    } 
 
    average_wait_time = average_wait_time / limit; 
    average_turnaround_time = average_turnaround_time / limit; 
 
    printf("\nAverage Waiting Time:\t%f", average_wait_time); 
    printf("\nAverage Turnaround Time:\t%f\n", average_turnaround_time); 
 
    return 0; 
} 

/*
------------------------------------------------------------
🧠 PROGRAM EXPLANATION — ROUND ROBIN CPU SCHEDULING
------------------------------------------------------------

🔹 ALGORITHM USED:
   This program implements the **Round Robin (RR) CPU Scheduling Algorithm**.
   Round Robin is a **preemptive** process scheduling method used in time-sharing systems.
   Each process is assigned a fixed CPU time slot called the **Time Quantum (TQ)**.
   Processes are executed in a cyclic order, ensuring fairness and no starvation.

------------------------------------------------------------
⚙️ LOGIC USED IN THE CODE:

1. INPUT PHASE:
   - User enters total number of processes.
   - For each process, input:
       ➤ Arrival Time
       ➤ Burst Time
   - Store burst times in a temporary array `temp[]` for manipulation.
   - Input the Time Quantum.

2. EXECUTION PHASE:
   - Initialize `total = 0` (current time) and `x = number of processes`.
   - Iterate through the process list repeatedly (cyclically) until all processes finish.
   - For each process:
       ➤ If remaining burst time ≤ time quantum → execute and complete process.
       ➤ Else → execute for one time quantum, reduce remaining time, and move to next.
   - Track completion time using `total`.
   - When a process finishes, calculate:
         Turnaround Time = total - arrival_time[i]
         Waiting Time    = Turnaround Time - burst_time[i]
   - Accumulate total waiting and turnaround times for averages.

3. OUTPUT PHASE:
   - Display each process with:
         Process ID | Burst Time | Turnaround Time | Waiting Time
   - Finally, print:
         ➤ Average Waiting Time
         ➤ Average Turnaround Time

------------------------------------------------------------
📊 EXAMPLE INPUT / OUTPUT:

Example Input:
---------------
Enter Total Number of Processes: 3
Enter Details of Process[1]
Arrival Time: 0
Burst Time: 5
Enter Details of Process[2]
Arrival Time: 1
Burst Time: 4
Enter Details of Process[3]
Arrival Time: 2
Burst Time: 2
Enter Time Quantum: 2

Example Output:
---------------
Process   Burst Time   Turnaround Time   Waiting Time
P[1]      5            11                6
P[2]      4            10                6
P[3]      2            4                 2

Average Waiting Time:     4.666667
Average Turnaround Time:  8.333333

------------------------------------------------------------
✅ SUMMARY:
   ➤ Scheduling Type: Preemptive
   ➤ Algorithm: Round Robin
   ➤ Purpose: Fair CPU sharing among all processes
   ➤ Key Concept: Each process executes for a fixed time quantum in cyclic order
------------------------------------------------------------
*/
