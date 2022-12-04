
#include "fonction.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*int verifierajout(Utilisateur p)
{
    int digits, mois30 = 0, mois31 = 0, mois29 = 0, mois28 = 0, bissextile = 0;

    if (digits == 8)
    {
        if (p.annee % 4 == 0)
        {
            if (p.annee % 100 == 0)
            {
                if (p.annee % 400 == 0)
                {
                    bissextile = 1;
                }
            }
            else
            {
                bissextile = 1;
            }
        }

        if (p.mois > 0 && p.mois < 12)
        {
            if (p.mois == 4 || p.mois == 6 || p.mois == 9 || p.mois == 11)
            {
                mois30 = 1;
            }

            if (p.mois == 1 || p.mois == 3 || p.mois == 5 || p.mois == 7 || p.mois == 8 || p.mois == 10 || p.mois == 12)
            {
                mois31 = 1;
            }
            if (p.mois == 2)
            {
                if (bissextile)
                {
                    mois29 = 1;
                }
                else
                {
                    mois28 = 1;
                }
            }

            if (((p.jour > 0 && p.jour < 31) && mois30) || ((p.jour > 0 && p.jour < 32) && mois31) || ((p.jour > 0 && p.jour < 30) && mois29) || ((p.jour > 0 && p.jour < 29) && mois28))
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
    }
    else
    {
        return -2;
    }
}
*/

int ajouter(Utilisateur p, char filename[])
{
    FILE *f = fopen(filename, "a");
    if (f != NULL)
    {
        fprintf(f, "%s %s %d %d %d %d %d %d %d %d\n", p.nom, p.prenom, p.cin, p.sexe, p.jour, p.mois, p.annee, p.etat, p.bv, p.vote);
        fclose(f);
        return 1;
    }
    else
        return 0;
}

int modifier(int cin, Utilisateur nouv, char *filename)
{
    Utilisateur p;
    FILE *f = fopen(filename, "r");
    FILE *f2 = fopen("aux.txt", "w");
    if (f == NULL || f2 == NULL)
        return 0;
    else
    {
        while (fscanf(f, "%s %s %d %d %d %d %d %d %d %d\n", p.nom, p.prenom, &p.cin, &p.sexe, &p.jour, &p.mois, &p.annee, &p.etat, &p.bv, &p.vote) != EOF)
        {
            if (p.cin != cin)
                fprintf(f2, "%s %s %d %d %d %d %d %d %d %d \n", p.nom, p.prenom, p.cin, p.sexe, p.jour, p.mois, p.annee, p.etat, p.bv, p.vote);
            else

                fprintf(f2, "%s %s %d %d %d %d %d %d %d %d\n", nouv.nom, nouv.prenom, nouv.cin, nouv.sexe, nouv.jour, nouv.mois, nouv.annee, p.etat, p.bv, p.vote);
        }
        fclose(f);
        fclose(f2);
        remove(filename);
        rename("aux.txt", filename);
        return 1;
    }
}

int supprimer(int cin, char *filename)
{
    Utilisateur p;
    FILE *f = fopen(filename, "r");
    FILE *f2 = fopen("aux.txt", "w");
    if (f == NULL || f2 == NULL)
        return 0;
    else
    {
        while (fscanf(f, "%s %s %d %d %d %d %d %d %d %d \n", p.nom, p.prenom, &p.cin, &p.sexe, &p.jour, &p.mois, &p.annee, &p.etat, &p.bv, &p.vote) != EOF)
        {
            if (p.cin != cin)
                fprintf(f2, "%s %s %d %d %d %d %d %d %d %d\n", p.nom, p.prenom, p.cin, p.sexe, p.jour, p.mois, p.annee, p.etat, p.bv, p.vote);
        }
        fclose(f);
        fclose(f2);
        remove(filename);
        rename("aux.txt", filename);
        return 1;
    }
}

Utilisateur chercher(int cin, char *filename)
{
    Utilisateur p;
    int tr = 0;
    FILE *f = fopen(filename, "r");
    if (f != NULL)
    {
        while (fscanf(f, "%s %s %d %d %d %d %d %d %d %d \n", p.nom, p.prenom, &p.cin, &p.sexe, &p.jour, &p.mois, &p.annee, &p.etat, &p.bv, &p.vote) != EOF && tr == 0)
        {
            if (p.cin == cin)
                tr = 1;
        }
    }
    if (tr == 0)
        p.cin = -1;
    return p;
}

int agemoy(char filename[])
{
    char nom[20], prenom[20];
    int Age, R = 0, i = 0, cin, sexe, jour, mois, annee, etat, bv, vote;
    float Agemoy;
    FILE *f = fopen(filename, "r");
    if (f != NULL)
    {
        while (fscanf(f, "%s %s %d %d %d %d %d %d %d %d\n", nom, prenom, &cin, &sexe, &jour, &mois, &annee, &etat, &bv, &vote) != EOF)
        {
            if (etat == 1)
            {
                R += 2022 - annee;
                i++;
            }
        }
        Agemoy = (R * 1.0) / (i * 1.0);
        fclose(f);
        return (int)Agemoy;
    }
    else
        return 0;
}

int nbe(char *filename, int id)
{
    char nom[20], prenom[20];
    int Age, R = 0, i = 0, cin, sexe, jour, mois, annee, etat, bv, vote;

    FILE *f = fopen(filename, "r");

    if (f != NULL)
    {

        while (fscanf(f, "%s %s %d %d %d %d %d %d %d %d\n", nom, prenom, &cin, &sexe, &jour, &mois, &annee, &etat, &bv, &vote) != EOF)
        {

            if (bv == id)
            {
                R++;
            }
        }
        fclose(f);
        return R;
    }
    else
        return -1;
}
int auth(Admin a, char admin[])
{
    int id;
    char login[20], mdp[20];
    FILE *f = fopen(admin, "r");
    if (f != NULL)
    {
        while (fscanf(f, "%d %s %s \n", &id, login, mdp) != EOF)
        {
            if (a.id == id && !(strcmp(login, a.login)) && !(strcmp(mdp, a.mdp)))
            {
                fclose(f);
                return 1;
            }
        }
        fclose(f);
        return 0;
    }
    else
    {
        fclose(f);
        return 0;
    }
}