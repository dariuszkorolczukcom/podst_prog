#include <stdio.h>
#include <ctype.h>
#define MAX_DL 100

int main() {
   char c, nazwa[MAX_DL];
   int i, l = 0, n = 0;
   printf("\npodaj napis: ");
   for (i = 0; (c = getchar()) !='\n'; ++i)
   {
      if (isalpha(c)) nazwa[i] = c;
      else --i;
   }
   int j = 0;
   --i;
   for (; i>=0;) {
   //printf("i: %d, j:%d, n[i]: %c, n[j]: %c\n",i,j,nazwa[i],nazwa[j]);
   if(nazwa[i]!=nazwa[j]) {
      printf("Wyraz nie jest palindromem\n");
      return 0;
   }
   ++j;
   --i;
   }
   //nazwa[i] = '\0';
   printf("Wyraz jest palindromem\n");
   return 0;
}

// Zadanie 3.6
// Napisz program, który wczytuje ze standardowego wejścia napis do tablicy i sprawdza, czy jest on palindromem. Wczytany napis ma mieć maksymalnie 40 znaków. Wielkość liter nie powinna mieć znaczenia w trakcie porównywania. 
// Wersja łatwiejsza: w porównaniu uwzględniaj wszystkie znaki.
// Wersja trudniejsza: w porównaniu pomijaj znaki, które nie są literami.