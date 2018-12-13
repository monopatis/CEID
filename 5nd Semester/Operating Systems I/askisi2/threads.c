/*Synarthseis gia ta threads		*/
#include "threads.h"

/*Synarthsh pou xrhsimopoieitai sto file tou server
initiate the thread to server a client. It takes as	
argument the file descriptor returned by accept to	
serve the client connected.				*/
void choice_thread_create(long sdaccept_thread) {
	//matavlhth gia elegxo lathwn
	int error;
	//metavlhth gia na apothhkeuei to id tou thread pou xzrhsimopoieitai sthn pthread_create
	pthread_t threadid;
	
	error = pthread_create(&threadid, NULL, server_function_choice, (void*)sdaccept_thread );
	if(error) {
		
		perror("Error during creating thread\n");
		exit(1);
		
	}
}


//Synarthsh pou kleidwnei to mutex
void account_mutex_lock(int cur_acc) {
	
	pthread_mutex_lock(&mutex_array[cur_acc]);
}

//Synarthsh pou kleidwnei to mutex
void parking_mutex_lock(int cur_park) {
	
	pthread_mutex_lock(&park_mutex_array[cur_park]);
}

//Synarthsh pou ksekleidwnei to mutex
void account_mutex_unlock(int cur_acc) {
	
	pthread_mutex_unlock(&mutex_array[cur_acc]);
}

void parking_mutex_unlock(int cur_park) {
	
	pthread_mutex_unlock(&park_mutex_array[cur_park]);
}

//Synarthsh pou arxikopoiei to mutex
//xrhsimopoioume to NULL gia na arxikopoieisoume me tis default times
void account_mutex_initialize(int cur_acc) {
	
	pthread_mutex_init(&mutex_array[cur_acc], NULL);
}

void parking_mutex_initialize(int cur_park) {
	
	pthread_mutex_init(&park_mutex_array[cur_park], NULL);
}
