#include<stdio.h> 
int main()
{
char protasi[256];
int i=0,j=0;
printf('Dwste mia protasi:');
while ((protasi[i-1]!='\n')&&(i<256))
{
	protasi[i]=getchar();
	i++;}
j=i;
for(i=0;i<j;i++)
{	if (protasi[i]==040)
        {	if (protasi[i+1]==','||'.')
		{	printf('%c',protasi[i+1]);
			i++;
		}
	}
	else	printf('%c',protasi[i]);}
}
