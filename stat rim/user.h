
#define USER_H_INCLUDED
#include <stdio.h>

typedef struct
{
 int jour;
 int mois;
 int annee;
} Date;
typedef struct
{
 char Nom[20];
 char Prenom[20];
 int cin;
 Date d;
 int sexe;
 int etatSocial;
 int Role;
 int idBV;
 int Vote;
} User;
 

int ajouter(char filename[], User U);
int modifier(char * filename,int cin, User New);
int supprimer(char * filename,int cin);
User chercher(char* filename ,int cin);
int agemoyen(char*filename, User U);
int nbe (char*filename,int idBV);

