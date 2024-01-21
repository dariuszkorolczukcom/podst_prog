#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    //deklaracja zmiennych
    int N, M, i, j, poprzednia = 0;

    // pobiera wielkosc tablicy
    printf("Podaj wielkość tablicy: ");
    scanf("%d %d",&N, &M);
    if(N<=0 || M<=0) 
    {
        printf("\ntablica musi mieć liczbę wierszy i liczbę kolumn większą od 0\n");
        return 0;
    }

    //deklaracja tablicy
    int t[N][M];

   //zainicjuj srand aby uywać czasu do losowania liczb
   srand(time(NULL));

   //wsad danych do tablicy
   for (i=0;i<M;++i)
   {
    for (j=0;j<N;++j) {
        int wiersz;
        if (i%2 == 0) wiersz = j;
        else wiersz = N - 1 - j;
        int random = rand() % 10 +1;
        t[wiersz][i] = poprzednia + random;
        poprzednia = t[wiersz][i];
    }
   }

   //wyswietla tablice t
   for (i=0;i<N;++i)
   {
      printf("[");
      for (j=0;j<M;++j)
      {
         if (j==M-1)
         printf("%3d",t[i][j]);
         else
         printf("%3d,",t[i][j]);
      }
      printf("]\n");
   }

   return 0;
}

// Zestaw 4
// 1.     Zadeklaruj tablicę liczb całkowitych o N wierszach i M kolumnach (wymiary tablicy wczytaj od użytkownika). Następnie wypełnij ją rosnącym ciągiem losowych wartości w sposób przedstawiony na załączonym przykładzie (w formie węża w góry na dół i z powrotem). Tak stworzoną tablicę wypisz na ekranie.
// Przykład:
//  2 25 29 70
// 11 22 35 66
// 17 18 48 63
// 2.     Napisz funkcję, która kopiuje wartości występujące tylko raz z jednowymiarowej tablicy liczb całkowitych o rozmiarze n do drugiej tablicy jednowymiarowej.  Pierwszą tablicę, jej rozmiar oraz drugą tablicę przekaż przez parametry funkcji. Jako wartość funkcji zwróć ilość skopiowanych pozycji. Możesz założyć, że druga tablica ma taki sam rozmiar jak pierwsza, a niewykorzystane pozycje w drugiej tablicy można pozostawić bez zmian. Dołącz również program pokazującu działanie funkcji.
// Przykład:
// pierwsza tablica = [1,4,3,3,1], rozmiar: 5
// druga tablica po wywołaniu funkcji = [4], wartość funkcji = 1