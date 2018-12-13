/*Synarthseis tou client				*/

#include "client.h"


/* Synarthsh pou dhmioyrgei to socket.Episis exoume ena error control pou
 deixnei oti h synarthsh apetyxe na dhmiourfisei to socket*/

/*Synarthsh poy pairnei thn epilogi toy client.		*/
/*An h epilogi den einai eggirh tote h synarthsh ektyponei	*/
/*to mhnuma "Invalid choice." kai o client termatizei	*/
/*alliws o client create,initialize and 	*/
/*connect the socket so,he can connect to the 	*/
/*server.se auth th periptosh h epilogh mas pernaei sto 	*/
/*proper case kai ekteleitai h synarthsh pou akolouthei.
oi synarthseiw aytes perigrafontsai parakatw.	*/
/*						*/

void client_function_choice(void) {
	//se auto to shmeio kanoume elegxo gia to an 8a xrhsimopoihsoume orismata
	//gia na treksoume ton cliient mas 'h xeirokinhta apo thn grammh entolon     
	if (arg_c>1){
		strcpy(buf,arg_v[1]);
	}
	else {	
	//synarthsh pou ftiaksame gia asfalh eisido apo to plhktrologio
	//To soma ths synarthshs vrisketai parakato         
		input();
		
	}
	//meso ths atoi() metatrepoume ton buf pou einai typou char se
	//akeraio integer kai to apothhkeuoume sthn choice
	choice = atoi( buf );
	//An o client pathsei 1 'h 2 tote mpainoume sto if kai kalountai 
	//oi synarthseis, alliws o client termatizei.
	if( choice > 0 && choice < 3 )  {				
		//synarthsi poy dhmioyrgei socket.
		socket_call();						
		//synarthsh poy arxikopoiei ta socket.
		socket_initialize();				  	
		socket_connect();
		//Stelnoyme thn epilogi tou client ston server.
		safe_write();						
		//An to read einai asfales,o client dexetai ena 
		//mhnuma apo ton server.(To soma ths 
		//synarthshs safe_read brisketai patakato)
		//o client diavazei to periexomeno ths choice pou tou stelnei oserver
		safe_read();	
		switch( choice ) {
			//1h periptosi.An o pelatis einai idioktitis.
			case 1 :					
				choice_idioktitis();		
				break;
			case 2 :
			//2h periptosi.An o pekatis einai odigos.
				choice_odigos();			
				break;
		}
	}
	//An epilogh choice den einai eggirh
	else {								
		//O client ektuponei to mhnuma "Invalid choice" kai termatizei.
		printf("Invalid choice.\n");				
	}
}
/*
H synarthsh ayth pairnei thn epilogh tou client 
kai sygkekrimena tou idiokthth,emfanizei to menu tou idiokthth
kai analoga me thn epilogh tou kalei tis antistoixes sunarthseis
*/
void choice_idioktitis(){
	if (arg_c>2){
		strcpy(buf,arg_v[2]);
	}	
	else {		
		printf("Menu idioktiti:\n");						
		printf(" 1.Dilosi neou parking \n");
		printf(" 2.Provoli 20 teleutaion kratiseon sto parking \n");
		//O client ektuponei:Enter your choice.
		printf("Enter your choice: ");					
		//h synarthsh input pairnei thn epilogh tou idioktith
		input();
	}
	choice = atoi( buf );
	//ean h epilogh einai 1 h 2
	if( choice > 0 && choice < 3 )  {					
		//me th safe_write() stelnoume sto server thn epilogh tou client
		safe_write();							
		//o client diavazei auto pou tou epistrefei o client					
		safe_read();
		//analoga me thn epilogh pou exei kanei o 
		//idiokthths kalountai oi antistoixes synarthseis 
		switch( choice ) {									
			case 1 :
				//dhlosh neou parking                 
				client_parking_create();
				break;
			case 2 :
				//provolh teleutaion 20 krathseon                 
				client_twenty_last_kratiseis();
				break;
		}
	}
	//ean den exei kanei thn katallhlh epilogh tote 
	//emfanizetai to mhnyma "Invalid choice"
	else {	
		printf("Invalid choice.\n");
	}
}

