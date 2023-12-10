#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void podziel(FILE *f, FILE *ujemne, FILE *dodatnie);

int main(int argc, char *argv[])
{
    char nazwa[50]; FILE *f, *ujemne, *dodatnie; int i, j=0, l=0, sr, no;

    printf("Podaj nazwe pliku: ");
    scanf("%s",nazwa);
    f = fopen(nazwa, "r");
    printf("Podaj nazwe pliku do zapisu liczb ujemnych: ");
    scanf("%s",nazwa);
    ujemne = fopen(nazwa, "w");

    printf("Podaj nazwe pliku do zapisu liczb dodatnich: ");
    scanf("%s",nazwa);
    dodatnie = fopen(nazwa, "w");

    
    if (f == NULL) {
        perror("Nie udalo sie otworzyc pliku do odczytu");
        // TODO: wlasciwie wyrzucic blad
        exit(1);
    }

    podziel(f, ujemne, dodatnie);
    fclose(f);
    fclose(dodatnie);
    fclose(ujemne);
    
    return 0;
}

void podziel(FILE *f, FILE *ujemne, FILE *dodatnie) {
    int i;
    while ((fscanf(f, "%d", &i)) != EOF)
    {
        if (i>0)
            fprintf(dodatnie, "%d\n", i);
        else if (i<0)
            fprintf(ujemne, "%d\n", i);
    }
    return;
}

// 7.4
// Dany jest plik zawierający liczby całkowite. Napisz funkcję, która rozdzieli te liczby do dwóch plików w taki sposób, że w jednym znajdą się liczby ujemne a w drugim dodatnie. PLIK przekaż jako parametry funkcji.