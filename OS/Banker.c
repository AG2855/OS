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