/*
h synarthsh ayth dhmiourgei nea parking gia ton idiokthth 
*/
void client_parking_create(void) {
	//O client diavazei to periexomeno tou bug pou tou esteile o server	
	safe_read();								
	//Syggrinei to periexomeno tou buf pou tou esteile o server me to 
	// mhnyma "There are no remaining slots".An ta duo mhnymata einai idia auto shmainei  
	//oti den uparxei xoros kai ara den mporoume na dhmiourghsoume neo parking. 
	if( strcmp( buf , "There are no remaining slots") == 0 ) {
		//O client ektyponeo to periexomeno tou buf pou se auth thn periptosh einai
		//There are no remainig slots		
		puts( buf );
  	 	//Kleinei to socket
		socket_disconnect();							
		//termatizei o client
		exit(1);							
	}
	//o client ektuponei "Found free slot for new parking"
	//pou shmainei oti brethike diathesimos xoros giadhmiourgia neou parking.    
	puts( buf );								
	//O client lamvanei ena apo ton server me ti ID tou parking pou 
	//dhmiourghse.
	safe_read();	
	//o client ektuponei to mhnuma tou server : 
	//"Created new parking with id: X" , opou X 
   	//einai to ID tou parking poy dhmiourgithike.                                     
  	puts( buf );								
	//edo arxikopoioume mia metavlhth lathos sto 0, etsi oste otan o client 
   	//dosei mh eggiro onoma gia to parking na tou zhthtai na ksanaeisagei ena 
   	//eggiro auth th fora onoma parking
	lathos=0;
	//kanoume thn epanalhpsh do-while gia na 
	//eleksoume an to onoma tou parking einai eggiro
	//Apaitoume to onoma tou parking na einai MONO 
	//EGGIROI XARAKTHRES.
	do{									
		if (arg_c>3 && lathos==0){
			//antigrafoume ston buf to periexomeno tou 4ou orismatos
			//mono otan h lathos einai = 0                  
			strcpy(buf,arg_v[3]);
			puts(buf);
		}
		else {
			//allios, o client ektuponei: "Dose onoma parking"
			printf("Dose onoma parking: ");
			//O client plhktologei to onoma tou parikng pou thelei na dhmiourghsei
			input();								
		}
		//An o client pathsei ENTER xoris na eisagei to 
		//onoma tou parking ,tote strlen(buf) = 0
		//(NULL) tote o client prepei na dosei ena eggiro onoma gia to 
		//parking.
		if((strlen(buf) > 0) && (strlen(buf) <= 15 ) ) {			
			//Atoi(buf).An o buf periexei xarakthres,prepei 
			//na eleksoume an einai eggiroi.Den 
			//theloume na exoume arithmous metaksi ton 
			//xarakthron,kena,tabs,h na ksekiname me arithmo.
                	if(!atoi(buf)) { 
				//Thetoume to j = 0;
				j = 0;							
				//kanoume ena for loop gia na elexoume enan enan 
				//tous xarakthres pou briskontai ston buf
				for( i = 0; i < strlen(buf); i++) {			
					//h isalpha epistrefei mh mhdenikous arithmous
					//gia grammata ths alfavhtou. Se 
					//opoiadhpote allh periptosh ektuponei mhden.
					if( isalpha(buf[i]) != 0 ) {				
						//An kathe periexomeno tou buf einai aritmous apo 
						//0-9 h tab h keno tote we ayksanoume 
						//thn timh tou j.
						j++;					
						//Otan ftasoume sto telos tou buf feugoume apo thn apanalhpsh 
					} 							
					//kai meta,	
				}							
				//elegxoume an to megethos tou buf is idio me to j
				//( poses fores emfanizontai noumera,tabs, kena). 
				if( strlen(buf) == j ) break;			
				//An einai idia tote feudoume apo thn epanalhpsi 
				//do-while,pou shmainei oti ta 
				//periexomena tou buf einai sosta. 
			} 									
		}	//An o client pathsei ENTER dhladh NULL h eisagei 
		//mh eggirouw xarakthres tote o client 
		//ektuponei to mhnuma: "Invalid onoma"
 		//kai tou ksanazhthtai na ksanaeisagei to onoma tou parking.
 		printf("Invalid onoma\n");						
		//Epishs thetoume thn metavlhth lathos ish me 1, etsi oste otan xsanampei
		//sthn epanalhpsh do-while, na tou zhth8ei na dozei ena eggiro onoma
		//parking. Syggekrimena ston client emfanizetai to mhnyma 'Dose onoma
		//parking'. 
		lathos=1;									
	} while( 1 );
	//o client stelnei to onoma tou parking ston server 
	safe_write();									
	//o client diavazei to mhnyma pou tou stelnei o server
	safe_read();
	//elegxos an to mhnyma pou esteile o server einai "uparxon parking",
	//diladi an uparxei idi parking me to idio onoma
	if( strcmp( buf , "uparxon parking") == 0 ) {
		//o client ektuponei to mhnuma: "uparxon parking" 
		puts( buf );								
		//Kleinei to socket									
		socket_disconnect();	
		//termatizei o client						
		exit(1);								
	}
	//Thetoume ksana thn metavlhth lathos = 0
    	lathos=0;
	//h epanalhpsh do-while gia na eleksoume an h 
	//perigrafh einai eggirh.
	do{									
		if (arg_c>4 && lathos==0){
		//antigrafoume ston buf to periexomeno tou 5ou orismatos
		//mono otan h lathos einai = 0           
			strcpy(buf,arg_v[4]);
		}
		else {
	         	//o client ektuponei:"Dose perigarafi parking".
			printf("Dose perigrafi parking: ");					 
			//h perigrafh pou eisagete apo to pliktrologio apothhkeuetai ston buf.
			input();								
		}
		//an o client dosei eggirh perigrafh, dhladh to mhkos tou buf einai
		//>0 kai <80 opos dhladh exoume kanei kai thn arxikopoihsh gia ton 
		//buf tote feugoume apo thn do kai h perigrafh mas einai eggirh
		if((strlen(buf) > 0) && (strlen(buf) <= 80 ) ) {			
			 break;
		}
		// ean o client pathsei enter xwris na dosei thn 
		//perigrafh ,tote  strlen(buf) = 0(NULL) 
		//kai emfanizetai to parakato mhnyma: 'Invalid perigrafi'. 
	   	printf("Invalid perigrafi\n");							
		//Epishs thetoume thn metavlhth lathos ish me 1, etsi oste otan xsanampei
		//sthn epanalhpsh do-while, na tou zhth8ei na ksanadozei perigrafh
		//parking. Syggekrimena ston client emganizetai to mhnyma 'Dose perigrafh
		//parking'. 
		lathos=1;								
	} while( 1 );
 	//o client stelnei to periexomeno tou buf, dhladh thn perigrafh tou parking
	//ston server
	safe_write();
	//o client diavazei to mhnyma pou tou stelnei o server meso tou buf
	safe_read();	
	//Thetoume ksana thn metavlhth lathos = 0, gia tous idious logous pou
	//eipame parapano
	lathos=0;
	do{									
		if (arg_c>5 && lathos==0){
			strcpy(buf,arg_v[5]);
		}
		else {
			//allios, o Client typwnei:'Dose timh gia xrisi thesis parking  
			printf("Dose timi gia xrisi thesis parking: ");			
			//O client dinei timh									
			input();							
		}
		//metatrepei ton buf pou krataei thn timh tou parking se char kai kanei ton 
		//parakato elegxo.An h timh pou edose o client einai >0, tote einai eggirh 		
		if( atof(buf) > 0) {							
  			break;									
		}
		//alliws den einai eggirh kai emfanizetai to mhnyma: 'Invalid timh'
		printf("Invalid timh\n");						
		//thetetai h metavlhth lathos = 1 kai emfanizetai to mhnyma: 'Dose timi 
		//fia xrisi thesis parking'
		lathos=1;
	} while (1);
	//O client stelnei ston server thn timh
	safe_write();
	//O client diavazei to mhnyma pou tou stelnei o server
	safe_read();									
	//kai to tupwnei, to mhnyma einai: 'Created new parking with name %s, 
	//price %.2f and description %s' X,X X.
	puts( buf );									
	//Nea grammh.
	printf("\n");								
}

