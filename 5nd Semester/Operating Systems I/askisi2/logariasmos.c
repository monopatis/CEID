/* Auto to arxeio periexei synartiseis sxetikes 	*/
/* me ton server. Oles autes ektelountai se mia 	*/
/* diergasia paidi ektos apo tin account_initialize 	*/
/* kai tin parking_initialize pou ektelountai stin  	*/
/* arxi tou server.					*/

#include "server.h"
#include "logariasmos.h"
#include "threads.h"
#include "sockets.h"

/* synarthsh poy arxikoloiei tous pointers sth  shared memory.	*/
/* gia kathe logarismo desmeuei 1 struct logariasmos kai 	*/
/* 4 struct last_four gia tis teleutaies kratiseis		*/
/* Meta sinexizei ston epomeno					*/

void accounts_initialize(void) {
	//epanalipsi gia olous tous logariasmous
	for( i = 0; i < MAXACCOUNTS; i++) {
		//dianemei ton xwro pou xreiazetai apo thn struct catalog kai epistrefei enan deikth pou deixnei sthn arxh
		pshm = malloc(sizeof(struct logariasmos));
	        //o deikths plogariasmos[i] deixnei ekei pou deixnei o pshm
	        plogariasmos[i] = (struct logariasmos *)pshm;    
	        //arxikopoiisi acc_id me -1
	        plogariasmos[i]->acc_id = -1;
	        //arxikopoiisi name me keno
	        strcpy( plogariasmos[i]->name, "" );
	        //arxikopoiisi surname me keno
	        strcpy( plogariasmos[i]->surname, "" );    
	        //arxikopoiisi ypoloipo me 0
	        plogariasmos[i]->ypoloipo = 0.0;
	        //epanalipsi gia arxikopoiisi twn timwn pou deixnei o pkratiseis
	        for(j = 0; j < KRATISEIS; j++) {
			//dienemei ton xwro pou xreiazetai gia thn struct last_four kai epistrefei enan pointer pou deixnei sthn arxh
			pshm = malloc(sizeof(struct last_four));
			//o deikths pkratiseis[j] deixnei ekei pou deixnei o pshm
			plogariasmos[i]->pkratiseis[j] = (struct last_four *)pshm;                
			//arxikopoihsh discription me keno
			strcpy( plogariasmos[i]->pkratiseis[j]->description, "" );
		}
	}
}

/*synarthsh pou arxikopoiei tous pointers sth shared memory*/
/*gia ka8e parking desmeuei mia struct parking*/
/*ka8ws epish kai struct last_twenty git tis teleuteies 20 krathseis */

void parking_initialize(void) {
     //epanalipsi gia ola ta parking=MAXPARKING
    for( i = 0; i < MAXPARKING; i++) {
	pshm = malloc(sizeof(struct parking));
        //o poiner pparking[i] deixnei ekei pou deixnei o pshm
        pparking[i] = (struct parking *)pshm;
        //arxikopoiisi park_id me -1   
        pparking[i]->park_id = -1;
         //arxikopoiisi name me keno
        strcpy( pparking[i]->name, "" );
         //arxikopoiisi timh me 0
        pparking[i]->timh = 0.0;
        //arxikopoiisi perigrafi me keno
        strcpy( pparking[i]->perigrafh, "" );       
        //epanalipsi 10 fores
        for(j=0;j<10;j++)
        {
            //arxikopoiisi thes[j] me 0
            pparking[i]->thesi[j]=0;
        }
        //Epanalipsi 20 fores          
        for(j =0; j<MAXRESERVATION; j++)
        {
		pshm = malloc(sizeof(struct last_twenty));
		//o pointer pparking_kratiseis[j] deixnei ekei pou deixnei o pshm
		pparking[i]->pparking_kratiseis[j] = (struct last_twenty *)pshm;
		//arxikopoiisi discription me keno
		strcpy(pparking[i]->pparking_kratiseis[j]->description, ""); 
        }        
    }
}
//pairnei thn epilogh tou client kai kalei tis synarthseis
//server_choice_idioktitis() 'h thn server_choice_odigos antistoixa.	
void *server_function_choice(void* sdaccept_thread) {
	int choice, error;
	int socket = (long)sdaccept_thread;
	char buf[100];
	//Eisagei ston buf tin epilogi pou stelnei o client 
	error = read( socket, &buf, sizeof(buf) );			
	error_read(error);							
	//meso ths atoi() metatrepoume ton buf pou einai typou char sto integer choice.
	//O client elegxei gia dektes times	
	choice = atoi(buf);	
	//apostoli tou buf ston client, to kanoume gia kaluteri epikoinonia			
	error = write( socket, &buf, sizeof(buf) );
	error_write(error);
	switch( choice ) {
		case 1 :
			//kaleite h sunarthsh
			server_choice_idioktitis(socket);
			//kanei break apo to switch
			break;						
		case 2 :
			//kaleite h sunarthsh
			server_choice_odigos(socket);
			//kanei break apo to switch
			break;
	}
	//afou oloklhrwsoume th diadikasia feugoume apo to thread
	pthread_exit(NULL);
}

