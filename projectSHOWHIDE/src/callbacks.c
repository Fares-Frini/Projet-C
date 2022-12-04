#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"


void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *fenetre_1;
  GtkWidget *fenetre_2;
  fenetre_1 = lookup_widget(button, "fenetre_1");
  gtk_widget_hide (fenetre_1);
  fenetre_2 = create_fenetre_2 ();
  gtk_widget_show (fenetre_2);
}

void
on_button2_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *fenetre_1;
  GtkWidget *fenetre_2;
  fenetre_1 = create_fenetre_1 ();
  gtk_widget_show (fenetre_1);
  fenetre_2 = lookup_widget(button, "fenetre_2");
  gtk_widget_hide (fenetre_2);
}




