#include <stdio.h>
#define N 5
int main() {
   int wodk = 0, n=N, i, k, suma = 0, sumaplus = 0, sumak = 0, sumanp = 0;
   printf("Podaj liczbę k ");
   scanf("%d",&k);
   int t[n];
   if(n==0) 
   {
      printf("wielkosc tablicy musi byc wieksza od 0");
      return 0;
   }
   for (i=0;i<n;++i)
   {
      printf("Podaj %d liczbę ", i+1);
      scanf("%d", &t[i]);
      suma += t[i];
      if(t[i]>0) sumaplus += t[i];
      if(t[i]>k && t[i]!=0) {
         sumak += t[i];
         ++wodk;
      }
      if(t[i]%2==1 || t[i]%2==-1) sumanp += t[i];
   }
   printf("[%d,",t[0]);
   for (i=1;i<n-1;++i)
   {
      printf("%d,", t[i]);
   }
   printf("%d]\n",t[n-1]);
   printf("suma wszystkich liczb %d\n", suma);

   if(sumaplus==0) printf("Brak liczb dodatnich\n");
   else printf("suma liczb dodatnich: %d\n",sumaplus);

   if(wodk==0) printf("Brak liczb wiekszych od %d\n",k);
   else printf("suma liczb większych od %d: %d\n",k,sumak);

   if(sumanp==0) printf("Brak liczb nieparzystych\n");
   else printf("suma liczb nieparzystych: %d\n",sumanp);
   return 0;
}

// Zadanie 3.1
// Napisz program, który po wczytaniu od użytkownika liczb do N-elementowej tablicy liczb rzeczywistych wypisze ją na ekran, a następnie obliczy i wyświetli na ekranie:
// sumę wszystkich liczb,
// sumę wszystkich liczb dodatnich,
// sumę wszystkich liczb większych od k (k wczytaj od użytkownika),
// sumę elementów o indeksach nieparzystych.
// W przypadku, gdy nie ma wartości spełniających zadane kryteria, program powinien wyświetlić stosowny komunikat.