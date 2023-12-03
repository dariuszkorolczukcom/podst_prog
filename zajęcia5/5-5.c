#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_NAME_SZ 256

void odwroc(int t[], int n) {
   int i, t2[n];

   for (i=0;i<n/2;i++) {
      int a = t[i];
      t[i] = t[n-i-1];
      t[n-i-1] = a;
   }
   // for (i=0;i<n;i++) {
   //    t[i] = t2[n-i-1];
   // }
}

int main() {
   int n, i;

   // pobiera wielkosc tablicy
   printf("Podaj wielkość tablicy: ");
   scanf("%d",&n);
   if(n<=0) 
   {
      printf("\ntablica musi być większa niz 0\n");
      return 0;
   }

   //deklaracja zmiennych
   int *t = (int*)calloc(n,sizeof(int));

   //wsad danych do tablicy
   printf("Podaj %d liczb\n", n);
   for (i=0;i<n;++i)
   {
      scanf("%d", &t[i]);
   }

   // //wyswietla tablice t
   printf("[%.d,",t[0]);
   for (i=1;i<n-1;++i)
   {
      printf("%d,", t[i]);
   }
   printf("%d]\n",t[n-1]);

   odwroc(t, n);
   // //wyswietla tablice t
   printf("[%.d,",t[0]);
   for (i=1;i<n-1;++i)
   {
      printf("%d,", t[i]);
   }
   printf("%d]\n",t[n-1]);

   return 0;
}

// Zadanie 5.5
// Napisz funkcję void odwroc(int t[], int n), która będzie odwracała kolejność elementów w przekazanej tablicy. Po jej wykonaniu ostatni element tablicy będzie pierwszym, przedostatni drugim, itd.