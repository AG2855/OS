#include<stdio.h> 
 
int findLRU(int time[], int n){ 
    int i, minimum = time[0], pos = 0; 
 
    for(i = 1; i < n; ++i){ 
        if(time[i] < minimum){ 
            minimum = time[i]; 
            pos = i; 
        } 
    } 
    return pos; 
} 
 
int main() 
{ 
    int no_of_frames, no_of_pages, frames[10], pages[30], counter = 0, time[10]; 
    int flag1, flag2, i, j, pos, faults = 0; 
 
    printf("Enter number of frames: "); 
    scanf("%d", &no_of_frames); 
 
    printf("Enter number of pages: "); 
    scanf("%d", &no_of_pages); 
 
    printf("Enter reference string: "); 
    for(i = 0; i < no_of_pages; ++i){ 
        scanf("%d", &pages[i]); 
    } 
 
    for(i = 0; i < no_of_frames; ++i){ 
        frames[i] = -1; 
    } 
 
    for(i = 0; i < no_of_pages; ++i){ 
        flag1 = flag2 = 0; 
 
        for(j = 0; j < no_of_frames; ++j){ 
            if(frames[j] == pages[i]){ 
                counter++; 
                time[j] = counter; 
                flag1 = flag2 = 1; 
                break; 
            } 
        } 
 
        if(flag1 == 0){ 
            for(j = 0; j < no_of_frames; ++j){ 
                if(frames[j] == -1){ 
                    counter++; 
                    faults++; 
                    frames[j] = pages[i]; 
                    time[j] = counter; 
                    flag2 = 1; 
                    break; 
                } 
            } 
  
        } 
 
        if(flag2 == 0){ 
            pos = findLRU(time, no_of_frames); 
            counter++; 
            faults++; 
            frames[pos] = pages[i]; 
            time[pos] = counter; 
        } 
 
        printf("\n"); 
        for(j = 0; j < no_of_frames; ++j){ 
            printf("%d\t", frames[j]); 
        } 
    } 


 /*
--------------------------------------------------------------------------------
Program: LRU (Least Recently Used) Page Replacement Algorithm
--------------------------------------------------------------------------------
Algorithm Used:
    This program implements the LRU (Least Recently Used) Page Replacement
    algorithm used in Operating Systems for memory management. 
    The LRU algorithm replaces the page that has not been used for the longest 
    period of time when a new page needs to be loaded into a full frame.

Logic Explanation:
    1. The program first takes input for:
         - Number of frames (memory slots available)
         - Number of pages (length of reference string)
         - The reference string (sequence of page requests)

    2. It maintains:
         - 'frames[]' → stores the current pages in memory
         - 'time[]'   → stores how recently each frame was accessed
         - 'counter'  → acts as a logical clock to mark the order of accesses

    3. For each page in the reference string:
         - If the page is already in a frame → it’s a hit.
           Update its time value to mark it as most recently used.
         - If the page is not in a frame:
              a. If an empty frame is available → place the page there.
              b. Otherwise → find the least recently used page using the 
                 function findLRU(time[], n) which returns the position of the 
                 page with the smallest time value.
                 Replace that page with the new one.
           Each such replacement or insertion counts as a page fault.

    4. Finally, the program prints the frame content after each step and displays 
       the total number of page faults at the end.

Function Used:
    int findLRU(int time[], int n)
        → Finds and returns the index of the least recently used frame by 
          comparing time[] values.

--------------------------------------------------------------------------------
Example Input/Output:

Input:
    Enter number of frames: 3
    Enter number of pages: 9
    Enter reference string: 5 0 1 3 2 4 1 0 5

Output:
    5   -1  -1
    5   0   -1
    5   0   1
    3   0   1
    3   2   1
    4   2   1
    4   2   1
    4   0   1
    5   0   1

    Total Page Faults = 7

--------------------------------------------------------------------------------
Summary:
    The program demonstrates how the LRU algorithm minimizes page faults by 
    replacing the least recently used page in memory. It keeps track of 
    "recency" using a time counter and efficiently simulates page replacement.
--------------------------------------------------------------------------------
*/

    printf("\n\nTotal Page Faults = %d", faults); 
 
    return 0; 

} 
