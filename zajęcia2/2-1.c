#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
   int liczba; //deklarowanie zmiennej
   printf("Podaj liczbe: ");
   scanf("%d",&liczba);
   if (liczba<1) 
   {
      printf("Podałeś liczbę operacji mniejszą od 1");
      return 0;
   }
   int i;
   float suma = 0;
   //zainicjuj srand aby uywać czasu do losowania liczb
   srand(time(NULL));
   for (i=1;i<=liczba;++i)
   {
      float random = rand() % 100 +1;

   printf("liczba %.3f\n",random);
      suma += random;
   }
   float srednia = suma/liczba;
   printf("Średnia z %d liczb to %.3f\n",liczba, srednia);
   return 0;
}
// Zadanie 2.1
// Napisz program, który wyznaczy średnią arytmetyczną z n losowych liczb z przedziału <1; 100>. Wartość n podawana jest przez użytkownika na początku działania programu.

