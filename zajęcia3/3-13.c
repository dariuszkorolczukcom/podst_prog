#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define N 10

float minimum (float, float, int, int), maximum (float, float, int, int);

int main() {
   int n = N, i;
   int j, min, max;
   srand(time(NULL));
   float t[n];

   t[0] = (float)rand()/(float)RAND_MAX;
   min = max = 0;
   for (i=1;i<n;++i)
   {
      t[i] = (float)rand()/(float)RAND_MAX;
      min = minimum (t[min],t[i], min, i);
      max = maximum (t[max],t[i], max, i);
   }
   printf("Tablica : [%.5f,",t[0]);
   for (i=1;i<n-1;++i)
   {
      printf("%.5f,", t[i]);
   }
   printf("%.5f]\n",t[n-1]);
   printf("pozycja min: %d, pozycja max: %d\n", min+1,max+1);

   return 0;
}

float minimum (float x, float y, int min, int i) {
   if (x<y)
      return min;
   else
      return i;
}
float maximum (float x, float y, int max, int i) {
   if (x>y)
      return max;
   else
      return i;
}

// Zadanie 3.13
// Napisz program, który wypełni tablicę o rozmiarze N losowymi liczbami rzeczywistymi z przedziału <0,1> a następnie wypisze pozycje pary liczb, dla której wartość bezwzględna ich różnicy jest największa.