#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct punkt {
    float x, y;
} Punkt;

void fill(Punkt * p, int N);
void show(Punkt * p, int N);
void radar(Punkt * p, int N, Punkt radar, float R);
int main() 
{
    int N; float R;
    printf("Podaj liczbę punktow:");
    scanf("%d",&N);
    if(N<1) {
       printf("liczba nie moze byc mniejsza niz 1!\n");
       return 1;
    }
    int i; float x,y;
    Punkt * punkty;
    punkty = calloc(N, sizeof(Punkt));
    fill(punkty, N);

    show(punkty, N);

    printf("Podaj polozenie radaru:");
    Punkt radar;
    scanf("%f %f",&radar.x,&radar.y);

    printf("Podaj R:");
    scanf("%f",&R);
    if(R<0) {
       printf("liczba nie moze byc mniejsza niz 0!\n");
       return 1;
    }
    radar(punkty, N, radar, R);

   //zainicjuj srand aby uywać czasu do losowania liczb

    return 0;
}
void radar(Punkt * p, int N, Punkt radar, float R)
{
    int i; float x,y;
    for (i=0;i<N;++i)
    {
        scanf("%f %f",&punkty[i].x, &punkty[i].y);
    }
    return;
};

void fill(Punkt * punkty, int N)
{
    int i; float x,y;
    for (i=0;i<N;++i)
    {
        scanf("%f %f",&punkty[i].x, &punkty[i].y);
    }
    return;
};
void show(Punkt * punkty, int N)
{
    int i; float x,y;
    for (i=0;i<N;++i)
    {
        printf("punkt numer: %d\nx: %.3f, y: %.3f\n",i+1,punkty[i].x,punkty[i].y);
    }
    return;
};

// Zadanie 8.3
// Korzystając z tablicy utworzonej w zadaniu 8.1 napisz funkcję, która wyświetli na ekran te punkty, które znajdują się w zasięgu radaru o współrzędnych struct punkt p oraz promieniu R. Wskaźnik do tablicy , jej rozmiar oraz dane dotyczące radaru przekaż jako argumenty funkcji.