#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#define N 1000
#define K 9
int RandomInteger(int low, int high)
{
	int k;
	double d;
	d = (double) rand() / ((double)RAND_MAX + 1);
	k = (int) (d* (high - low + 1));
	return (low + k);
}
main()
{
	int i,number,sixnotita[K],x,j;
	for (i=0;i<K;i++)
	{
		sixnotita[i]=0;
	}
	for (i=0;i<N;i++)
	{
		number=RandomInteger(1,K);
		for (j=1;j<=K;j++)
		{
			if (number==j)
			{
				sixnotita[j]+=1;
			}
		}
	}
	for (j=1;j<=K;j++)
	{
		printf ("%d | ",j);
		for (x=1;x<=sixnotita[j]/5;x++)
		{
                        printf("*");
		}
		printf("\n");
	} 
}
