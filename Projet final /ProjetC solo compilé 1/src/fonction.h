#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED
#include<stdio.h>
#include<gtk/gtk.h>
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

void afficher_personne(GtkWidget *liste);
int ajouter(Utilisateur p , char filename []);
int modifier(int cin,Utilisateur nouv, char * filename);
int supprimer(int cin, char * filename);
Utilisateur chercher(int cin, char * filename);
int agemoy(Utilisateur p, char filename []);
int nbelecteur(Utilisateur p,char filename[],int nb);
int nbvotes(char bvfilename[]);
#endif // FONCTION_H_INCLUDED
