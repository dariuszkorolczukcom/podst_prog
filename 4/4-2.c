#include <stdio.h>
#include <stdlib.h>
#define N 3
#define M 3
int main() {
   int i,j,sr;
   float sr_a;
   int t[N][M];
   for (i=0;i<N;++i)
   {
      sr=0;
      for (j=0;j<M;++j)
      {
         int liczba;
         printf("Podaj liczbę %d kolumny %d wiersza:",i,j);
         scanf("%d",&liczba);
         t[i][j] = liczba;
         sr += liczba;
      }
      float s = (float)sr/j;
      if (i == 0 || s>sr_a) sr_a = s;
   }
   for (i=0;i<N;++i)
   {
      printf("[");
      for (j=0;j<M;++j)
      {
         if (j==M-1)
         printf("%3d",t[i][j]);
         else
         printf("%3d,",t[i][j]);
      }
      printf("]\n");
   }
   
   printf("największa średnia wierszy: %.2f\n", sr_a);
   return 0;
}

// Zadanie 4 .2
// Napisz program, który wypełni dwuwymiarową tablicę t[N][M] nieujemnymi wartościami pobranymi od użytkownika, wypisze ją na ekran (każdy wiersz w nowej linii), a następnie znajdzie numer wiersza o największej średniej elementów.