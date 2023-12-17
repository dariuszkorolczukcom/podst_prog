#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int srednia(const char *nazwa);
int wieksze_niz_srednia(const char *nazwa, int srednia);
int main(int argc, char *argv[])
{
    char nazwa[50];
    printf("Podaj nazwe pliku: ");
    scanf("%s",nazwa);

    int a = srednia(nazwa);
    printf("wieksze niz srednia: %d\n",a);
    // int b = wieksze_niz_srednia(nazwa,a);
    // printf("wieksze niz srednia: %d\n",b);
    //TODO: kontrola danych
    return 0;
}

int srednia(const char *nazwa) {

    FILE *f; int i, j=0, l=0, sr, no;
   int *t = (int*)calloc(100,sizeof(int));
    f = fopen(nazwa, "r");
    
    if (f == NULL) {
        perror("Nie udalo sie otworzyc pliku do odczytu");
        // TODO: wlasciwie wyrzucic blad
        exit(1);
    }
    //feof(f) - is end of file
    while ((fscanf(f, "%d", &i)) != EOF)
    {
        printf("no: %d, i: %d, j: %d\n",no,i,j);
        no+=i;
        t[j] = i;
        ++j;
    }
    // TODO: rewind
    sr=no/j;
    for (;j>0;--j) if (t[j]>sr) l++;
    // printf("no: %d, i: %d, j: %d, sr: %d\n",no,i,j,sr);
    fclose(f);
    return l;
}

int wieksze_niz_srednia(const char *nazwa, int srednia) {

    FILE *f; int i, j=0;
    f = fopen(nazwa, "r");
    
    if (f == NULL) {
        perror("Nie udalo sie otworzyc pliku do odczytu");
        // TODO: wlasciwie wyrzucic blad
        exit(1);
    }
    //feof(f) - is end of file
    while ((fscanf(f, "%d", &i)) != EOF)
    {
        if (i>srednia) ++j;
        printf("i: %d, j: %d\n, srednia: %d",i,j, srednia);
    }
    
    fclose(f);
    return j;
}

// Zadanie 7.3
// Dany jest plik zawierający liczby całkowite. Napisz funkcję, która wyznaczy i zwróci liczbę wartości większych od średniej arytmetycznej wszystkich wartości w pliku. Ścieżkę dostępu do pliku przekaż jako parametry funkcji.