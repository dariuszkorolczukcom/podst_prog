#include <stdio.h>
int main() {
   int i;
   int n;
   printf("Podaj liczbę ");
   scanf("%d",&n);
   if (n==1 || n==2 || n==3) {
         printf("%d jest liczba pierwsza",n);
         return 0;
   }
      if (n % 2 == 0) {
         printf("*%d nie jest liczba pierwsza",n);
         return 0;
      }
   int p = 3;
   while (p<=n/2) {
      if (n % p == 0) {
         printf("*%d nie jest liczba pierwsza",n);
         return 0;
      } else {
         p+=2;
      }
   }
   printf("%d jest liczba pierwsza",n);
   return 0;
}
// Zadanie 2.8
// Napisz program, sprawdzający, czy podana przez użytkownika liczba jest liczbą pierwszą.