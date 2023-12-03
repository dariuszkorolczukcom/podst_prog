#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void show(int * t, int N);
int* wypelnij_tablice_losowo(int n);
int* wypelnij_tablice_od_uzytkownika(int n);
int* wypelnij_tablice_wartoscia(int n, int w);

int main() {
   int N, w;
   // pobiera wielkosc tablicy
   printf("Podaj wielkość tablicy: ");
   scanf("%d",&N);
   printf("Podaj liczbe w: ");
   scanf("%d",&w);
   if(N<=0) 
   {
      printf("\ntablica musi być większa niz 0\n");
      return 0;
   }


   int * t =  wypelnij_tablice_losowo(N);
   show(t, N);
   free(t);
   t = wypelnij_tablice_od_uzytkownika(N);
   show(t, N);
   free(t);
   t = wypelnij_tablice_wartoscia(N, w);
   show(t, N);
   free(t);

   return 0;
}

void show(int * t, int N) {
   int i;
   //wyswietla tablice t
   printf("[%d,",t[0]);
   for (i=1;i<N-1;++i)
   {
      printf("%d,", t[i]);
   }
   printf("%d]\n",t[N-1]);
}

int* wypelnij_tablice_wartoscia(int N, int w) {
   //deklaracja zmiennych
   int *t = (int*)malloc(N * sizeof(int));

   int i;
   //wsad danych do tablicy
   printf("Podaj %d liczb\n", N);
   for (i=0;i<N;++i)
   {
      t[i] = w;
   }

   return t;
}

int* wypelnij_tablice_od_uzytkownika(int N) {
   //deklaracja zmiennych
   int *t = (int*)malloc(N * sizeof(int));

   int i;
   //wsad danych do tablicy
   printf("Podaj %d liczb\n", N);
   for (i=0;i<N;++i)
   {
      scanf("%d", &t[i]);
   }

   return t;
}

int* wypelnij_tablice_losowo(int N) {
   //deklaracja zmiennych
   int *t = (int*)malloc(N * sizeof(int));

   int i;

   for(i=0;i<N;i++)
   t[i]=rand()% 100 + 1;

   return t;
}

// Zadanie 6.1
// Napisz trzy funkcje wypełniające i zwracające n-elementową tablicę liczb całkowitych:

// int* wypelnij_tablice_losowo(int n) - wartościami losowymi,
// int* wypelnij_tablice_od_uzytkownika(int n)- wartościami pobranymi od użytkownika,
// int* wypelnij_tablice_wartoscia(int n, int w) - wartością w.