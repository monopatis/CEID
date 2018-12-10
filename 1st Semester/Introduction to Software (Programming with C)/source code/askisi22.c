#include <stdio.h>
#include <string.h>
main()
{
	char ba8mous[100];
	int sum=0,i,p,x=0;
	printf("Dose ba8mous:");
	scanf("%s",&ba8mous);
	p=strlen(ba8mous);	
	for(i=0;i<p;i++)
	{
	if (ba8mous[i]=='A')
	  { sum+=4;
	    x++; }
	else if (ba8mous[i]=='B')
	  { sum+=3;
	    x++; }
	else if (ba8mous[i]=='C')
	  { sum+=2;
	    x++; }
	else if (ba8mous[i]=='D')
	  { sum+=1;
	    x++; }
	else if (ba8mous[i]=='F')
	    x++;
        }
        printf( "O mesos oros einai %.2f to athroisma einai %d kai to pli8os %d\n",(float)sum/x, sum, x );
 }
