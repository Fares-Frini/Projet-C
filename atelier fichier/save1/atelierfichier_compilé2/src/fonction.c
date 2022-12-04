
#include "fonction.h"
#include<stdio.h>
#include<string.h>



int  ajouter(char filename[],char nom[],char prenom[],char username[],char password[],int role)
{

FILE * f=fopen(filename,"a");
inscri p ;
if(f!=NULL)
{
strcpy(p.nom, nom);
strcpy(p.prenom, prenom);
strcpy(p.username, username);
strcpy(p.password, password);
p.role=role;
fprintf(f,"%s %s %s %s %d",p.nom,p.prenom,p.username,p.password,p.role);
fclose(f);
return 1;
}else return 0;
}
int login(char username[],char password[], char filename[])
{
inscri p; int tr=0;
    FILE * f=fopen(filename, "r");
 if(f!=NULL )
    {
while(fscanf(f,"%s %s %s %s %d",p.nom,p.prenom,p.username,p.password,&p.role)!=EOF && tr==0)
{if(username==p.username && password==p.password)
{
return 1;
}else return 2;
 }
}

}
