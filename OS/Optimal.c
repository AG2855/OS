#include <stdio.h>

// Function to display the current state of frames
void printFrames(int frames[], int capacity, int count) {
    for (int i = 0; i < capacity; i++) {
        if (i < count)
            printf("%d ", frames[i]);
        else
            printf("- ");
    }
    printf("\n");
}

// Function to check if a page is already present in frames
int search(int frames[], int count, int page) {
    for (int i = 0; i < count; i++) {
        if (frames[i] == page)
            return 1;
    }
    return 0;
}

// Function to perform Optimal Page Replacement
void optimal(int pages[], int n, int capacity) {
    int frames[capacity];
    int count = 0;
    int faults = 0, hits = 0;

    printf("\n--- Optimal Page Replacement Algorithm ---\n");

    for (int i = 0; i < n; i++) {
        int page = pages[i];

        // If page not found in frames
        if (!search(frames, count, page)) {
            faults++;

            // If there is space in frames
            if (count < capacity) {
                frames[count++] = page;
            } else {
                int replace_index = -1, farthest = i + 1;

                for (int j = 0; j < capacity; j++) {
                    int k;
                    for (k = i + 1; k < n; k++) {
                        if (frames[j] == pages[k]) {
                            if (k > farthest) {
                                farthest = k;
                                replace_index = j;
                            }
                            break;
                        }
                    }

                    // If a frame is never used again
                    if (k == n) {
                        replace_index = j;
                        break;
                    }
                }

                if (replace_index == -1)
                    replace_index = 0;

                frames[replace_index] = page;
            }
        } else {
            hits++;
        }

        printf("After inserting page %d: ", page);
        printFrames(frames, capacity, count);
    }

    printf("\nTotal Page Faults = %d\n", faults);
    printf("Total Page Hits = %d\n", hits);
    printf("Fault Ratio = %.2f\n", (float)faults / n);
    printf("Hit Ratio = %.2f\n", (float)hits / n);
}

int main() {
    int n, capacity, pages[100];

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &capacity);

    optimal(pages, n, capacity);

    return 0;
}