//synarthsh pou orizei thn leitourgia analoga me thn epilogh tou idiokthth
void server_choice_idioktitis(int socket) {
	int choice, error;
	char buf[100];
	//Eisagei ston buf tin epilogi pou stelnei o client 
	error = read( socket, &buf, sizeof(buf) );			
	error_read(error);
	//meso ths atoi() metatrepoume ton buf pou einai typou char ston integer choice.
	//O client elegxei gia dektes times
	choice = atoi(buf);						 			
	//apostoli tou buf ston client, to kanoume gia kaluteri epikoinonia	
	error = write( socket, &buf, sizeof(buf) );
	error_write(error);
	switch( choice ) {
		case 1 :
			//kaleite h sunarthsh
			server_parking_create(socket);
			//kanei break apo to switch
			break;
		case 2 :
			//kaleite h sunarthsh
			server_twenty_last_kratiseis(socket);
			//kanei break apo to switch
			break;
	}
}

//synarthsh pou dhmiourgei ena neo parking
void server_parking_create(int socket){
	int cur_park, error, i;
	char buf[100];
	//Afou stin arxikopoiisi ths struct thesame to
	//acc_id is me  -1, anazitame sthn for -1 pou shmainei tha einai to prwto eleuthero
	for( i = 0; i < MAXPARKING; i++ ) {
		//thetoume to cur_park iso me -1			
		cur_park = -1;						
		//an to park_id -1 einai elefthero
		if( pparking[i]->park_id == -1 ) {			
			//thetoume to cur_park iso me i
			cur_park = i;	
			//eggrafh mhnumatos ston buf				
			strcpy( buf, "Found free slot for new parking" );
			//apostolh buf ston client 
			error = write( socket, &buf, sizeof(buf) );
			error_write(error);	
			//exodos ths for				
			break;
		} 
	}
	//ean den brhkame kapoio diathesimo parking tote stelnoume to pparakatw mhnhma sto client.
	if( cur_park == -1 ) {						
		strcpy( buf, "There are no remaining slots" );
		error = write( socket, &buf, sizeof(buf) );
		error_write(error);
		//termatizei to thread
		pthread_exit(NULL);
	}
	//eggrafi ston buf tou mhnumatos
	snprintf( buf, sizeof(buf), "Will created new parking with id: %d", cur_park+1 );
	//apostoli buf ston client
	error = write( socket, &buf, sizeof(buf) );
	error_write(error);							
	//anagnosi onomatos apo client
	error = read( socket, &buf, sizeof(buf) );			
	error_read(error);
	//arxikopoioume to mutex_array  eidika gia auto to parking
	parking_mutex_initialize(cur_park);
	//kleidwnoume to mutex_array eidika gia auto to parking
	parking_mutex_lock(cur_park);
	for (i=0;i < cur_park;i++)
	{	//elegxos an to onoma parking pou dothike yparxei
		if (strcmp(buf,pparking[0]->name)==0)
		{
			strcpy( buf, "uparxon parking" );
			//stelnoume ston clien tti synevei
			error = write( socket, &buf, sizeof(buf) );
			error_write(error);
			//ksekleidwnoume to mutex_array pou kleidwsame prohgoumenws
			parking_mutex_unlock(cur_park);
			pthread_exit(NULL);
		}
	}
	//thetoume to park_id
	pparking[cur_park]->park_id = cur_park + 1;
	//apothikeusi buf sto name
	strcpy( pparking[cur_park]->name, buf );
	//apostoli buf gia kaliteri epikoinonia
	error = write( socket, &buf, sizeof(buf) );
	error_write(error);
	//anagnosi perigrafis apo client
	error = read( socket, &buf, sizeof(buf) );			
	error_read(error);
	//apothikeusi buf stin perigrafh
	strcpy( pparking[cur_park]->perigrafh, buf );
	//apostoli buf gia kaluterh epikoinonia
	error = write( socket, &buf, sizeof(buf) );
	error_write(error);
	//anagnosi timis apo ton client
	error = read( socket, &buf, sizeof(buf) );			
	error_read(error);
	//apothikeusi float timis tou buf stin timh
	pparking[cur_park]->timh=atof(buf);
	//eggrafei tou mhnumatos ston buf
	snprintf( buf, sizeof(buf), "Created new parking with name %s, price %.2f and description %s", pparking[cur_park]->name,pparking[cur_park]->timh, pparking[cur_park]->perigrafh );
	//apostoli buf ston client
	error = write( socket, &buf, sizeof(buf) );
	error_write(error);
	//ksekleidwnoume to mutex_array pou lkeidwsame prin
	parking_mutex_unlock(cur_park);
}

