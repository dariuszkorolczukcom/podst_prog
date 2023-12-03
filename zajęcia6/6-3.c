#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void show(int * t, int N);
int* kopiuj(int *t, int n, int m);

int main() {
   int N, *wektor, i, m, n;
   // pobiera wielkosc tablicy
   printf("Podaj wielkość wektora: ");
   scanf("%d",&N);
   if(N<=0) 
   {
      printf("\ntablica musi być większa niz 0\n");
      return 0;
   }

   printf("Podaj %d liczb wektora\n", N);
   for (i=0;i<N;++i)
   {
      scanf("%d", &wektor[i]);
   }
   show(wektor, N);

   printf("Podaj liczbe m\n");
      scanf("%d", &m);

   printf("Podaj liczbe n\n");
      scanf("%d", &n);

   int * t_2 = kopiuj(wektor, n, m);
   show(t_2, m);

   return 0;
}

void show(int * t, int N) {
   int i;
   //wyswietla tablice t
   printf("{%d,",t[0]);
   for (i=1;i<N-1;++i)
   {
      printf("%d,", t[i]);
   }
   printf("%d}\n",t[N-1]);
}

int* kopiuj(int *t, int n, int m) {
   int *t_2 = (int*)malloc(m * sizeof(int));
   int i;
   for (i=0;i<n;++i) {
      t_2[i] =t[i];
   }
   return t_2;
}
// Zadanie 6.3
// Napisz funkcję int* kopiuj(int *t, int n, int m), która tworzy nowy wektor liczb całkowitych o rozmiarze m będący kopią n elementów z wektora t.