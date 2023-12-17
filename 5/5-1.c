#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_NAME_SZ 256

int licznik_slow(char *s)
{
   int licz; licz = 0;
   while (*s != '\0')
   {
      while (isspace(*s)) /*pomijanie spacji */
      ++s;
      if (*s != '\0') /*znaleziono słowo */
      {
         ++licz;
         while (!isspace(*s) && *s != '\0')
         ++s; /*akceptowanie słowa*/
      }
   }
   return licz;
}

int main() {
   char *p = malloc(MAX_NAME_SZ);
   printf("podaj zdanie: ");
   fgets(p, MAX_NAME_SZ, stdin);
   int liczba = licznik_slow(p);

   printf("\nliczba slow %d!\n",liczba);

   return 0;
}

// Zadanie 5.1
// Napisz funkcję int słowo(char *napis), która wyznaczy liczbę słów. w danym jako parametr łańcuchu. Słowo definiujemy jako ciąg znaków oddzielony białym znakiem. W łańcuchu znajdują się tylko litery oraz spacje