/*h synarthsh ayth vriskei kai ektuponei 
tis 20 teleytaies krathseis sto parking
*/
void client_twenty_last_kratiseis(void){	
	safe_read();
	//Ean to arg_c>3, tote antigrafoume ston buf to periexomeno tou
	//arg_v[3] pou einai to ID toy parking
	if(arg_c>3) strcpy(buf,arg_v[3]);
	//allios,o client typonei to mhnyma: 'Epelekse parking' kai sth sunexeia 
	//plhktrologei ton ari8mo tou parking pou thelei na epileksei 
	else{
		printf("Epelekse parking: ");			

    	input();
	}
	//o client stelnei ston server to ID tou parking pou epelekse
	safe_write();		
	//Emfanizontai oi 20 teleutaies kratiseis sto parking pou epelekse o client
	for( i=0; i < 20; i++ ) {							
		printf("%d. ", i+1 );							
		safe_read();								
		puts( buf );
		safe_write();
	}

} 
			
/*
h synarthsh ayth emfanizei to menu tou odhgou
kai analoga me thn epilogh pou kanei kalountai oi katallhles 
synarthseis
*/
void choice_odigos(){
	//An dosoume orisma apo thn grammh entolon >2 tote antigrafetais ton buf 
	//to to 3o stoixeio tou pinaka arg_v[]
	if (arg_c>2){
		strcpy(buf,arg_v[2]);
	}
	//allios, ston client emfanizontai ta parakato mhnumata:
	else {	
		printf("Menu pelati:\n");
		printf(" 1.Dimiourgia neou logariasmou\n");
		printf(" 2.Dimiourgia neas kratisis\n");
		printf(" 3.Provoli stoixeion logariasmou\n");
		printf(" 4.Katathesi xrimaton ston logariasmo\n");
		printf("Enter your choice: ");					
		//O client plhktrologei thn epilogh tou
        	input();
		
	}
	//metatrepoume to periexomeno tou buf pou einai char se akeraio integer kai 
	//to apothhkeuoume sthn choice
	choice = atoi( buf );
	//ean h epilogh tou odhgou einai metaxu 1'h 2'h 3'h 4 
	//kalountai oi analoges synarthseis 
	if( choice > 0 && choice < 5 )  {			
		//stelnoume thn epilogh tou odhgou ston server			
		safe_write();							
		//o client diavazei to periexomeno ths choice pou tou stelnei o server
		safe_read();
		//analoga me to choice kalountai oi analoges synarthseis	
		switch( choice ) {
			case 1 :
				//dhmiourgia neou logariasmou
				client_account_create();
				break;
			case 2 :
				//dhmiourgia neas krathshs               
				client_create_new_reservation();
				break;
			case 3 :
				//provolh stoixeion logariasmou              
				client_account_view();
				break;
			case 4 :
				//katathesh xrhmaton sto logariasmo              
				client_account_deposit();
				break;
		}
	}
	else {								
		//an h epilogh den einai metaxu 1-4 o client emfanizei to 
		//mhnyma 'Invalid choice'
		printf("Invalid choice.\n");			
	}
}


