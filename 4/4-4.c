#include <stdio.h>

void show(int w, int s);
int main() {
   int w, s;
   printf("Podaj wysokość i szerokość: ");
   scanf("%d %d",&w, &s);
      if(w<2 || s<2) {
      printf("nieprawidłowe wartości liczby wierszy i/lub kolumn!\n");
      return 1;
   }
   show(w,s);
   return 0;
}

void show(int w, int s) {
   int t[w][s];
   int i, j;

   for (i=0;i<w;++i)
   {
      for (j=0;j<s;++j)
      {
         if (i==0) printf("*");
         else if (i==w-1) printf("*");
         else if (j==0) printf("*");
         else if (j==s-1) printf("*");
         else printf(" ");
      }
      printf("\n");
   }

}

// Zadanie 4.4
// Napisz funkcję typu void, która przyjmuje dwa parametry całkowite - wysokość i szerokość, a następnie wyświetla (przy pomocy symboli '*') ramkę prostokątną o zadanym rozmiarze.