#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

int main() {
   int d, i, j, t[N];

   //wsad danych do tablicy
   printf("Podaj %d liczb\n", N);
   for (i=0;i<N;++i)
   {
      printf("podaj %d liczbe i kliknij enter ", i+1);
      scanf("%d", &d);
      for (j=0;j<i;j++) 
         if (d==t[j]) {
            break;
         }
      if(j!=i) {
         printf("Liczba %d juz znajduje sie w tablicy\n", d);
         --i;
         continue;
      }
      t[i] = d;
   }

   //wyswietla tablice t
   printf("[%.d,",t[0]);
   for (i=1;i<N-1;++i)
   {
      printf("%d,", t[i]);
   }
   printf("%d]\n",t[N-1]);

   return 0;
}

// Zadanie 3.12
// Napisz program, który wypełni tablicę o rozmiarze N liczbami całkowitymi wczytanymi od użytkownika. Upewnij się przy tym, że są to wartości unikalne (jeśli użytkownik wpisze wartość którą już wcześniej wprowadzał, wyświetl komunikat proszący o ponowne jej podanie).