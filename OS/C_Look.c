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