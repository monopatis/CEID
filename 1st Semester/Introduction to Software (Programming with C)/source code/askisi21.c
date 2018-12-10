#include <stdio.h>
main()
{
	int N,i,j;
	long int par=1,k=1;
	printf("Dose ari8mo N:");
	scanf("%d",&N);
	for(i=1;i<=N;i++)
	{	par=par*i;}
	for(j=1;j<=N-1;j++)
	{	k=k*N;}
	printf("To N! einai %ld, to N eis tin N-1 einai %ld.\n",par,k);
	if (par>k)
	 printf("Megalytero einai to N.");
	else if (k>par)
	 printf("Megalytero einai to N eis tin N-1.");
	else
	 printf("To N! kai to N eis tin N-1 einai isa");
	printf("\n");
}
