#include <stdio.h>
int main() {
   float x;
   printf("Podaj x ");
   scanf("%f",&x);

   int n;
   printf("Podaj n ");
   scanf("%d",&n);

   int i;
   float suma = 0;
   for (i=1;i<=n;++i)
   {
         suma += 1/(x*(float)i);
   }
   printf("suma ciągu liczb  1/x + 1/x2 + 1/x3 + 1/x4 + ... + 1/xn dla x = %f oraz n = %d to %f\n",x,n,suma);
   return 0;
}
// Zadanie 2.3
// Napisz program, który dla podanych x oraz n wyznaczający iteracyjnie sumę szeregu:
// 1/x + 1/x2 + 1/x3 + 1/x4 + ... + 1/xn.