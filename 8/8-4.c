/* Zadanie 8.4
 Korzystając z tablicy utworzonej w Zadaniu 8.1 napisz funkcję, która znajdzie i wyświetli na ekranie
 współrzędne punktu najbliższego do punktu danego jako parametr. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct punkt
{
    float x, y;
} Punkt;
void fillArray(Punkt *tab, int n);
void show(Punkt *tab, int n);
Punkt searchNearestPoint(Punkt *tab, int n, Punkt point);
double distance(Punkt p, Punkt q);
int main()
{
    int n = 0;
    while (n <= 0)
    {
        printf("Podaj rozmiar tablicy:\n");
        scanf("%d", &n);
    }
    Punkt *tab = calloc(n, n * sizeof(Punkt));
    fillArray(tab, n);
    show(tab, n);
    Punkt point;
    point.x = 1;
    point.y = 2;
    Punkt minPoint = searchNearestPoint(tab, n, point);
    printf("Najbliższy punkt: (%1.2f, %1.2f)", minPoint.x, minPoint.y);
    return 0;
}

void fillArray(Punkt *tab, int n)
{
    printf("Podaj elementy tablicy:\n");
    for (int i = 0; i < n; i++)
        scanf("%f, %f", &tab[i].x, &tab[i].y);
    return;
}

void show(Punkt *tab, int n)
{
    int i;
    printf("[ (%1.2f, %1.2f), ", tab[0].x, tab[0].y);
    for (i = 1; i < n - 1; i++)
        printf("(%1.2f, %1.2f), ", tab[i].x, tab[i].y);
    printf("(%1.2f, %1.2f) ]\n", tab[n - 1].x, tab[n - 1].y);
    return;
}

double distance(Punkt p, Punkt q)
{
    return abs(sqrt(pow(p.x - q.x, 2) + pow(p.y - q.y, 2)));
}

Punkt searchNearestPoint(Punkt *tab, int n, Punkt point)
{
    double minDistance = distance(tab[0], point);
    Punkt minPoint = tab[0];
    for (int i = 1; i < n; i++)
    {
        double currentDistance = distance(tab[i], point);
        if (currentDistance < minDistance)
        {
            minDistance = currentDistance;
            minPoint = tab[i];
        }
    }
    return minPoint;
}