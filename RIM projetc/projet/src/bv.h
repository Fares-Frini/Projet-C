#ifndef bv_H_INCLUDED
#define bv_H_INCLUDED
#include <stdio.h>
#include <gtk/gtk.h>
typedef struct {
int ID;
int IDAGBV;
char Region[30];
char Adresse[100];
char Mnp[30];
int cpt_obser;
int cpt_elec;
int salle ;
}BVOTE;

typedef struct {
char ID[30];
char IDAGBV[30];
char Region[30];
char Adresse[100];
char Mnp[30];
char cpt_obser[30];
char cpt_elec[30];
char salle [30];
}BUVOTE;

int ajouterbv(BVOTE p);
int modifierbv(int ID_modifier,BVOTE nouv);
int supprimerbv(int ID_supprimer);
int recherchebv(int ID_recherche);
int afficherbv();
void vider(GtkWidget *liste);
void Afficher_Bureau_de_Vote(GtkWidget *liste);
void ajouter_bv(BVOTE p);
void supprimer_bv(BVOTE p);
void ajouterr_bv(BUVOTE b);
void supprimerr_bv(BUVOTE b);
//void ssupprimerbv(BVOTE p);
//int supprimer(int ID_supprimer, char * filename);
int modifier_bv(char* filename ,int ID_modifier,BVOTE nouv);
#endif
