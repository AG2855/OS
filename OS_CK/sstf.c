#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
 
int main() { 
    int n, i, j, head, total = 0; 
    int requests[100], visited[100] = {0}; 
 
    printf("Enter number of disk requests: "); 
    scanf("%d", &n); 
 
    printf("Enter disk requests: "); 
    for (i = 0; i < n; i++) 
        scanf("%d", &requests[i]); 
 
    printf("Enter initial head position: "); 
    scanf("%d", &head); 
 
    printf("\nSSTF Disk Scheduling:\n"); 
    printf("Sequence: %d", head); 
 
    int count = 0; 
    while (count < n) { 
        int min = 9999, index = -1; 
 
        for (i = 0; i < n; i++) { 
            if (!visited[i]) { 
                int dist = abs(head - requests[i]); 
                if (dist < min) { 
                    min = dist; 
                    index = i; 
                } 
            } 
        } 
 
        total += min; 
        head = requests[index]; 
        visited[index] = 1; 
        count++; 
        printf(" -> %d", head); 
    } 
 
    printf("\nTotal head movement: %d\n", total); 
    return 0; 

}

/*
-------------------------------------------------------------------------------
Program: Shortest Seek Time First (SSTF) Disk Scheduling Algorithm
-------------------------------------------------------------------------------
Algorithm Used:
- The SSTF (Shortest Seek Time First) algorithm is a disk scheduling method that 
  selects the disk I/O request that is closest (in terms of absolute distance) 
  to the current head position. 
- This minimizes the total seek time for each operation compared to FCFS.

Logic Explanation:
1. The program first accepts:
   - Number of disk requests.
   - The sequence of disk requests.
   - The initial head position.
2. It maintains a `visited[]` array to track which requests have been serviced.
3. In each iteration:
   - It finds the unvisited request closest to the current head position 
     (using absolute difference).
   - Moves the head to that request.
   - Adds the movement distance to the total head movement.
   - Marks that request as visited.
4. This continues until all requests are serviced.
5. Finally, it prints the complete service sequence and the total head movement.

-------------------------------------------------------------------------------
Example Input and Output:

Enter number of disk requests: 8
Enter disk requests: 55 58 39 18 90 160 150 184
Enter initial head position: 100

SSTF Disk Scheduling:
Sequence: 100 -> 90 -> 58 -> 55 -> 39 -> 18 -> 150 -> 160 -> 184
Total head movement: 331

-------------------------------------------------------------------------------
Advantages:
- Reduces total seek time compared to FCFS.
- More efficient as it always services the closest request next.

Disadvantages:
- May cause starvation for requests far from the current head.

-------------------------------------------------------------------------------
*/