//synarthsh pou stelnei ston client tis teleutaies 20 krathseis se ena parking
void server_twenty_last_kratiseis(int socket){
	int error, i,j;
	char buf[100];
	error = write( socket, &buf, sizeof(buf) );
	error_write(error);
	error = read( socket, &buf, sizeof(buf) );			
	error_read(error);
	//meso ths atoi() metatrepoume ton buf pou einai typou char se
	//akeraio integer kai apothikeuetai sto i
	i = atoi(buf);
	//kleidwnoume to mutex_array eidika gia auto to parking
	parking_mutex_lock(i);
	//epanalipsi 20 fores
	for(j=0; j<20; j++){
		//antigrafi ston buffer thn kratisi tou parking j
		//i-1 giati o pinakas xekinaei apo to 0
		strcpy(buf, pparking[i-1]->pparking_kratiseis[j]->description);
		error = write( socket, &buf, sizeof(buf) );
		error_write(error);
		error = read( socket, &buf, sizeof(buf) );			
		error_read(error);	
	}
	//ksekleidwnoume to mutex_array pou kleidwsame prin
	parking_mutex_unlock(i);
}

//synarthsh pou kanei tis katallhles energeies analoga me thn epilogh tou odhgou
void server_choice_odigos(int socket) {
	int choice, error;
	char buf[100];
	error = read( socket, &buf, sizeof(buf) );			
	error_read(error);
	//meso ths atoi() metatrepoume ton buf pou einai typou char sto integer choice.
	//O client elegxei gia dektes times	
	//etsi den xreiazetai na elenxoume kai edo
	choice = atoi(buf);				
	error = write( socket, &buf, sizeof(buf) );
	error_write(error);
	//analoga me thn epilogh tou odhgou kalountai kai oi 
	//antoistixes synarthseis.
	switch( choice ) {
		case 1 :
			server_account_create(socket);
			break;
		case 2 :
			server_create_new_reservation(socket);
			break;
		case 3 :
			server_account_view(socket);
			break;
		case 4 :
			server_account_deposit(socket);
			break;
	}
}
			
