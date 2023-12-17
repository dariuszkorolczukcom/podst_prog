#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct punkt {
    float x, y;
} Punkt;

void fill(Punkt * p, int N);
void show(Punkt * p, int N);
void radarF(Punkt * p, int N, Punkt radar, float R);
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
    radarF(punkty, N, radar, R);

   //zainicjuj srand aby uywać czasu do losowania liczb

    return 0;
}
void radarF(Punkt * punkty, int N, Punkt radar, float R)
{
    int i; float x,y;
        int closest = 0;
        float odl = 0;
    for (i=0;i<N;++i)
    {        
        float h = sqrtf(pow(punkty[i].x - radar.x, 2) + pow(punkty[i].y - radar.y,2));
        if (fabs(h)<odl || h == 0) {closest = i; odl = R-h;}
    }
        printf("Najblizszy punkt x: %.3f, y: %.3f\n",punkty[closest].x,punkty[closest].y);
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
// Zadanie 8.4
// Korzystając z tablicy utworzonej w Zadaniu 8.1 napisz funkcję, która znajdzie i wyświetli na ekranie współrzędne punktu najbliższego do punktu danego jako parametr.