 #include <stdio.h>
#include <string.h>

int main( void )
{
	char str[150];
	int length, i, sum, count;

	printf( "Dwse vathmous " );
	scanf( "%s", &str );

	length = strlen( str );

	count = 0; sum = 0;
	for( i=0; i<length; i++ )
	{
		     if( str[i] == 'A' ) { sum += 4; count++; }
		else if( str[i] == 'B' ) { sum += 3; count++; }
		else if( str[i] == 'C' ) { sum += 2; count++; }
		else if( str[i] == 'D' ) { sum += 1; count++; }
		else if( str[i] == 'F' )   count++; 
	}

	printf( "\nO mesos oros einai %.2f to athroisma einai %d kai to plithos %d\n",
		(float)sum / count, sum, count );

	return 1;
}


