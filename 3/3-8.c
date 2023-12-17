#include <stdio.h>
#include <ctype.h>
#define MAX_DL 50

int main() {
   char c, c1[MAX_DL], c2[MAX_DL];
   int i, j, k, suf = 1, pref = 1;
   printf("\nciąg 1: ");
   for (i = 0; (c = getchar()) !='\n'; ++i)
   {
      c1[i] = c;
   }
   printf("\nciąg 2: ");
   for (j = 0; (c = getchar()) !='\n'; ++j)
   {
      c2[j] = c;
   }
   --i;
   --j;
   for (k=0; k<j;++k) {
      //printf("pref i: %d, j:%d, k:%d, c1[i-k]: %c, c2[j-k]: %c\n",i,j,k,c1[k],c2[k]);
      if(c1[k]!=c2[k]) {
         pref = 0;
         break;
      }
   }
   for (k=0; k<j;++k) {
      //printf("suf i: %d, j:%d, k:%d, c1[i-k]: %c, c2[j-k]: %c\n",i,j,k,c1[i-k],c2[j-k]);
      if(c1[i-k]!=c2[j-k]) {
         suf = 0;
         break;
      }
   }
   if (suf == 0 && pref ==0) printf("\nNie jest sufiksem, ani prefiksem");
   if (suf == 1) printf("\nJest Sufiksem ");
   if (pref ==1) printf("\nJest Prefiksem");
   return 0;
}

// Zadanie 3.8
// Napisz program, który sprawdzi, czy k-elementowy ciąg znaków jest sufiksem lub prefiksem drugiego n-elementowego ciągu. Obydwa ciągi znaków wczytaj od użytkownika (maksymalna długość napisów to 20 znaków). Wielkość liter nie powinna mieć znaczenia w trakcie porównywania. Program powinien wypisywać komunikaty: "Jest sufiksem", "Jest prefiksem" lub "Nie jest sufiksem ani prefiksem".
// Przykłady:
// ciąg 1: "kotek"
// ciąg 2: "ek"
// wynik: "Jest sufiksem"

// ciąg 1: "(+48) 623 769 265"
// ciąg 2: "(+48)"
// wynik: "Jest prefiksem"

// ciąg 1: "Ala ma kota"
// ciąg 2: "kot"
// wynik: "Nie jest sufiksem, ani prefiksem"

// ciąg 1: "123 abc 123"
// ciąg 2: "123"
// wynik: "Jest sufiksem" "Jest prefiksem"