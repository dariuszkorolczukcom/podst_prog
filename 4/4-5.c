#include <stdio.h>
#include <math.h>
float show(float x, int s);
int main() {
   float x;
   int n;
   printf("Podaj x i n: ");
      if(n<1) {
         printf("nieprawidłowa wartość liczby n!\n");
      return 1;
   }
   scanf("%f %d",&x, &n);
   printf("suma = %.2f", show(x,n));
   return 0;
}

float show(float x, int n) {
   float sum = 0;
   int i;

   for (i=1;i<=n;++i)
      if (i%2==1) sum += pow(x,i) + i;
         else sum -= pow(x,i) - i;
   return sum;
}

// Zadanie 4.5
// Napisz funkcję float suma(float x, int n), która wyznaczy sumę szeregu: (x+1)-(x2-2)+(x3+3)-...±(xn±n).