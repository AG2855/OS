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