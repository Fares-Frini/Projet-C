#ifndef bv_H_INCLUDED
#define bv_H_INCLUDED
#include <stdio.h>

typedef struct
{
  int id_bv;
  int id_agent_bv;
  char gouvernorat[30];
  int salle;
  int cap_electeur;
  int cap_observateur;
} bv;

typedef struct
{
  int jour;
  int mois;
  int annee;
} Date;

typedef struct
{
  char nom[20];
  char prenom[20];
  Date date;
  int cin;
  int id;
  int login;
  int mdp;
  char sexe[7];
  char nationalite[20];
} observateur;

typedef struct
{
  Date date;
  int num;
  int id;
  char nationalite[20];
  int vote;
} liste_electorale;

int ajout(char *filename, bv p);
int modifier(char *filename, int id, bv neww);
int supprimer(char *filename, int id);
bv recherche(char *filename, int id);

void taux(char *filename, float *tn, float *te);
float TVB(char *filename);

#endif
