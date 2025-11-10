#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
 
int i, j; 
 
void sort(int arr[], int n) { 
    for (i = 0; i < n - 1; i++) { 
        for (j = 0; j < n - i - 1; j++) { 
            if (arr[j] > arr[j + 1]) { 
                int temp = arr[j]; 
                arr[j] = arr[j + 1]; 
                arr[j + 1] = temp; 
            } 
        } 
    } 
} 
 
int main() { 
    int n, head, disk_size, direction; 
    int requests[100]; 
    int left[100], right[100]; 
    int l = 0, r = 0; 
    int total = 0; 
 
    printf("Enter number of disk requests: "); 
    scanf("%d", &n); 
 
    printf("Enter disk requests: "); 
    for (i = 0; i < n; i++) 
        scanf("%d", &requests[i]); 
 
    printf("Enter initial head position: "); 
    scanf("%d", &head); 
 
    printf("Enter total disk size: "); 
    scanf("%d", &disk_size); 
 
    printf("Enter head movement direction (1 for high, 0 for low): "); 
    scanf("%d", &direction); 
 
    for (i = 0; i < n; i++) { 
        if (requests[i] < head) 
            left[l++] = requests[i]; 
        else 
            right[r++] = requests[i]; 
    } 
 
    sort(left, l); 
    sort(right, r); 
 
    printf("\nSCAN Disk Scheduling Algorithm:\n"); 
    printf("Initial head position: %d\n", head); 
    printf("Seek Sequence: %d", head); 
 
    if (direction == 1) { 
        for (i = 0; i < r; i++) { 
            total += abs(head - right[i]); 
            head = right[i]; 
            printf(" -> %d", head); 
        } 
 
        if (l > 0) { 
            total += abs(head - (disk_size - 1)); 
            head = disk_size - 1; 
            total += abs(head - left[l - 1]); 
            head = left[l - 1]; 
            printf(" -> %d", head); 
            for (i = l - 2; i >= 0; i--) { 
                total += abs(head - left[i]); 
                head = left[i]; 
                printf(" -> %d", head); 
            } 
        } 
    } else { 
        for (i = l - 1; i >= 0; i--) { 
            total += abs(head - left[i]); 
            head = left[i]; 
            printf(" -> %d", head); 
        } 
 
        if (r > 0) { 
            total += abs(head - 0); 
            head = 0; 
            total += abs(head - right[0]); 
            head = right[0]; 
            printf(" -> %d", head); 
            for (i = 1; i < r; i++) { 
                total += abs(head - right[i]); 
                head = right[i]; 
                printf(" -> %d", head); 
            } 
        } 
    } 
 
    printf("\nTotal head movement: %d\n", total); 
    return 0; 

} 

/*
--------------------------------------------------------------------------------
Program: SCAN Disk Scheduling Algorithm (Elevator Algorithm)
--------------------------------------------------------------------------------
Algorithm Used:
    The program implements the **SCAN Disk Scheduling Algorithm**, also known as 
    the **Elevator Algorithm**, used in Operating Systems for managing disk I/O 
    requests efficiently.

Concept:
    - In SCAN scheduling, the disk arm (head) moves in one direction (either 
      towards higher or lower cylinder numbers), servicing all pending requests 
      in that direction until it reaches the end (or the last request in that 
      direction). 
    - After reaching the end, it reverses its direction and continues servicing 
      the requests in the opposite direction — similar to an elevator moving up 
      and down a building, hence the name “Elevator Algorithm”.

--------------------------------------------------------------------------------
Logic Explanation:
1. **Inputs:**
       - Number of disk requests (n)
       - Request queue (list of requested tracks)
       - Initial head position
       - Total disk size
       - Head movement direction 
         (1 → moving toward higher tracks, 0 → moving toward lower tracks)

2. **Step-by-Step Logic:**
       a. Separate the requests into two arrays:
          - `left[]` → requests less than head position
          - `right[]` → requests greater than or equal to head position

       b. Sort both `left` and `right` arrays in ascending order.

       c. Depending on the direction:
          - **If direction = 1 (high):**
              • Move from current head to all requests in `right[]` (in order).
              • Then move to the end of the disk (`disk_size - 1`).
              • Reverse direction and service all requests in `left[]` 
                (from largest to smallest).
          
          - **If direction = 0 (low):**
              • Move from current head to all requests in `left[]` (in reverse order).
              • Then move to track 0 (start of disk).
              • Reverse direction and service all requests in `right[]`
                (in ascending order).

       d. Each move adds the absolute distance between the current head position 
          and the next request to the total head movement.

3. **Output:**
       - The sequence of serviced tracks (seek sequence)
       - The total head movement (total seek distance)

--------------------------------------------------------------------------------
Example Input/Output:

Input:
    Enter number of disk requests: 8
    Enter disk requests: 98 183 37 122 14 124 65 67
    Enter initial head position: 53
    Enter total disk size: 200
    Enter head movement direction (1 for high, 0 for low): 1

Output:
    SCAN Disk Scheduling Algorithm:
    Initial head position: 53
    Seek Sequence: 53 -> 65 -> 67 -> 98 -> 122 -> 124 -> 183 -> 199 -> 37 -> 14
    Total head movement: 331

--------------------------------------------------------------------------------
Explanation of Output:
    - The head starts at 53 and moves toward higher track numbers.
    - It services all higher requests (65, 67, 98, 122, 124, 183) first.
    - Then it moves to the end (199), reverses direction, and services 
      the remaining lower requests (37, 14).
    - The total head movement is the sum of all seek distances.

--------------------------------------------------------------------------------
Summary:
    - The SCAN algorithm reduces total seek time compared to FCFS 
      by servicing requests in an ordered path.
    - It provides better performance and fairness since the head moves 
      systematically across the disk in both directions.
--------------------------------------------------------------------------------
*/
