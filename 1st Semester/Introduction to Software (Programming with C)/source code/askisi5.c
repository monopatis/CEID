#include <stdio.h>
int main()
{
	long g=0, m=0, k=0;
	long x;
	printf("Dose bytes:\n");
	scanf("%ld",&x);
	printf("Ta %ld bytes analyontai ws eksis:\n",x);
	g=x/(1024*1024*1024);
	x=x-g*1024*1024*1024;
	m=x/(1024*1024);
	x=x-m*1024*1024;
	k=x/1024;
	x=x-k*1024;
	printf("%ld Gibibytes kai %ld Mibibytes kai %ld Kibibytes kai %ld bytes\n",g,m,k,x);
}
