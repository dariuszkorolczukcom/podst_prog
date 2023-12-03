#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int minimum (int, int), maximum (int, int), isSmaller (int, int, float);

int main() {
   int n = 30, i;
   int j, k, l;
   srand(time(NULL));
   do {
   printf("Podaj wielkość zakresu ");
   scanf("%d",&j);
   scanf("%d",&k);
   } while (j>=k);
   int t[n], sum = 0, min, max;
   float sr;
   int av;

   l = k - j;
   t[0] = rand() % (k-j+1) + j;
   sum+=t[0];
   min = max = t[0];
   for (i=1;i<n;++i)
   {
      t[i] = rand() % (k-j+1) + j;
      sum+=t[i];
      min = minimum (min,t[i]);
      max = maximum (max,t[i]);
   }
   printf("Tablica : [%d,",t[0]);
   for (i=1;i<n-1;++i)
   {
      printf("%d,", t[i]);
   }
   printf("%d]\n",t[n-1]);
   sr = 1.0*sum/n;
   av = t[0];
   for (i=1;i<n;++i)
   {
      av = isSmaller(t[i-1], av, sr);
   }
   printf("średnia: %f\n", sr);
   printf("najblisza średniej: %d\n", av);
   printf("min: %d, max: %d\n", min,max);

   return 0;
}

int isSmaller(int x, int y, float sr) {
   if (fabs(fabs((sr)) - (float)abs(x)) < fabs(fabs((sr)) - (float)abs(y))) return x;
   else return y;
}

int minimum (int x, int y) {
   if (x<y)
      return x;
   else
      return y;
}
int maximum (int x, int y) {
   if (x>y)
      return x;
   else
      return y;
}

// Zadanie 3.2
// Napisz program, który wygeneruje tablicę liczb losowych z podanego przez użytkownika zakresu, a następnie
// znajdzie minimum i maksimum
// obliczy średnią arytmetyczną wszystkich elementów tablicy,
// znajdzie element średni (najbliższy średniej arytmetycznej).