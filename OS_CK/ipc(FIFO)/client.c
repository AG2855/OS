#include<stdio.h> 
#include<stdlib.h> 
#include<sys/types.h> 
#include<sys/stat.h> 
#include<unistd.h> 
#include<fcntl.h> 
#include<string.h> 
 
int main() 
{ 
    puts("\n\tClient - Listening\n"); 
    int code6 = mkfifo("fifo6.txt",0666); 
    int code7 = mkfifo("fifo7.txt",0666); 
    char strMessage[5000];     
    if(code6 == -1) 
        perror("\n\tmkfifo6 returned an error-file may already exist\n"); 
    if(code7 == -1) 
        perror("\n\tmkfifo7 returned an error-file may already exist\n"); 
 
    int fd = open("fifo6.txt", O_RDONLY); 
    int fd2 = open("fifo7.txt", O_WRONLY); 
    if(fd == -1) 
    { 
        perror("Cannot open FIFO6 for read"); 
        return EXIT_FAILURE; 
    } 
    if(fd2 == -1) 
    { 
        perror("Cannot open FIFO7 for write"); 
        return EXIT_FAILURE; 
    } 
    puts("FIFO OPEN"); 
 
    char stringBuffer[5000]; 
    memset(stringBuffer, 0, 5000); 
     
    int res; 
    char Len; 
    { 
        res = read(fd, &Len, 1); 
        read(fd, stringBuffer, Len);  
        stringBuffer[(int)Len] = 0; 
        printf("\nClient Received: %s\n", stringBuffer); 
 
        int j = 0, w = 0, line = 0; 
        while(stringBuffer[j] != '\0'){ 
            char ch = stringBuffer[j];         
            if((ch == ' ') || (ch == '\n')){ 
                w++; 
                if(ch == '\n') 
                    line++; 
            } 
} 
j++;             
char LC = (char) strlen(strMessage); 
char str1[256], str2[256], str3[256]; 
sprintf(str1," No.of Words : %d:::", w); strcat(strMessage,str1);  
sprintf(str2," No.of Characters: %d:::", (j-1)); strcat(strMessage,str2); 
sprintf(str3," No.of Lines: %d", line); strcat(strMessage,str3); 
strcat(strMessage,"\0"); 
printf("\n\tString: %s", strMessage); 
write(fd2, &LC, 1); 
write(fd2, strMessage, strlen(strMessage)); 
fflush(stdin); 
strMessage[0] = 0; 
} 
printf("\n"); 
puts("CLIENT CLOSED"); 
puts("SERVER CLOSED"); 
close(fd); 
close(fd2); 
return 0; 

} 

/*
--------------------------------------------------------------------------------
Program: Inter-Process Communication using Named Pipes (FIFOs)
--------------------------------------------------------------------------------
Algorithm Used:
    This program demonstrates **Inter-Process Communication (IPC)** using 
    **Named Pipes (FIFOs)** between a **Client** and a **Server** process.

Concept:
    - FIFOs (First In First Out) are special types of files that allow unrelated 
      processes to communicate with each other using a shared name in the file 
      system.
    - One process writes data to the FIFO (writer), and another process reads 
      from it (reader).
    - This example uses two FIFOs for **bidirectional communication**:
          • fifo6.txt → For Server → Client communication (Server writes, Client reads)
          • fifo7.txt → For Client → Server communication (Client writes, Server reads)

--------------------------------------------------------------------------------
Logic Explanation:

1. **Server Process:**
      - Opens fifo6.txt for writing and fifo7.txt for reading.
      - Prompts the user to enter a message.
      - Sends (writes) the message and its length to the client via fifo6.txt.
      - Waits for a response from the client on fifo7.txt.
      - Reads the response (processed string) and displays it.

2. **Client Process:**
      - Creates the FIFOs if they do not already exist.
      - Opens fifo6.txt for reading and fifo7.txt for writing.
      - Reads the message length and content sent by the server.
      - Processes the received string by:
            → Counting the number of words
            → Counting the number of characters
            → Counting the number of lines
      - Constructs a result string containing these counts.
      - Sends this result string (and its length) back to the server via fifo7.txt.

3. **Communication Flow:**
      Server → sends message → fifo6.txt → Client  
      Client → processes and sends back result → fifo7.txt → Server

4. **Termination:**
      - Entering a blank message (pressing ENTER without input) can terminate
        the communication loop.
      - Both processes then close the FIFOs and exit gracefully.

--------------------------------------------------------------------------------
Example Input/Output:

**Server Side (Input & Output):**
------------------------------------
Server
FIFO OPEN

        Enter the Message to be passed (hitting ENTER without any string will terminate program): 
        Hello ChatGPT
        This is a FIFO test message!

Server Received:  No.of Words : 7::: No.of Characters: 38::: No.of Lines: 2

------------------------------------

**Client Side (Processing):**
------------------------------------
	Client - Listening
	mkfifo6 returned an error-file may already exist
	mkfifo7 returned an error-file may already exist
	FIFO OPEN

	Client Received: Hello ChatGPT
	This is a FIFO test message!

	String:  No.of Words : 7::: No.of Characters: 38::: No.of Lines: 2
------------------------------------

--------------------------------------------------------------------------------
Explanation of Output:
    - The Server sends the message to the Client.
    - The Client counts:
         → Words: Number of space-separated elements
         → Characters: Total characters (excluding null terminator)
         → Lines: Number of newline characters
    - The Client sends this data back to the Server, which displays the result.

--------------------------------------------------------------------------------
Summary:
    - This program showcases **bidirectional IPC** using **two FIFOs**.
    - Demonstrates **synchronization** and **data exchange** between two 
      independent processes.
    - Useful in operating systems and networking for message passing between 
      processes without using sockets.
--------------------------------------------------------------------------------
*/
