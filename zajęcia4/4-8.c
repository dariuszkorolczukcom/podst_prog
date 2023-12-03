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

// Zadanie 4.8
// Napisz zestaw funkcji do obsługi tablic dwuwymiarowych:
// - funkcję wypełniającą tablicę wartościami pobranymi od użytkownika,
// - funkcję wypełniającą tablicę wg schematu:
//     + w pierwszym wierszu tablicy mogą znaleźć się liczby z przedziału <1; 10>
//     + w drugim wierszu z przedziału <min pierwszego wiersza; min pierwszego wiersza+10>,
//     + w trzecim z przedziału <min drugiego wiersza; min drugiego wiersza+ 10>,
//     + itd...
// - funkcję wyświetlającą tablicę na ekranie (każdy wiersz w nowej linii),
// - funkcję wyznaczającą średnią arytmetyczną wszystkich elementów w tablicy,
// - funkcję wyznaczającą ile elementów (liczonych wierszami) tablicy) przekracza graniczną wartość k przekazaną w parametrze.
// Parametrami każdej z tych funkcji jest dwuwymiarowa tablica typu całkowitego oraz jej rozmiar.