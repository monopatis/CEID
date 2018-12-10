#include <stdio.h>
main()
{
	int ores,epilogh,euro;
	float kathari_amoivi,foroi,synolo;
	printf("Dose arithmo wrwn:");
	scanf("%d",&ores);
	printf("Dialexte kathgoria mis6odosias (epilexte to katallhlo noymero)\n0. Exodos\n1. Aneidikeytos: 10 Euro/h\n2. Eidikos texniths: 15 Euro/h\n3. Epistaths: 16 Euro/h\nEPILOGH:");
	scanf("%d",&epilogh);
	while (epilogh!=0)
	{
	if (epilogh==1)
	 euro=10;
	else if (epilogh==2)
	 euro=15;
	else if (epilogh==3)
	 euro=16;
	else
	{printf("LATHOS EPILOGH!!!\n");
	 goto ekei;}
	{if (ores<=40)
		kathari_amoivi=euro*ores;
	else
		kathari_amoivi=euro*40+(ores-40)*euro*1.5;
	if (kathari_amoivi<=200)
		foroi=0.15*kathari_amoivi;
	else if (kathari_amoivi<=350)
		foroi=0.15*200+(kathari_amoivi-200)*0.2;
	else 
		foroi=0.15*200+0.2*150+0.25*(kathari_amoivi-350);
	synolo=kathari_amoivi-foroi;
	printf("Kathari Amoivi: %.2f Foroi: %.2f Synolo Apodoxwn: %.2f\n",synolo,foroi,kathari_amoivi); }
    ekei:
	printf("Dialexte kathgoria mis6odosias (epilexte to katallhlo noymero)\n0. Exodos\n1. Aneidikeytos: 10 Euro/h\n2. Eidikos texniths: 15 Euro/h\n3. Epistaths: 16 Euro/h\nEPILOGH:");
        scanf("%d",&epilogh);
	}
}
