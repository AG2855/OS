#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/types.h> 
 
void asc(int *a, int sz); 
void desc(int *a, int sz); 
 
int main() 
{ 
    int *a, i, sz; 
    pid_t pid; 
 
    printf("Enter the size of the array:\n"); 
    scanf("%d", &sz); 
 
    a = (int *)malloc(sz * sizeof(int)); 
    if (a == NULL) { 
        printf("Memory allocation failed\n"); 
        exit(1); 
    } 
 
    printf("Enter elements of the array:\n"); 
    for (i = 0; i < sz; i++) { 
        scanf("%d", &a[i]); 
    } 
 
    pid = fork(); 
 
    switch (pid) { 
        case -1: 
            printf("Error in fork\n"); 
            exit(1); 
 
        case 0: 
            printf("\nChild process:\n"); 
            asc(a, sz); 
            free(a); 
            exit(0); 
 
        default: 
            printf("\nParent process:\n"); 
            desc(a, sz); 
            free(a); 
            exit(0); 
    } 
 
    return 0; 
} 
 
void asc(int *a, int sz) { 
    int i, j, temp; 
    for (i = 0; i < sz - 1; i++) { 
        for (j = i + 1; j < sz; j++) { 
            if (a[i] > a[j]) { 
                temp = a[i]; 
                a[i] = a[j]; 
                a[j] = temp; 
            } 
        } 
    } 
 
    printf("Sorted array in ascending order:\n"); 
    for (i = 0; i < sz; i++) { 
        printf("%d\t", a[i]); 
    } 
    printf("\n"); 
} 
 
void desc(int *a, int sz) { 
    int i, j, temp; 
    for (i = 0; i < sz - 1; i++) { 
        for (j = i + 1; j < sz; j++) { 
            if (a[i] < a[j]) { 
                temp = a[i]; 
                a[i] = a[j]; 
                a[j] = temp; 
            } 
        } 
    } 
 
    printf("Sorted array in descending order:\n"); 
    for (i = 0; i < sz; i++) { 
printf("%d\t", a[i]); 
} 
printf("\n"); 
}