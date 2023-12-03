#include <stdio.h>
int main() {
   int n, i, j;
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

   j=t[n-1];
   for (i=n-1;i>0;--i)
   {
   printf("i: %d, j: %d, t[i]: %d\n", i, j, t[i]);
   t[i] = t[i-1];
   }
   t[0] = j;

   //wyswietla tablice t po przekształceniu
   printf("[%.d,",t[0]);
   for (i=1;i<n-1;++i)
   {
      printf("%d,", t[i]);
   }
   printf("%d]\n",t[n-1]);

   return 0;
}

// Zadanie 3.10
// Napisz program, który przesunie zawartość N-elementowej tablicy (rozmiar tablicy podawany jest przez użytkownika) cyklicznie o jedną pozycję „w górę”. (tzn. pierwszy element na miejsce drugiego, drugi na miejsce trzeciego, ..., ostatni na miejsce pierwszego).