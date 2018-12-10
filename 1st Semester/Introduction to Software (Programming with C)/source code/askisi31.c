#include<stdio.h> 
int main()
{
char protasi[256];
int i=0,j=0;
printf("Dwste mia protasi:");
while ((protasi[i-1]!='\n')&&(i<256))
{
	protasi[i]=getchar();
	i++;}
j=i;
for(i=0;i<j;i++)
{	if (protasi[i+1]==',')
	{	if (protasi[i]==32)
		{	printf("%c ",protasi[i+1]);
			i++;
		}
		else if (protasi[i+2]!=32)
		{	printf("%c, ",protasi[i]);
			i++;
		}
		else
		{
			
			printf("%c",protasi[i]);
			
		}	
	}
	else if (protasi[i+1]=='.')
	{	if (protasi[i]==32)
		{	printf("%c ",protasi[i+1]);
			i++;
		}
		else if (protasi[i+2]!=32)
		{	printf("%c. ",protasi[i]);
			i++;
		}
		else
		{
			
			printf("%c",protasi[i]);
			
		}	
	}
	else	printf("%c",protasi[i]);
}
}
