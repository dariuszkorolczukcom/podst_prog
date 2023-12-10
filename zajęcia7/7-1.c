#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void wpisz_do_pliku(const char *nazwa, int n, int a, int b);

int main(int argc, char *argv[])
{
    int N, a, b; char nazwa[50];
    printf("Podaj nazwe pliku: ");
    scanf("%s",nazwa);
    printf("Podaj ilość liczb: ");
    scanf("%d",&N);
    printf("Podaj przedzial: ");
    scanf("%d %d",&a,&b);

    wpisz_do_pliku(nazwa, N, a, b);
    //TODO: kontrola danych
    return 0;
}

void wpisz_do_pliku(const char *nazwa, int n, int a, int b) {

    FILE *f; int i;
    f = fopen(nazwa, "w");
    //TODO: nie ma potrzeby sprawdzania
    // if (f == NULL) {
    //     perror("Nie udalo sie otworzyc pliku do zapisu");
    //     return;
    // }   
   for (i=1;i<=n;++i)
   {
      int random = rand() % (b-a) + a;
      fprintf(f, "%d\n", random);
   }

    fclose(f);
    return;
}

// Zadanie 7.1
// Napisz funkcję void wpisz_do_pliku(const char *nazwa, int n, int a, int b), która zapisze do pliku tekstowego n losowych wartości z przedziału [a, b] każdą z nich umieszczając w nowej linii. Ścieżkę dostępu do pliku przekaż jako parametry funkcji.