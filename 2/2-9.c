#include <stdio.h>
int main() {
   int suma = 0;
   int n;
   printf("Podaj liczbę ");
   scanf("%d",&n);
   if (n<0) {
         printf("%d nie jest liczba naturalna",n);
         return 0;
   }
   while (n>0) {
      int reszta = n%10;
      printf("n: %d, reszta %d\n",n,reszta);
      if (n<10) {
         suma+=n;
      } else {
         suma += reszta;
      }
      n=n/10;
   }
      printf("suma cyfr to %d",suma);
   return 0;
}
// Zadanie 2.9
// Napisz program obliczający sumę cyfr wczytanej liczby naturalnej.