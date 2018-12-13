///Header pou xreiazetai o client	

#ifndef CLIENT_H
#define CLIENT_H
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
//Orizetai to onoma pou xreisimopoieitai apo to socket.
#define UNIXSTR_PATH "./ParkingServer.socket"
//synarthsh pou pairnei thn epilogh tou idiokthth kai th stelnei sto server.				
void choice_idioktitis();
//synarthsh pou pairnei thn epilogh tou odigou kai th stelnei sto server.
void choice_odigos();
//synarthsh gia th dhmiourgia neou parking
void client_dimiourgia_parking();
//synarthsh gia tis teleutaies 20 krathseis sto parking					
void client_twenty_last_kratiseis();
//synarthsh gia th dhmiourgia neas krathshs
void client_create_new_reservation();
					
//sd:file perigrafh sxetika me thn 
//synarthsh socket(), sdconnect:file perigrafh sxetika me 
//thn synarthsh  connect(), h metavlhth choice xrisimopoieitai gia 
//na krataei thn epilogh tou client.
//h metavlhth error xrhsimopoieitai gia na ginontai elegxoi gia lathh
int sd,sdconnect,choice,error, len;
unsigned int i,j, arg_c, counter, lathos;
//pinakas gia ta orismata ths main.
char *arg_v[10];
//Struct pou krataei thn dieythinsh tou server
struct sockaddr_un serveraddr;	
//Char table:buf.		
char buf[100];								
//synarthsh poy dhmiourgei socket, kai brisketai sto 
//clientfunctions.c.
void socket_call(void);
//synarthsh pou syndeei socket, kai brisketai sto 
//clientfunctions.c.						
void socket_connect(void);
//synarthsh pou kleinei to socket, kai brisketai sto 
//clientfunctions.c.						
void socket_disconnect(void);
//synarthsh pou arxikopoiei to socket, kai brisketai sto 
//clientfunctions.c						
void socket_initialize(void);	
//synarthsh pou pairnei thn epologi tou client kai elegxei gia 
//eggiri epilogi, h synarthsh  syth brisketai sto clientfunctions.c					
void client_function_choice(void);	
//synarthsh pou dhmioyrgei ena neo logariasmo gia ton client, kai 
//brisketai sto clientfunctions.c				
void client_account_create(void);
//synarthsh pou dhmiourgei ena neo parking.					
void client_parking_create(void);
//synarthsh pou elegxei thn katabolh mias posothtas xrhmatwn toy client, kai brisketai 
//sto clientfunctions.c
void client_account_deposit(void);
//synarthsh pou ektiponei pliroforia gia enan logariasmo enos syggekrimenou client, 
//kai brisketai sto clientfunctions.c		
void client_account_view(void);	
//synarthsh pou plirofogorei ton client gia tis teleutaies 4 
//kratiseis, kai brisketai sto clientfunctions.c
void client_account_last_four_kratiseis(void);				
//synarthsh pou kanei asfales read, kai brisketai sto 
//clientfunctions.c					
void safe_read(void);
//synarthsh pou kanei asfales write, kai brisketia sto 
//clientfunctions.c					
void safe_write(void);
//synarthsh pou xrhsimopoieitai gia asfalh eisodo apo to plhktrologio.							
void input(void);
#endif
