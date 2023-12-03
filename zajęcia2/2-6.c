#include <stdio.h>
int main() {
   int iloczyn = 1;
   int i;

      int n;
      printf("Podaj liczbę ");
      scanf("%d",&n);
      if(n==0) 
      {
         printf("iloczyn podanych liczb to 0");
         return 0;
      }
   for (;;)
   {
      iloczyn *= n;
      printf("Podaj liczbę ");
      scanf("%d",&n);
      if(n==0) 
      {
         break;
      }
   }
   printf("iloczyn podanych liczb to %d\n",iloczyn);
   return 0;
}
// Zadanie 2.6
// Napisz program, który wczytuje liczby całkowite podane przez użytkownika aż do momentu podania wartości 0, a następnie wyświetla ich iloczyn. Zero kończące podawanie danych nie może być uwzględniane w wyniku.