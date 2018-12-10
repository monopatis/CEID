#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
char strmix(char *s, char *t, char *apotelesma, int q1, int q2) 
{ 
        int i,j; 
        if (q1>q2) 
        { 
                j=0; 
                for (i=0;i<q2;i++) 
                { 
                        apotelesma[j]=s[i]; 
                        j+=2; 
                } 
                j=1; 
                for (i=0;i<q2;i++) 
                { 
                        apotelesma[j]=t[i]; 
                        j+=2; 
                } 
                j=2*q2; 
                for (i=q2;i<q1;i++) 
                { 
                        apotelesma[j]=s[i]; 
                        j++; 
                } 
        } 
	else 
	{ 
                j=0; 
                for (i=0;i<q1;i++) 
                { 
                        apotelesma[j]=s[i]; 
                        j+=2; 
                } 
                j=1; 
                for (i=0;i<q1;i++) 
                { 
                        apotelesma[j]=t[i]; 
                        j+=2; 
                } 
                j=2*q1; 
                for (i=q1;i<q2;i++) 
                { 
                        apotelesma[j]=t[i]; 
                        j++; 
                } 
        } 
} 
 main() 
{ 
int mege8os,i,p1=0,p2=0; 
char *prwto,*deytero,*teliko; 
printf("Dwse megisto mege8os string:"); 
scanf("%d", &mege8os); 
prwto=(char*)malloc(mege8os*sizeof(char)); 
deytero=(char*)malloc(mege8os*sizeof(char)); 
teliko=(char*)malloc((mege8os*2)*sizeof(char)); 
printf("Dwse prwto string (mege8os to poly %d):",mege8os); 
scanf("%s",prwto); 
p1=strlen(prwto);
printf("Dwse deytero string (mege8os to poly %d):",mege8os); 
scanf("%s",deytero); 
p2=strlen(deytero);
strmix(prwto,deytero,teliko,p1,p2); 
printf("%s\n",teliko); 
} 
