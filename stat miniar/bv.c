#include <stdio.h>
#include <stdlib.h>
#include "bv.h"
#include <string.h>

int ajout(char filename[], bv p)
{

    FILE *f = fopen(filename, "a");
    if (f != NULL)
    {
        fprintf(f, "%d %d %s %d %d %d \n", p.id_bv, p.id_agent_bv, p.gouvernorat, p.salle, p.cap_electeur, p.cap_observateur);
        fclose(f);
        return 1;
    }
    else
        return 0;
}
bv p;

int modifier(char *filename, int id, bv neww)
{
    bv p;
    int tr = 0;
    FILE *f = fopen(filename, "r");
    FILE *f2 = fopen("neww.txt", "w");

    if (f != NULL && f2 != NULL)
        return 0;
    else
    {
        while (fscanf(f, "%d %d %s %d %d %d \n", &p.id_bv, &p.id_agent_bv, p.gouvernorat, &p.salle, &p.cap_electeur, &p.cap_observateur) != EOF)
        {

            if (id != p.id_bv)
            {
                fprintf(f2, "%d %d %s %d %d %d \n", neww.id_bv, neww.id_agent_bv, neww.gouvernorat, neww.salle, neww.cap_electeur, neww.cap_observateur);
                tr = 1;
            }
            else
            {
                fprintf(f2, "%d %d %s %d %d %d \n", p.id_bv, p.id_agent_bv, p.gouvernorat, p.salle, p.cap_electeur, p.cap_observateur);

                tr = 0;
            }
        }
        fclose(f);
        fclose(f2);
        remove(filename);
        rename("new.txt", filename);
        return tr;
    }
}

int supprimer(char *filename, int id)
{
    bv p;
    FILE *f = fopen(filename, "r");
    FILE *f2 = fopen("neww.txt", "w");
    if (f == NULL || f2 == NULL)
        return 0;
    else
    {
        while (fscanf(f, "%d %d %s %d %d %d \n", &p.id_bv, &p.id_agent_bv, p.gouvernorat, &p.salle, &p.cap_electeur, &p.cap_observateur) != EOF)
        {
            if (p.id_bv != id)
                fprintf(f2, "%d %d %s %d %d %d \n", p.id_bv, p.id_agent_bv, p.gouvernorat, p.salle, p.cap_electeur, p.cap_observateur);
        }
        fclose(f);
        fclose(f2);
        remove(filename);
        rename("neww.txt", filename);
        return 1;
    }
}

bv recherche(char *filename, int id)
{
    bv p;
    int tr = 0;
    FILE *f = fopen(filename, "r");
    if (f != NULL)
    {
        while (tr == 0 && fscanf(f, "%d %d %s %d %d %d \n", &p.id_bv, &p.id_agent_bv, p.gouvernorat, &p.salle, &p.cap_electeur, &p.cap_observateur) != EOF)
        {
            if (p.id_bv == id)
                tr = 1;
        }
    }
    fclose(f);
    if (tr == 0)
        p.id_bv = -1;
    return p;
}
void taux(char *filename, float *tn, float *te)
{
    float nb_t = 0;
    float nb_e = 0;
    observateur ob;
    FILE *f = fopen(filename, "r");
    if (f != NULL)
    {
        while (fscanf(f, "%d %d %d %s %s %d %d %s %d %s %d ", &ob.date.jour, &ob.date.mois, &ob.date.annee, ob.nom, ob.prenom, &ob.cin, &ob.id, ob.nationalite, &ob.login, ob.sexe, &ob.mdp) != EOF)
        {
            if (strcmp(ob.nationalite, "tunisien") == 0)
            {
                nb_t++;
            }
            else
            {
                nb_e++;
            }
        }
    }

    *tn = nb_t / (nb_t + nb_e);
    *te = nb_e / (nb_t + nb_e);

    fclose(f);
}

float TVB(char *filename)
{
    int nb_votes = 0;
    int nb_votes_blanc = 0;
    float tvb;
    liste_electorale LE;
    FILE *f = fopen(filename, "r");
    if (f != NULL)
    {
        while (fscanf(f, "%d %d %d %d %s %d %d \n", &LE.date.jour, &LE.date.mois, &LE.date.annee, &LE.num, LE.nationalite, &LE.id, &LE.vote) != EOF)
        {
            if (LE.vote == 0)
            {
                nb_votes_blanc++;
            }
            if ((LE.vote == 1) || (LE.vote == 0))
            {
                nb_votes++;
            }
        }
    }

    tvb = (nb_votes_blanc * 1.0) / (nb_votes * 1.0);
    fclose(f);
    return tvb;
}
