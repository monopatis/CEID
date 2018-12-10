#include <stdio.h>
#include <string.h>
#define N 4
main()
{
        char pinakasmorse[10][2][5] = {
        "0", "-----",
        "1", ".----",
        "2", "..---",
        "3", "...--",
        "4", "....-",
        "5", ".....",
        "6", "-....",
        "7", "--...",
        "8", "---..",
        "9", "----."
        };
        int epilogh,flag=0,i,j,k;
        char arithmos[N];
        char morse[5];
        char synolikamorse[N*5];
        printf("1 - Ari8mos se kwdika Morse\n2 - Kwdikas Morse se ari8mo\n0 - Eksodos\n");
        scanf("%d",&epilogh);
        while (epilogh!=0)
        {
                if (epilogh==1)
                {
                        printf("Dwse ari8mo : ");
                        scanf("%s",arithmos);
                        printf("\nO isodynamos kwdikas Morse einai : ");
                        for (i=0;i<N;i++)
                        {
                                j=0;
                                while (flag==0)
                                {
                                        if (arithmos[i]==pinakasmorse[j][0][0])
                                        {
                                                flag=1;
                                                for (k=0;k<5;k++)
                                                {
                                                        morse[k]=pinakasmorse[j][1][k];
                                                }
                                                printf("%s ",morse);

                                        }
                                        else
                                        {
                                                j++;
                                        }
                                }
                                flag=0;
                        }
                }
                else if (epilogh==2)
                {
                        printf("Dwse kwdika Morse: ");
                        scanf("%s",&synolikamorse);
                }
                printf("\n1 - Ari8mos se kwdika Morse\n2 - Kwdikas Morse se ari8mo\n0 - Eksodos\n");
                scanf("%d",&epilogh);}
}
