#include <stdio.h>
#include <string.h>
main()
{	char protasi[10];
	int x,i=0;
	printf ("Dwste mia protasi:");
	while (protasi!="\n")
	 { scanf ("%s",&protasi);
	   i++; }
	x=i;
	for (i=0;i<x;i++)
	  printf ("%s",protasi[i]);
 }
