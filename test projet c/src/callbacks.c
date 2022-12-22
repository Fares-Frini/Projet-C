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
    char code[10] = "test";
    GtkWidget *combobox;
    GtkWidget *spin;
    GtkWidget *entry;
    combobox = lookup_widget(objet_graphique, "combobox");
    spin = lookup_widget(objet_graphique, "spinbutton");
    entry = lookup_widget(objet_graphique, "entry");
    strcpy(code, gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)));
    p = chercher(code, "V2.txt");
    gtk_spin_button_set_value(spin, p.nb_pages);
    gtk_entry_set_text(entry,p.titre);
}