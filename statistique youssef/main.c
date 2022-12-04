#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "stat.h"
void main()
{
    Utilisateur p;
    int nb[50],R,i=0,M;
    char fichierreclamation[50]="gestionreclamation.txt";
    char listeelectorale[50]="listeelectorale.txt";
    R=nbreclamation(nb, fichierreclamation,listeelectorale);
    printf("Le nombre de réclamation totales\n");
    printf("%d\n",R);
        
    while(nb[i]!=-1)
    {   
        printf("Le nombre de réclamation dans le bureau de vote num %d \n",i+1);
        printf("%d\n",nb[i]);
        fflush( stdout );
        i++;
        
    }
 

}
