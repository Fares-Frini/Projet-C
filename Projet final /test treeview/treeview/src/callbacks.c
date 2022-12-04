#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include<string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include"fonction.h"

void
on_afficher_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
    
    GtkWidget *fenetre_afficher ;
    GtkWidget *treeview1;
    
   fenetre_afficher=lookup_widget(objet,"afficher_window");
    fenetre_afficher=create_afficher_window ();
   gtk_widget_show(fenetre_afficher);
   gtk_widget_hide(fenetre_afficher);
    treeview1=lookup_widget(objet,"treeview1");
    printf("error");
    afficher_personne(treeview1);

}
