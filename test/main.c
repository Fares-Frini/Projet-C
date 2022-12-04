#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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


void main()
{
	char fares[20]="Fares",frini[20]="Frini",nom[20]="/";
	strcat(fares,"lets go");
	printf("%s",fares);

}
