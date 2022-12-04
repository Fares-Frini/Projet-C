#include <gtk/gtk.h>
#include <stdlib.h>
#include "fonction.h"
#include<stdio.h>
int ajouter(Utilisateur p , char filename [])
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %d %d %d %d %d %d %d \n",p.nom,p.prenom,p.cin,p.sexe,p.jour,p.mois,p.annee,p.etat,p.bv);
        fclose(f);
        return 1;
    }
    else return 0;
}

int modifier(int cin, Utilisateur nouv, char * filename)
{
Utilisateur p;
    FILE * f=fopen(filename, "r");
    FILE * f2 =fopen("aux.txt", "w");
    if(f==NULL || f2==NULL)
return 0;
else
    {
while(fscanf(f,"%s %s %d %d %d %d %d %d %d \n",p.nom,p.prenom,&p.cin,&p.sexe,&p.jour,&p.mois,&p.annee,&p.etat,&p.bv)!=EOF)
{
if(p.cin!=cin)
        fprintf(f2,"%s %s %d %d %d %d %d %d %d \n",p.nom,p.prenom,p.cin,p.sexe,p.jour,p.mois,p.annee,p.etat,p.bv);
else

  fprintf(f2,"%s %s %d %d %d %d %d %d %d \n",nouv.nom,nouv.prenom,nouv.cin,nouv.sexe,nouv.jour,nouv.mois,nouv.annee,p.etat,p.bv);

}
        fclose(f);
        fclose(f2);
remove(filename);
rename("aux.txt", filename);
        return 1;
    }
 
}

int supprimer(int cin, char * filename)
{
Utilisateur p;
    FILE * f=fopen(filename, "r");
    FILE * f2 =fopen("aux.txt", "w");
    if(f==NULL || f2==NULL)
return 0;
else
    {
while(fscanf(f,"%s %s %d %d %d %d %d %d %d \n",p.nom,p.prenom,&p.cin,&p.sexe,&p.jour,&p.mois,&p.annee,&p.etat,&p.bv)!=EOF)
{
if(p.cin!=cin)
        fprintf(f2,"%s %s %d %d %d %d %d %d %d \n",p.nom,p.prenom,p.cin,p.sexe,p.jour,p.mois,p.annee,p.etat,p.bv);

}
        fclose(f);
        fclose(f2);
remove(filename);
rename("aux.txt", filename);
        return 1;
    }
}

Utilisateur chercher(int cin, char * filename)
{
Utilisateur p; int tr=0;
    FILE * f=fopen(filename, "r");
 if(f!=NULL )
    {
while(fscanf(f,"%s %s %d %d %d %d %d %d %d \n",p.nom,p.prenom,&p.cin,&p.sexe,&p.jour,&p.mois,&p.annee,&p.etat,&p.bv)!=EOF && tr==0)
{if(p.cin==cin)
tr=1;
}
}
if(tr==0)
p.cin=-1;
return p;

}

int agemoy(Utilisateur p,char filename[])
{
int Age,R=0,i=0;
float Agemoy;
FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
	    while(fscanf(f,"%s %s %d %d %d %d %d %d %d \n",p.nom,p.prenom,&p.cin,&p.sexe,&p.jour,&p.mois,&p.annee,&p.etat,&p.bv)!=EOF)
       	{
            if (p.etat==1)
            {
                R+=2022-p.annee;
                i++;
                
	        }
        }
	    Agemoy=(R*1.0)/(i*1.0);
        fclose(f);
	    return (int)Agemoy;    
    }
    else return 0;
}
int nbelecteur(Utilisateur p,char filename[],int nb)
{
    int nbe;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
	    while(fscanf(f,"%s %s %d %d %d %d %d %d %d \n",p.nom,p.prenom,&p.cin,&p.sexe,&p.jour,&p.mois,&p.annee,&p.etat,&p.bv)!=EOF)
       	{
         if (p.bv==nb)
         {
            nbe+=1;
         }
         
            
        }   
        return nbe; 
    }
    else return 0;
}

/*int nbvotes(char bvfilename[])
{
    int nbe;
    FILE * f=fopen(bvfilename, "r");
    if(f!=NULL)
    {
	    while(fscanf(f,"%s %s %d %d %d %d %d %d %d \n",p.nom,p.prenom,&p.cin,&p.sexe,&p.jour,&p.mois,&p.annee,&p.etat,&p.bv)!=EOF) //A remplir selon le travail de sirine 
       	{
         nbe+=1   ;
        }   
        return nbe; 
    }
    else return 0;
}*/

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
    COLUMNS
};
void afficher_personne(GtkWidget* liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	
	char nom[30];
	char prenom[30];
	int cin ;
	int jour;
	int mois;
	int annee ;
	int etat;
	int sexe;
	int bv;
	FILE *f;
    store = NULL;
	store=gtk_tree_view_get_model(liste);
	if(store==NULL)
	{
	renderer = gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("cin" ,renderer,"text",CIN,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    renderer = gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("nom" ,renderer,"text",NOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    renderer = gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Prenom" ,renderer,"text",PRENOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    renderer = gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Jour" ,renderer,"text",JOUR,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    renderer = gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Mois" ,renderer,"text",MOIS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    renderer = gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Année" ,renderer,"text",ANNEE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    renderer = gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("status" ,renderer,"text",ETAT,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    renderer = gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("bureau de vote" ,renderer,"text",BV,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    renderer = gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("sexe" ,renderer,"text",SEXE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	
    }

    store=gtk_list_store_new(COLUMNS, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);
    f=fopen("utilisateur.txt","r");
    if(f==NULL)
    {
    return;
    }
    else
    {
    f=fopen("utilisateur.txt","a+");
    while(fscanf(f,"%s %s %d %d %d %d %d %d %d \n",nom,prenom,&cin,&sexe,&jour,&mois,&annee,&etat,&bv)!=EOF)
    {
        gtk_list_store_append(store,&iter);
        gtk_list_store_set(store,&iter,cin,nom,prenom,jour,mois,annee,bv,etat,sexe,-1);
    }
    fclose(f);
    gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
    g_object_unref(store);
    
    }
}