#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int N,M;
   printf("Podaj  liczbę wierszy i kolumn:");
   scanf("%d %d",&N, &M);
   if(N<1 || M<1) {
      printf("nieprawidłowe wartości liczby wierszy i/lub kolumn!\n");
      return 1;
   }
   //zainicjuj srand aby uywać czasu do losowania liczb
   srand(time(NULL));
   int i,j,min,min_p,min_w,min_k;
   int t[N][M];
   for (i=0;i<N;++i)
   {
         for (j=0;j<M;++j)
         {
            float random = rand() % 100;
            t[i][j] = random;
         }
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
   min = t[0][0];
   min_p = t[0][0];
   for (i=0;i<N;++i)
   {
      min_w = t[i][0];
         for (j=0;j<M;++j)
         {
            if(t[i][j]<min) min = t[i][j];
            if (N==M) if(i==j && t[i][j]<min_p) min_p = t[i][j];
            if(t[i][j]<min_w) min_w = t[i][j];
         }
   printf("minimum wiersza %d: %d\n",i+1, min_w);
   }
   for (i=0;i<M;++i)
   {
      min_k = t[0][i];
         for (j=0;j<N;++j)
         {
            if(t[j][i]<min_k) min_k = t[j][i];
         }
   printf("minimum kolumny %d: %d\n",i+1, min_k);
   }
   
   printf("minimum: %d\n", min);
   if (N!=M)
      printf("minimum na głównej przekątnej nie istnieje, macierz nie jest kwadratowa\n");
   else
      printf("minimum na głównej przekątnej: %d\n", min_p);
   return 0;
}

// Zadanie 4.1
// Napisz program, który wypełni losowymi wartościami dwuwymiarową tablicę t[N][M], wypisze ją na ekran (każdy wiersz w nowej linii), a następnie wynaczy wartość minimalną:
// - całej tablicy,
// - elementów na głównej przekątnej,
// - każdego wiersza osobno,
// - każdej kolumny osobno.
// W przypadku, gdy wartości nie da się wyznaczyć, program powinien wyświetlić stosowny komunikat.