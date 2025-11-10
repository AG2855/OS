#include <pthread.h> 
#include <stdlib.h> 
#include <stdio.h> 
#include <unistd.h> 
pthread_mutex_t x, wsem; 
int readcount; 
void initialize() 
{ 
pthread_mutex_init(&x, NULL); 
pthread_mutex_init(&wsem, NULL); 
readcount = 0; 
} 
void* reader(void* param) 
{ 
int waittime = rand() % 5; 
printf("\nReader is trying to enter"); 
pthread_mutex_lock(&x); 
readcount++; 
if (readcount == 1) 
pthread_mutex_lock(&wsem); 
pthread_mutex_unlock(&x); 
printf("\n%d Reader(s) are inside", readcount); 
sleep(waittime); 
pthread_mutex_lock(&x); 
readcount--; 
if (readcount == 0) 
pthread_mutex_unlock(&wsem); 
pthread_mutex_unlock(&x); 
printf("\nReader is leaving"); 
return NULL; 
} 
void* writer(void* param) 
{ 
    int waittime = rand() % 3; 
    printf("\nWriter is trying to enter"); 
    pthread_mutex_lock(&wsem); 
    printf("\nWriter has entered"); 
    sleep(waittime); 
    pthread_mutex_unlock(&wsem); 
    printf("\nWriter is leaving"); 
    return NULL; 
} 
 
int main() 
{ 
    int n1, n2, i; 
    printf("\nEnter the number of readers: "); 
    scanf("%d", &n1); 
    printf("\nEnter the number of writers: "); 
    scanf("%d", &n2); 
 
    pthread_t rtid[n1], wtid[n2]; 
    initialize(); 
 
    for (i = 0; i < n1; i++) 
        pthread_create(&rtid[i], NULL, reader, NULL); 
 
    for (i = 0; i < n2; i++) 
        pthread_create(&wtid[i], NULL, writer, NULL); 
 
    for (i = 0; i < n1; i++) 
        pthread_join(rtid[i], NULL); 
 
    for (i = 0; i < n2; i++) 
        pthread_join(wtid[i], NULL); 
 
    return 0; 
} 

/*
------------------------------------------------------------
PROGRAM EXPLANATION:
------------------------------------------------------------
This program demonstrates the **Readers–Writers Problem** using 
**POSIX threads (pthreads)** and **mutex locks** in C.

------------------------------------------------------------
ALGORITHM USED:
------------------------------------------------------------
→ The algorithm implemented is the **First Readers–Writers Problem** 
  using **mutex synchronization** (pthread_mutex).

→ It ensures that:
   - Multiple readers can read the shared resource simultaneously.
   - Writers get exclusive access to the resource (only one writer 
     can write at a time, and no readers can read during writing).
   - Prevents data inconsistency due to concurrent access.

------------------------------------------------------------
LOGIC / WORKING OF THE PROGRAM:
------------------------------------------------------------
1. Two mutex locks are used:
   - **x**: Used to ensure mutual exclusion when updating `readcount`.
   - **wsem**: Ensures writers get exclusive access.

2. Variables:
   - `readcount`: Tracks how many readers are currently accessing 
     the shared resource.

3. **Reader Thread Behavior:**
   - Tries to enter (locks `x`), increments `readcount`.
   - If it’s the first reader, it locks `wsem` (blocking writers).
   - Reads the data (simulated using `sleep()`).
   - After reading, decrements `readcount`.
   - If it’s the last reader to leave, unlocks `wsem` (allowing writers).

4. **Writer Thread Behavior:**
   - Tries to enter (locks `wsem`).
   - Performs write operation (simulated using `sleep()`).
   - Unlocks `wsem` after writing (allowing readers/writers).

5. **Thread Creation:**
   - The user specifies the number of readers and writers.
   - Reader and writer threads are created and executed concurrently.

6. **Thread Synchronization:**
   - Mutex locks ensure there’s no race condition between threads.
   - Multiple readers can read together, but writers always get exclusive access.

------------------------------------------------------------
EXAMPLE INPUT / OUTPUT:
------------------------------------------------------------
Example Input:
---------------
Enter the number of readers: 3
Enter the number of writers: 2

Example Output (sample run, actual order may vary due to concurrency):
---------------------------------------------------------------------
Reader is trying to enter
1 Reader(s) are inside
Reader is trying to enter
2 Reader(s) are inside
Writer is trying to enter
Reader is leaving
Reader is leaving
Writer has entered
Writer is leaving
Reader is trying to enter
1 Reader(s) are inside
Writer is trying to enter
Reader is leaving
Writer has entered
Writer is leaving

------------------------------------------------------------
KEY POINTS:
------------------------------------------------------------
- Multiple readers can read concurrently.
- Writers have exclusive access — no reader/writer can enter when a writer is active.
- Synchronization is achieved using **mutex locks**.
- Simulates real-world scenarios like database read/write concurrency control.

------------------------------------------------------------
ADVANTAGE:
------------------------------------------------------------
- Prevents data inconsistency in concurrent environments.
- Allows high concurrency when multiple readers are active.

DISADVANTAGE:
------------------------------------------------------------
- May cause **writer starvation** (writers might wait indefinitely 
  if readers keep coming continuously).

------------------------------------------------------------
*/

