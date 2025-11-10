#include <stdio.h> 
#include <stdlib.h> 
 
int mutex = 1; 
int full = 0; 
int empty = 10; 
int x = 0; 
 
void producer() 
{ 
    --mutex; 
    ++full; 
    --empty; 
    x++; 
    printf("\nProducer produces item %d", x); 
    ++mutex; 
} 
 
void consumer() 
{ 
    --mutex; 
    --full; 
    ++empty; 
    printf("\nConsumer consumes item %d", x); 
    x--; 
    ++mutex; 
} 
 
int main() 
{ 
    int n, i; 
 
    printf("\n1. Press 1 for Producer"); 
    printf("\n2. Press 2 for Consumer"); 
    printf("\n3. Press 3 for Exit\n"); 
 
    for (i = 1; i > 0; i++) 
    { 
        printf("\nEnter your choice: "); 
        scanf("%d", &n); 
 
        switch (n) 
        { 
            case 1: 
                if ((mutex == 1) && (empty != 0)) 
                { 
                    producer(); 
                } 
                else 
                { 
                    printf("Buffer is full!"); 
                } 
                break; 
 
            case 2: 
                if ((mutex == 1) && (full != 0)) 
                { 
                    consumer(); 
                } 
                else 
                { 
                    printf("Buffer is empty!"); 
                } 
                break; 
 
            case 3: 
                exit(0); 
 
            default: 
                printf("Invalid choice!"); 
                break; 
        } 
    } 
 
    return 0; 

} 

/*
--------------------------------------------------------------------------------
Program: Producer-Consumer Problem (Using Semaphores)
--------------------------------------------------------------------------------
Algorithm Used:
    This program demonstrates the classic **Producer-Consumer Problem** 
    using **semaphore variables** (mutex, full, and empty) to achieve 
    process synchronization.

Concept:
    - The Producer and Consumer share a common buffer of fixed size.
    - The Producer adds (produces) items into the buffer.
    - The Consumer removes (consumes) items from the buffer.
    - Synchronization ensures that:
        1. Producer cannot add items if the buffer is full.
        2. Consumer cannot remove items if the buffer is empty.
        3. Only one process accesses the buffer at a time (mutual exclusion).

--------------------------------------------------------------------------------
Variables Used:
    mutex → Acts as a binary semaphore to maintain mutual exclusion 
             (ensures only one process accesses the buffer at a time).

    full  → Counts how many slots in the buffer are currently filled.

    empty → Counts how many slots in the buffer are empty.

    x     → Acts as the item counter (number of items produced so far).

--------------------------------------------------------------------------------
Logic Explanation:
    1. Initially:
           mutex = 1   (buffer is free)
           full  = 0   (no filled slots)
           empty = 10  (buffer of size 10)
           x = 0       (no items produced yet)

    2. The user selects an operation:
           1 → Producer
           2 → Consumer
           3 → Exit

    3. For Producer:
           - Check if (mutex == 1) and (empty != 0)
             → If true: produce item, increment full, decrement empty.
             → Else: print "Buffer is full!"

    4. For Consumer:
           - Check if (mutex == 1) and (full != 0)
             → If true: consume item, decrement full, increment empty.
             → Else: print "Buffer is empty!"

    5. The program continues to run until user selects Exit (3).

--------------------------------------------------------------------------------
Example Input/Output:

Initial values:
    mutex = 1, full = 0, empty = 10, x = 0

Sample Run:

1. Press 1 for Producer
2. Press 2 for Consumer
3. Press 3 for Exit

Enter your choice: 1
Producer produces item 1

Enter your choice: 1
Producer produces item 2

Enter your choice: 2
Consumer consumes item 2

Enter your choice: 2
Consumer consumes item 1

Enter your choice: 2
Buffer is empty!

Enter your choice: 3
(Program exits)

--------------------------------------------------------------------------------
Summary:
    - This program simulates producer-consumer synchronization using 
      semaphore-based logic.
    - It ensures proper coordination between producer and consumer 
      processes without using actual threading.
    - It demonstrates key Operating System concepts:
         * Mutual Exclusion
         * Process Synchronization
         * Critical Section Control
--------------------------------------------------------------------------------
*/
