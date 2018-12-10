#include <stdio.h>
int main()
{
	int h,m,h1,h2,m1,m2,s1,s2,x;
	printf("Dose ton proto xroniko prosdiorismo:\n");
	scanf("%d:%d:%d",&h1,&m1,&s1);
	printf("Dose ton deutero xroniko prosdiorismo:\n");
	scanf("%d:%d:%d",&h2,&m2,&s2);
	s1=s1+m1*60+h1*60*60;
	s2=s2+m2*60+h2*60*60;
	x= s1>s2?s1-s2:s2-s1;
	h=x/(60*60);
	x=x-h*60*60;
	m=x/60;
	x=x-m*60;
	printf("%2d:%2d:%2d\n",h,m,x);
}
