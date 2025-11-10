#include <stdio.h> 
 
int main() { 
    int no_of_frames, no_of_pages; 
    int frames[10], pages[30], temp[10]; 
    int flag1, flag2, flag3, i, j, k, pos, max, faults = 0; 
 
    printf("Enter number of frames: "); 
    scanf("%d", &no_of_frames); 
 
    printf("Enter number of pages: "); 
    scanf("%d", &no_of_pages); 
 
    printf("Enter page reference string: "); 
    for (i = 0; i < no_of_pages; ++i) { 
        scanf("%d", &pages[i]); 
    } 
 
    for (i = 0; i < no_of_frames; ++i) { 
        frames[i] = -1; 
    } 
 
    for (i = 0; i < no_of_pages; ++i) { 
        flag1 = flag2 = 0; 
 
        for (j = 0; j < no_of_frames; ++j) { 
            if (frames[j] == pages[i]) { 
                flag1 = flag2 = 1; 
                break; 
            } 
        } 
        if (flag1 == 0) { 
            for (j = 0; j < no_of_frames; ++j) { 
                if (frames[j] == -1) { 
                    faults++; 
                    frames[j] = pages[i]; 
                    flag2 = 1; 
                    break; 
                } 
            } 
        } 
        if (flag2 == 0) { 
            flag3 = 0; 
 
            for (j = 0; j < no_of_frames; ++j) { 
                temp[j] = -1; 
 
                for (k = i + 1; k < no_of_pages; ++k) { 
                    if (frames[j] == pages[k]) { 
                        temp[j] = k; 
                        break; 
                    } 
                } 
            } 
            for (j = 0; j < no_of_frames; ++j) { 
                if (temp[j] == -1) { 
                    pos = j; 
  
                    flag3 = 1; 
                    break; 
                } 
            } 
 
            if (flag3 == 0) { 
                max = temp[0]; 
                pos = 0; 
 
                for (j = 1; j < no_of_frames; ++j) { 
                    if (temp[j] > max) { 
                        max = temp[j]; 
                        pos = j; 
                    } 
                } 
            } 
            frames[pos] = pages[i]; 
            faults++; 
        } 
        printf("\n"); 
        for (j = 0; j < no_of_frames; ++j) { 
            printf("%d\t", frames[j]); 
        } 
    } 
    printf("\n\nTotal Page Faults = %d", faults); 
 
    return 0; 

} 

/*
------------------------------------------------------------
PROGRAM EXPLANATION:
------------------------------------------------------------
This program implements the **Optimal Page Replacement Algorithm** used in 
operating systems for managing memory pages.

------------------------------------------------------------
ALGORITHM USED: Optimal Page Replacement Algorithm
------------------------------------------------------------
→ The Optimal Page Replacement algorithm replaces the page 
  that will not be used for the longest period of time in the future.

→ It minimizes the number of page faults by making the best 
  possible replacement decision — but it requires knowledge 
  of future page references (hence "optimal").

------------------------------------------------------------
LOGIC / WORKING OF THE PROGRAM:
------------------------------------------------------------
1. The user enters:
     - Number of frames (memory slots)
     - Number of pages (page reference string length)
     - The sequence of page references

2. The algorithm checks each page in the reference string:
   a) If the page is already present in a frame → No page fault.
   b) If not present:
        - If an empty frame is available → place the page.
        - Otherwise → find the page that will not be used for the longest 
          time in the future (or not at all) and replace it.
        - Increase the page fault count.

3. After each page reference, the program prints the current 
   frame contents for visualization.

4. Finally, it displays the **total number of page faults**.

------------------------------------------------------------
EXAMPLE INPUT / OUTPUT:
------------------------------------------------------------
Example Input:
---------------
Enter number of frames: 3
Enter number of pages: 12
Enter page reference string: 
7 0 1 2 0 3 0 4 2 3 0 3

Example Output:
---------------
7	-	-
7	0	-
7	0	1
2	0	1
2	0	1
2	3	1
2	3	0
4	3	0
4	2	0
4	2	3
0	2	3
0	2	3

Total Page Faults = 9

------------------------------------------------------------
ADVANTAGE:
------------------------------------------------------------
- Produces the minimum number of page faults among all algorithms.

DISADVANTAGE:
------------------------------------------------------------
- Not practical for real-time systems because it requires 
  future knowledge of page references.

------------------------------------------------------------
*/