//Synarthsh pou dhmiourgei neo logariasmo gia ton client
void client_account_create( void ) {
	//o client diavazei to periexomeno tou buf pou tou stelenei o server,
	//to opoio periexomeno tou buf mporei na einai ena apo ta parakato mhnymata:
	//'There are no remaining slots' 'h 'Found free slot for new client'.
	safe_read();									
	//Syggrinei to periexomeno tou buffer me to 	
	//mhnuma "There are no remaining slots" pou 
	//shmainei oti o server den mporei na dextei 
	//allon client.
	if( strcmp( buf , "There are no remaining slots") == 0 ) {			
		//O client ektuponei to mhnuma "There are no 
		//remaining slots".		
		puts( buf );							
		//kleinei to socket.
		socket_disconnect();						
		//termatizei o client.
		exit(1);								
	}
	//allios, o client ektuponei "Found free slot for new 
	//client" pou shmainei oti o server mporei na 
	//dextei ayta ta dedomana.
	puts( buf );
	//o client dexetai apo ton server ena mhnyma me to ID tou 
	//logariasmou tou 
	safe_read();								
	//o client ektuponei to mhnuma pou tou esteile o server: Created 
	//new account with id: X ".
	puts( buf );										
	//kanoume thn epanalhpsh do-while gia na elegxei 
	//an to onoma tou client einai eggiro.
	//apaitoume to onoma tou client na periexei MONO 
	//EGGIROUS XARAKTHRES.Kai opos eipame kai prin thetoume thn lathos = 0
	//kai thn allazoume mesa sthn do-while gia na anagkazoume ton odhgo na 
	//dinei eggiro onoma
	lathos=0;
	do{									
		if (arg_c>3 && lathos==0){
			//antigrafoume ston buf to periexomeno tou arg_v[3]	
			strcpy(buf,arg_v[3]);
		}
		//allios, o client ektuponei: 'Dose onoma odhgou'
		else {
			printf("Dose onoma odigou: ");					 
			//o odhgos plhktrologei to onona tou
			input();						
		}
		if((strlen(buf) > 0) && (strlen(buf) <= 20 ) ) 
		{			
			//Atoi(buf).An o buf periexei xarakthres 
 			//tote,prepei na elexgoume an einai egguroi.Den 
			//theloume na exoume noumera metaxi ton 
			//xarakthron, kena, tabs, h na ksekina me noumero.
    			if(!atoi(buf)) 
			{ 						
				//Thetoume thn metablhth j = 0;
				j = 0;									
				//bazoume mia for epanalipsh gia na kanoume toses 
				//epanalhpseis oso to mhkos tou buf kai   
				//elegxoume olous tous xarakthres pou briskontai ston buf.
				for( i = 0; i < strlen(buf); i++) {				
					//h isalpha  epistrefei mh mhdeniko arithmo gia 
					//grammata ths alfabhtou. se opoiadhpote 
					//allh periptosi mhden.
					if( isalpha(buf[i]) != 0 ) {				
						//an kapoio stoixeio tou buf is :arithmos apo 0-9 
						//h tab h keno ( " ") tote 
						//au3anoume thn timh tou j.	
						j++;
						//Otan ftasoume to mhkos toy buf feugoume apo to loop
					} 							
				//kai tote,
				}							
			//elegxoume an to mhkos tou buf einai iso me j
			//( poses fores emfanizontai arithmoi, 
  			//tabs kai kena).
        		if( strlen(buf) == j ) break;				
			//An einai idia tote feygoume apo thn do-while 
			//epanalhpsh,pou shmainei oti ta 
      			//periexomena tou buf einai sosta.
    			} 								
		}									
		//An o client pathsei ENTER (dhladh NULL) h 
		//pathsei mh eggyrous xarakthres tote 
		//o client ektuponei to mhnuma:Invalid onoma, 
		printf("Invalid onoma\n");
	   	//epishs kanoume thn metavlhth lathos = 1, etsi oste otan ksanampoume mesa
	    	//sto do-while na anagkasoume ton odhgo na dosei eggiro onoma. Syggekrimena
		//ston client emfanizetai to mhnyma "Dose onoma odigou' kai autos prepei na 
		//dosei eggiro onoma odhgou
		lathos=1;
	} while( 1 );
	//o client stelnei ston server to onoma tou odhgou
	safe_write();							
	//Thetoume ksana thn lathos = 0 gia ton idio logo pou eipame kai prin
    	lathos=0;
	//kanoume thn epanalhpsh do-while gia na 
	//elegsoume an to eponumo tou client einai eggiro
	//Apaitoume to eponumo tou client na einai MONO 
	//EGGIROI XARAKTHRES.
	do{
		//pali kanoume ton elegxo me ta orismata h oxi
		if (arg_c>4 && lathos==0){
			strcpy(buf,arg_v[4]);
		}
		else {
			//allios, o client ektuponei "Dose eponimo odhgou".
			printf("Dose eponimo odigou: ");				
			//O odhgos plhktrologei to eponumo tou
			input();							
		}
		//An o  client pathsei ENTER xoris na eisagei 
		//onoma tote strlen(buf) = 0(NULL) etsi o 
		//client prepei na xsanagrafei to eponumo tou.
		if((strlen(buf) > 0) && (strlen(buf) <= 20 ) ) 
		{				
			//Atoi(buf).An o buf periexei xarakthres, prepei 
			//na elegxoume ean einai eggyroi.Den 
	  		//theloume na exoume aritmous metaxsi ton 
			//xarakthron, kena, tabs h na ksekiname me 
			//arithmo.if(!atoi(buf)) { 						
			//Thetoume thn metablhth j = 0.
			j = 0;						
			//bazoume mia for epanalipsh gia na kanoume toses 
			//epanalhpseis oso kai to mhkos tou buf, 
			//etsi elegxoume olous tous xarakthres pou 
			//briskontai ston buf.
			for( i = 0; i < strlen(buf); i++)
			{			
				//h isalpha epistrefei mh mhdeniko arithmo gia 
				//grammata ths alfabhtou se opoiadhpote 
				// allh periptosh epistrefei mhden.
				if( isalpha(buf[i]) != 0 )
				{			
					//An kapoio steixeio tou buf einai arithmos apo 
					//0-9 h tab h keno, tote ayksanoume thn 
					//timh tou j.                    
					j++;					
					//otan ftasoume to mhkos tou buf feugoume apo to loop 
				}						
			//kai tote										
			}							
			//elegxoume an to mhkow tu buf einai idio me to j
			//( poses fores emfanizontai arithmoi, 
       			//tabs, kena.
			if( strlen(buf) == j  ) break;				
			//An einai idia tote geugoume apo thn epanalhpsh 
			//do-while, ara ta periexomena tou buf 
			//einai sosta.								
		}
		//An o client pathsei ENTER, dhladh NULL h 
		//eisagei mh eggirous xarakthres tote 
		//ektyponei to mhnuma: Invalid eponumo.
		printf("Invalid eponimo\n");						
		//h lathos ginetai ish me 1 etsi oste na zhthtai apo ton 
		//odhgo na ksanagrapsei to eponumo toy.
		lathos=1;	
	} while( 1 );								
	//o odhgow stelnei ston server to eponymo tou		
	safe_write();							
	//o client diavazei to mhnyma pou tou stelnei o serner	
	safe_read();							
	//kai to emfanizei.To mhnyma einai to exsis: 'Created new account 
	//for client %s %s'                                                                                   
	puts( buf );									
	//Nea grammh											
	printf("\n");				
}

