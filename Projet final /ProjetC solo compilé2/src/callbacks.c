#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"


void
on_afficher_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
    
    GtkWidget *fenetre_afficher;
    GtkWidget *treeview1;
    
    fenetre_afficher=lookup_widget(objet,"faresfrini_gestionutilisateur_window");
    fenetre_afficher=create_faresfrini_gestionutilisateur_window();
   gtk_widget_show(fenetre_afficher);
    treeview1=lookup_widget(fenetre_afficher,"treeview1");
    printf("error");
    afficher_personne(treeview1);

}

