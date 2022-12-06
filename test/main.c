#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int recherche(char *filename, char *cin);
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
char nom[20] ;
char prenom[20];
char cin[20];
char sexe[20];
char jour[20] ;
char bv[20];
char etat[20];
char vote[20];
}affi;

void main()
{
char filename[30]="utilisateurAffichage.txt",tab[20],debut[100]="L'utilsateur a ete trouvé CIN:";

    char cin[10];
    int R;
 
    strcpy(cin, "14362491");
    R=recherche(filename,cin);

}
int recherche( char *filename, char *cin)
{
    affi p;
    FILE *f = fopen("utilisateurAffichage.txt", "r");
    int R = 0;
    if (f != NULL)
    {
        while(fscanf(f,"%s %s %s %s %s %s %s %s\n",p.nom,p.prenom,p.cin,p.sexe,p.jour,p.etat,p.bv,p.vote)!= EOF)
        {
            if ((strcmp(p.cin,cin)) == 0)
            {
                R = 1;
            }
        }
        fclose(f);
        return R;
    }
    else
    {
        return R;
    }
}
