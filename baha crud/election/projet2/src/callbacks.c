#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"


void on_buttonHello_clicked  (GtkButton *button,  gpointer         user_data)                                                   
{
GtkWidget *input;
GtkWidget *output;
char nom [10],hello[10];
input=lookup_widget(objet_graphique,"entrynom");
output=lookup_widget(objet_graphique,"labelhello");
sayhello(nom,hello);
gtk_label_set_text_(GTK_LABEL(output),hello);
}

