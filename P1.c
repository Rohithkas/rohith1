#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define MIN_PID 100
#define MAX_PID 1000
int sizeoft;
int thnu = 0;
pthread_mutex_t m;
struct pid_t
{
    int p;
    float bitm;
}pidA[1000];

int allomap(void)                               
{
    int i,j;
    for(i = MIN_PID, j =0; i <= MAX_PID; i++, j++)
    {
        pidA[j].p = i;
        pidA[j].bitm = 0;
    }

    if(i == MAX_PID && j == MAX_PID)
    {
    return 1;
	}
    else
    {
	return -1;
	}
}
