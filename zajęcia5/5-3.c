#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_NAME_SZ 256

void ile(char *napis, int *litery, int *cyfry) {
   int i;
      for (i = 0; (napis[i]) !='\0'; ++i)
   {
      if (isalpha(napis[i])) ++(*litery);
      if (isdigit(napis[i])) ++(*cyfry);
   }
}

int main() {
   int i,  n, litery = 0, cyfry = 0;

   //deklaracja zmiennych
   char t[MAX_NAME_SZ];
   // char t[] = "ala ma 12 kotow";
   char c;

   //wsad danych do tablicy
   printf("\npodaj napis: ");
   for (i = 0; (c = getchar()) !='\n'; ++i)
   {
      t[i] = c;
   }

   //wyswietla tablice t
   // printf("[%c,",t[0]);
   // for (i=1;i<n-1;++i)
   // {
   //    printf("%c,", t[i]);
   // }
   // printf("%c]\n",t[n-1]);

   ile(t, &litery, &cyfry);
   printf("litery: %d, cyfry: %d\n",litery,cyfry);

   return 0;
}

// Zadanie 5.3
// Napisz funkcję void ile(char *napis, int *litery, int *cyfry), która dla łańcucha danego jako parametr obliczy i zwróci liczbę występujących w nim liter oraz liczbę występujących w nim cyfr.

