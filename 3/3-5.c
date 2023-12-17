#include <stdio.h>
#include <ctype.h>
#define MAX_DL 100

int main() {
   char c, nazwa[MAX_DL];
   int i, l = 0, n = 0;
   printf("\npodaj napis: ");
   for (i = 0; (c = getchar()) !='\n'; ++i)
   {
      nazwa[i] = c;
      if (isalpha(c)) ++l;
      if (isdigit(c)) ++n;
   }
   nazwa[i] = '\0';
   printf("liter: %d \nliczb: %d.\n",l,n);
   return 0;
}

// Zadanie 3.5
// Napisz program, który wczytuje ze standardowego wejścia napis do tablicy i wyznacza ile razy wystąpiły w nim litery, a ile cyfry.