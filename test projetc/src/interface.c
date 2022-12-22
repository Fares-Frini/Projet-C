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
create_window1 (void)
{
  GtkWidget *window1;
  GtkWidget *fixed2;
  GtkObject *spinbutton_adj;
  GtkWidget *spinbutton;
  GtkWidget *entry;
  GtkWidget *label3;
  GtkWidget *label2;
  GtkWidget *label1;
  GtkWidget *recherche;
  GtkWidget *alignment1;
  GtkWidget *hbox1;
  GtkWidget *image1;
  GtkWidget *label4;
  GtkWidget *combobox;

  window1 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_size_request (window1, 380, 266);
  gtk_window_set_title (GTK_WINDOW (window1), _("window1"));

  fixed2 = gtk_fixed_new ();
  gtk_widget_show (fixed2);
  gtk_container_add (GTK_CONTAINER (window1), fixed2);

  spinbutton_adj = gtk_adjustment_new (1, 0, 100, 1, 10, 10);
  spinbutton = gtk_spin_button_new (GTK_ADJUSTMENT (spinbutton_adj), 1, 0);
  gtk_widget_show (spinbutton);
  gtk_fixed_put (GTK_FIXED (fixed2), spinbutton, 152, 152);
  gtk_widget_set_size_request (spinbutton, 60, 27);

  entry = gtk_entry_new ();
  gtk_widget_show (entry);
  gtk_fixed_put (GTK_FIXED (fixed2), entry, 144, 104);
  gtk_widget_set_size_request (entry, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry), 8226);

  label3 = gtk_label_new (_("Nombre de pages"));
  gtk_widget_show (label3);
  gtk_fixed_put (GTK_FIXED (fixed2), label3, 8, 152);
  gtk_widget_set_size_request (label3, 128, 24);

  label2 = gtk_label_new (_("Titre ouvrage"));
  gtk_widget_show (label2);
  gtk_fixed_put (GTK_FIXED (fixed2), label2, 8, 104);
  gtk_widget_set_size_request (label2, 112, 24);

  label1 = gtk_label_new (_("Code Ouvrage"));
  gtk_widget_show (label1);
  gtk_fixed_put (GTK_FIXED (fixed2), label1, 16, 48);
  gtk_widget_set_size_request (label1, 104, 24);

  recherche = gtk_button_new ();
  gtk_widget_show (recherche);
  gtk_fixed_put (GTK_FIXED (fixed2), recherche, 72, 216);
  gtk_widget_set_size_request (recherche, 208, 32);

  alignment1 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment1);
  gtk_container_add (GTK_CONTAINER (recherche), alignment1);

  hbox1 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox1);
  gtk_container_add (GTK_CONTAINER (alignment1), hbox1);

  image1 = gtk_image_new_from_stock ("gtk-find", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image1);
  gtk_box_pack_start (GTK_BOX (hbox1), image1, FALSE, FALSE, 0);

  label4 = gtk_label_new_with_mnemonic (_("Rechercher ouvrage"));
  gtk_widget_show (label4);
  gtk_box_pack_start (GTK_BOX (hbox1), label4, FALSE, FALSE, 0);

  combobox = gtk_combo_box_new_text ();
  gtk_widget_show (combobox);
  gtk_fixed_put (GTK_FIXED (fixed2), combobox, 144, 40);
  gtk_widget_set_size_request (combobox, 160, 32);
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox), _("TU1679"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox), _("TU2654    "));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox), _("TU3978     "));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox), _("TU3999  "));

  g_signal_connect ((gpointer) recherche, "clicked",
                    G_CALLBACK (on_recherche_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (window1, window1, "window1");
  GLADE_HOOKUP_OBJECT (window1, fixed2, "fixed2");
  GLADE_HOOKUP_OBJECT (window1, spinbutton, "spinbutton");
  GLADE_HOOKUP_OBJECT (window1, entry, "entry");
  GLADE_HOOKUP_OBJECT (window1, label3, "label3");
  GLADE_HOOKUP_OBJECT (window1, label2, "label2");
  GLADE_HOOKUP_OBJECT (window1, label1, "label1");
  GLADE_HOOKUP_OBJECT (window1, recherche, "recherche");
  GLADE_HOOKUP_OBJECT (window1, alignment1, "alignment1");
  GLADE_HOOKUP_OBJECT (window1, hbox1, "hbox1");
  GLADE_HOOKUP_OBJECT (window1, image1, "image1");
  GLADE_HOOKUP_OBJECT (window1, label4, "label4");
  GLADE_HOOKUP_OBJECT (window1, combobox, "combobox");

  return window1;
}

