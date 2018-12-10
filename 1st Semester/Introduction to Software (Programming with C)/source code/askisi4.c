#include <stdio.h>
main(void)
{
int i, j;
int res;
scanf("%d", &i);
scanf("%d", &j);
res = (++i == 3) && (++j == 4);
printf("%d\n", i);
printf("%d\n", j);
printf("%d\n", res);
}
