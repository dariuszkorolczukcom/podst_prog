#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
   int n = 5, i;
   int j, k, l;
   srand(time(NULL));
   char c;
   //wczytanie przedziału
   printf("Podaj przedział ");
   scanf("%d",&j);
   scanf("%d",&k);
   if (j>k) {
      l = j;
      j = k;
      k = l;
   }
   int t[n];
   for (i=0;i<n;++i)
   {
      t[i] = rand() % (k-j+1) + j-3;
      printf("t[i]: %d ", t[i]);
      t[i] += 3 - t[i] % 3;
      if (t[i]<j) t[i]+=3;
      printf("t[i]: %d\n", t[i]);
   }
   printf("Tablica : [%d,",t[0]);
   for (i=1;i<n-1;++i)
   {
      printf("%d,", t[i]);
   }
   printf("%d]\n",t[n-1]);

   for (i=1;i<n;++i)
   {
      if (t[i]>t[i-1]) break;
   }
   if (i==n) 
      printf("Liczby są w porządku malejącym\n");
   else 
      printf("Liczby nie są w porządku malejącym\n");

   return 0;
}

// Zadanie 3.11
// Napisz program, który wypełnia tablicę o rozmiarze N całkowitymi liczbami losowymi podzielnymi przez 3 pochodzącymi z przedziału <a, b>. Wartości a i b wczytaj od użytkownika (program powinien działać również wtedy, gdy użytkownik poda a>b).  Wypełnioną tablicę wypisz na ekranie. Sprawdź i wyświetl informację, czy wylosowane liczby są w tablicy w porządku malejącym.