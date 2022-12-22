#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"

void on_recherche_clicked(GtkWidget *objet_graphique, gpointer user_data)
{
    ouvrage p;
    char code[10]="test";
    GtkWidget *combobox;
     GtkWidget *output;
    /*combobox = lookup_widget(objet_graphique, "combobox");
    strcpy(code, gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)));
    p=chercher( code,"V2.txt");
     GtkWidget *spin;
    spin = lookup_widget(objet_graphique, "spinbutton");
    gtk_spin_button_set_value(spin,p.nb_pages);*/
    output=lookup_widget(objet_graphique, "label");
    gtk_label_set_text(GTK_LABEL(output), code);
    GtkWidget *output1;
    output1=lookup_widget(objet_graphique, "label2");
    gtk_label_set_text(GTK_LABEL(output), code);
    GtkWidget *output2;
    output2=lookup_widget(objet_graphique, "label3");
    gtk_label_set_text(GTK_LABEL(output), code);
}
