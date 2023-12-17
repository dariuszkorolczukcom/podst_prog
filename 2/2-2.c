#include <stdio.h>
#include <stdlib.h>
int main() {
   int ilosc; //deklarowanie zmiennej
   printf("Podaj ilość liczb ");
   scanf("%d",&ilosc);
   if (ilosc<1) 
   {
      printf("Podałeś liczbę operacji mniejszą od 1");
      return 0;
   }
   int i;
   int suma = 0;
   for (i=1;i<=ilosc;++i)
   {
      int liczba;
      printf("Podaj %d liczbę:",i);
      scanf("%d",&liczba);
      if (liczba%3==0) 
      {
         ++suma;
      }
   }
   printf("Z podanych liczb podzielnych przez 3 było %d\n",suma);
   return 0;
}
// Zadanie 2.2
// Napisz program, który wczyta od użytkownika n liczb i zliczy ile z nich jest podzielnych przez 3. Wartość n podawana jest przez użytkownika na początku działania programu.

