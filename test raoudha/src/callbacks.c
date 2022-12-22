#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "function.h"

void on_register_button_clicked(GtkWidget *objet_graphique, gpointer user_data)
{
    int R;
    GtkWidget *combobox;
    child p;
    GtkWidget *day;
    GtkWidget *month;
    GtkWidget *year;
    GtkWidget *name;
    day = lookup_widget(objet_graphique, "day_spin");
    combobox = lookup_widget(objet_graphique, "combobox1");
    p.day = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(day));
    month = lookup_widget(objet_graphique, "month_spin");
    p.month = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(month));
    year = lookup_widget(objet_graphique, "year_spin");
    p.year = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(year));
    name = lookup_widget(objet_graphique, "name_entry");
    strcpy(p.name, gtk_entry_get_text(GTK_ENTRY(name)));
    if (strcmp("3Years", gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox))) == 0)
    {
        p.class = 1;
    }
    else
    {
        if (strcmp("4Years", gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox))) == 1)
        {
            p.class = 2;
        }
        else
        {
            p.class = 3;
        }
    }

    R = registerr(p, "register.txt");
}
