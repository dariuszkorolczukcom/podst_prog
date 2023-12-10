#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void show(int * t, int N);
int* kopiuj(int *t, int n, int m);

int main() {
   int N, *wektor, i, x1, x2;
   // pobiera wielkosc tablicy
   printf("Podaj wielkość wektora: ");
   scanf("%d",&N);
   if(N<=0) 
   {
      printf("\ntablica musi być większa niz 0\n");
      return 1;
   }

   printf("Podaj %d liczb wektora\n", N);
   for (i=0;i<N;++i)
   {
      scanf("%d", &wektor[i]);
   }
   show(wektor, N);

   printf("Podaj zakres\n");
   scanf("%d %d", &x1, &x2);
   if(x1>N || x2>N || x1<1 || x2<x1) 
   {
      printf("\nnieprawidlowy zakres\n");
      return 1;
   }
   int * t_2 = kopiuj(wektor, x1, x2);
   show(t_2, x2-x1+1);

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

int* kopiuj(int *t, int x1, int x2) {
   int *t_2 = (int*)malloc((x2-x1+1) * sizeof(int));
   int i, j = 0;
   for (i=x1-1;i<x2;++i) {
      // printf("i: %d, t[i]:%d\n",i, t[i]);
      t_2[j] =t[i];
      ++j;
   }
   return t_2;
}
// Zadanie 6.5
// Napisz funkcję, która z tablicy podanej jako parametr skopiuje elementy ze wskazanego zakresu indeksów do tablicy zwracanej jako wynik (pamiętaj by zwrócić również rozmiar utworzonej tablicy).
// przykład: tablica = {2, 4, 7, 1, 5, 8, 3, 6, 9}, idx0 = 2, idx1 = 5
// wynik: {7, 1, 5, 8}.