//dhmiourgei to logariasmo tou xrhsth.
void server_account_create(int socket) {
	int cur_acc, error;
	char buf[100];
	/*exoume arxikopoihsei th struct kanoume anazhthsh gia na vroume
	 keno meros gia th dhmiourgia neou logariasmou.ean enas logariasmos
	 exei acc_id -1 tote ayto einai free.*/
	for( i = 0; i < MAXACCOUNTS; i++ ) {				
		//thetoume to cur_acc -1 etsi emeis mporoume na elegxoume an oloi oi logariasmoi exoun dhmiourghthei.
		cur_acc = -1;
		//yaxnoume na vroume ton proto diathesimo logariasmo.
		if( plogariasmos[i]->acc_id == -1 ) {
			//ean to broume thetoume sto cur_acc to i
			cur_acc = i;
			strcpy( buf, "Found free slot for new client" );
			error = write( socket, &buf, sizeof(buf) );
	error_write(error);
			//Exit apo to loop.
			break;
		} 
	}
	//ean den brhkame kapoio diathesimo logariasmo tote stelnoume to pparakatw mhnhma sto client.
	if( cur_acc == -1 ) {						
		strcpy( buf, "There are no remaining slots" );
		error = write( socket, &buf, sizeof(buf) );
		error_write(error);
		pthread_exit(NULL);
	}
	/*ean vroume diathesimo logariasmo synexizoume apo edw.	*/
	//we initialize the mutex_array member specific to this account.
	account_mutex_initialize(cur_acc);
	//kleidwnoume to mutex_array eidika gia auton ton logariasmo
	account_mutex_lock(cur_acc);
	//thetoume to account's ID
	plogariasmos[cur_acc]->acc_id = cur_acc + 1;
	snprintf( buf, sizeof(buf), "Created new account with id: %d", plogariasmos[cur_acc]->acc_id );
	//Stelnoume sto client oti mas zhthse kai merikes plirofories.	
	error = write( socket, &buf, sizeof(buf) );
	error_write(error);
	//diabazoume to onoma tou client. 
	error = read( socket, &buf, sizeof(buf) );			
	error_read(error);
	//apothikevoume to onoma
	strcpy( plogariasmos[cur_acc]->name, buf );
	//diabazoume to epitheto tou client. 
	error = read( socket, &buf, sizeof(buf) );			
	error_read(error);
	//apothikevoume to epitheto
	strcpy( plogariasmos[cur_acc]->surname, buf );
	//stelnoume ston client to parakato mhnhma oti dhmiourghthhke enas neos logariasmos
	//kai merikes akomh plhrofories.
	snprintf( buf, sizeof(buf), "Created new account for client %s %s", plogariasmos[cur_acc]->name, plogariasmos[cur_acc]->surname );
	error = write( socket, &buf, sizeof(buf) );
	error_write(error);
	//ksekleidwnoume to mutex_array pou kleidwsame prin
	account_mutex_unlock(cur_acc);
}