/*
h synarthsh auth dhmioyrgei nea krathsh 
gia ton client
*/
void client_create_new_reservation(void) {
	//o client diavazei to periexomeno tou metrhth counter pou tou stelnei
	//o server, dhladh to plhthos ton id parking pou yparxoun  
	safe_read();
	//metatrepoume ton char buf se intefer kai to apothhkeuoune ston counter
	counter = atoi(buf);
	//o client stelnei ston server to periexomeno tou counter
	safe_write();
	//Ean yparxei toulaxiston ena parking		
	if(counter > 0)
	{	
		for (i =0; i<counter; i++)
		{
        		//o client diavazei to mhnyma pou tou esteile o server:
        		//'Brethhke parking with id %d'
			safe_read();
        		//kai o client to ektyponei
			puts(buf);  			
        		//			
			safe_write();
			for (j =0; j<10; j++)
			{
				//o client diavazei to mhnyma pou tou stelnei o server.To mhnyma
				//pou tou stelnei o server einai ena apo ta parakato duo:
				//'h thesh %d diathesimh,' h' 'h thesh %d diathesimh,'.
				safe_read();
				//o client ektuponeoi to katallhlo mhnyma
				puts(buf);					
				//kai stelnei ston server to periexomeno tou buf
            			safe_write();
			}
		}
	}
	else {
		//Kleinei ti socket
		socket_disconnect();							
		exit(1);
	}
	//safe_read();
	//Kanoume ksana ton idio elegxo gia ta orismata 
	if(arg_c>3) strcpy(buf,arg_v[3]);
	else{
		//allios ektyponei o client 'Epelekse ena id parking'
		printf("Epelekse ena id parking: ");
		//o client plhktrologei to id tou parking pou epilegei
		input();
	}
	//o client stelnei ston server to id tou parking pou epelekse
	safe_write();
	//o server edo stelnei ena mhnyma ston client
	safe_read();
	//puts(buf);
	if (arg_c>4){
		strcpy(buf,arg_v[4]);
	}
	else {
		//O client tuponei: 'Please enter account ID or 
		//client "name surname": '.
		printf("Please enter account ID or client \"name surname\": ");	
		//o client plhktrologei onoma kai eponymo
		input();								
	}
	//o client stelnei to mhnyma ston server
	safe_write();									
	//se auto to shmeio apo thn allh meria o server kalei thn synarthsh 
	// server_account_search(), gia na elegsei ean ontos yparxei logariasmos me
	//ayta ta stoixeia pou edose o client.								
	//kai o client dexetai ena mhnyma apo ton server, to opoio mporei na einai
	//ena apo ta parakato duo: 'Invalid account' 'h 'Account found with 
	//account ID: %d'.  
	safe_read();
	//sygkrish metaxu tou mhnymatos poy exei stalei 
	//apo ton server kai tou "Invalid account".ean 
	//einai idia ,  
	//tote,
	if( strcmp( buf, "Invalid account") == 0 ) {				
		//o client typonei: 'Invalid account'
        	puts( buf );								
		//Kleinei to socket
		socket_disconnect();
        	//Termatizei o client						
		exit(1);								
	}										
	//ean o server exei vrei to account, 
	//tote
	//client typwnei:Account found with account ID: X
	puts( buf );								
	//Nea grammh
	printf("\n");
	//o client dexetai ena mhnyma apo ton server:'To upoloipo sou den eparkei'
	//'h 'Xreosi'.
	safe_read();
	if( strcmp( buf , "To upoloipo sou den eparkei") == 0 )
	{
		//o client ektuponei: 'To upoloipo sou den eparkei'
		puts(buf);								
		socket_disconnect();
		//Kleinei o client
		exit(1);
	}
	//allios, o client ektuponei: 'Xreosi, X'
	puts(buf);   	
	if(arg_c>5) strcpy(buf,arg_v[5]);							
	else
	{	
		printf("Eisagete mia thesh parking: ");
		//o client eisagei mia thesi parking
		input();
	}
	//h thesi stelnetai ston server
	safe_write();
	//o client dexetai ena mhnyma apo ton server pou tou leei ean kataxwrhthhke 
	//h thesh epityxws h' oxi
	safe_read();		
	//O client ektuponei to katallhlo mhnyma					
	puts(buf);
}	                                                                           


