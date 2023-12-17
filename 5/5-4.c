#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define MAX_NAME_SZ 256

int pierwiastki(float a, float b, float c, float *x1, float *x2) {
   float delta; int mz;
   delta = (b*b - 4*a*c);

   if (delta>0) {
      *x1 = (-b -sqrt(delta))/(2*a);      
      *x2 = (-b +sqrt(delta))/(2*a); 
      return 2;
   }
   if (delta==0) {
      *x1 = *x2 = -b/(2*a);
      return 1;
   }
   if (delta<0) return 0;
}
int main() {
   float a,b,c,x1,x2;
   if (a==0) return 1;
   // pobiera wielkosc tablicy
   printf("a b c: ");
   scanf("%f %f %f",&a,&b,&c);
   int mz = pierwiastki(a,b,c,&x1,&x2);
   if (mz == 2)printf("2 miejsca zerowe: %12.4f, %12.4f \n",x1,x2);
   if (mz == 1)printf("1 miejsce zerowe: %12.4f, \n",x1);
   if (mz == 0)printf("brak miejsc zerowych, \n");

   return 0;
}

// Zadanie 5.4
// Napisz funkcję int pierwiastki(float a, float b, float c, float *x1, float *x2), która przyjmuje jako parametry współczynniki równania kwadratowego i liczy jego pierwiastki - przez return zwracana jest liczba pierwiastków (0, 1 lub 2), zaś w parametrach x1 oraz x2 zwracamy ich wartości.