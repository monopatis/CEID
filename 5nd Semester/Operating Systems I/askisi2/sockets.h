
#ifndef SOCKETS_H
#define SOCKETS_H

//Periexei to kurio header mas server.h
#include "server.h"					
//Periexei ta header pou xreiazontai gia thn epikoinonia tou socket
#include <sys/socket.h>	
#include <sys/types.h>				
//Periexei header gia Unix domain sockets (topika (AF_LOCAL) sockets)
#include <sys/un.h>					

//Kathorizetai to onoma pou xrhsimopoieitai gia to socket
#define UNIXSTR_PATH "./ParkingServer.socket"	
//Kathorizetai h oura syndeseon ths synarthshs listen()
#define LISTENQ 20				

/*Edo orizoume tis metavlhtes pou xrhsimopoiountai sta sockets arxeia. 
Oi metavlhtes sdbind kai sdlisten xrhsimopoiountai gia elegxo sfalmaton
kai h sdaccept einai opos eipame o perigrafeas arxeiou tou paidiou.
*/
int sd, sdbind, sdlisten, sdaccept;			

//domh pou that krataei th diethhnsh tou server kai tou client.
struct sockaddr_un clientaddr, serveraddr;	

//domh pou krataei to megethos ths dieuthynshs tou socket.
socklen_t clientaddrlen;			

//Synarthsh pou kalei to socket
void socket_call(void);				
//Synatrhsh pou arxikopoiei to socket
void socket_initialize(void);				
//Synarthsh pou dinei ena onoma to socket
void socket_bind(void);					
//Synarthsh pou akouei to aithma tou client gia syndesh me ton server
void socket_listen(void);				
//Synarthsh pou dexetai mia syndesh sto socket
void socket_accept(void);			
//Autes oi duo synatrhseis kleinoun to sdaccept-paidi kai to sd-pateras
void socket_disconnect(void);		
#endif
