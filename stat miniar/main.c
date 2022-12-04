#include "bv.h"
#include <stdio.h>
#include <string.h>

int main()
{
   int x;
   float vb;
   float * tn;
   float * te;
   bv p;
   bv b1 = {4, 9, "bizerte", 8, 9, 6},
      b2 = {5, 3, "manouba", 5, 7, 3},
      b3 = {8, 65, "nabeul", 5, 9, 3};
   x = ajout("bv.txt", b1);
   x = ajout("bv.txt", b3);
   if (x == 1)
   {
      printf("ajoutee avec succes");
   }
   else
      printf("ajout echec");

   x = modifier("bv.txt", 3, b2);

   if (x == 1)
   {
      printf(" \n modif avec succes \n");
   }
   else
   {
      printf(" \n echec de modification\n");
   }

   x = supprimer("bv.txt", 4);
   if (x == 1)
      printf("\n suppression avec succees\n");
   else
      printf("\n echec  suppression\n");

 /*  b3 = recherche("bv.txt", 3);
   if (p.id_bv == -1)
      printf("recherche avec succes");
   else
      printf("\n echec de recherche ");*/

   taux("observateur.txt", tn, te);
   printf("taux d'observateur tunisien est  %f \n", tn);
   printf("taux d'observateur etranger est  %f \n", te);

   vb = TVB("liste_electorale.txt");
   printf("taux de vote blanc %f \n", vb);

   return 0;
}
