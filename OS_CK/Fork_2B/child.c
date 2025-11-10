#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[], char *en[])
{
    int i, j, c, arr[argc], ele;

    // Convert arguments to integers
    for (j = 0; j < argc - 1; j++)
    {
        arr[j] = atoi(argv[j]);
    }

    ele = atoi(argv[j]);
    i = 0;
    j = argc - 2;
    c = (i + j) / 2;

    while (arr[c] != ele && i <= j)
    {
        if (ele > arr[c])
            i = c + 1;
        else
            j = c - 1;
        c = (i + j) / 2;
    }

    if (i <= j)
        printf("\nElement found in given array");
    else
        printf("\nElement not found in given array");

    return 0;
}

/*
------------------------------------------------------------
PROGRAM EXPLANATION:
------------------------------------------------------------
This program demonstrates the use of **fork()** and **execv()**
system calls in C for **process creation and execution**,
combined with **bubble sort** and **binary search** algorithms.

It consists of two parts:
1. **Parent Program (main program)** — handles input, sorting, and
   process creation.
2. **Child Program (execv target)** — performs binary search on the
   sorted array.

------------------------------------------------------------
ALGORITHM USED:
------------------------------------------------------------
→ 1. **Bubble Sort Algorithm**
   - Used in the parent process to sort the input array.
   - Repeatedly swaps adjacent elements if they are in the wrong order.
   - Time Complexity: O(n²)

→ 2. **Binary Search Algorithm**
   - Used in the child process to efficiently search for an element
     in the sorted array.
   - It repeatedly divides the array into halves to locate the element.
   - Time Complexity: O(log n)

→ 3. **Process Control using fork() and execv()**
   - `fork()` creates a new process (child process).
   - `execv()` replaces the child process with a new program
     (the binary search executable), passing the sorted array and
     search element as command-line arguments.

------------------------------------------------------------
WORKING / LOGIC OF THE PROGRAM:
------------------------------------------------------------
1. The **Parent Program**:
   - Takes array size and elements from the user.
   - Displays entered elements.
   - Sorts them using **Bubble Sort**.
   - Takes an element to search (`ele`).
   - Converts the sorted array and search element to **string format**
     (since execv() requires string arguments).
   - Uses **fork()** to create a child process.
   - The child process executes the second program (Binary Search)
     using **execv()**, passing the sorted numbers and the search
     element as arguments.

2. The **Child Program**:
   - Receives the sorted array and the search element as command-line
     arguments from the parent.
   - Converts them back to integers using `atoi()`.
   - Performs **Binary Search** on the array to locate the element.
   - Displays whether the element was found or not.

------------------------------------------------------------
EXAMPLE INPUT / OUTPUT:
------------------------------------------------------------
Example Execution Steps:

(1) Compile both programs:
    gcc parent.c -o parent
    gcc child.c -o child

(2) Run the parent program and pass child program name:
    ./parent ./child

Sample Input:
--------------
Enter the size of array: 5
Enter the numbers:
9 4 2 7 3

Elements entered are:
9 4 2 7 3
Sorted elements are:
2 3 4 7 9

Enter element to search: 7

Sample Output:
--------------
(From Child Process Executed via execv)
Element found in given array

------------------------------------------------------------
LOGICAL FLOW:
------------------------------------------------------------
Parent Process:
   Input → Sort → Fork → Execv(child, sorted array + element)

Child Process:
   Receive args → Convert to int → Perform Binary Search → Print result

------------------------------------------------------------
KEY POINTS:
------------------------------------------------------------
- Demonstrates **Interprocess Communication via Arguments**.
- Shows **use of fork() and execv()** for process replacement.
- Combines **Sorting** and **Searching** algorithms.
- Efficient use of **Binary Search** after sorting data.

------------------------------------------------------------
ADVANTAGES:
------------------------------------------------------------
✔ Efficient search using Binary Search.
✔ Demonstrates process creation and execution concepts in UNIX.
✔ Clear separation of sorting (parent) and searching (child).

------------------------------------------------------------
*/

