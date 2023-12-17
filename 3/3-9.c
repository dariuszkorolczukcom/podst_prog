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
   int t[n], u[n];

   //wsad danych do tablicy
   printf("Podaj %d liczb\n", n);
   for (i=0;i<n;++i)
   {
      scanf("%d", &t[i]);
   }

   for (i=0;i<n;++i)
   {
      int sum = 0;
      for (j=0;j<=i;j++) 
      {
         if (j % 2 == 0) sum+=t[j];
         else sum-=t[j];
         printf("i: %d, j: %d, t[j]: %d, sum: %d, bool: %d\n", i, j, t[j], sum, j % 2);
      }
      u[i] = sum;
   }

   //wyswietla tablice t
   printf("[%.d,",t[0]);
   for (i=1;i<n-1;++i)
   {
      printf("%d,", t[i]);
   }
   printf("%d]\n",t[n-1]);


   //wyswietla tablice u
   printf("[%.d,",u[0]);
   for (i=1;i<n-1;++i)
   {
      printf("%d,", u[i]);
   }
   printf("%d]\n",u[n-1]);

   return 0;
}

// Zadanie 3.9
// Napisz program, który na podstawie tablicy liczb całkowitych tabA (rozmiar i wartości podawane są przez użytkownika) stworzy tablicę tabB wg następującego wzoru: tabB[i]=tabA[0]-tabA[1]+tabA[2]-...tabA[i].

