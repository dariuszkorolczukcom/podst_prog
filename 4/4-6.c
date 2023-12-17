#include <stdio.h>

int sum(int min, int max);
int sum1(int min, int max);
int sum2(int min, int max);
int sum3(int min, int max);

int main() {
   int min, max;
   printf("Podaj liczbę przedział ");
   scanf("%d %d", &min, &max);
   printf("suma wszystkich liczb: %d\n", sum(min,max));
   printf("suma wszystkich liczb parzystych: %d\n", sum1(min,max));
   printf("suma wszystkich liczb podzielnych przez 3: %d\n", sum2(min,max));
   printf("suma wszystkich liczb takich, że suma aktualnej liczby i jej następnika jest podzielna przez 3: %d\n", sum3(min,max));
   return 0;
}

int sum(int min, int max) {
   int i, sum = 0;
   for (i=min;i<=max;++i) sum += i;
   return sum;
}

int sum1(int min, int max) {
   int i, sum = 0;
   for (i=min;i<=max;++i) if(i%2==0) sum += i;
   return sum;
}

int sum2(int min, int max) {
   int i, sum = 0;
   for (i=min;i<=max;++i) if(i%3==0) sum += i;
   return sum;
}

int sum3(int min, int max) {
   int i, sum = 0;
   for (i=min;i<=max;++i) if((i+1+1)%3==0) sum += i;
   return sum;
}

// Zadanie 4.6
// Napisz cztery warianty funkcji int sum(int min, int max), która oblicza sumę liczb z przedziału <min, max>:
// - sumuje wszystkie liczby,
// - sumuje tylko liczby parzyste,
// - sumuje tylko liczby podzielne przez 3,
// - sumuje tylko takie, że suma aktualnej liczby i jej następnika jest podzielna przez 3.