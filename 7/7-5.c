#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void znajdzMinMax(FILE *f,int *min,int *max);

int main(int argc, char *argv[])
{
    char nazwa[50];
    printf("Podaj nazwe pliku: ");
    scanf("%s",nazwa);

    FILE *f; int min, max;
    f = fopen(nazwa, "r");
    
    if (f == NULL) {
        perror("Nie udalo sie otworzyc pliku do odczytu");
        // TODO: wlasciwie wyrzucic blad
        exit(1);
    }

    znajdzMinMax(f, &min, &max);

    printf("min: %d, max: %d\n", min, max);
    fclose(f);
    
    return 0;
}

void znajdzMinMax(FILE *f,int *min,int *max) {
    FILE *ujemne, *dodatnie; int i;
    // todo : sprawdz czy plik nie jest pusty
    *min = *max =fscanf(f, "%d", &i);
    while ((fscanf(f, "%d", &i)) != EOF)
    {
        if (i>*max)
            *max = i;
        else if (i<*min)
            *min = i;
    }
    return;
}

// Zadanie 7.5
// Dany jest plik zawierający liczby całkowite. Napisz funkcję, która znajdzie i zwróci wartość minimalną i wartość maksymalną spośród wartości w pliku. Ścieżkę dostępu do pliku przekaż jako parametry funkcji.