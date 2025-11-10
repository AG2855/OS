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