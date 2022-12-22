#include <stdio.h>
#include <string.h>
#include "election.h"

int main()
{
	election e1;
	election e2;
	election e3;
	int y, id, x;
	float s, h;
	printf("taper0 pour ajouter 1 pour modification ,2 pour supprission, 3 pour chercher une election et 4 pour afficher le taux de participation d 'électeur");
	scanf("%d", &y);
	printf("%d", y);
	if (y == 0)
	{
		printf("donner l identifiant d election");
		scanf("%d", &e1.id);
		printf("donner la  date d election");
		scanf("%s", e1.date);
		printf("donner la  municipalite");
		scanf("%s", e1.municipalite);
		printf("donner le nombre d habitant");
		scanf("%d", &e1.nbh);
		printf("donner le nombre de  conseillers");
		scanf("%d", &e1.nbc);

		x = ajouter("election.txt", e1);
		if (x == 1)
			printf("\n ajout d election avec succes");
		else
			printf("\n echec d ajout ");
	}

	if (y == 1)
	{
		printf("donner l identifiant de election a modifier");
		scanf("%d", &id);
		printf("donner  le nouveau date ");
		scanf("%s", e2.date);
		printf("donner  la nouvelle municipalite ");
		scanf("%s", e2.date);
		printf("donner  le nouveau nombre d habitant ");
		scanf("%d", &e2.nbh);
		printf("donner  le nouveau nombre de conseiller ");
		scanf("%d", &e2.nbc);
		x = modifier("election.txt", id, e2);
		if (x == 1)
			printf("\n modification d election avec succes");
		else
			printf("\n echec de modification d election");
	}
	else if (y == 2)
	{
		printf("donner l identidian d election a supprimer");
		scanf("%d", &id);
		x = supprimer("election.txt", id);
		if (x == 1)
			printf("\n suppression avec succes");
		else
			printf("\echec de suppression");
	}
	else if (y == 3)
	{
		printf("donner l identifiant d election a chercher");
		scanf("%d", &id);
		e3 = chercher("election.txt", id);
		if (e3.id == -1)
			printf("introuvable");
		else
			printf("%d %s %s %d %d\n", id, e3.date, e3.municipalite, e3.nbh, e3.nbc);
	}
	else if (y == 4)
	{
		s = TPE("utilisateur.txt");
		printf("le taux de participation d électeur est: %.2f %%", s);
	}
	else
	{
		s = TPHF("utilisateur.txt", &h);
		printf("le taux de participation des Hommes est :%.2f %% \n", h);
		printf("le taux de participation des Femmes est :%.2f %%", s);
	}

	return (0);
}
