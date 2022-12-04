#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include <stdio.h>
#include <gtk/gtk.h>
#include <stdlib.h>
#include "fonction.h"
#include <string.h>
enum
{
	CIN,
	NOM,
	PRENOM,
	JOUR,
	MOIS,
	ANNEE,
	ETAT,
	BV,
	SEXE,
	ADRESSE,
	COLUMNS,
};
void afficher_personne(GtkWidget *liste)
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
	FILE *f;
	store = NULL;
	store=gtk_tree_view_get_model(liste);
	if (store == NULL)
	{
		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("cin", renderer, "text", CIN, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text", NOM, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("Prenom", renderer, "text", PRENOM, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("Jour", renderer, "text", JOUR, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("Mois", renderer, "text", MOIS, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("Année", renderer, "text", ANNEE, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("status", renderer, "text", ETAT, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("bureau de vote", renderer, "text", BV, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("sexe", renderer, "text", SEXE, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	}

	store=gtk_list_store_new(COLUMNS, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);
  f=fopen("utilisateur.txt","r");
	if(f!=NULL)
	{
	while(fscanf(f,"%s %s %d %d %d %d %d %d %d\n ",nom,prenom,&cin,&sexe,&jour,&mois,&annee,&etat,&bv)!=EOF)
	{
		gtk_list_store_append(store,&iter);
		gtk_list_store_set(store,&iter,CIN,cin,NOM,nom,PRENOM,prenom,JOUR,jour,MOIS,mois,ANNEE,annee,BV,bv,ETAT,etat,SEXE,sexe,-1);
	}
	fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	g_object_unref(store);

	}
}
