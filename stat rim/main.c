#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "user.h"



void main()
{ 
  int M,nb,n,R,cin,idBV,i,E=1;
  char filename[20]="User.txt";
  User 	U,New;
  char Nom[20],Prenom[20];
  liste l;
  printf(" Gestion des Utilisateurs \n \n \n");
  do{
  printf("Choisir l'action \n 1-Afficher la liste \n 2-Ajouter un utilisateur \n 3-Modifier un utilisateur \n 4-Supprimer un utilisateur \n 5-Afficher l'age moyen des électeurs \n 6-Afficher le nombre des électeurs par bureau de vote  \n 7-Fermez le programme \n Mode choisi:");
  scanf("%d",&M);
  switch(M){
  case 1:
       /*printf("Affichage de la liste \n");
       FILE * f=fopen("User.txt","r");
       if(f!=NULL)
       {
        while (fscanf(f,"%s %s %d %d %d %d %d %d %d %d %d \n",U.Nom,U.Prenom,&U.cin,&U.d.jour,&U.d.mois,&U.d.annee,&U.sexe,&U.etatSocial,&U.Role,&U.idBV,&U.Vote)!=EOF);
       {
          printf("%s %s %d \t %d/ %d/ %d \t %d %d %d %d %d \n",U.Nom,U.Prenom,U.cin,U.d.jour,U.d.mois,U.d.annee,U.sexe,U.etatSocial,U.Role,U.idBV,U.Vote);
       };
       }
        
       else{
           printf("votre fichier est vide \n");
           }*/
       break;
  case 2:
  /*printf("Nom:\n"); scanf("%s",U.Nom);fflush(stdin);
   printf("Prenom:\n"); scanf("%s",U.Prenom);fflush(stdin);
   printf("Iden:\n"); scanf("%d",&U.cin);fflush(stdin);
   printf("date de naissance:\n");
   printf("Jour:\n");    
     scanf("%d",&U.d.jour);fflush(stdin);
printf("Mois:\n");    
     scanf("%d",&U.d.mois);fflush(stdin);
printf("Annee:\n");    
     scanf("%d",&U.d.annee);fflush(stdin);
   printf("Sexe:(1-homme 2-femme)\n"); scanf("%d",&U.sexe);fflush(stdin);
   printf("Etat Social:(1-marié 2-célébataire 3-divorcé)\n");  
   scanf("%d",&U.etatSocial);fflush(stdin);
   printf("Role:(1-electeur 2-observateur)\n");
   scanf("%d",&U.Role);fflush(stdin);
   printf("idBV:\n"); scanf("%d",&U.idBV);fflush(stdin);
   printf("Vote:\n"); scanf("%d",&U.Vote);fflush(stdin);
   R=ajouter(filename,U);
   if (R==1)
       printf("\najout d'un nouveau utilisateur avec succés\n");
   else printf("\nechec ajout\n");
  break;*/
  case 3:
   /*printf("saisir le cin\n");
   scanf("%d",&cin);
   printf("saisir le nom\n");
   scanf("%s",New.Nom);
   fflush(stdin);
   printf("saisir le prenom\n");
   scanf("%s",New.Prenom);
   fflush(stdin); 
   printf("saisir le nouveau cin\n");
   scanf("%d",&New.cin);
   fflush(stdin);
  printf("nouveau date de naissance:\n");
   printf("Jour:\n");    
     scanf("%d",&New.d.jour);fflush(stdin);
printf("Mois:\n");    
     scanf("%d",&New.d.mois);fflush(stdin);
printf("Annee:\n");    
     scanf("%d",&New.d.annee);fflush(stdin);
   printf("Saisir le sexe:(1-homme 2-femme)\n");
   scanf("%d",&New.sexe);
   fflush(stdin);
   printf("Etat Social:(1-marié 2-célébataire 3-divorcé)\n");  
   scanf("%d",&New.etatSocial);
   fflush(stdin);
   printf("Role:(1-electeur 2-observateur)\n");
   scanf("%d",&New.Role);
   fflush(stdin);
   printf("idBV:\n"); scanf("%d",&New.idBV);fflush(stdin);
   printf("Vote:\n"); scanf("%d",&New.Vote);fflush(stdin);
   R=modifier(filename,cin,New);
   if(R==1)
     printf("\nModification des utilisateurs avec succés\n");
   else printf("\nechec Modification\n");*/
   break;
 case 4:
 /*  printf("Souhaitez-vous supprimer un utilisateur? \n");
   printf("saisir cin \n");
   scanf("%d",&cin);
   R=supprimer(filename,cin);
   
   
   if (R==1)
      printf("Suppression des utilisateurs avec succés\n");
   else printf("Echec Suppression\n");*/
   break;
   case 5:
   R= agemoyen(filename,U);
   printf("L'age moyen des électeurs est : %d \n",R);
   break;

 case 6:
   printf("Le nombre des électeur par bureau de vote \n");
   nb=l.nb_vote;
   for ( i=0;i<nb;i++)
      {
        n=nbe(filename,i+1);
        printf("le nombre des électeurs dans le bureau num %d est %d",i+1,n);
      }

   break;
 case 7:
   printf("Fermeture du programme\n");
   E=0;
   break;
}
}while(E==1);
}

  
   
   
 

