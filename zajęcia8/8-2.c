#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct punkt {
float x, y;
};

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
    for (i=0;i<N;++i)
    {
        scanf("%f %f",&x, &y);
        punkty[i].x = x;
        punkty[i].y = y;
    }
    for (i=0;i<N;++i)
    {
        printf("punkt numer: %d\nx: %.3f, y: %.3f\n",i+1,punkty[i].x,punkty[i].y);
    }
    return 0;
}

// Zadanie 8.2
// Napisz funkcję, która wyświetli na ekranie tablicę punktów stworzoną w Zadaniu 8.1.