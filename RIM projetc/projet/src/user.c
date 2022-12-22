#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"
#include <gtk/gtk.h>
enum
{
   CIN,
   NOM,
   PRENOM,
   MUNICIPALITE,
   SEXE,
   NATION,
   IDBV,
   DATE,
   VOTE,
   ETATSOCIAL,
   GOUVER,
   ROLE,
   COLUMNS
};
void affiche_userr(GtkWidget *liste)
{
   GtkCellRenderer *renderer;
   GtkTreeViewColumn *column;
   GtkTreeIter iter;
   GtkListStore *store;
   char nom[20];
   char prenom[20];
   char cin[20];
   char date[20];
   char sexe[20];
   char nationalite[20];
   char etatSocial[20];
   char municipalite[20];
   char gouvernorat[20];
   char role[20];
   char idBV[20];
   char vote[20];

   FILE *f;
   store = NULL;
   store = gtk_tree_view_get_model(liste);

   if (store == NULL)
   {
      renderer = gtk_cell_renderer_text_new();
      column = gtk_tree_view_column_new_with_attributes("CIN", renderer, "text", CIN, NULL);
      gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
      renderer = gtk_cell_renderer_text_new();
      column = gtk_tree_view_column_new_with_attributes("Nom", renderer, "text", NOM, NULL);
      gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
      renderer = gtk_cell_renderer_text_new();
      column = gtk_tree_view_column_new_with_attributes("Prénom", renderer, "text", PRENOM, NULL);
      gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
      renderer = gtk_cell_renderer_text_new();
      column = gtk_tree_view_column_new_with_attributes("Date de naissance", renderer, "text", DATE, NULL);
      gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
      renderer = gtk_cell_renderer_text_new();
      column = gtk_tree_view_column_new_with_attributes("Etat Social", renderer, "text", ETATSOCIAL, NULL);
      gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
      renderer = gtk_cell_renderer_text_new();
      column = gtk_tree_view_column_new_with_attributes("Nationalité", renderer, "text", NATION, NULL);
      gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
      renderer = gtk_cell_renderer_text_new();
      column = gtk_tree_view_column_new_with_attributes("Municipalité", renderer, "text", MUNICIPALITE, NULL);
      gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
      renderer = gtk_cell_renderer_text_new();
      column = gtk_tree_view_column_new_with_attributes("Gouvernorat", renderer, "text", GOUVER, NULL);
      gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
      renderer = gtk_cell_renderer_text_new();
      column = gtk_tree_view_column_new_with_attributes("idBV", renderer, "text", IDBV, NULL);
      gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
      renderer = gtk_cell_renderer_text_new();
      column = gtk_tree_view_column_new_with_attributes("Role", renderer, "text", ROLE, NULL);
      gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
      renderer = gtk_cell_renderer_text_new();
      column = gtk_tree_view_column_new_with_attributes("Vote", renderer, "text", VOTE, NULL);
      gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
      store = gtk_list_store_new(COLUMNS, G_TYPE_STRING , G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
      f = fopen("User.txt", "r");
      if (f == NULL)
      {
         return;
      }
      else
      {
         f = fopen("User.txt", "a+");
         while (fscanf(f, "%s %s %s %s %s %s %s %s %s %s %s %s\n", nom, prenom, cin, date, sexe, etatSocial, municipalite, gouvernorat, role, idBV, vote,nationalite) != EOF)
         {

      gtk_list_store_append(store, &iter);
      gtk_list_store_set(store, &iter, CIN, cin,NOM,nom,PRENOM,prenom,DATE,date, SEXE, sexe, NATION, nationalite, GOUVER, gouvernorat, ETATSOCIAL, etatSocial, ROLE, role, IDBV, idBV, VOTE, vote,-1);
      }
   }
   fclose(f);

      gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
      g_object_unref(store);
   }
}

int ajouter(char *filename, User U)
{
   int i = 0;
   FILE *f = fopen("User.txt", "a");
   if (f != NULL)
   {
      fprintf(f, "%s %s %d  %d/%d/%d  %d %d %d %s %s %d %d %d \n", U.Nom, U.Prenom, U.cin, U.d.jour, U.d.mois, U.d.annee, U.sexe, U.nationalite, U.etatSocial, U.municipalite, U.gouvernorat, U.Role, U.idBV, U.Vote);
      fclose(f);
      return 1;
   }
   else
      return 0;
}

int modifier(char *filename, int cin, User New)
{
   int i = 0;
   User U;
   FILE *f = fopen("User.txt", "r");
   FILE *f2 = fopen("New.txt", "w");
   if (f != NULL && f2 != NULL)
   {
      while (fscanf(f, "%s %s %d %d/%d/%d %d %d %s %s %d %d %d \n", U.Nom, U.Prenom, &U.cin, &U.d.jour, &U.d.mois, &U.d.annee, &U.sexe, &U.etatSocial, U.municipalite, U.gouvernorat, &U.Role, &U.idBV, &U.Vote) != EOF)
      {
         if (U.cin == cin)
         {
            fprintf(f, "%s %s %d %d %d %d %d %d %s %s %d %d %d \n", New.Nom, New.Prenom, New.cin, New.d.jour, New.d.mois, New.d.annee, New.sexe, New.etatSocial, New.municipalite, New.gouvernorat, New.Role, New.idBV, New.Vote);
            i = 1;
         }
         else
            fprintf(f2, "%s %s %d %d %d %d %d %d %s %s %d %d %d \n", U.Nom, U.Prenom, U.cin, U.d.jour, U.d.mois, U.d.annee, U.sexe, U.etatSocial, U.municipalite, U.gouvernorat, U.Role, U.idBV, U.Vote);
      }
   }
   fclose(f);
   fclose(f2);
   remove("User.txt");
   rename("New.txt", "User.txt");
   return i;
}
int supprimer(char *filename, int cin)
{
   int i = 0;
   User U;
   FILE *f = fopen("User.txt", "r");
   FILE *f2 = fopen("New.txt", "w");
   if (f != NULL && f2 != NULL)
   {
      while (fscanf(f, "%s %s %d %d %d %d %d %d %s %s %d %d %d \n", U.Nom, U.Prenom, &U.cin, &U.d.jour, &U.d.mois, &U.d.annee, &U.sexe, &U.etatSocial, U.municipalite, U.gouvernorat, &U.Role, &U.idBV, &U.Vote) != EOF)
      {
         if (U.cin == cin)
            i = 1;
         else
            fprintf(f, "%s %s %d %d %d %d %d %d %s %s %d %d %d \n", U.Nom, U.Prenom, U.cin, U.d.jour, U.d.mois, U.d.annee, U.sexe, U.etatSocial, U.municipalite, U.gouvernorat, U.Role, U.idBV, U.Vote);
      }
   }
   else
      return 0;
   fclose(f);
   fclose(f2);
   remove("User.txt");
   rename("New.txt", "User.txt");
   return i;
}
User chercher(char *filename, int cin)
{
   User U;
   int i;
   FILE *f = fopen("User.txt", "r");
   if (f != NULL)
   {
      while (i == 0 && fscanf(f, "%s %s %d %d %d %d %d %d %s %s %d %d %d \n", U.Nom, U.Prenom, &U.cin, &U.d.jour, &U.d.mois, &U.d.annee, &U.sexe, &U.etatSocial, U.municipalite, U.gouvernorat, &U.Role, &U.idBV, &U.Vote) != EOF)
      {
         if (U.cin == cin)
            i = 1;
      }
   }
   fclose(f);
   if (i == 0)
      U.cin = -1;
   return U;
}

int agemoyen(char *filename, User U)
{
   int nb, na, i = 0, x = 0;
   float moy;

   FILE *f = fopen("User.txt", "r");
   if (f != NULL)
   {
      while (fscanf(f, "%s %s %d %d %d %d %d %d %d %s %s %d %d %d \n", U.Nom, U.Prenom, &U.cin, &U.d.jour, &U.d.mois, &U.d.annee, &U.sexe, &U.nationalite, &U.etatSocial, U.municipalite, U.gouvernorat, &U.Role, &U.idBV, &U.Vote) != EOF)
      {
         if (U.Role == 1)
         {
            x += 2022 - U.d.annee; // x=total  d'age
            i++;                   // i est le nombre des électeurs
         }
      }
      moy = (float)(x * 1) / (i * 1.0);
      fclose(f);
      return moy;
   }
   else
   {
      fclose(f);
      return -1;
   }
}

int nbe(char *filename, int id)
{
   User U;
   char Nom[20], Prenom[20];
   int R = 0, i = 0, cin, sexe, jour, mois, annee, etatSocial, Role;
   FILE *f = fopen(filename, "r");
   if (f != NULL)
   {
      while (fscanf(f, "%s %s %d %d %d %d %d %d %s %s %d %d %d \n", U.Nom, U.Prenom, &U.cin, &U.d.jour, &U.d.mois, &U.d.annee, &U.sexe, &U.etatSocial, U.municipalite, U.gouvernorat, &U.Role, &U.idBV, &U.Vote) != EOF)
      {
         if (U.idBV == id)
         {
            R++;
         }
      }
      fclose(f);
      return R;
   }
}
int verifaj(User U, char filename[])
{
   int n, mois30 = 0, mois31 = 0, mois29 = 0, mois28 = 0, bissextile = 0;
   char cin[20], Nom[20], Prenom[20];
   int sexe, jour, annee, mois, etatSocial, idBV, Vote;
   sprintf(cin, "%d", U.cin);
   n = strlen(cin);
   if (n == 8)
   {
      if (U.d.annee % 4 == 0)
      {
         if (U.d.annee % 100 == 0)
         {
            if (U.d.annee % 400 == 0)
            {
               bissextile = 1;
            }
         }
         else
         {
            bissextile = 1;
         }
      }
      if (U.d.mois == 4 || U.d.mois == 6 || U.d.mois == 9 || U.d.mois == 11)
      {
         mois30 = 1;
      }
      if (U.d.mois == 1 || U.d.mois == 3 || U.d.mois == 5 || U.d.mois == 7 || U.d.mois == 8 || U.d.mois == 10)
      {
         mois31 = 1;
      }
      if (((U.d.jour > 0 && U.d.jour < 31) && mois30) || ((U.d.jour > 0 && U.d.jour < 32) && mois31))
      {
         FILE *f = fopen(filename, "r");
         if (f != NULL)
         {
            while (fscanf(f, "%s %s %d %d %d %d %d %d %s %s %d %d %d \n", U.Nom, U.Prenom, &U.cin, &U.d.jour, &U.d.mois, &U.d.annee, &U.sexe, &U.etatSocial, U.municipalite, U.gouvernorat, &U.Role, &U.idBV, &U.Vote) != EOF)
            {
               if (U.cin == *cin)
               {
                  fclose(f);
                  return 3;
               }
            }
            fclose(f);
            if (U.d.annee > 2004)
            {
               return 4;
            }
            else
            {
               return 1;
            }
         }

         else
         {
            return 2;
         }
      }
      else
      {
         return 0;
      }
   }
   else
      return -1;
}
