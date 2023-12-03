#include <stdio.h>
#include <math.h>
#define N 5
float pole(float a, float b, float c);
int main() {

            float a,b,c;
            printf("Podaj długość boków trójkąta: ");
            scanf("%f %f %f",&a, &b, &c);
            if (a+b<=c || b+c<=a || a+c<=a || a<=0 || b<=0 || c<=0) {
               printf("figura nie jest trójkątem");
               return 1;
            }
   printf("pole trójkąta %.2f\n", pole(a,b,c));

   return 0;
}

float pole(float a, float b, float c) {
   float p;
   p=(a+b+c)/2.0;
   return sqrt(p*(p-a)*(p-b)*(p-c));

}

// Zadanie 4.3
// Napisz funkcję, która zwróci pole trójkąta. Długości boków trójkąta przekaż jako parametry funkcji.