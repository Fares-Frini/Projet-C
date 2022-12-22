#ifndef ELECTION_H_INCLUDED
#define ELECTION_H_INCLUDED
#include <stdio.h>
typedef struct
{
char date[12],municipalite[13];
int id,nbh,nbc;
}election;
typedef struct utilisateurs
{
	char nom[20];
	char prenom[20];
	int age;
	char sexe[2];
	long cin;
	long numtel;
	char mdp[10];
	char confirmmdp[10];
	char role[20];
	char region[20];
	int v;

} utilisateurs;
int ajouter(char*filename,election e);
int modifier(char*filename,int id,election e);
int supprimer(char*filename,int id);
election chercher(char*filename,int id);
float TPE(char*filename);
float TPHF(char*filename,float*h);

#endif//ELECTION_H_INCLUDED

