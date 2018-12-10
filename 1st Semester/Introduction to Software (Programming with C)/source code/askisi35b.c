#include <stdio.h>
int gcd (int noum1, int noum2)
{
	if (noum1==0)
	{
		return noum2;
	}
  	return gcd (noum2%noum1,noum1);
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
