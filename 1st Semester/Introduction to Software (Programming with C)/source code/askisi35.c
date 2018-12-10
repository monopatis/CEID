#include <stdio.h>
int gcd ( int noum1, int noum2 )
{
	int temp;
	if (noum1>noum2)
	{
		while (noum1!=0)
		{
     			temp =noum1; 
			noum1=noum2%noum1;
			noum2=temp;
		}
		return noum2;
	}
	else if (noum1==noum2)
	{
		return noum2;
	}
	else
	{
		while (noum2!=0)
		{
			temp=noum2;
			noum2=noum1%noum2;
			noum1=temp;
		}
		return noum1;
	}
}
main()
{
	int noumero1,noumero2;
	printf("Dwse ton prwto ari8mo\n");
	scanf("%d",&noumero1);
	printf("Dwse ton deutero ari8mo\n");
	scanf("%d",&noumero2);
	printf("O megistos koinos diaireths einai to %d\n",gcd(noumero1,noumero2));
}
