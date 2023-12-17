#include <stdio.h>
int main() {
   int i;
   int n;
   printf("Podaj liczbę ");
   scanf("%d",&n);
   printf("\nczynniki to "); 
   while (n!=1) {
      if (n % 2 == 0) {
         printf("*%d",2);
         n = n/2;
      } else break;
   }
   int p = 3;
   while (n!=1) {
      if (n % p == 0) {
         printf("*%d",p);
         n = n/p;
      } else {
         p+=2;
      }
   }
   
      // for (i=2;i<=n;i++) {
      //    if (n==1) {
      //       break;
      //    }
      //    if (n % i == 0) {
      //       printf("*%d",i);
      //       int a = n/i;
      //       n=a;
      //       i=1;
      //    }
      // }
   return 0;
}
// Zadanie 2.7
// Napisz program rozkładający daną liczbę naturalną na czynniki pierwsze. Sprawdzamy, czy liczba dzieli się przez 2. Jeżeli tak, to na ekranie wypisujemy "2" , a samą liczbę dzielimy przez 2. Czynność tę powtarzamy, aż liczba przestanie być podzielna przez 2. Następnie powtarzamy tę samą procedurę badając podzielność przez 3,4, itd., aż rozważana liczba stanie się równa 1.
// Przykład:
// Podana liczba: 24
// Czynniki: 24 = 2*2*2*3
// Podana liczba: 392
// Czynniki: 392 = 2*2*2*7*7