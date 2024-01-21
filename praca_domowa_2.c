#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int filtruj(int *tab, int N, int *tab_2) {
    int i, j, k = 0, unikalne = 0;
    for (i=0;i<N;i++) {
        int unikalna = 1;
        for (j=0;j<N;j++) {
            if (tab[i]==tab[j] && i!=j) unikalna = 0;
        }
        printf("unikalna:%d, i:%d, j:%d, liczba:%d\n",unikalna,i,j,tab[i]);
        if (unikalna == 1) {
            ++unikalne;
            tab_2[k] = tab[i];
            ++k;
        }
    }
    return unikalne;
}

int main() {

    //deklaracja zmiennych
    int N, i;

    // pobiera wielkosc tablicy
    printf("Podaj wielkość tablicy: ");
    scanf("%d",&N);
    if(N<=0) 
    {
        printf("\ntablica musi mieć liczbę wierszy większą od 0\n");
        return 0;
    }

    //deklaracja tablic
    int *tab = (int*)calloc(N,sizeof(int));
    int *tab_2 = (int*)calloc(N,sizeof(int));

    //zainicjuj srand aby uywać czasu do losowania liczb
    srand(time(NULL));

    //wsad danych do tablicy
    for (i=0;i<N;++i)
    {
            int random = rand() % 10 +1;
            tab[i] = random;
    }

    int unikalne = filtruj(tab, N, tab_2);

    //wyswietla tablice wejsciowa
    printf("[%.d,",tab[0]);
    for (i=1;i<N-1;++i)
    {
        printf("%d,", tab[i]);
    }
    printf("%d]\n",tab[N-1]);

    //wyswietla tablice wynikowa
    printf("[%.d,",tab_2[0]);
    for (i=1;i<N-1;++i)
    {
        if (tab_2[i+1]==0) {
            printf("%d]\n",tab_2[i]);
            break;
        }
        printf("%d,", tab_2[i]);
    }

    printf("liczby unikalne: %d\n", unikalne);
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