#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "user.h"

/*
int remplissage(User tab[],int n)
{
User U;
int i=0;
FILE *f=NULL;
f=fopen("user.txt","a+");
while(fscanf(f,"%s %s %s %d%d%d %s %d %d%d %d \n",U.Nom,U.Prenom,U.cin,U.d.jour,U.d.mois,U.d.annee,U.sexe,U.etatSocial,U.Role,U.NumBV,U.Vote)!=EOF)
{   n++;
    strcpy(tab[i].Nom,U.Nom);
    strcpy(tab[i].Prenom,U.Prenom);
    tab[i].d.jour=U.d.jour;
    tab[i].d.mois=U.d.mois;
    tab[i].d.annee=U.d.annee;
    strcpy(tab[i].sexe,U.sexe);
    tab[i].etatSocial=U.etatSociale;
    tab[i].NumBV=U.idBV;
    tab[i].Vote=U.Vote;
    i++;
}
fclose(f);
return(n);
}
int ajouter( User U,User tab[],int n)
{
   n++;
   strcpy(tab [n-1].Nom,U.Nom);
   strcpy(tab [n-1].Prenom,U.Prenom);
   strcpy(tab [n-1].cin,U.cin);
   tab [n-1].d.jour=U.d.jour;
   tab [n-1].d.mois=U.d.mois;
   tab [n-1].d.annee=U.d.annee;
   strcpy(tab [n-1].sexe,U.sexe;
   tab[n-1].etatSocial=U.etatSocial;
   tab[n-1].Role=U.Role;
   tab[n-1].NumBV=U.NumBV;
   tab[n-1].Vote=U.Vote;

return (n);
}
//supprimer un utilisateur
int supprimer(char cin[],User tab[],int n)
{
int i,j;
for(i=0;i<n;i++)
   {
    if(strcmp(cin,tab[i].cin)==0)
        {
         for(j=i;j<n;j++)
             {
             strcpy(tab [j].Nom,tab[j+1].Nom);
             strcpy(tab [j].Prenom,tab[j+1].Prenom);
             strcpy(tab [j].cin,tab[j+1].cin);
             tab [j].d.jour=tab[j+1].d.jour;
             tab [j].d.mois=tab[j+1].d.mois;
             tab [j].d.annee=tab[j+1].d.annee;
             strcpy(tab [j].sexe,tab[j+1].sexe);
             tab[j].etatSocial=tab[j+1].etatSocial;
             tab[j].Role=tab[j+1].Role;
             tab[j].NumBV=tab[j+1].NumBV;
             tab[j].Vote=tab[j+1].Vote;
             }
          n--;
          }
        }
return(n);
}
//chercher un utilisateurs
int chercher (char cin[],User tab[],int n , User U)
   {
   FILE * f;
   int i;
   for(i=0;i<n;i++)
      {
      if(strcmp(cin,tab



*/
int ajouter(char * filename,User U)
{
   int i=0;
   FILE * f=fopen("User.txt", "a");
   if (f!=NULL)
   {
       fprintf(f,"%s %s %d %d %d %d %d %d %d %d %d \n",U.Nom,U.Prenom,U.cin,U.d.jour,U.d.mois,U.d.annee,U.sexe,U.etatSocial,U.Role,U.idBV,U.Vote);
       fclose(f);
       return 1;
    }
    else return 0;
}

int modifier(char * filename, int cin, User New)
{
    int i=0;
    User U;
    FILE * f=fopen("User.txt", "r");
    FILE * f2=fopen("New.txt","w");
    if (f!=NULL && f2!=NULL)
    {
      while(fscanf(f,"%s %s %d %d %d %d %d %d %d %d %d \n",U.Nom,U.Prenom,&U.cin,&U.d.jour,&U.d.mois,&U.d.annee,&U.sexe,&U.etatSocial,&U.Role,&U.idBV,&U.Vote) !=EOF)
                 {
                  if (U.cin== cin)
                     { fprintf(f2,"%s %s %d %d %d %d %d %d %d %d %d \n",New.Nom,New.Prenom,New.cin,New.d.jour,New.d.mois,New.d.annee,New.sexe,New.etatSocial,New.Role,New.idBV,New.Vote);
                        i=1;
                     }
                     else 
                    fprintf(f2,"%s %s %d %d %d %d %d %d %d %d %d \n",U.Nom,U.Prenom,U.cin,U.d.jour,U.d.mois,U.d.annee,U.sexe,U.etatSocial,U.Role,U.idBV,U.Vote);
                  }
}
   fclose(f);
   fclose(f2);
   remove("User.txt");
   rename("New.txt","User.txt");
   return i;
}
int supprimer(char * filename , int cin)
{
   int i=0;
   User U;
   FILE * f=fopen("User.txt","r");
   FILE * f2=fopen("New.txt", "w");
   if (f!=NULL && f2!=NULL)
   {   
        while (fscanf (f, "%s %s %d %d %d %d %d %d %d %d %d \n",U.Nom,U.Prenom,&U.cin,&U.d.jour,&U.d.mois,&U.d.annee,&U.sexe,&U.etatSocial,&U.Role,&U.idBV,&U.Vote)!=EOF)
    {
        if (U.cin==cin)
            i=1;
         else
             fprintf(f2,"%s %s %d %d %d %d %d %d %d %d %d \n",U.Nom,U.Prenom,U.cin,U.d.jour,U.d.mois,U.d.annee,U.sexe,U.etatSocial,U.Role,U.idBV,U.Vote);
     }
  }
 else return 0;
  fclose(f);
  fclose(f2);
  remove("User.txt");
  rename("New.txt","User.txt");
  return i;
}
  User chercher(char * filename, int cin)
{
  User U;
  int i;
  FILE * f= fopen("User.txt","r");
  if(f!=NULL)
  {
    while(i==0 && fscanf(f,"%s %s %d %d %d %d %d %d %d %d %d \n",U.Nom,U.Prenom,&U.cin,&U.d.jour,&U.d.mois,&U.d.annee,&U.sexe,&U.etatSocial,&U.Role,&U.idBV,&U.Vote)!=EOF)
     {
         if(U.cin==cin)
               i=1;
      }
    }
    fclose(f);
    if(i==0)
        U.cin=-1;
     return U;
}

int agemoyen(char*filename, User U)
{
  int nb,na,i=0,x=0;
  float moy;
 
  FILE * f=fopen("User.txt","r");
  if (f!=NULL)
   { 
   while(fscanf(f,"%s %s %d %d %d %d %d %d %d %d %d \n",U.Nom,U.Prenom,&U.cin,&U.d.jour,&U.d.mois,&U.d.annee,&U.sexe,&U.etatSocial,&U.Role,&U.idBV,&U.Vote)!=EOF)
   {
   if(U.Role==1)
      {
        x+=2022-U.d.annee;
         i++;
      }
   }
   moy=(x*1)/(i*1.0);   
   fclose(f);
   return (int)moy;
   }
   else
   {
      fclose(f);
      return -1;
   }
}

int nbe (char*filename,int id)
{ User U; 
  int nbe=0;
  FILE * f=fopen(filename,"r");
   if(f!=NULL)
{while(fscanf(f,"%s %s %d %d%d%d %d %d %d%d %d \n",U.Nom,U.Prenom,&U.cin,&U.d.jour,&U.d.mois,&U.d.annee,&U.sexe,&U.etatSocial,&U.Role,&U.idBV,&U.Vote)!=EOF)
{
if(U.idBV==id)
 {
   if(U.Role==1)
{
   nbe+=1;
  }
}

return nbe;
}}
else return 0;

}



 
