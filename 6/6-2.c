#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void show(int * t, int N);
int* iloczyn(int n, int *wektor, int a);

int main() {
   int N, *wektor, i, a;
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

   printf("Podaj %d liczbe a\n", N);
      scanf("%d", &a);

   int * t = iloczyn(N, wektor, a);
   show(t, N);

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

int* iloczyn(int n, int *wektor, int a) {
   int i;
   for (i=0;i<n;++i) {
      wektor[i] *= a;
   }
   return wektor;
}
// Zadanie 6.2
// Napisz funkcję int* iloczyn(int n, int *wektor, int a), która liczy iloczyn liczby a przez wektor o długości n (wynikiem jest wektor o długości n).
// przykład: wektor = {2, 4, 3, 1}, a = 2
// wynik: {4, 8, 6, 2}