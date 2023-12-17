#include <stdio.h>
int main() {
   int suma = 0;
   int i;
   int cegly;
   for (cegly=15;cegly>0;cegly--)
   {
      int n;
      suma += cegly*2;
   }
   printf("ściana wazy %d kg\n",suma);
   return 0;
}
// Zadanie 2.5
// Pan Kowalski zbudował ścianę z cegieł. Każda cegła ważyła 2 kilogramy. U podstawy ściany znajdowało się 15 cegieł. Każda kolejna warstwa posiadała o jedną cegłę mniej. Napisz program, który oblicza masę ściany.