//diafores synatrhseis


#include "server.h"
#include "sockets.h"
#include "threads.h"

/* Synarthsh pou ekteleitai otan anixneuetai ena SIGINT signal
Xrhsimopoieitai gia na termatisei ton server. Patontas to ^C (control C)
o server termatizei, stamata na trexei.*/
void SIGINT_handler(int sig) {
	//edw kleinoume to socket file descriptor sd kai sdaccept
	socket_disconnect();
	//edw apodesmeuoume oles tis struct catalog akai ths struct last_four
	//me ton idio tropo pou tis katanemame sthn synarthsh accounts_initialize()
	for( i = 0; i < MAXACCOUNTS; i++ ) {						
		free(plogariasmos[i]);
		for( j = 0; j < KRATISEIS; j++ ) {
			free(plogariasmos[i]->pkratiseis[j]);
		}
	}
	//vriskoume poia mutexes arxikopoiountai sumfwna me to poioi logariasmoi xrhsimopoiountai
	for( i = 0; i < MAXACCOUNTS; i++) {
		//kai sth synexeia katastrefoume ta mutex tous*/
		if(plogariasmos[i]->acc_id != -1) {
			pthread_mutex_destroy(&mutex_array[i]);
		}
	}
	for( i = 0; i < MAXPARKING; i++) {
		free(pparking[i]);
		for( j = 0; j < MAXRESERVATION; j++ ) {
			free(pparking[i]->pparking_kratiseis[j]);
		}
	}
	for( i = 0; i < MAXPARKING; i++) {
		if(pparking[i]->park_id != -1) {
			pthread_mutex_destroy(&park_mutex_array[i]);
		}
	}
	printf("Server shutting down\n");
	exit(sig);
}

/*Sinartisi pou diaxeirizetai to error pou epistrefei i read*/
void error_read(int error) {	
	//an error einai -1
	if( error == -1 ) {
		//Emfanizei katallhlo mhnyma se periptosh pou entopistei sfalma	
		perror("Error during a read operation");
		//termatizei to thread
		pthread_exit(NULL);
	}
}

/*synarthsh pou diaxeirizetai to error pou epistrefei h write*/
void error_write(int error) {
	//ean h metavlhth error einai -1
	if( error == -1 ) {
		//Emfanizei katallhlo mhnyma se periptosh pou entopistei sfalma	
		perror("Error during a write operation");
		//termatizei to thread
		pthread_exit(NULL);
	}
}

