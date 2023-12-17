#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20
// #define m 10

int main() {
   int m; //deklarowanie zmiennej
   printf("Podaj gorną granicę zakresu: ");
   scanf("%d",&m);
   if (m<=1) 
   {
      printf("Podałeś gorną granicę mniejszą od 1");
      return 0;
   }
   int i;
   int t[N];
   int u[m+1];
   i=0;
   while (i<m+1) {
      u[i]=0;
      i++;
   }
   //zainicjuj srand aby uywać czasu do losowania liczb
   srand(time(NULL));
   for (i=0;i<N;++i)
   {
      float random = rand() % m +1;
      t[i] = (int)random;
      u[t[i]]++;
   }

   //wyswietla tablice
   printf("Tablica : [%d,",t[0]);
   for (i=1;i<N-1;++i)
   {
      printf("%d,", t[i]);
   }
   printf("%d]\n",t[N-1]);
   printf("wynik: ");
   for (i=1;i<m+1;++i)
   {
      if(u[i]==1) printf("%d-%d raz;",i, u[i]);
      if(u[i]>1) printf("%d-%d razy;",i, u[i]);
   }
   return 0;
}

// Zadanie 3.4
// Napisz program, który wylosuje do tablicy N liczb z przedziału 1...M (M podawane jest przez użytkownika) i wypisze na ekran wylosowane elementy oraz policzy liczność każdego z nich.
// Przykład:
// N=10, M=6,
// tablica: 1 4 2 4 6 3 1 2 2 1
// wynik: 1-3 razy; 2-3 razy; 3-1 raz; 4-2 razy; 5-0 razy; 6-1 raz