#include <stdio.h>

int minimum (int, int), maximum (int, int);

int main() {
   int n, i, j=0;
   // Napisz program, który po wczytaniu od użytkownika liczb do N-elementowej tablicy liczb całkowitych wypisze ją na ekran, a następnie obliczy i wyświetli na ekranie:

   // pobiera wielkosc tablicy
   printf("Podaj wielkość tablicy: ");
   scanf("%d",&n);
   if(n<=0) 
   {
      printf("\ntablica musi być większa niz 0\n");
      return 0;
   }

   //deklaracja zmiennych
   int t[n], sum = 0, minnp, maxp;

   //wsad danych do tablicy
   printf("Podaj %d liczb\n", n);
   for (i=0;i<n;++i)
   {
      scanf("%d", &t[i]);
   }

   //wyswietla tablice
   printf("Tablica : [%.d,",t[0]);
   for (i=1;i<n-1;++i)
   {
      printf("%d,", t[i]);
   }
   printf("%d]\n",t[n-1]);

   // największą wartość spośród elementów parzystych,
   int parzysta = 0;
   i=0;
   while(i<n) {
      if (t[i]%2==0)
      {
         parzysta = t[i];
         break;
      }
      ++i;
   }
   if (i==n) printf("\nbrak parzystych\n");
   else {
      for (i=0;i<n;++i)
      {
         if (t[i]%2==0 && t[i]>parzysta)
         {
            parzysta = t[i];
         }
      }
      printf("\nnajwieksza parzysta: %d\n",parzysta);
   }

   // najmniejszą wartość spośród elementów nieparzystych,
   int nparzysta = 0;
   i=0;
   while(i<n) {
      if (t[i]%2!=0)
      {
         nparzysta = t[i];
         break;
      }
      ++i;
   }
   if (i==n) printf("\nbrak nieparzystych\n");
   else {
      for (i=0;i<n;++i)
      {
         if (t[i]%2==1 && t[i]<nparzysta)
         {
            nparzysta = t[i];
         }
      }
      printf("\nnajmniejsza nieparzysta: %d\n",nparzysta);
   }

   // średnią arytmetyczną elementów mieszczących się w przedziale <a, b> (wartości a i b wczytaj od użytkownika),
   int a,b,sredniaab=0;
   printf("Podaj przedział <a, b> ");
   scanf("%d",&a);
   scanf("%d",&b);
   i=0;
   while(i<n) {
      if (t[i]>=a && t[i]<=b)
      {
         break;
      }
      ++i;
   }
   if (i==n) printf("\nbrak liczb w podanym przedziale\n");
   else {
      i=0;
      j=0;
      while(i<n) {
         if (t[i]>=a && t[i]<=b)
         {
            sredniaab += t[i];
            ++j;
         }
         ++i;
      }
   }
   printf("\nśrednia w przedziale <%d, %d>: %f\n", a,b, (float)sredniaab/(float)j);

   // średnią arytmetyczną elementów podzielnych przez x (x wczytaj od użytkownika),
   int x,sredniax=0;
   printf("Podaj x ");
   scanf("%d",&x);
   i=0;
   while(i<n) {
      if (t[i]%x == 0)
      {
         break;
      }
      ++i;
   }
   if (i==n) printf("\nbrak liczb podzielnych przez x\n");
   else {
      i=0;
      j=0;
      while(i<n) {
         if (t[i]%x == 0)
         {
            sredniax += t[i];
            ++j;
         }
         ++i;
      }
   }
   printf("\nśrednia liczb podzielnych przez %d: %f\n", x, (float)sredniax/(float)j);

   // średnią arytmetyczną elementów o indeksach parzystych.
   int srednia2=0;
   i=0;
   while(i<n) {
      if (t[i]%2 == 0)
      {
         break;
      }
      ++i;
   }
   if (i==n) printf("\nbrak liczb  parzystych\n");
   else {
      i=1;
      j=0;
      while(i<n) {
         srednia2 += t[i];
         ++j;
         i+=2;
      }
   }
   printf("\nśrednia liczb o indeksach parzystych: %f\n", (float)srednia2/(float)j);

   return 0;
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

// Zadanie 3.3

// W przypadku, gdy nie ma wartości spełniających zadane kryteria, program powinien wyświetlić stosowny komunikat.