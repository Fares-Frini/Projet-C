#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include<stdio.h>
#include<gtk/gtk.h>
#include<stdlib.h>
#include<string.h>	
typedef struct
{
char nom[20] ;
char prenom[20];
int cin;
int sexe;
int jour ;
int mois; 
int annee;
int bv;
int etat;
}Utilisateur;

void afficher_personne(GtkWidget* liste);



