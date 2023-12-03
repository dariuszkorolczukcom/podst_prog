#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_NAME_SZ 256

void wyznacz (int *tab, int n, int *ile_max, int *ile_min) {
   int i;
   ile_max = ile_min = tab[0];
   printf("w funkcji: %d, %d, %d\n", tab[0], tab[0], &tab[0]);
   printf("w funkcji: %d, %d, %d\n", ile_max, *ile_max, &ile_max);
   for (i=1;i<n;i++) {
      if(ile_max<&tab[i]) ile_max = &tab[i];
      if(ile_min>&tab[i]) ile_min = &tab[i];
   }

}

int main() {
   int n, i, j, *ile_max, *ile_min;
   // Napisz program, który po wczytaniu od użytkownika liczb do N-elementowej tablicy liczb całkowitych wypisze ją na ekran, a następnie obliczy i wyświetli na ekranie:

   // pobiera wielkosc tablicy
   printf("Podaj wielkość tablicy: ");
   scanf("%d",&n);
   if(n<=0) 
   {
      printf("\ntablica musi być większa niz 0\n");
      return 0;
   }

   //deklaracja zmiennych
   int t[n];

   //wsad danych do tablicy
   printf("Podaj %d liczb\n", n);
   for (i=0;i<n;++i)
   {
      scanf("%d", &t[i]);
   }

   //wyswietla tablice t
   printf("[%.d,",t[0]);
   for (i=1;i<n-1;++i)
   {
      printf("%d,", t[i]);
   }
   printf("%d]\n",t[n-1]);

   wyznacz(*t, n, ile_max, ile_min);
   printf("\nmax: %d, min: %d\n",*ile_max,*ile_min);

   return 0;
}

// Zadanie 5.6
// Napisz funkcję, która sprawdzi, czy k-elementowy ciąg znaków jest podciągiem drugiego n-elementowego ciągu. Obydwa ciągi znaków przekaż jako parametry funkcji.