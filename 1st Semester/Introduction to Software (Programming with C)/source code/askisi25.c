#include <stdio.h>
main()
{
	int N,stavroi=1,sum=1,seires,j,m;
	do{
	  printf("Dose perito ari8mo megalitero tou 3:");
	  scanf("%d",&N);
	  } while((N%2==0)||(N<=3));
	for (seires=2;seires<=N;seires++)
		sum+=2;
	for (seires=1;seires<=N;seires++)
	{	for (j=1;j<=sum;j++)
			printf(" ");
		for (m=1;m<=stavroi;m++)
			printf("+");
		stavroi+=2;
		sum-=1;
		printf("\n"); }
}
