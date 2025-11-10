#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>

#define SHMSZ 27

int main() {
    int shmid;
    key_t key;
    char *shm, *s;

    key = 5678;

    if ((shmid = shmget(key, SHMSZ, 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    for (s = shm; *s != '\0'; s++) {
        putchar(*s);
    }
    putchar('\n');

    *shm = '*';

    return 0;
}


/*
--------------------------------------------------------------------------------
Program Title: Inter-Process Communication (IPC) using Shared Memory (Reader & Writer)
--------------------------------------------------------------------------------
Algorithm/Concept Used:
- This program demonstrates communication between two processes using 
  **System V Shared Memory (shmget, shmat, shmctl)** in Linux.
- Shared memory allows multiple processes to access the same section of memory, 
  enabling fast and efficient data exchange.

--------------------------------------------------------------------------------
Logic Explanation:
1. **Writer Process (Second Program):**
   - Creates a shared memory segment using `shmget()` with `IPC_CREAT | 0666`.
   - Attaches the segment to its address space using `shmat()`.
   - Writes lowercase alphabets ('a' to 'z') into the shared memory.
   - Adds a null character `'\0'` to indicate the end of the string.
   - Waits in a loop until the first character of shared memory becomes '*', 
     which signals that the reader has finished reading.

2. **Reader Process (First Program):**
   - Connects to the same shared memory segment using the same key (`5678`).
   - Attaches the shared memory to its own address space using `shmat()`.
   - Reads the data written by the writer process and prints it on the screen.
   - Writes '*' in the shared memory to notify the writer that the data 
     has been successfully read.

--------------------------------------------------------------------------------
Algorithm Steps:
1. Generate a unique key using `key = 5678`.
2. Writer process creates the shared memory segment.
3. Writer writes data (a–z) into shared memory.
4. Reader attaches to the same segment using the same key.
5. Reader reads and displays the shared memory content.
6. Reader writes '*' as a signal to the writer.
7. Writer detects the '*' and terminates.

--------------------------------------------------------------------------------
Execution Procedure:
1. **Compile both programs:**
```

gcc writer.c -o writer
gcc reader.c -o reader

```
2. **Run the writer first:**
```

./writer

```
(It will wait for the reader to read the data.)
3. **Open a new terminal and run the reader:**
```

./reader

```
(It will print the data and signal the writer to terminate.)

--------------------------------------------------------------------------------
Example Input/Output:

Writer Terminal:
```

$ ./writer
(waiting...)

```

Reader Terminal:
```

$ ./reader
abcdefghijklmnopqrstuvwxyz

```

After reading, the reader writes '*' to shared memory, and the writer terminates.

--------------------------------------------------------------------------------
Key Functions Used:
- `shmget(key, size, flag)` → Creates or accesses shared memory.
- `shmat(shmid, NULL, 0)` → Attaches the shared memory to process address space.
- `shmdt(ptr)` → Detaches the shared memory (optional, not used here).
- `IPC_CREAT | 0666` → Permissions and creation flag for shared memory.

--------------------------------------------------------------------------------
Advantages:
- Fastest method of IPC since it directly uses memory space.
- Ideal for large-volume data transfer between processes.

Disadvantages:
- Requires synchronization to prevent race conditions (handled here by a simple '*').

--------------------------------------------------------------------------------
End of Program
--------------------------------------------------------------------------------
*/
```
