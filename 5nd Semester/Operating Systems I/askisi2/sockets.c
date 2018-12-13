//perilamvanei to header file sockets.h
#include "sockets.h"

/* synarthsh pou dhmiourgei to socket.epishs emeis exoume*/
/* ena error control pou dixnei enan h synarthsh epetyxe */
/*na dhmiourghsei to socket.			*/
void socket_call(void) {
		//dhmiourgei ena unbound socket se ena tomea epikoinonias.
		//kai epistrefei ena file discriptor sto sd.
		//AF_LOCAL proteinei topiko tomea epikoinonias
		//SOCK_STREAM proteinei to socket parexei allhloyxia 
		//axioppistia.auto to orisma einai mhden etsi to default 
		//protocol gia ayth thn oikogeneia prokeitai na xrhsimopoihthei.
	sd = socket( AF_LOCAL, SOCK_STREAM, 0 );				
	//sd einai to file descriptor tou socket
	//kata thn erituxh oloklhrosh sd tha einai enas mh arnhtikos akeraios.
	//ean prokuyei kapoio lathos auto tha einai -1.
	if(sd == -1) {									
										
		perror("Error in creation of socket\n");
        //exodos ths process				
		exit(1);								
	}
}

/* synarthsh pou arxikolpoiei to socket.sto prwto bhma
 mhdenizoume ola ta pedia tou server address.	
 meta orizoume oti socket type einai topiko	
 teleika orizoume to onoma tou socket.*/
void socket_initialize(void) {
//afairoume opoiodhpote prohgoumeno socket me to idio filename
	unlink( UNIXSTR_PATH );								
	//mhdenizoume olata pedia tou serveraddr.
	memset( &serveraddr, 0, sizeof( serveraddr ) );
	//thetei ton tupo tou soocket  local.
	serveraddr.sun_family = AF_LOCAL;
	//orizei to onoma tou socket.
	strcpy( serveraddr.sun_path, UNIXSTR_PATH );					
}

/* synarthsh pou binds an unbound socket dhmiourghthhke
 prohgoumenos me socket().	*/
void socket_bind(void) {
	//ekxwrei ena local socket address &serveraddr sto
	//socket pou prosdiorizetai apo to  sd.		
	sdbind = bind( sd ,(const struct sockaddr_un *) &serveraddr, sizeof(serveraddr) );	
	//sdbind xrhsimopoieitai gia errors kata th diarkeia ths leitourgias.
    //kata thn epityxh oloklhrwsh to sdbind tha einai 0.
    //ean symvei kapoio lathos epistrefetai to -1.							  		
	if(sdbind == -1) {								
	          perror("Error during binding socket name\n");	
         		//exodos ths process	
	          	exit(1);								
	}
}

//synarthsh pou elegxei to socket gia eiserxomenes syndeseis.
void socket_listen(void) {
     /*Markarei to socket sd kathos dexetai syndeseis.
     LISTENQ orizetai sto sockets.h kai einai h oura gia eiserxomenes  syndeseis*/
	sdlisten = listen(sd,LISTENQ);							 
	//sdlisten xrhsimopoieitai kata th diarkeia ths leitourgias.kata thn epityxh
    // oloklhrwsh sdlisten tha einai 0.ean ena lathos symvei epistrefetai -1			  
	if(sdlisten == -1) {								
											
		perror("Cannot listen to incoming requests\n");	
        //exodos apo th process		
		exit(1);							
	}
}

// synarthsh pou dexetai eiserxomenes syndeseis	
// listed sthn oura.				
void socket_accept(void) {
    //thetei to megethos tou clientaddr sto clientaddrlen gia metepeita xrhsh.
	clientaddrlen = sizeof( clientaddr );						
	//Exagei thn prwth syndesh sthn oura anamonhs
	//syndeseis dhmioyrgoun ena neo socket me to idio socket type protocol
	//kai th dieuthinsh ths oikogenias opws to sd
	//kai desmeuei sdaccept file descriptor gia auto to socket.
	sdaccept = accept( sd , (struct sockaddr_un *) &clientaddr, &clientaddrlen );
	//sdaccept einai to file descriptor tou socket.kata
	//kata thn epityxh oloklhrwsh to sdbind tha einai 0.
	//ean symvei kapoio lathos epistrefetai to -1.	
	if(sdaccept == -1) {
		perror("Error during accepting a connection\n");
		//exodos ths process		
		exit(1);							
	}
}

/*synarthsh pou kleinei to socket 
 ayto einai edo mono gia armonia.*/
void socket_disconnect(void) {
	int error;
	//apodesmeuei to file descriptor pou upodiknietai apo to sdaccept
	error = close( sdaccept );							
	//h error pairnei thn epistrefomenh timh apo thn close() gia error checking
	//kata thn epityxh oloklhrwsh to sdbind tha einai 0.
    	//ean symvei kapoio lathos epistrefetai to -1.	
	if (error == -1) {
		printf("Error during disconnecting child's socket\n");
		exit(1);
	}
	error = close( sd );	
	if (error == -1) {
		printf("Error during disconnecting parents's socket\n");
		exit(1);
	}
}

