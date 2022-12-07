// fonction.h
#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED
#include <stdio.h>
#include <gtk/gtk.h>
// fonction.c

#include "fonction.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>
// callbacks.c
#include "fonction.h"

//EN TETE
    (GtkWidget *objet_graphique, gpointer user_data)

//HIDE
    GtkWidget *Affichage;
    Affichage = lookup_widget(objet_graphique, "id");
    gtk_widget_hide(Affichage);
//SHOW
    GtkWidget *authentification;
    authentification = create_authentification();
    gtk_widget_show(authentification);

//TOGGLE
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
    {
        variable = 1;
    }

//SPIN
    GtkWidget *variable;
    variable = lookup_widget(objet_graphique, "id");
    p.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(variable));

//ENTRY
    GtkWidget *variable;
    variable = lookup_widget(objet_graphique, "entry_id");
    strcpy(p.nom, gtk_entry_get_text(GTK_ENTRY(variable)));

//LABEL
    GtkWidget *output;
    output = lookup_widget(objet_graphique, "label_id");
    gtk_label_set_text(GTK_LABEL(output), chaine);

//COMBOBOX

//TREEVIEW
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
    GtkWidget *Affichage;
    GtkWidget *treeview;
    Affichage = lookup_widget(objet_graphique, "Affichage");
    Affichage = create_Affichage();
    gtk_widget_show(Affichage);
    treeview = lookup_widget(Affichage, "treeview");
    Afficher_Personne(treeview);
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
        column = gtk_tree_view_column_new_with_attributes("NOM", renderer, "text", PRENOM, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
        column = gtk_tree_view_column_new_with_attributes("PreNom", renderer, "text", NOM, NULL);
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
                gtk_list_store_set(store, &iter, CIN, cin, NOM, nom, PRENOM, prenom, JOUR, jour, SEXE, sexe, ETAT, etat, BV, bv, VOTE, vote, -1);
            }
        }
        fclose(f);
        gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
        g_object_unref(store);
    }
}



