#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct produkt {
    char nazwa[20];
    char kategoria[20];
    char producent[15];
    float waga;
    float cena;
} Produkt;

void isNull(FILE *f);
void wyswietl(Produkt * produkty, int n);
void wyswietlNajmniejszaIlosc(Produkt * produkty, int n);
void wyswietlSrednieKategorii(Produkt * produkty, int n);
float policzSrednia(Produkt * produkty, int n);
void wpiszDoPlikuWyzszeNizSrednia(Produkt * produkty, float srednia, int n);
void znajdzProduktProducenta(Produkt * produkty, int n, char * producent);

int main() {

    FILE *f; int i, n;
    Produkt * produkty;
    produkty = calloc(n, sizeof(Produkt)); 

    f = fopen("dane.txt", "r");
    isNull(f);
    fscanf(f, "%d",&n);
    for (i=1;i<=n;++i)
    {
        fscanf(f, "%20s %20s %15s %f %f",
        produkty[i].nazwa, 
        produkty[i].kategoria, 
        produkty[i].producent,
        &produkty[i].waga, 
        &produkty[i].cena);
    }
    fclose(f);

    wyswietl(produkty, n);
    printf("Napisz funkcję, która znajdzie i wyświetli na ekranie dane o produkcie, którego kupiono najmniej.\n");
    wyswietlNajmniejszaIlosc(produkty, n);
    printf("Napisz funkcję, która wyświetli na ekranie średnią wartość (cena*ilość) wszystkich produktów w każdej kategorii. Jeśli któraś kategoria nie zawiera produktów, nie wypisuj jej.\n");
    wyswietlSrednieKategorii(produkty, n);
    float sredniaCena = policzSrednia(produkty, n);
    printf("srednia cena: %.2f\n",sredniaCena);
    wpiszDoPlikuWyzszeNizSrednia(produkty, sredniaCena, n);
    char * producent[15];
    printf("Podaj nazwe producenta:");
    scanf("%s", producent);
    znajdzProduktProducenta(produkty, n, producent);
    
    return 0;
}

void isNull(FILE *f) {
    if (f == NULL) {
        perror("Nie udalo sie otworzyc pliku do odczytu");
        exit(1);
    }   
}

void wyswietl(Produkt * produkty, int n)
{
    int i;
    printf("%20s %20s %15s %3s %3s\n","nazwa","kategoria","producent","waga","cena");
    for (i=1;i<=n;++i)
    {
        printf("%20s %20s %15s %.2f %.2f\n",
        produkty[i].nazwa, 
        produkty[i].kategoria, 
        produkty[i].producent, 
        produkty[i].waga, 
        produkty[i].cena);
    }
    return;
}

void wyswietlNajmniejszaIlosc(Produkt * produkty, int n)
{
    int i, najmniej=1;
    printf("najmniej kupiono:\n%20s %20s %15s %3s %3s\n","nazwa","kategoria","producent","waga","cena");
    for (i=2;i<=n;++i)
    {
        if(produkty[i].waga<produkty[najmniej].waga) najmniej = i;
    }
    printf("%20s %20s %15s %.2f %.2f\n",
        produkty[najmniej].nazwa, 
        produkty[najmniej].kategoria, 
        produkty[najmniej].producent, 
        produkty[najmniej].waga, 
        produkty[najmniej].cena);
    return;
}

void wyswietlSrednieKategorii(Produkt * produkty, int n)
{
    int i, j, m=1;
    typedef struct kategoria
    {
        char nazwa[20];
        int liczba;
        float suma;
    } Kat;
    Kat * kategorie;
    kategorie = calloc(n, sizeof(Kat)); 
    
    strcpy(kategorie[0].nazwa, produkty[1].kategoria);
    kategorie[0].liczba = 1;
    kategorie[0].suma = produkty[1].cena*produkty[1].waga;

    for (i=2;i<=n;++i)
    {
        for (j=0;j<m;++j) 
        {
            if(strcmp(produkty[i].kategoria,kategorie[j].nazwa)==0)
            {
                kategorie[j].liczba++;
                kategorie[j].suma+=produkty[i].cena*produkty[i].waga;
                break;
            }
        }
        if(j==m) {
            strcpy(kategorie[j].nazwa, produkty[i].kategoria);
            kategorie[j].liczba = 1;
            kategorie[j].suma = produkty[i].cena*produkty[i].waga;
            ++m;
        }
    }
    for (j=0;j<m;++j) 
    {
        printf("%20s:  liczba: %2d, suma: %5.2f srednia: %.2f\n",
        kategorie[j].nazwa, 
        kategorie[j].liczba, 
        kategorie[j].suma,
        kategorie[j].suma/kategorie[j].liczba);

    }
    return;
}

float policzSrednia(Produkt * produkty, int n) {
    int i; float srednia, suma = 0.0;
    printf("%20s %20s %15s %3s %3s\n","nazwa","kategoria","producent","waga","cena");
    for (i=1;i<=n;++i)
    {
        suma += produkty[i].cena;
    }
    return suma/n;
}


void wpiszDoPlikuWyzszeNizSrednia(Produkt * produkty, float srednia, int n) {

    FILE *f; int i;
    f = fopen("ceny_wyzsze_niz_srednia.txt", "w"); 
    for (i=1;i<=n;++i)
    {
        if(produkty[i].cena>srednia)
            fprintf(f, "%20s %20s %15s %.2f %.2f\n",
            produkty[i].nazwa, 
            produkty[i].kategoria, 
            produkty[i].producent, 
            produkty[i].waga, 
            produkty[i].cena);
    }

    fclose(f);
    return;
}

void znajdzProduktProducenta(Produkt * produkty, int n, char * producent) {
    printf("%s", producent);
    int i, najwiecej=0; float ilosc = 0;
    for (i=1;i<=n;++i)
    {
        if(strcmp(produkty[i].producent,producent)==0)
        {
            printf("Halo\n");
            if(ilosc == 0) {
                ilosc = produkty[i].waga;
                najwiecej = i;
            } else if (ilosc < produkty[i].waga) {
                ilosc = produkty[i].waga;
                najwiecej = i;
            }
        }
    }
    printf("najwięcej produktu %15s %20s %.2f\n", 
            produkty[najwiecej].producent,
            produkty[najwiecej].nazwa, 
            produkty[najwiecej].waga);
    return;
}