//synarthsh pou dhmiourgei mia  nea krathsh
void server_create_new_reservation(int socket){
	//metablhth typou time_t pou krata thn wra otan to roloi xekina na metra
	time_t nowtime;
	//metablhth typou time_t pou krata thn wra otan to roloi stamathsei na metra.
	int cur_acc,cur_park, error, i, j, counter;
	char buf[100],tempbuf[100];
	//arxikopoiisi counter pou metra ta uparxon parking
	counter=0;
	//epanalipsei gia ola ta parking
	for(i=0; i<MAXPARKING; i++)
	{	//an to park_id den einai -1 simainei oti yparxei to parking
		if(pparking[i]->park_id != -1 ){ 		
			counter++;	
		}else break;//break an einai -1, diladi vrethike ena adio ara kai ta alla tha einai adia
	}
	//egrafei ston buf ton counter me morfi string
	snprintf(buf, sizeof(buf), "%d", counter);
	//apostoli buf ston client
	error = write( socket, &buf, sizeof(buf) );
	error_write(error);
	//anagnosi buf apo ton client
	error = read( socket, &buf, sizeof(buf) );			
	error_read(error);
	//an counter>0 diladi yparxoun parking
	if (counter>0){
		//epanalipsi gia ola ta parking
		for( i = 0; i < counter; i++ ) {	
			//an uparxei to parking
			if( pparking[i]->park_id == i+1 ) {
				//eggrafi ston buf minimatos
				snprintf(buf, sizeof(buf), "Brethhke parking with id %d", pparking[i]->park_id);
				//apostoli ston client
				error = write( socket, &buf, sizeof(buf) );
				error_write(error);
				//anagnosi apo client
				error = read( socket, &buf, sizeof(buf) );			
				error_read(error);
				
				//epanalipsi 10 fores
				for(j=0;j<10;j++){
					//an i thesi einai diathesimi
					if (pparking[i]->thesi[j]==0){
						//egrafei minimatos ston buff
						snprintf(buf, sizeof(buf), "h thesh %d diathesimh, ", j+1);
						//apostoli ston client
						error = write( socket, &buf, sizeof(buf) );
						error_write(error);
						error = read( socket, &buf, sizeof(buf) );			
						error_read(error);
					}
					else {	//an i thesi den einai diathesimi
						snprintf(buf, sizeof(buf), "h thesi %d den einai diathesimh", j+1);
						error = write( socket, &buf, sizeof(buf) );
						error_write(error);
						error = read( socket, &buf, sizeof(buf) );			
						error_read(error);	
					}					
				}
						
			}
			else break;							 
		}
	}
	else {
		account_mutex_unlock(cur_acc);
		parking_mutex_unlock(cur_park);
		pthread_exit(NULL);
	}
	//perimenei apo ton client na steilei tin epilogi apo ton xristi poio parking thelei
	error = read( socket, &buf, sizeof(buf) );			
	error_read(error);
	//o pinakas xekina apo to 0						
	i = atoi(buf)-1;
	parking_mutex_initialize(i);
	parking_mutex_lock(i);
	//apostoli buf ston client gia syxronismeni epikoinonia
	error = write( socket, &buf, sizeof(buf) );
	error_write(error);	
	//klisi tis sunartisis	gia epilogi account			
	cur_acc = server_account_search(socket);
	//we initialize the mutex_array member specific to this account.
	account_mutex_initialize(cur_acc);
	//ksekleidwnoume to  mutex_array eidika gia auton ton logariasmo
	account_mutex_lock(cur_acc);
	//elegxos an to ypoloipo tou xristi eparkei
	if ((plogariasmos[cur_acc]->ypoloipo - pparking[i]->timh)>0){
		//afairei apo to ypoloipo tin timh tou parking
		plogariasmos[cur_acc]->ypoloipo = plogariasmos[cur_acc]->ypoloipo - pparking[i]->timh;
		//mhnuma gia ton client
		snprintf(buf, sizeof(buf), "Xreosi %.2f \n",pparking[i]->timh);
		//apostoli buff
		error = write( socket, &buf, sizeof(buf) );
		error_write(error);
		//anagnosi buf apo ton client pou stelnei poia thesi thelei
		error = read( socket, &buf, sizeof(buf) );			
		error_read(error);
		//o pinakas ton theseon xekina apo 0								
		j = atoi(buf)-1;
	}		
	else {	//an to ypoloipo einai mikrotero apo tin timh tou parking
		snprintf(buf, sizeof(buf), "To upoloipo sou den eparkei");
		//apostoli buf ston client
		error = write( socket, &buf, sizeof(buf) );
		error_write(error);
		//ksekleidwnoume to mutex_array
		account_mutex_unlock(cur_acc);
		parking_mutex_unlock(cur_park);
		pthread_exit(NULL);
	}
	//an h thesi den einai piasmenh 
	if (pparking[i]->thesi[j] == 0){
		//tote thn desmeuoume
		pparking[i]->thesi[j] = 1;
		//kaloume tis sinartisis
		kratiseis_rotate(cur_acc);
		parking_kratiseis_rotate(i);
		//to nowtime exei tin sigkekrimeni ora
		time(&nowtime);
		//egrafi ston buf enos megalou minumatos	
		snprintf(buf, sizeof(buf),"Sto parking ");
		//xrisimopoiisei tis strcat gia prosthiki string ston buf 	
		strcat(buf, pparking[i]->name);
		snprintf(tempbuf, sizeof(buf)," sth thesi %d",j+1);
		strcat(buf, tempbuf);
		snprintf(tempbuf,sizeof(buf)," stis %s", ctime(&nowtime));
		strcat(buf,tempbuf);
		//eggrafi buf stin proti thesi apo tis teleutaies 4 kratiseis tou logariasmou
		snprintf(plogariasmos[cur_acc]->pkratiseis[0]->description,sizeof(struct last_four),"%s", buf);
		snprintf(buf, sizeof(buf),"O xrhsths ");	 	
		strcat(buf, plogariasmos[cur_acc]->name);
		snprintf(tempbuf, sizeof(buf)," ");
		strcat(buf, tempbuf);
		strcat(buf, plogariasmos[cur_acc]->surname);			
		snprintf(tempbuf, sizeof(buf),",ekane krathsh sth thesi %d",j+1);
		strcat(buf, tempbuf);
		snprintf(tempbuf,sizeof(buf)," stis %s", ctime(&nowtime));
		strcat(buf,tempbuf);
		//eggrafi buf stin proti thesi apo tis teleutaies 20 kratiseis tou parking
		snprintf(pparking[i]->pparking_kratiseis[0]->description,sizeof(struct last_twenty),"%s", buf);
		//eggrafi ston buf tou parakato minimatos	
		snprintf(buf, sizeof(buf), "H thesh kataxorithike epitixos gia ta epomena 30 sec\n");
		//apostoli buf ston client
		error = write( socket, &buf, sizeof(buf) );
		error_write(error);
		//apodesmeusi tis mnimis
		//ksekleidwnoume to  mutex_array
		account_mutex_unlock(cur_acc);
		parking_mutex_unlock(i);
		//perimenei 30 sec 
		sleep(30);
		//arxikopoioume to  mutex_array eidika gia auton ton logariasmo
		account_mutex_initialize(cur_acc);
		parking_mutex_initialize(i);
		//kleidwnoume to  mutex_array eidika gia auton ton logariasmo
		account_mutex_lock(cur_acc);
		parking_mutex_lock(i);
		//thetei tin thesi diathesimi
		pparking[i]->thesi[j] = 0;
	}
	else {
		//egrafi ston buffer ena minima
		snprintf(buf, sizeof(buf), "H thesh den kataxorithike epitixos\n");
		//apostoli buf ston client
		error = write( socket, &buf, sizeof(buf) );
		error_write(error);
	}
	//apodesmeusi tis mnimis
	//ksekleidwnoume to prohgoumeno mutex_array pou eixame kleidwsei
	account_mutex_unlock(cur_acc);
	parking_mutex_unlock(i);
}

