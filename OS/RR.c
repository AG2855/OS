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
 
    printf("\nProcess\tArrival Time\tBurst Time\tTurnaround Time\tWaiting Time\n"); 
 
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
            printf("P[%d]\t%d\t\t%d\t\t%d\t\t%d\n", 
                   i + 1, 
                   arrival_time[i], 
                   burst_time[i], 
                   total - arrival_time[i], 
                   total - arrival_time[i] - burst_time[i]); 
 
            average_wait_time += total - arrival_time[i] - burst_time[i]; 
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
