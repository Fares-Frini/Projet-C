#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"


void
on_ajouter_bouton_clicked(GtkWidget *objet_graphique, gpointer user_data)
{
inscrit p;
GtkWidget* input_nom ;
GtkWidget* input_prenom ;
GtkWidget* input_username ;
GtkWidget* input_password ;
GtkWidget* input_role ;
GtkWidget* output ;
char nom[20],prenom[20],username[20],password[20],resultat[50]
int role;
resultat=ajouter(p,"utilisateur.txt",nom,prenom,username,password,role);
input_nom = lookup_widget(objet_graphique, "entry_nom") ;
input_prenom = lookup_widget(objet_graphique, "entry_prenom") ;
input_username = lookup_widget(objet_graphique, "entry_username") ;
input_password = lookup_widget(objet_graphique, "entry_password") ;
input_role = lookup_widget(objet_graphique, "entry_role") ;
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input_nom)));
strcpy(prenom,gtk_entry_get_text(GTK_ENTRY(input_prenom)));
strcpy(username,gtk_entry_get_text(GTK_ENTRY(input_username)));
strcpy(password,gtk_entry_get_text(GTK_ENTRY(input_password)));
strcpy(role,gtk_entry_get_text(GTK_ENTRY(input_role)));
output = lookup_widget(objet_graphique, "label_resultat") ;
gtk_label_set_text(GTK_LABEL(output),resultat);
}


void
on_button2_clicked(GtkWidget *objet_graphique, gpointer user_data)
{
int rt;
GtkWidget* input_username ;
GtkWidget* input_password ;
char username[20],password[20];
input_username = lookup_widget(objet_graphique, "entry_auth_username");
input_password = lookup_widget(objet_graphique, "entry_auth_password");
strcpy(username,gtk_entry_get_text(GTK_ENTRY(input_username)));
strcpy(password,gtk_entry_get_text(GTK_ENTRY(input_password)));
rt=login(username,password,"utilisateur.txt");
gtk_label_set_text(GTK_LABEL(output),rt);
}

