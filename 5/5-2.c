#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_NAME_SZ 256

void wyznacz(int *tab, int n, int *ile_max, int *ile_min) {
   int i, min, max;
   min = max = tab[0];
   *ile_max = * ile_min = 1;
   for (i=1;i<n;i++) {
      if(max<tab[i]) {
         max = tab[i];
         *ile_max=0;
      }
      if(min>tab[i]) {
         min = tab[i];
         *ile_min=0;
      }
      if(min==tab[i]) ++(*ile_min);
      if(max==tab[i]) ++(*ile_max);
   }
}

int main() {
   int n, i, j, ile_max , ile_min;

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

   wyznacz(t, n, &ile_max, &ile_min);
   printf("\nmax: %d, min: %d\n",ile_max,ile_min);

   return 0;
}

// Zadanie 5.1
// napisz funkcje void wyznacz (int *tab, int n, int *ile_max, int *ile_min), która dla tablicy liczb całkowitych dane jako parametr obliczy i zwróci informację ile razy w tablicy występuje wartość maksymalna i ile razy występuje wartość