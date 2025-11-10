#include <stdio.h>

int main() {
    int n = 5; // number of processes
    int r = 3; // number of resources

    int alloc[5][3] = {{0, 1, 0},{2, 0, 0},{3, 0, 2},{2, 1, 1},{0, 0, 2}};

    int max[5][3] = {{7, 5, 3},{3, 2, 2},{9, 0, 2},{2, 2, 2},{4, 3, 3}};

    int avail[3] = {3, 3, 2};

    int need[n][r];
    int finish[n];
    int ans[n];
    int ind = 0;

    // Calculate need matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < r; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    // Initialize finish array
    for (int i = 0; i < n; i++) {
        finish[i] = 0;
    }

    // Safety algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (finish[i] == 0) {
                int flag = 0;
                for (int j = 0; j < r; j++) {
                    if (need[i][j] > avail[j]) {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0) {
                    ans[ind++] = i;
                    for (int j = 0; j < r; j++) {
                        avail[j] += alloc[i][j];
                    }
                    finish[i] = 1;
                }
            }
        }
    }

    // Print safe sequence
    printf("The SAFE Sequence is:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d ", ans[i]);
    }
    printf("\n");

    return 0;
}

/*
------------------------------------------------------------
Explanation of the Program
------------------------------------------------------------

🔹 Algorithm Used:
This program implements the **Banker's Algorithm (Safety Algorithm)** in Operating Systems.

The Banker's Algorithm is used to **avoid deadlock** by ensuring that a system is always in a "safe state".
A *safe state* means there exists at least one sequence of processes (safe sequence)
in which all processes can complete without causing a deadlock.

------------------------------------------------------------
🔹 Logic / Steps in the Code:

1. **Initialization:**
   - `n` = number of processes
   - `r` = number of resource types
   - `alloc[][]` = Allocation matrix (current resources allocated to each process)
   - `max[][]` = Maximum resource requirement of each process
   - `avail[]` = Available resources at the moment

2. **Calculate Need Matrix:**
need[i][j] = max[i][j] - alloc[i][j]
This represents how many more instances of each resource a process may still request.

3. **Initialize Finish Array:**
- `finish[i] = 0` → process not yet finished.

4. **Apply Safety Algorithm:**
- Repeatedly check all processes.
- If a process's remaining need ≤ available resources → it can safely execute.
- After execution, release its allocated resources (add to available).
- Mark process as finished and add to the safe sequence.

5. **If all processes finish successfully:**
- The system is in a *safe state*.
- Print the Safe Sequence.

------------------------------------------------------------
🔹 Example Input (Already Defined in Code):

Number of Processes: 5  
Number of Resources: 3  

Allocation Matrix:
| P | A | B | C |
|---|---|---|---|
| P0 | 0 | 1 | 0 |
| P1 | 2 | 0 | 0 |
| P2 | 3 | 0 | 2 |
| P3 | 2 | 1 | 1 |
| P4 | 0 | 0 | 2 |

Maximum Matrix:
| P | A | B | C |
|---|---|---|---|
| P0 | 7 | 5 | 3 |
| P1 | 3 | 2 | 2 |
| P2 | 9 | 0 | 2 |
| P3 | 2 | 2 | 2 |
| P4 | 4 | 3 | 3 |

Available Resources: {3, 3, 2}

------------------------------------------------------------
🔹 Expected Output:

The SAFE Sequence is:
P1 P3 P4 P0 P2

------------------------------------------------------------
🔹 Key Point:
If no safe sequence exists, it means the system is in a *deadlock state* or *unsafe state*.

------------------------------------------------------------
*/
