#include<stdio.h>
#include<stdlib.h>
#include "bv.h"
#include <gtk/gtk.h>
enum
{
    ID,
    IDAGBV,
    REGION,
    MNP,
    ADRESSE,
    SALLE,
    CPT_OBSER,
    CPT_ELEC,
    COLUMNS
};
int ajouterbv(BVOTE p){
	FILE *f;
	f=fopen("bureauvote.txt","a+");
	if(f==NULL){
		return 0;
	}
	else{
		fprintf(f,"%d %d %s %s %s %d %d %d \n",p.ID,p.IDAGBV,p.Region,p.Mnp,p.Adresse,p.salle,p.cpt_elec,p.cpt_obser);
		};
		fclose(f);
		return 1;
	}

int modifierbv(int ID_modifier,BVOTE nouv){
	BVOTE p;
	FILE *f,*f1;
	f=fopen("bureauvote.txt","r");
	f1=fopen("tmp.txt","a+");
	if(f==NULL || f1==NULL){
		return 0;
	}
	else{
		while(fscanf(f,"%d %d %s %s %s %d %d %d  \n",&p.ID,&p.IDAGBV,p.Region,p.Mnp,p.Adresse,&p.salle,&p.cpt_elec,&p.cpt_obser)!=EOF)
		{
			if(p.ID==ID_modifier){
				fprintf(f1,"%d %d %s %s %s %d %d %d  \n",ID_modifier,nouv.IDAGBV,nouv.Region,nouv.Mnp,nouv.Adresse,nouv.salle,nouv.cpt_elec,nouv.cpt_obser);
			}
			else{
				fprintf(f1,"%d %d %s %s %s %d %d %d \n",p.ID,p.IDAGBV,p.Region,p.Mnp,p.Adresse,p.salle,p.cpt_elec,p.cpt_obser);

			}
		}
		fclose(f);
		fclose(f1);
		remove("bureauvote.txt");
		rename("tmp.txt","bureauvote.txt");
		return 1;
	}
	
}
int supprimerbv(int ID_supprimer){
	BVOTE p;
	FILE *f,*f1;
	f=fopen("bureauvote.txt","r");
	f1=fopen("tmp.txt","a+");
	if(f==NULL || f1==NULL){
		return 0;
	}
	
	else{
		while(fscanf(f,"%d %d %s %s %s %d %d %d  \n",&p.ID,&p.IDAGBV,p.Region,p.Mnp,p.Adresse,&p.salle,&p.cpt_elec,&p.cpt_obser)!=EOF)
		{
	if(p.ID!=ID_supprimer){
				fprintf(f1,"%d %d %s %s %s %d %d %d  \n",p.ID,p.IDAGBV,p.Region,p.Mnp,p.Adresse,p.salle,p.cpt_elec,p.cpt_obser);
			}
			
		}
		fclose(f);
		fclose(f1);
		remove("bureauvote.txt");
		rename("tmp.txt","bureauvote.txt");
		return 1;
	}
}
int recherchebv(int ID_recherche){
	int trouve=0;
	BVOTE p;
	FILE *f;
	f=fopen("bureauvote.txt","r");
	if(f==NULL){
		return 0;
	}
	else{
		while(fscanf(f,"%d %d %s %s %s %d %d %d  \n",&p.ID,&p.IDAGBV,p.Region,p.Mnp,p.Adresse,&p.salle,&p.cpt_elec,&p.cpt_obser)!=EOF)
		{
			if(ID_recherche==p.ID)
				trouve= 1;
		}
		fclose(f);
		return trouve;
	}
}
int afficherbv(){
	BVOTE p;
	FILE *f;
	f=fopen("bureauvote.txt","r");
	if(f==NULL){
		return 0;
	}
	else{
		while(fscanf(f,"%d %d %s %s %s %d %d %d  \n",&p.ID,&p.IDAGBV,p.Region,p.Mnp,p.Adresse,&p.salle,&p.cpt_elec,&p.cpt_obser)!=EOF)
		{
			printf("%d %d %s %s %s %d %d %d  \n",p.ID,p.IDAGBV,p.Region,p.Mnp,p.Adresse,p.salle,p.cpt_elec,p.cpt_obser);
		}
		fclose(f);
		return 1;
	}
}
///////////////////////////////////////////////////////////////////////////////////////////
/*
void ajouter_bv(BVOTE p){
	FILE *f;
	f=fopen("bureauvote.txt","a+");
	if(f!=NULL)
{
fprintf(f,"%s %s %s %s %s %s %s %s \n",p.ID,p.IDAGBV,p.Region,p.Mnp,p.Adresse,p.salle,p.cpt_elec,p.cpt_obser);
		fclose(f);
	}
	}
*/
/*
void ssupprimerbv(BVOTE p)
{
	BVOTE p;
	FILE *f,*f1;
	f=fopen("bureauvote.txt","r");
	f1=fopen("tmp.txt","a+");
	if(f==NULL || f1==NULL)
{
		return ;
	}
	
	else
{
		while(fscanf(f,"%d %d %s %s %s %d %d %d  \n",&p.ID,&p.IDAGBV,p.Region,p.Mnp,p.Adresse,&p.salle,&p.cpt_elec,&p.cpt_obser)!=EOF)
		{
	if(p.ID!=ID_supprimer)
{
				fprintf(f1,"%d %d %s %s %s %d %d %d  \n",p.ID,p.IDAGBV,p.Region,p.Mnp,p.Adresse,p.salle,p.cpt_elec,p.cpt_obser);
			}
			
		}
		fclose(f);
		fclose(f1);
		remove("bureauvote.txt");
		rename("tmp.txt","bureauvote.txt");
	}
}
*/
void supprimer_bv(BVOTE p)
{
    char id[30];
    char idagbv[30];
    char region[30];
    char mnp[30];
    char adresse[30];
    char salle[20];
    char cpt_elec[20];
    char cpt_obser[20];

	FILE *f,*f1;
	f=fopen("bureauvote.txt","r");
	f1=fopen("tmp.txt","a+");
	if(f==NULL || f1==NULL)
        {
		return ;
	}
	
	else{
		while(fscanf(f,"%s %s %s %s %s %s %s %s  \n",id,idagbv,region,mnp,adresse,salle,cpt_elec,cpt_obser)!=EOF)
		{
	if(strcmp(p.ID,id)!=0||strcmp(p.IDAGBV,idagbv)!=0||strcmp(p.Region,region)!=0||strcmp(p.Mnp,mnp)!=0||strcmp(p.Adresse,adresse)!=0||strcmp(p.salle,salle)!=0||strcmp(p.cpt_elec,cpt_elec)!=0||strcmp(p.cpt_obser,cpt_obser)!=0)

fprintf(f1,"%s %s %s %s %s %s %s %s  \n",id,idagbv,region,mnp,adresse,salle,cpt_elec,cpt_obser);
			
			
		}
		fclose(f);
		fclose(f1);
		remove("bureauvote.txt");
		rename("tmp.txt","bureauvote.txt");
		
	}

}

