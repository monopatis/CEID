/*Ena header gia threads, pou periexei ta includes kai tis synarthseis*/
#ifndef THREADS_H
#define THREADS_H

#include <pthread.h>
#include "logariasmos.h"
#include "sockets.h"

//synarthsh pou dhmiourgei ena thread
void choice_thread_create(long sdaccept_thread);	
//synarthsh pou arxikopoiei to mutex_array
void account_mutex_initialize(int cur_acc);
void parking_mutex_initialize(int cur_park);	
//kleidwnei to mutex_array
void account_mutex_lock(int cur_acc);
void parking_mutex_lock(int cur_park);			
//ksekleidwnei to mutex_array
void account_mutex_unlock(int cur_acc);	
void parking_mutex_unlock(int cur_park);					
#endif
