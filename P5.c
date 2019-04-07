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
int allocate_pid(void)                               
{
	int i,j;
    for(i = MIN_PID, j =0; i <= MAX_PID; i++, j++)
    {
        if(pidA[j].bitm == 0)
        {
            pidA[j].p = i;
            pidA[j].bitm = 1;
            return i;
            break;
        }
    }
	
}

void release_pid(int rpid)                            
{
	int i;
    for(i = 0; i <= MAX_PID; i++)
    {
        if(pidA[i].p == rpid)
        {
            pidA[i].bitm = 0;
        }
    }
}


void * Multi_Thread(void * v)                     
{
    int rpid = allocate_pid();       
	while (thnu < sizeoft)
    {
        pthread_mutex_lock(&m);     
        if (thnu >= sizeoft)
        {
            pthread_mutex_unlock(&m);
            break;
        }
        thnu++;                   
        printf("\n\t##   Thread %d    ##   Succesfully Created   ##",thnu);
        pthread_mutex_unlock(&m);     
    }
    release_pid(rpid);          
    
}