/*
H synarthsh ayth probalei ta stoixeia 
tou logariasmou tou client
*/
void client_account_view(void) {
	if (arg_c>3){
		strcpy(buf,arg_v[3]);
	}
	else {
	//O Client tYpOnei: 'Please enter account ID or 
	//client "name surname": ".
		printf("Please enter account ID or client \"name surname\": ");	
		input();						
	}
	safe_write();							
	safe_read();
	//sygkrish metaxu tou mhnymatos poy exei stalei 
	//apo ton server kai tou "Invalid account".ean 
	//einai idia ,  
	//tote,
	if( strcmp( buf, "Invalid account") == 0 ) {				
		//client typwnei :Invalid account.
		puts( buf );							
		//Kleinei to sicket
		socket_disconnect();							
		//o client termatizei.
		exit(1);
	}									
	//ean o server exei vrei to account, 
	//tote
	//client typwnei:Account found with account ID: X
	puts( buf );
	printf("\n");					
	//ena loop gia na typwsei ta 4 dedomena,1.ID  
	//2.name,3.surname,4.ypoloipo.
	for( i=0; i < 4; i++) {							
		//ean read einai safe,client lamvanei ena mhnyma 
		//kathe stigmh apo ton server
		safe_read();							
		//O client tupwnei sth prwth epanalhpsh:Account ID, sth deuterh 
		//:name, sthn trith: surname kai sthn tetarth 
		//:ypoloipo.
		puts( buf );							
	}
	//kaleitai h synarthsh client_account_last_four_kratiseis()
	client_account_last_four_kratiseis();
}



