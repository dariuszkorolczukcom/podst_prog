#include <stdio.h>
int main() {
   int suma = 0;
   while(suma<10)
   {
      int n;
      printf("Podaj liczbę ");
      scanf("%d",&n);
      if(n<0) 
      {
         ++suma;
      }
   }
   printf("podano 10 liczb ujemnych\n");
   return 0;
}
// Zadanie 2.4
// Napisz program wczytujący kolejne liczby z klawiatury i kończący się, gdy liczba podanych liczb ujemnych przekroczy 10.