void vider(GtkWidget *liste)
{
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;
    char id[30];
    char idagbv[30];
    char region[30];
    char mnp[30];
    char adresse[30];
    char salle[20];
    char cpt_elec[20];
    char cpt_obser[20];
  
    FILE *f;
    store = gtk_tree_view_get_model(liste);
if (store == NULL)
    {
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ID", renderer, "text", ID, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("IDAGBV", renderer, "text", IDAGBV, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
        column = gtk_tree_view_column_new_with_attributes("Region", renderer, "text", REGION, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
        column = gtk_tree_view_column_new_with_attributes("Municipalité", renderer, "text", MNP, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
        column = gtk_tree_view_column_new_with_attributes("Adresse", renderer, "text", ADRESSE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
        column = gtk_tree_view_column_new_with_attributes("Salle", renderer, "text", SALLE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
 	column = gtk_tree_view_column_new_with_attributes("Capacités des électeurs", renderer, "text", CPT_ELEC, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
        column = gtk_tree_view_column_new_with_attributes("Capacités des observateurs", renderer, "text", CPT_OBSER, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

   }
 store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

gtk_list_store_append(store, &iter);

gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
//g_object_unref(store);


}

void Afficher_Bureau_de_Vote(GtkWidget *liste)
{
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;
    char id[30];
    char idagbv[30];
    char region[30];
    char mnp[30];
    char adresse[30];
    char salle[20];
    char cpt_elec[20];
    char cpt_obser[20];
  
    FILE *f;
    store = NULL;
    store = gtk_tree_view_get_model(liste);
    if (store == NULL)
    {
          renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ID", renderer, "text", ID, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("IDAGBV", renderer, "text", IDAGBV, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
        column = gtk_tree_view_column_new_with_attributes("Region", renderer, "text", REGION, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
        column = gtk_tree_view_column_new_with_attributes("Municipalité", renderer, "text", MNP, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
        column = gtk_tree_view_column_new_with_attributes("Adresse", renderer, "text", ADRESSE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
        column = gtk_tree_view_column_new_with_attributes("Salle", renderer, "text", SALLE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
 	column = gtk_tree_view_column_new_with_attributes("Capacités des électeurs", renderer, "text", CPT_ELEC, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
        column = gtk_tree_view_column_new_with_attributes("Capacités des observateurs", renderer, "text", CPT_OBSER, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
       

        store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
        f = fopen("bureauvote.txt", "r");
        if (f == NULL)
        {
            return;
        }
        else
        {
            f = fopen("bureauvote.txt", "a+");
            while (fscanf(f, "%s %s %s %s %s %s %s %s \n ", id, idagbv, region, mnp, adresse, salle, cpt_elec, cpt_obser) != EOF)
            {
                gtk_list_store_append(store, &iter);
                gtk_list_store_set(store, &iter, ID, id,IDAGBV, idagbv,REGION, region,MNP,mnp, ADRESSE,adresse, SALLE,salle,CPT_ELEC,cpt_elec,CPT_OBSER,cpt_obser, -1);
            }
        }
        fclose(f);
        gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
        g_object_unref(store);
    }
}


void supprimerr_bv(BUVOTE b)
{
    char id[30];
    char idagbv[30];
    char region[30];
    char mnp[30];
    char adresse[30];
    char salle[20];
    char cpt_elec[20];
    char cpt_obser[20];

	FILE *f,*f1;
	f=fopen("bureauvote.txt","r");
	f1=fopen("tmp.txt","a+");
	if(f==NULL || f1==NULL)
        {
		return ;
	}
	
	else{
		while(fscanf(f,"%s %s %s %s %s %s %s %s  \n",id,idagbv,region,mnp,adresse,salle,cpt_elec,cpt_obser)!=EOF)
		{
	if(strcmp(b.ID,id)!=0||strcmp(b.IDAGBV,idagbv)!=0||strcmp(b.Region,region)!=0||strcmp(b.Mnp,mnp)!=0||strcmp(b.Adresse,adresse)!=0||strcmp(b.salle,salle)!=0||strcmp(b.cpt_elec,cpt_elec)!=0||strcmp(b.cpt_obser,cpt_obser)!=0)

fprintf(f1,"%s %s %s %s %s %s %s %s  \n",id,idagbv,region,mnp,adresse,salle,cpt_elec,cpt_obser);
			
			
		}
		fclose(f);
		fclose(f1);
		remove("bureauvote.txt");
		rename("tmp.txt","bureauvote.txt");
		
	}

}
void ajouterr_bv(BUVOTE b){
	FILE *f;
	f=fopen("bureauvote.txt","a+");
	if(f!=NULL)
{
fprintf(f,"%s %s %s %s %s %s %s %s \n",b.ID,b.IDAGBV,b.Region,b.Mnp,b.Adresse,b.salle,b.cpt_elec,b.cpt_obser);
		fclose(f);
	}
	}
/*int supprimer(int ID_supprimer, char * filename)
{
BVOTE p;
    FILE * f=fopen(filename, "r");
    FILE * f2 =fopen("aux.txt", "w");
    if(f==NULL || f2==NULL)
return 0;
else
    {
while(fscanf(f,"%d %d %s %s %s %d %d %d  \n",&p.ID,&p.IDAGBV,p.Region,p.Mnp,p.Adresse,&p.salle,&p.cpt_elec,&p.cpt_obser)!=EOF)
{
if(p.ID!=ID_supprimer)
       fprintf(f2,"%d %s %s %d %d %d %d\n","%d %d %s %s %s %d %d %d  \n",p.ID,p.IDAGBV,p.Region,p.Mnp,p.Adresse,p.salle,p.cpt_elec,p.cpt_obser);


}
        fclose(f);
        fclose(f2);
remove(filename);
rename("aux.txt", filename);
        return 1;
    }
}*/
int modifier_bv(char* filename ,int ID_modifier,BVOTE nouv)
{
	int tr=0;
BVOTE p;
	FILE *f,*f1;
	f=fopen("bureauvote.txt","r");
	f1=fopen("tmp.txt","a+");
	if(f!=NULL && f1!=NULL)
		{
		
		while(fscanf(f,"%d %d %s %s %s %d %d %d  \n",&p.ID,&p.IDAGBV,p.Region,p.Mnp,p.Adresse,&p.salle,&p.cpt_elec,&p.cpt_obser)!=EOF)
		{
			if(p.ID==ID_modifier)
			{
				fprintf(f1,"%d %d %s %s %s %d %d %d  \n",ID_modifier,nouv.IDAGBV,nouv.Region,nouv.Mnp,nouv.Adresse,nouv.salle,nouv.cpt_elec,nouv.cpt_obser);
		tr=1;	
		}
			else fprintf(f1,"%d %d %s %s %s %d %d %d \n",p.ID,p.IDAGBV,p.Region,p.Mnp,p.Adresse,p.salle,p.cpt_elec,p.cpt_obser);

			}
		}
		fclose(f);
		fclose(f1);
		remove("bureauvote.txt");
		rename("tmp.txt","bureauvote.txt");
		return (tr);
	
	
}



