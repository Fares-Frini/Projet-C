
#include "fonction.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>
enum
{
    NOM,
    PRENOM,
    CIN,
    JOUR,
    SEXE,
    ETAT,
    VOTE,
    BV,
    COLUMNS
};
int cin(char filename[])
{
    FILE *f;
    int cin;
    char cinchar[20];
    f=fopen(filename,"r");
    if (f!=NULL)
    {
        while (fscanf(f,"%s",cinchar)!=EOF);    
        {
            cin=atoi(cinchar);
        }
        fclose(f);
        return cin;
        
    }
    
}
void convert()
{
    char filename[20] = "utilisateur.txt";
    Utilisateur p;
    char cin[20], sexe[20], jour[10], mois[10], annee[10], etat[30], bv[20], vote[20], slash[5] = "/";
    FILE *f = fopen(filename, "r");
    FILE *f1 = fopen("utilisateurAffichage.txt", "w");
    if (f != NULL)
    {
        while (fscanf(f, "%s %s %d %d %d %d %d %d %d %d\n", p.nom, p.prenom, &p.cin, &p.sexe, &p.jour, &p.mois, &p.annee, &p.etat, &p.bv, &p.vote) != EOF)
        {
            sprintf(cin, "%d", p.cin);
            sprintf(jour, "%d", p.jour);
            sprintf(mois, "%d", p.mois);
            sprintf(annee, "%d", p.annee);
            sprintf(bv, "%d", p.bv);
            strcat(jour, slash);
            strcat(jour, mois);
            strcat(jour, slash);
            strcat(jour, annee);
            if (p.sexe == 1)
            {
                strcpy(sexe, "Homme");
            }
            else
            {
                strcpy(sexe, "Femme");
            }
            if (p.etat == 1)
            {
                strcpy(etat, "Electeur");
            }
            else
            {
                strcpy(etat, "Agent_de_Bureau_de_Vote");
            }
            if (p.vote == -1)
            {
                strcpy(vote, "En_Attente");
            }
            else
            {
                strcpy(vote, "A_voté");
            }
            if (p.bv == 0)
            {
                strcpy(bv, "Non_Assigne");
            }
            else
            {
                bv;
            }
            fprintf(f1, "%s %s %s %s %s %s %s %s\n", p.nom, p.prenom, cin, sexe, jour, etat, bv, vote);
        }
        fclose(f);
        fclose(f1);
    }
}
void Afficher_Personne(GtkWidget *liste)
{
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;
    char nom[20];
    char prenom[20];
    char cin[20];
    char sexe[20];
    char jour[20];
    char bv[20];
    char etat[20];
    char vote[20];
    FILE *f;
    store = NULL;
    store = gtk_tree_view_get_model(liste);
    if (store == NULL)
    {
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("CIN", renderer, "text", CIN, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Prenom", renderer, "text", PRENOM, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
        column = gtk_tree_view_column_new_with_attributes("Nom", renderer, "text", NOM, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
        column = gtk_tree_view_column_new_with_attributes("Date de Naissance", renderer, "text", JOUR, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
        column = gtk_tree_view_column_new_with_attributes("Sexe", renderer, "text", SEXE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
        column = gtk_tree_view_column_new_with_attributes("Role", renderer, "text", ETAT, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
        column = gtk_tree_view_column_new_with_attributes("Bureau de vote", renderer, "text", BV, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
        column = gtk_tree_view_column_new_with_attributes("Vote", renderer, "text", VOTE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
        f = fopen("utilisateurAffichage.txt", "r");
        if (f == NULL)
        {
            return;
        }
        else
        {
            f = fopen("utilisateurAffichage.txt", "a+");
            while (fscanf(f, "%s %s %s %s %s %s %s %s \n ", nom, prenom, cin, sexe, jour, etat, bv, vote) != EOF)
            {
                gtk_list_store_append(store, &iter);
                gtk_list_store_set(store, &iter,CIN,cin,NOM,nom,PRENOM,prenom,JOUR,jour,SEXE,sexe,ETAT,etat,BV,bv,VOTE,vote, -1);
            }
        }
        fclose(f);
        gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
        g_object_unref(store);
    }
}
void vider(GtkWidget *liste)
{
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;
    char nom[20];
    char prenom[20];
    int cin;
    int sexe;
    int jour;
    int mois;
    int annee;
    int bv;
    int etat;
    int vote;
    if (store == NULL)
    {
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text", NOM, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Prenom", renderer, "text", PRENOM, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    }
    store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING);
    gtk_list_store_append(store, &iter);
    gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
}
int auth(Admin a, char admin[], char id[])
{
    int R = 0;
    char login[20], mdp[20], cin[20];
    FILE *f = fopen(admin, "r");
    if (f != NULL)
    {
        while (fscanf(f, "%s %s %s \n", login, mdp, cin) != EOF)
        {

            if (!(strcmp(id, cin)) && !(strcmp(login, a.login)) && !(strcmp(mdp, a.mdp)))
            {
                R = 1;
            }
        }
    }
    fclose(f);
    return R;
}
int length(char str[])
{
    int count;
    for (count = 0; str[count] != '\0'; ++count)
        ;
    return count;
}

int verifierajout(Utilisateur p, char filename[])
{
    int digits, mois30 = 0, mois31 = 0, mois29 = 0, mois28 = 0, bissextile = 0;
    char cin[20], nom[20], prenom[20];
    int id, sexe, jour, annee, mois, etat, bv, vote;
    sprintf(cin, "%d", p.cin);
    digits = length(cin);
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

        if (p.mois == 4 || p.mois == 6 || p.mois == 9 || p.mois == 11)
        {
            mois30 = 1;
        }

        if (p.mois == 1 || p.mois == 3 || p.mois == 5 || p.mois == 7 || p.mois == 8 || p.mois == 10 || p.mois == 12)
        {
            mois31 = 1;
        }
        if (p.mois == 2 && bissextile)
        {
            mois29 = 1;
        }
        if (p.mois == 2 && !(bissextile))
        {
            mois28 = 1;
        }

        if (((p.jour > 0 && p.jour < 31) && mois30) || ((p.jour > 0 && p.jour < 32) && mois31) || ((p.jour > 0 && p.jour < 30) && mois29) || ((p.jour > 0 && p.jour < 29) && mois28))
        {
            FILE *f = fopen(filename, "r");
            if (f != NULL)
            {
                while (fscanf(f, "%s %s %d %d %d %d %d %d %d %d\n", nom, prenom, &id, &sexe, &jour, &mois, &annee, &etat, &bv, &vote) != EOF)
                {
                    if (p.cin == id)
                    {
                        fclose(f);
                        return 3;
                    }
                }
                fclose(f);
                if (p.annee > 2004)
                {
                    return 4;
                }
                else
                {
                    return 1;
                }
            }
        }
        else
        {
            return 2;
        }
    }
    else
    {
        return 0;
    }
}

int ajouter(Utilisateur p, char filename[])
{
    FILE *f2 = fopen("utilisateurtemp.txt", "r");
    if (f2 != NULL)
    {
        while (fscanf(f2, "%s %s %d %d %d %d %d %d %d %d\n", p.nom, p.prenom, &p.cin, &p.sexe, &p.jour, &p.mois, &p.annee, &p.etat, &p.bv, &p.vote) != EOF)
        {
        }
    }
    fclose(f2);
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
int ajoutertemp(Utilisateur p, char filename[])
{
    FILE *f = fopen(filename, "w");
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
