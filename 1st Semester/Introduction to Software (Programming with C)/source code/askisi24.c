#include <stdio.h>
main()
{
	int thesh;
	float kostos,kila;
	printf("Dose eidos 8eshs (1-oikonomiki, 2-diakekrimeni, 3-business):");
	scanf("%d",&thesh);
	if (thesh==1)
	 {printf("Dose ari8mo kilwn:");
          scanf("%f",&kila);
	  if (kila<=20)
		kostos=0;
	  else if(kila<=50)
		kostos=(kila-20)*1;
	  else	kostos=30*1+(kila-50)*2;
	  printf("Synoliko kostos: %.1f euro",kostos);}
	else if(thesh==2)
         {printf("Dose ari8mo kilwn:");
          scanf("%f",&kila);
	  if (kila<=30)
		kostos=0;
	  else if (kila<=60)
		kostos=(kila-30)*1;
	  else  kostos=30*1+(kila-60)*1.5;
	  printf("Synoliko kostos: %.1f euro",kostos);}
	else if(thesh==3)
         {printf("Dose ari8mo kilwn:");
          scanf("%f",&kila);
	 if (kila<=70)
		kostos=0;
	  else kostos=30;
	  printf("Synoliko kostos: %.1f euro",kostos);}
	else printf("Lathos epilogh");
	printf("\n");
}
