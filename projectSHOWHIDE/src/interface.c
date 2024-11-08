/*
 * DO NOT EDIT THIS FILE - it is generated by Glade.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"

#define GLADE_HOOKUP_OBJECT(component,widget,name) \
  g_object_set_data_full (G_OBJECT (component), name, \
    gtk_widget_ref (widget), (GDestroyNotify) gtk_widget_unref)

#define GLADE_HOOKUP_OBJECT_NO_REF(component,widget,name) \
  g_object_set_data (G_OBJECT (component), name, widget)

GtkWidget*
create_fenetre_2 (void)
{
  GtkWidget *fenetre_2;
  GtkWidget *button2;

  fenetre_2 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (fenetre_2), _("fenetre 2"));

  button2 = gtk_button_new_with_mnemonic (_("page precedente"));
  gtk_widget_show (button2);
  gtk_container_add (GTK_CONTAINER (fenetre_2), button2);
  gtk_container_set_border_width (GTK_CONTAINER (button2), 186);

  g_signal_connect ((gpointer) button2, "clicked",
                    G_CALLBACK (on_button2_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (fenetre_2, fenetre_2, "fenetre_2");
  GLADE_HOOKUP_OBJECT (fenetre_2, button2, "button2");

  return fenetre_2;
}

GtkWidget*
create_fenetre_1 (void)
{
  GtkWidget *fenetre_1;
  GtkWidget *button1;

  fenetre_1 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (fenetre_1), _("fenetre 1"));

  button1 = gtk_button_new_with_mnemonic (_("page suivante"));
  gtk_widget_show (button1);
  gtk_container_add (GTK_CONTAINER (fenetre_1), button1);
  gtk_container_set_border_width (GTK_CONTAINER (button1), 186);

  g_signal_connect ((gpointer) button1, "clicked",
                    G_CALLBACK (on_button1_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (fenetre_1, fenetre_1, "fenetre_1");
  GLADE_HOOKUP_OBJECT (fenetre_1, button1, "button1");

  return fenetre_1;
}

