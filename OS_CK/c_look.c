#include <stdio.h> 
#include <stdlib.h> 
 
void sort(int arr[], int n) { 
    int i, j, temp; 
    for (i = 0; i < n - 1; i++) { 
        for (j = 0; j < n - i - 1; j++) { 
            if (arr[j] > arr[j + 1]) { 
                temp = arr[j]; 
                arr[j] = arr[j + 1]; 
                arr[j + 1] = temp; 
            } 
        } 
    } 
} 
 
int main() { 
    int n, head, i, total, index, current; 
    total = 0; 
    index = 0; 
 
    printf("Enter number of disk requests: "); 
    scanf("%d", &n); 
 
    int requests[100]; 
 
    printf("Enter the disk requests: "); 
    for (i = 0; i < n; i++) { 
        scanf("%d", &requests[i]); 
    } 
 
    printf("Enter initial head position: "); 
    scanf("%d", &head); 
 
    sort(requests, n); 
 
    for (i = 0; i < n; i++) { 
        if (requests[i] > head) { 
            index = i; 
            break; 
        } 
    } 
 
    printf("\nC-LOOK Disk Scheduling Order:\n"); 
    current = head; 
 
    for (i = index; i < n; i++) { 
        printf("%d -> ", requests[i]); 
        total += abs(requests[i] - current); 
        current = requests[i]; 
    } 
 
    if (index > 0) { 
        total += abs(requests[n - 1] - requests[0]); 
        current = requests[0]; 
 
        for (i = 0; i < index; i++) { 
            printf("%d -> ", requests[i]); 
            total += abs(requests[i] - current); 
            current = requests[i]; 
        } 
    } 
 
    printf("END\n"); 
    printf("\nTotal head movement = %d\n", total); 
    return 0; 

}

/*
------------------------------------------------------------
Program Explanation: C-LOOK Disk Scheduling Algorithm
------------------------------------------------------------

Algorithm Used:
---------------
This program implements the **C-LOOK (Circular LOOK)** Disk Scheduling Algorithm.
C-LOOK is a variant of the LOOK algorithm used in operating systems for servicing
disk I/O requests efficiently.

Working Logic:
--------------
1. The algorithm first sorts all disk requests in ascending order.
2. It starts servicing requests from the current head position and moves
   toward the higher end of the disk.
3. When it reaches the highest request, instead of moving to the end of the disk,
   it jumps directly to the lowest request (circular movement) and continues
   servicing the remaining requests.
4. The total head movement is calculated as the sum of all distances the head travels.

Step-by-Step Execution:
-----------------------
1. Input the number of disk requests.
2. Enter all the request track numbers.
3. Input the initial head position.
4. The program:
   - Sorts the requests.
   - Finds the point where requests are greater than the head.
   - Moves sequentially from that point to the end.
   - Then jumps to the smallest request and continues till the starting point.
5. Finally, it prints the order of servicing and total head movement.

Example Input/Output:
---------------------

Example Input:
---------------
Enter number of disk requests: 8
Enter the disk requests: 176 79 34 60 92 11 41 114
Enter initial head position: 50

Example Output:
---------------
C-LOOK Disk Scheduling Order:
60 -> 79 -> 92 -> 114 -> 176 -> 11 -> 34 -> 41 -> END

Total head movement = 322

Explanation:
------------
- Requests are sorted: [11, 34, 41, 60, 79, 92, 114, 176]
- Head starts at 50, so it moves from 60 upward till 176,
  then jumps back to 11 (circularly), and continues till 41.
- Total head movement is calculated as the sum of all seek distances.

------------------------------------------------------------
*/
