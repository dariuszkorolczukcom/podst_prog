#include <stdio.h>
#include <ctype.h>
#define MAX_DL 50

int main() {
   char c, nazwa[MAX_DL];
   int i;
   printf("\npodaj napis: ");
   for (i = 0; (c = getchar()) !='\n'; ++i)
   {
      nazwa[i] = c;
   }
   printf("podaj szukany znak: ");
   c = getchar();
   int j = 0;
   --i;
   for (; j<=i;) {
   if(c==nazwa[i-j]) {
      break;
   }
   ++j;
   }
   //nazwa[i] = '\0';
   printf("wynik :%d\n",i-j+1);
   return 0;
}

// Zadanie 3.7
// Napisz program, który wczytuje od użytkownika łańcuch znaków a następnie pojedynczy znak i podaje indeks ostatniego wystąpienia tego znaku w zadanym łańcuchu. Wyświetlane indeksy mają być liczone od jedynki. Wczytany napis ma mieć maksymalnie 50 znaków.
// Przykład:
// znak: 'o',
// łańcuch: ”Ola ma kota”
// wynik: 9