/*
h synarthsh auth kanei thn katathesh 
xrhmatwn sto logariasmo tou xrhsth
*/
void client_account_deposit( void ) {
	if (arg_c>3){
		strcpy(buf,arg_v[3]);
	}
	else {
        	//Client tupwnei:"Please enter account ID or 
		//client "name surname": ".
		printf("Please enter account ID or client \"name surname\": ");		
      		//o client emfanizei katallhlo mhnyma
		input();							
	}
	//o client stelnei to mynhma ston server
	safe_write();									
	safe_read();
	//sygkrish metaxu tou mhnymatos poy exei stalei 
	//apo ton server kai tou "Invalid account".ean 
	//einai idia ,  
	//tote,
	if( strcmp( buf, "Invalid account") == 0 ) {				
		//client typwnei :Invalid account
		puts( buf );
		socket_disconnect();						
		exit(1);							
	}									
	//ean o server exei vrei to account, 
	//tote
	//client typwnei:Account found with account ID: X,
	//( X = 1,2,3,4,5).
	puts( buf );								
	printf("\n");						
	if(arg_c>4) strcpy(buf,arg_v[4]);                                                          
	else{
		//o client ektuponei to mhnua: "Enter the amount 
		//to deposit: ".
		printf("Enter the amount to deposit: ");				
		input();								
	}
	//o client stelnei ston server en amhnyma
	safe_write();								
	printf("\n");									
	//An to read einai asfales,o client lambanei ena 
	//mhnuma apo ton server
	safe_read();								
	//Syggrinei to mhnuma pou exei steilei o server 
	//me to "Invalid amount".An einai idia   
	//tote
	if( strcmp( buf,"Invalid amount") == 0) {				
		//o client ektuponei to mhnuma: "Invalid amount"
		puts( buf );							
		socket_disconnect();						
		exit(1);							
        	//allios,	
	}
	else {								
	//o client ektyponei to mhnuma: 'You deposited X'
	puts( buf );								
	//Nea grammh.
	printf("\n");								
	}
}

