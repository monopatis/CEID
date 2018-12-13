//programma tou client gia na epikoinonei me ton server
#include "client.h"

int main (int argc, char *argv[])
{
	//pernaei ta orismata pou dexete i main ston pinaka arg_v pou einai global 
	if (argc > 1) {				
		arg_c = argc;
		for ( j=1 ; j < arg_c ; j++){
			arg_v[j] = argv[j];
		}
	}
	else {
		//proti epilogh an eiste idioktitis
		printf("1.An eiste idioktitis.\n");	
		//deuteri epilogi an eiste odigos
		printf("2.An eiste odigos.\n");		
		// o client ektuponei: Grapste epilogi
		printf("Grapste epilogi: ");		 
	}
	//h client_function_choice pairnei thn epilogi tou client
	//kai elegxei gia egkiri epilogi
	//ayth h sunatrhsh brisketai sto clientfunctions.c 	 
	client_function_choice();			
	//h synarthsh ayth kleinei to socket kai brisketai sto clientfunctions.c
	socket_disconnect();			
	//o client termatizei kanonika 		
	return 0;						
}
