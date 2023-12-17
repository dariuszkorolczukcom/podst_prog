#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ile_parzystych(const char *nazwa);

int main(int argc, char *argv[])
{
    char nazwa[50];
    printf("Podaj nazwe pliku: ");
    scanf("%s",nazwa);

    int a = ile_parzystych(nazwa);
    printf("liczb parzystych: %d\n",a);
    //TODO: kontrola danych
    return 0;
}

int ile_parzystych(const char *nazwa) {

    FILE *f; int i, l=0;
    f = fopen(nazwa, "r");
    
    if (f == NULL) {
        perror("Nie udalo sie otworzyc pliku do odczytu");
        // TODO: wlasciwie wyrzucic blad
        exit(1);
    }
    while ((fscanf(f, "%d", &i)) != EOF)
    {
        if (i%2==0)
            ++l;
    }

    fclose(f);
    return l;
}

// Zadanie 7.2
// Dany jest plik zawierający liczby całkowite. Napisz funkcję, która wyznaczy i zwróci liczbę wartości parzystych znajdujących się w tym pliku. Ścieżkę dostępu do pliku przekaż jako parametry funkcji.