//stelnei ston client plhrofories gia enan logarismo odhgou
void server_account_view(int socket) {
	char buf[100];
	int cur_acc, error;
	//vriskei ton sxetiko logariasmo.
	cur_acc = server_account_search(socket);
	account_mutex_lock(cur_acc);
	//stelnei to id logariasmou ston client.
	snprintf( buf, sizeof(buf), "Account ID: %d", plogariasmos[cur_acc]->acc_id );
	error = write( socket, &buf, sizeof(buf) );
	error_write(error);
	//stelnei to onoma tou odhgou ston client
	snprintf( buf, sizeof(buf), "Client name: %s", plogariasmos[cur_acc]->name );
	error = write( socket, &buf, sizeof(buf) );
	error_write(error);
	//stelnei to epitheto  tou odhgou ston client
	snprintf( buf, sizeof(buf), "Client surname: %s", plogariasmos[cur_acc]->surname );
	error = write( socket, &buf, sizeof(buf) );
	error_write(error);
	//stelnei to ypoloipoo tou odhgou ston client.
	snprintf( buf, sizeof(buf), "Ypoloipo: %.2f", plogariasmos[cur_acc]->ypoloipo );
	error = write( socket, &buf, sizeof(buf) );
	error_write(error);
	//stelnei epishs kai tis teleutaies krathseis tou odhgou gia ton opoio kanoume anazhthsh.
	//Stelnei thn perigrafh apo tis kratiseis ston cur_acc kathos to i auxanetai
	for( i = 0; i < KRATISEIS; i++) {
		strcpy( buf, plogariasmos[cur_acc]->pkratiseis[i]->description );
		error = write( socket, &buf, sizeof(buf) );
		error_write(error);
		error = read( socket, &buf, sizeof(buf) );			
		error_read(error);
	}
	account_mutex_unlock(cur_acc);
}

//katathetei mia posothta xrhmatwn sto logariasmo enos odhgou
//me elegxo eggurotitas
void server_account_deposit(int socket) {
	int cur_acc, error;
	float amount;
	char buf[100];
	//vriskei ton sxetiko logariasmo.
	cur_acc = server_account_search(socket);
	//diavazei thn posothta twn xrhmatwn
	error = read( socket, &buf, sizeof(buf) );			
	error_read(error);
	//vazoume sto char buf mia float posothta
	amount = atof(buf);
	//ean h posothta einai 0 or akyroi xarakthres pou eisagontai
	if( amount <= 0.0 ) {
		strcpy( buf, "Invalid amount" );
		//Stelnoume ston client ti sunebh.
		error = write( socket, &buf, sizeof(buf) );
		error_write(error);
		//kanoume exodo.				
		pthread_exit(NULL);
	}
	account_mutex_lock(cur_acc);						
	//kanei tis katallhles litourgies
	plogariasmos[cur_acc]->ypoloipo = plogariasmos[cur_acc]->ypoloipo + amount;
	snprintf( buf, sizeof(buf), "You deposited %.2f", amount);
	//Stelnei ston client that emeis kaname dhladh oti zhththhke kai merikes plirofories.
	error = write( socket, &buf, sizeof(buf) );
	error_write(error);
	account_mutex_unlock(cur_acc);
}


