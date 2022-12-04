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
int vote;
}Utilisateur;
typedef struct 
{
int id;
char login[20];
char mdp[20];
}Admin;
int cin(char filename[]);
void convert();
void vider(GtkWidget * liste);
void Ajouter_Personne (Utilisateur p);
void Afficher_Personne (GtkWidget * liste);
int ajouter(Utilisateur p , char filename []);
int modifier(int cin,Utilisateur nouv, char * filename);
int supprimer(int cin, char * filename);
Utilisateur chercher(int cin, char * filename);
int agemoy(char filename []);
int nbelecteur(Utilisateur p,char filename[],int nb);
int nbvotes(char bvfilename[]);
int nbe( char * filename, int id );
int verifierajout(Utilisateur p,char filename[]);
int auth(Admin a,char admin[], char id[]);
int ajoutertemp(Utilisateur p, char filename[]);
int length(char cin[]);
Utilisateur lire(Utilisateur p,char tempfilename);
#endif // FONCTION_H_INCLUDED
