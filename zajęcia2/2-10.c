#include <stdio.h>
int main() {
   int n;
   printf("Podaj liczbę ");
   scanf("%d",&n);
   printf("\nczynniki to ");
   int p = 2;
   int i = 0;
   while (n!=1) {
      if (n % 2 == 0) {
         i++;
         n = n/2;
      } else {
         printf("%d^%d",2,i);
         break;
      }
   }
   p++;
   i=0;
   while (n!=1) {
      if (n % p == 0) {
         if(n==p && i==0) printf("*%d^1",p);
         if(n==p && i>0) printf("*%d^%d",p,i+1);
         i++;
         n = n/p;
      } else {
         if(i>0) printf("*%d^%d",p,i);
         p+=2;
         i=0;
      }
   }
   return 0;
}
// Zadanie 2.10
// Zmodyfikuj rozwiązanie zadania 2.7 w taki sposób, by rozwiązanie pojawiało się w następującej postaci:
// Podana liczba: 24
// Czynniki: 24 = 2^3*3^1
// Podana liczba: 392
// Czynniki: 392 = 2^3*7^2