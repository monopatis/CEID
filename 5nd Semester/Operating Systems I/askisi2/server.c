/* Main server file. periexei kuriws synarthseis to swma ton opoion brisketai
se alla files.	*/

#include "server.h"
#include "threads.h"
#include "sockets.h"
#include "logariasmos.h"

int main( void ) {	
    	//typwnoume ena mhnhma kalososrismatos me merikes plirofories sxetika me ti litourgia.
	printf("Welcome to our parking server.\nAt any moment press Ctrl-C to exit the server cleanly.\n");
	//ekteleitai to SIGINT_handler otan SIGINT signal symvainei. 	
	signal(SIGINT, SIGINT_handler);			
	signal(SIGPIPE, SIG_IGN);
					
	//arxikopoiei tous logariasmous sth koinh mnhmh.tekmirionetai sto logariasmos.c.
	accounts_initialize();	
	//arxikopoiei ta nea parking.
	parking_initialize();
	//synarthsh pou kalei ena socket.tekmirionetai sto socket.c kai socket.h
	socket_call();			
	//synarthsh pou arxikopoiei to socket.
	socket_initialize();	
	//synarthsh pou dinei ena onoma sto socket.
	socket_bind();				
	//synarthsh pou akouei tis aithseis tou client gia sundesh me ton server.tekmirionetai 
	//sto socket.c and socket.h
	socket_listen();	
	do {
       		 //synarthsh pou dexetai mia syndesh
		socket_accept();	 
		//function pou dhmiourgei to  thread	 
		choice_thread_create(sdaccept);			
	//loop gia na parei th parent process pisw opou perimenei gia syndeseis.	
	} while( 1 );				
}

