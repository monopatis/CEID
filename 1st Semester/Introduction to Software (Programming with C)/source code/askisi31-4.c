#include <stdio.h>
main()
{	char protasi[200];
	int x,i=0;
	printf ("Dwste mia protasi:");
	do 
	 {  scanf ("%c",protasi[i]);
	    i++; } while (protasi[i]!="\n");
	for (x=0;x<=i;x++)
	 printf ("%c",protasi[x]);
}
