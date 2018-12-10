#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 1000
#define K 9
int RandomInteger(int low, int high) {
  int k = high - low + 1;
  return rand() % k + low;
}

main() {
  int A[K],i,m,number;
  srand((int)time(NULL));

  for(i=0;i<K;i++)
    A[i]=0;

  for(i=0;i<N;i++) {
    number=RandomInteger(1,K);
    A[number-1]++;
  }
  for(i=0;i<K;i++) {
    m=A[i]/5;
   printf("%d",i+1);
   printf("|");
   while(m>0) {
     printf("*");
     m--;
   }
   printf("\n", A[i]);
  }
}

