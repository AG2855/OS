#include<stdio.h>  
 
int main() 
{ 
    int incomingStream[] = {4, 1, 2, 4, 5}; 
    int pageFaults = 0; 
    int frames = 3; 
    int m, n, s, pages; 
 
    pages = sizeof(incomingStream)/sizeof(incomingStream[0]); 
 
    printf("Incoming \t Frame 1 \t Frame 2 \t Frame 3"); 
    int temp[frames]; 
    for(m = 0; m < frames; m++) 
    { 
        temp[m] = -1; 
    } 
 
    for(m = 0; m < pages; m++) 
    { 
        s = 0; 
 
        for(n = 0; n < frames; n++) 
        { 
            if(incomingStream[m] == temp[n]) 
            { 
                s++; 
                pageFaults--; 
            } 
        } 
        pageFaults++; 
         
        if((pageFaults <= frames) && (s == 0)) 
        { 
            temp[m] = incomingStream[m]; 
        } 
        else if(s == 0) 
        { 
            temp[(pageFaults - 1) % frames] = incomingStream[m]; 
        } 
       
        printf("\n"); 
        printf("%d\t\t\t", incomingStream[m]); 
        for(n = 0; n < frames; n++) 
        { 
            if(temp[n] != -1) 
                printf(" %d\t\t\t", temp[n]); 
            else 
                printf(" - \t\t\t"); 
        } 
    } 
 
    printf("\nTotal Page Faults:\t%d\n", pageFaults); 
    return 0; 

} 

/*
------------------------------------------------------------
📘 PROGRAM: FIFO Page Replacement Algorithm in C
------------------------------------------------------------

🔹 PURPOSE:
This program simulates the **FIFO (First-In First-Out) Page Replacement Algorithm**, 
which is one of the simplest page replacement techniques used in Operating Systems 
to manage memory pages.

------------------------------------------------------------
⚙️ ALGORITHM USED: FIFO (First-In First-Out)

🔸 Concept:
- Pages are loaded into frames in the order they arrive.
- When a page fault occurs and memory is full, the page that entered **first** (oldest)
  is replaced with the new incoming page.
- It works just like a queue (first page in → first page out).

------------------------------------------------------------
🧩 LOGIC / WORKING OF THE CODE:

1️⃣ **Initialization**
   - `incomingStream[]`: The sequence of page requests (reference string).
   - `frames`: Total number of memory frames (slots available in memory).
   - `temp[]`: An array used to store currently loaded pages in frames.
   - Initialize all frame slots with `-1` (indicating empty).

2️⃣ **Processing Each Page Request**
   - For each page in the incoming stream:
     - Check if the page is already present in frames.
       - If yes → **Page Hit** (no page fault).
       - If no → **Page Fault** occurs.
     - When a page fault occurs:
       - If there’s still space in frames → insert the page into the next empty frame.
       - If frames are full → replace the oldest page (using `(pageFaults - 1) % frames`).

3️⃣ **Display**
   - After each page request, the program prints the current state of all frames.
   - At the end, total number of page faults is displayed.

------------------------------------------------------------
🧮 EXAMPLE EXECUTION:

Example Input (Already defined in code):
----------------------------------------
Incoming Pages: {4, 1, 2, 4, 5}
Number of Frames: 3

Step-by-step Output:
----------------------------------------
Incoming     Frame 1     Frame 2     Frame 3
4            4           -           -
1            4           1           -
2            4           1           2
4            4           1           2   (No page fault - already present)
5            5           1           2   (Replaces oldest: 4 → 5)

Total Page Faults: 4

------------------------------------------------------------
🧾 OUTPUT EXPLANATION:

✅ Page Faults occur for: 4, 1, 2, 5  
❌ No Page Fault for: 4 (already in frame)

Hence, total page faults = 4

------------------------------------------------------------
📊 SUMMARY:
- Algorithm Used: FIFO (First-In First-Out)
- Type: Page Replacement Algorithm
- Advantages: Simple to implement
- Disadvantages: May not provide optimal performance
------------------------------------------------------------
*/
