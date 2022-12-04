#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "stat.h"
int nbreclamation(int nb[], char * fichierreclamation, char *  listeelectorale)
{
    int R=0,num_list,id_tete_liste,c=0,i=0,n=0,id_observateur,liste_electorale,numero_bureau_de_vote;
    char tab_candidats[50],tb[50],type_de_reclamation[50],entree_reclamation[500];
     FILE * f=fopen(listeelectorale, "r");
    if(f!=NULL)
    {
        while(fscanf(f,"%d %d %s\n",&num_list,&id_tete_liste,tab_candidats)!=EOF)
        {
            n++;
        }
    }
    fclose(f);
    FILE * f2=fopen(fichierreclamation,"r");
    if (f!=NULL)
    {    

        for ( i = 0; i < n; i++)
        {    
            c=0;
          while(fscanf(f2,"%d %d %d %s %s\n",&id_observateur,&liste_electorale,&numero_bureau_de_vote,type_de_reclamation,entree_reclamation)!=EOF)
            {   
                 
            
                if (i+1==liste_electorale)
                {
                    c++;
                    R++;
                }
                
            }
            nb[i]=c;
        }
        nb[n]=-1;
        
    }
    fclose(f2);
    return R;
    

}
int ajouter(Utilisateur p , char filename [])
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%d %d %s \n",p.num_list,p.id_tete_list,p.tab_candiats);
        fclose(f);
        return 1;
    }
    else return 0;
}