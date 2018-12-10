#include <stdio.h>
#include <string.h>
#define N 4

void add(int ar1[],int ar2[],int apot[])
{	int i;
        apot[0]=0;
        for(i=0;i<N;i++)
        {
                apot[i+1]=ar1[i]+ar2[i];
        }
	for(i=N+1;i>0;i--)
        {
                if (apot[i]==2)
                {	apot[i]=0;
                        apot[i-1]++;
                }
                if (apot[i]==3)
                {	apot[i]=1;
                        apot[i-1]++;
                }
        }
}

main()
{
	int i;
	char arithmos1[N];
	char arithmos2[N];
	int apotelesma[N+1];
	int karith1[N],karith2[N];
	printf("Dwse ton prwto pros8eteo\n");
	scanf("%s",arithmos1);
	for(i=0;i<N;i++)
	{
		karith1[i]=arithmos1[i]-48;
	}
	printf("Dwse ton deutero pros8eteo\n");	
	scanf("%s",arithmos2);
	for(i=0;i<N;i++)
	{
		karith2[i]=arithmos2[i]-48;
	}
	add(karith1,karith2,apotelesma);
	for(i=0;i<N+1;i++)
	{
		printf("%d",apotelesma[i]);
	}
}

