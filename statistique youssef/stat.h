#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED
#include <stdio.h>
typedef struct
{
   int  num_list;
   int id_tete_list;
char tab_candiats[50]; 
}Utilisateur;
//le type de  retour int c'est pour indiquer si la tache a été réalisée avec succés ou non// pour afficher des lsg plus tard exemple erreur d'ouverture de fichier, element introuvable
int ajouter(Utilisateur p , char filename []);

int nbreclamation(int nb[], char * fichierreclamation, char *  listeelectorale);
#endif // POINT_H_INCLUDED