/*
H synarthsh auth tupwnei tis 4 teleutaies krathseis
*/
void client_account_last_four_kratiseis( void ) {
	//ena for loop gia na typwsei tis teleutaies 4 
	//krathseis
	for( i=1; i < 5; i++ ) {					
		//tupwnei ton arithmo ths krathshs kathe fora
		printf("%d. ", i );						
		safe_read();								
		//o client typonei thn prwth fora:thn perigrafh ths 
		//prwths ktathshs.deuterh fora:perigrafh deuterhs 
		//krathshs.trith fora :perigrafh triths 
		//krathshs.tetarth fora :perigrafh tetarths 
		//krathshs.
		puts( buf );							
		safe_write();
	}
}

/*Synatrhsh gia na ginetai h write() sosta kai na apofeugontai ta sfalmata
kata thn eggrafh
*/
void safe_write(void) {

	//enas integer pernaei apo th synarthsh write sth 
	//metavlhth error. 
	error = write( sd, &buf, sizeof(buf));						
	//An error == -1, 
	if( error == -1) {							
		//tote,
		//mhnyma:Error during write operation. typwnetai.
		perror("Error during write operation.");			
		//kleinei to socket
		socket_disconnect();							
		//o client termatizei
		exit(1);							
	}
}

/*Synatrhsh gia na ginetai h read() sosta kai na apofeugontai ta sfalmata
kata thn anagnosh
*/
void safe_read(void) {
	error = read( sd, &buf, sizeof(buf));					
	//An error == -1,
	//tote,
	if( error == -1) {								
		//mhnyma:Error during write operation. tupwnetai.
		perror("Error during read operation.");					
		//kleinei to socket
		socket_disconnect();						
		//o client termatizei
		exit(1);							
	}
}
/*
th xrhsimopoioune gia asfalh eisodo apo to plhktrologio
*/
void input(void){
	fflush(stdin);
	fgets(buf, sizeof(buf), stdin);
	len = strlen(buf);
	if (buf[len - 1] == '\n')	buf[len - 1] = 0;
}

void socket_call( void ) {
	sd = socket ( AF_LOCAL,SOCK_STREAM,0 );
	if ( sd == -1 ) {
		//elegxei gia erros. Ean apetyxe h dhmioyrgia tou socket  
		perror ( "Failed to create socket.");				
		//o client ektuponei: 'Failed to create socket'
		exit ( 1 );
	}
}

//synarthsh pou syndeei to socket
void socket_connect( void ) {
	sdconnect = connect ( sd, ( struct sockaddr * ) &serveraddr,sizeof ( serveraddr ) );
	if ( sdconnect == -1 ) {
		//Error control.An anapetuxe h syndesi toy socket ,
		perror( "Failed to connect socket");				
		//tote o client ektuponei: Failed to connect socket and client terminates.
		exit( 1 );
        	//allios							
	} else {								
		//ektuponei "Connected...".
		printf("Connected...\n\n");					
	}
}

//synarthsh pou kleinei to socket
void socket_disconnect( void ) {
	//Error control.	
	error = close ( sd );						
	//An apetuxe h aposundesi tote error = -1,
	if( error == -1 ) {							
		//kai o client ektuponei:Error to close socket. 
		perror("Error to close socket");					
		//o client termatizei.
		exit(1);								
	}
}

//synarthsh pou arxikopoiei to socket
void socket_initialize( void ) {
	// mhdenizei ola pedia toy servaddr. 
	memset ( &serveraddr, 0, sizeof( serveraddr ) );			
	// o tupoe tou socket einai topikos (Unix Domain). 
	serveraddr.sun_family = AF_LOCAL; 					
	// Orizei to onoma tou socket. 
	strcpy ( serveraddr.sun_path, UNIXSTR_PATH );			
}


