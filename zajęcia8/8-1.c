#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct punkt {
float x, y;
};

void fill(struct punkt * p, int N);
int main() 
{
    int N;
    printf("Podaj liczbę punktow:");
    scanf("%d",&N);
    if(N<1) {
       printf("liczba nie moze byc mniejsza niz 1!\n");
       return 1;
    }
   //zainicjuj srand aby uywać czasu do losowania liczb
    int i; float x,y;
    struct punkt punkty[N];
    fill(punkty, N);
    for (i=0;i<N;++i)
    {
        printf("punkt numer: %d\nx: %.3f, y: %.3f\n",i+1,punkty[i].x,punkty[i].y);
    }
    return 0;
}

void fill(struct punkt * punkty, int N)
{
    int i; float x,y;
    for (i=0;i<N;++i)
    {
        scanf("%f %f",&x, &y);
        punkty[i].x = x;
        punkty[i].y = y;
    }
};


// Zadanie 8.1
// Dana jest następująca struktura:
// struct punkt {
// float x, y;
// };
// Napisz funkcję, która wypełni danymi pobranymi od użytkownika tablicę n punktów. Wskaźnik do tablicy oraz jej rozmiar przekaż jako argumenty funkcji.