#include <stdio.h>
int main (void)
{
 float arxiko_poso,ethsio_epitokio,tokos,sunoliko_poso;
 int xronia,i;
 printf("dwse to poso katatheshs:\n to ethsio_epitokio:\n kai ta xronia:\n");
 scanf("%f %f %d",&arxiko_poso,&ethsio_epitokio,&xronia);
 sunoliko_poso=arxiko_poso;
 for(i=1;i<=xronia;i++)
 {
  tokos=(sunoliko_poso*ethsio_epitokio)/100;
  sunoliko_poso=sunoliko_poso+(ethsio_epitokio*sunoliko_poso)/100;
  printf("meta to %d etos o tokos einai %.2f kai to neo kefalaio %.2f\n",i,tokos,sunoliko_poso);
 }
}
