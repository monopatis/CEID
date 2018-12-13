/* Global header.periexei ta panta
 oxi amesa sysxetizomena me to shm
'h  sockets.epishs periexei 		
dhlwseis synarthsewn pou vriskontai sto
logariasmo.c and sto diafora.c	*/

#ifndef SERVER_H
#define SERVER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
//Include gia na xeroume tin ora tou sistimatos				
#include <time.h>					
//Include gia signals
#include <signal.h>					
//megistos arithmos apo logariasmous odhgwn.
#define MAXACCOUNTS 30
//megistos aritmos gia dhmiourgia parking.
#define MAXPARKING  10					
//orizei KRATISEIS iso me 4, gia thn provolh twn tessarwn teleutaiwn kratisewn enos odhgou.
#define KRATISEIS 4
//gia thn probolh twn eikosi teleutaiwn krathsewn se ena parking.
#define MAXRESERVATION 20				

//Struct pou periexei tis 20 teleutaies krathseis
struct last_twenty {					
     //Char table pou krata th perigrafh  mias  krathshs se ena parking.  
	char description[100];				
};
//Struct pou periexei tis 4 teleutaies krathseis.	
struct last_four {	
     //Char table pou krata th perigrafh mias krathshs enos odhgou.  				
	char description[70];				
};
//struct pou periexei dedomena gia tis krathseis pou ginontai.
struct reservation{
     //int table pou krata to id mias krathshs.  
	int reserv_id[10];
	//int table pou diathrei to plithos twn thesewn.
	int plithos_thesewn_reservation[10];
	
}*preservation[MAXRESERVATION];

//Struct pou krataei ta dedomena enos logariasmou.
struct logariasmos {
	//char table gia to onoma tou odhgou.20 characters max.
	char name[20];                       
	//char table gia to epitheto tou odhgou.        
	char surname[20];
	//akeraios pou periexei to id tou enos logariasmou.
	int acc_id;	
	//float metavlhth pou diathrei to ypoloipo pou exei enas odhgos sto logariasmo tou.			
	float ypoloipo;				
	//pointer typou struct last_four.diathrei tis krathseis.
	struct last_four *pkratiseis[KRATISEIS];	
} *plogariasmos[MAXACCOUNTS];  //pointer sth struct logariasmos.				

//struct pou krata dedomena gia th dhlwsh enos neou parking.
struct parking{
	//char table pou diathrei to onoma tou parking.
	char name[15];
	//int kai diathrei to id kathe neou parking pou dhmiourgeitai.
	int park_id;
	//char table pou krata th perigrafh tou parking.
	char perigrafh[80];
	//float metavlhth pou krata th timh pou kostizei h kathe thesh parking.
	float timh;
	//int table pou periexei tis thesis tou parking.
	int thesi[10];
	//pointer tupou struct last_twenty.
	struct last_twenty *pparking_kratiseis[20];
}*pparking[MAXPARKING];   //pointer sth struct parking.
//
pthread_mutex_t mutex_array[MAXACCOUNTS];
pthread_mutex_t park_mutex_array[MAXPARKING];
//integer metavlhtes pou vohthane stis diafores leitourgies.
//oi j,i,k,l einai syxna xrhsimopoioumenes metavlhtes,
//enw h error xrhsimopoieietai gia diaforous elegxous.
int i,j;	

//function pou xeirizetai thn exodo ths diergasias
void SIGINT_handler(int sig);				
/*
aytes oi duo synarthseis xrhsimopoiountai 
anti gia tis aples read kai write
*/
void error_read(int error);					
void error_write(int error);
#endif