//pairnei thn eisodo apo ton client kai anazhta ean yparxei o sygkekrimenos logarismos.
int server_account_search(int socket) {
	int error,i,j,cur_acc;
	char buf[100], tempbuf[100];
	//o server lamvanei to name surname 'h to id tou logariasmou
	error = read( socket, &buf, sizeof(buf) );			
	error_read(error);							
	//elexei ean o buffer pou alabe einai to id tou logariasmou
	//'h to onoma kai to epitheto.
	//ayth einai h periptosh opou exoume to onoma kai to epitheto.
	if( atoi(buf) <= 0 ) {
		//thetei sto cur_acc to -1
		j = -1;
		//emeis kanoume anazhthsh na doume ean teriazei me kapoio account
		for( i = 0; i < MAXACCOUNTS; i++ ) {
			//antigrafoume to onoma tou client se ena temporary buffer
			strcpy( tempbuf, plogariasmos[i]->name );
			//prosthetoume ena keno metaxu tou  name kai surname
			strcat( tempbuf, " " );
			//prosthetome to surname tou client  sto temporary buffer
			strcat( tempbuf, plogariasmos[i]->surname );
			//sygkrinoumr to  tempbuf string me thn eisodo tou xrhsth apo ton client
			if( strcmp( tempbuf, buf ) == 0 ) {
				//ean teriazoun metaxu tous thetoume sto cur_acc ton aritmo tou logariasmou
				j = i;		
				// kanoume break apo to loop kai etsi den kanoume elegxo xana.	
				break;
			}
		}
		if( j == -1 ) {
			//Stelnoume to parakatw mhnhma ston client		
			strcpy( buf, "Invalid account" );
			error = write( socket, &buf, sizeof(buf) );
			error_write(error);
			pthread_exit(NULL);
		} else {
			//an vroume oti teriazoun stelnoume to parakatw minima ston client.
			snprintf( buf, sizeof(buf), "Account found with account ID: %d", plogariasmos[cur_acc]->acc_id );
			error = write( socket, &buf, sizeof(buf) );
			error_write(error);
			return j;					
		}
	//ayth einai h periptosh opou exoume to id tou logariasmou ws eisodo.
	} else {
		//thetoume sto cur_acc to dothen ID mionontas to kata  1
		//to Account ID's xekina apo 1 and plogariasmos table apo 0
		j = atoi(buf) - 1;
		//elegxoume gia egkuro id, meaning,dhladh ean exei dhmiourghthei	
		if( plogariasmos[j]->acc_id == -1 ) {
			//stelnoume to parakatw mhnhma ston client kai kanoume exit.
			strcpy( buf, "Invalid account" );
			error = write( socket, &buf, sizeof(buf) );
			error_write(error);
			pthread_exit(NULL);
		} else {//ean o logariasmos yparxei stelnoume to parakato minima sto client
			snprintf( buf, sizeof(buf), "Account found with account ID: %d", plogariasmos[cur_acc]->acc_id );
			error = write( socket, &buf, sizeof(buf) );
			error_write(error);
			return j;
		}
	}
}

//olisthainei tis krathseis etsi vste na exoume kathe fora tis teleutaies tesseris gia ena odhgo.
/* ayto antigrafei thn trith krathsh sth tetarth,th deyterh sth trith 
kai th proth sth deuterh me ayth th seira*/
void kratiseis_rotate(int cur_acc) {
	int k,l;
	for( l = 2; l >= 0; l--) {
		k = l + 1;
		strcpy ( plogariasmos[cur_acc]->pkratiseis[k]->description, plogariasmos[cur_acc]->pkratiseis[l]->description );
	}
}

//olisthhsh twn krihsewn se ena parking gia na exoume kathe fora tis teleutaies 20 krathseis.
void parking_kratiseis_rotate(int i){
	int k,l;
	for( l = 18; l >= 0; l--) {
		k = l + 1;
		strcpy ( pparking[i]->pparking_kratiseis[k]->description, pparking[i]->pparking_kratiseis[l]->description );
	}
}
