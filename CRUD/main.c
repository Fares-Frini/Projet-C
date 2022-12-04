
#include "fonction.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main()
{
	float Rf;
	int nb, M, R, cin, E = 1, id[100], n;
	Utilisateur p, nouv;
	Admin a;
	char filename[20] = "utilisateur.txt", bvfilename[20] = "bureaudevote.txt",admin[20]="admin.txt";
	char nom[20], prenom[20];
	printf("                 Bienvenue Dans LA gestion des Utilisateurs \n \n \n");
	do
	{
		printf("Saisissez ce que vous voulez faire \n 1-Afficher le tableau \n 2-Ajouter un utilisateur \n 3-Modifier Un Utilisateur \n 4-Supprimer Un Utilisateur \n 5-Afficher l'age moyen des electeurs \n  6-Afficher le nombre d'electeurs par bureau de vote \n 7-Fermez le programme  \n Mode Choisi:");
		scanf("%d", &M);
		switch (M)
		{
		case 1:
			printf("Affichage du Tableau \n");
			FILE *f = fopen(filename, "r");
			if (f != NULL)
			{
				while (fscanf(f, "%s %s %d %d %d %d %d %d %d ", p.nom, p.prenom, &p.cin, &p.sexe, &p.jour, &p.mois, &p.annee, &p.etat, &p.bv) != EOF)
				{
					printf("%s %s %d %d %d %d %d %d %d \n ", p.nom, p.prenom, p.cin, p.sexe, p.jour, p.mois, p.annee, p.etat, p.bv);
				};
			}
			else
			{
				printf("Votre Fichier est vide \n");
			}
			break;
		case 2:
			printf("Vous souhaitez ajouter un utilisateur: \n");
			printf("Veuillez Saisir le nom de l'utilisateur: \n");
			scanf("%s", p.nom);
			fflush(stdin);
			printf("Veuillez Saisir le prenom de l'utilisateur: \n");
			scanf("%s", p.prenom);
			fflush(stdin);
			printf("Veuillez Saisir le CIN de l'utilisateur: \n");
			scanf("%d", &p.cin);
			fflush(stdin);
			printf("Veuillez Saisir le sexe de l'utilisateur (1-Homme/2-Femme): \n");
			scanf("%d", &p.sexe);
			fflush(stdin);
			printf("Veuillez Saisir la date de naissance de l'utilisateur: \n");
			printf("Le jour: \n");
			scanf("%d", &p.jour);
			fflush(stdin);
			printf("Le mois \n");
			scanf("%d", &p.mois);
			fflush(stdin);
			printf("L'année \n");
			scanf("%d", &p.annee);
			fflush(stdin);
			printf("Saisir si il s'agit d'un electeur ou d'un observateur (1-electeur 2-observateur)");
			scanf("%d", &p.etat);
			p.bv = 0;
			p.vote = -1;
			R = ajouter(p, filename);
			if (R == 1)
			{
				printf("Votre utilisateur a été ajouté avec succés \n");
			}
			else
			{
				printf("echec de l'ajout\n");
			}
			break;
		case 3:
			printf("Vous Souhaitez modifier un utilisateur \n");
			printf("Saisir son cin \n");
			scanf("%d", &cin);
			printf("Veuillez Saisir le nom de l'utilisateur: \n");
			scanf("%s", nouv.nom);
			fflush(stdin);
			printf("Veuillez Saisir le prenom de l'utilisateur: \n");
			scanf("%s", nouv.prenom);
			fflush(stdin);
			printf("Veuillez Saisir le CIN de l'utilisateur: \n");
			scanf("%d", &nouv.cin);
			fflush(stdin);
			printf("Veuillez Saisir le sexe de l'utilisateur (1-Homme/2-Femme): \n");
			scanf("%d", &nouv.sexe);
			fflush(stdin);
			printf("Veuillez Saisir la date de naissance de l'utilisateur: \n");
			printf("Le jour: \n");
			scanf("%d", &nouv.jour);
			fflush(stdin);
			printf("Le mois \n");
			scanf("%d", &nouv.mois);
			fflush(stdin);
			printf("L'année \n");
			scanf("%d", &nouv.annee);
			fflush(stdin);
			R = modifier(cin, nouv, filename);
			if (R == 1)
			{
				printf("Votre Utilisateur a été modifié avec succés \n");
			}
			else
			{
				printf("erreur de l'operation\n");
			}
			break;
		case 4:
			printf("Vous souhaitez Supprimer un utilisateur \n");
			printf("Saisir son cin \n");
			scanf("%d", &cin);
			R = supprimer(cin, filename);
			break;
		case 7:
			printf("Fermeture du programme\n");
			E = 0;
			break;
		case 5:

			R = agemoy(filename);
			printf("L'age moyen des electeurs est : %i \n", R);
			break;

		case 6:
			printf("Le nombre d'electeurs par bureau de vote \n Saisir le nombre de bureau de vote  ");
			scanf("%d", &n);
			for (int i = 0; i < n; i++)
			{
				printf("Saisir l'id du bureau de vote num %d\n", i + 1);
				scanf("%d", &id[i]);
			}
			for (int i = 0; i < n; i++)
			{
				R = nbe(filename, id[i]);
				printf("il y a %d electeurs dans le bureau de vote num %d (id:%d)\n", R, i + 1, id[i]);
			}

			break;
		case 8:
			printf("Sasir id");
			scanf("%d",&a.id);
			printf("Sasir nom");
			scanf("%s",a.login);
			printf("Sasir prenom");
			scanf("%s",a.mdp);
			if (auth(a,admin))
			{
					printf("lets goooo");
			}
			
			break;
		}
	} while (E == 1);
}
