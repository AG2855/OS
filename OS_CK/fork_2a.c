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


/*
------------------------------------------------------------
📘 PROGRAM: Process Creation using fork() — Sorting in Parent and Child
------------------------------------------------------------

🔹 PURPOSE:
This program demonstrates the use of the **fork() system call** in Linux/Unix
to create a child process. The parent and child processes perform different tasks:
- The **child process** sorts an array in **ascending order**.
- The **parent process** sorts the same array in **descending order**.

It shows process differentiation, independent execution, and basic inter-process behavior.

------------------------------------------------------------
⚙️ ALGORITHM / LOGIC USED:

1️⃣ **Input Phase**
   - The user enters the size of the array and its elements.
   - Memory is dynamically allocated using `malloc()` to store the array.

2️⃣ **Process Creation (fork)**
   - The `fork()` system call creates a **child process**.
   - After fork:
       - `pid = 0` → child process executes.
       - `pid > 0` → parent process executes.
       - `pid = -1` → fork failed.

3️⃣ **Child Process (pid = 0)**
   - Calls the function `asc()` to sort the array in ascending order.
   - Prints the sorted array.
   - Frees allocated memory and exits.

4️⃣ **Parent Process (pid > 0)**
   - Calls the function `desc()` to sort the array in descending order.
   - Prints the sorted array.
   - Frees allocated memory and exits.

5️⃣ **Sorting Functions**
   - Both `asc()` and `desc()` use a simple **Bubble Sort algorithm**:
     - Compare each element with all others.
     - Swap elements to arrange them in ascending or descending order.

------------------------------------------------------------
🧮 EXAMPLE EXECUTION:

Example Input:
----------------
Enter the size of the array:
5
Enter elements of the array:
10 5 3 8 2

Example Output:
----------------
Parent process:
Sorted array in descending order:
10	8	5	3	2	

Child process:
Sorted array in ascending order:
2	3	5	8	10	

------------------------------------------------------------
📊 EXPLANATION:

- When `fork()` is called, the process splits into two — a parent and a child.
- Both processes run **independently** with their own copies of the array.
- The child process sorts the array in **ascending** order.
- The parent process sorts the array in **descending** order.
- Both print their respective results.

------------------------------------------------------------
✅ SUMMARY:
- System Call Used: fork()
- Concept: Process Creation and Independent Execution
- Algorithm Used: Bubble Sort
- Features Demonstrated:
   • Dynamic memory allocation (`malloc`)
   • Parent-child process execution
   • Ascending and descending sorting
------------------------------------------------------------
*/
