/* Functions for operation on accounts	*/
/* and the server it's self		*/
/* These can be found in account.c	*/
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "server.h"
#include "threads.h"
#include "sockets.h"

//deikths void pou pairnei auto pou epistrefei h malloc otan katanamoume xwro gia ta struct 
void *pshm;					

//arxikopoiei ton pointer plogarismos  mesa sth shared memory
void accounts_initialize(void);
//arxikopoiei ton pointer pparking mesa sth shared memory.
void parking_initialize(void);
//synarthsh pou orizei thn leitourgia analoga me thn epilogh tou idiokthth.
void server_choice_idioktitis(int socket);
//synarthsh pou kanei tis katallhles energeies analoga me thn epilogh tou odhgou.
void server_choice_odigos(int socket);
//pairnei thn epilogh tou client kai kalei tis synarthseis
//server_choice_idioktitis() 'h thn server_choice_odigos antistoixa.
void *server_function_choice(void *sdaccept_thread);
//dhmiourgei to logariasmo tou xrhsth.
void server_account_create(int socket);
//dhmiourgei ena neo parking.
void server_parking_create(int socket);
//katathetei mia posothta xrhmatwn sto logariasmo enos odhgou.
void server_account_deposit(int socket);
//stelnei ston client plhrofories gia enan logarismo odhgou.
void server_account_view(int socket);
//stelnei ston client tis teleutaies 20 krathseis se ena parking.
void server_twenty_last_kratiseis(int socket);
//dhmiourgei mia  nea krathsh.
void server_create_new_reservation(int socket);
//stelnei ston client tis tesseris teleutaies krathseis enos odhgou	
void server_account_last_four_kratiseis(int socket);
//pairnei thn eisodo apo ton client kai anazhta ean yparxei o sygkekrimenos logarismos.
int server_account_search(int socket);
//olisthainei tis krathseis etsi vste na exoume kathe fora tis teleutaies tesseris gia ena odhgo.
void kratiseis_rotate(int cur_acc);
//olisthhsh twn krathsewn se ena parking gia na exoume kathe fora tis teleutaies 20 krathseis.
void parking_kratiseis_rotate(int i);
#endif
