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
  GtkWidget *fixed1;
  GtkWidget *entry;
  GtkObject *spinbutton_adj;
  GtkWidget *spinbutton;
  GtkWidget *label1;
  GtkWidget *label2;
  GtkWidget *label3;
  GtkWidget *combobox;
  GtkWidget *recherche;
  GtkWidget *alignment1;
  GtkWidget *hbox1;
  GtkWidget *image1;
  GtkWidget *label4;

  window1 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window1), _("chercher ouvrage"));

  fixed1 = gtk_fixed_new ();
  gtk_widget_show (fixed1);
  gtk_container_add (GTK_CONTAINER (window1), fixed1);

  entry = gtk_entry_new ();
  gtk_widget_show (entry);
  gtk_fixed_put (GTK_FIXED (fixed1), entry, 152, 120);
  gtk_widget_set_size_request (entry, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry), 8226);

  spinbutton_adj = gtk_adjustment_new (1, 0, 100, 1, 10, 10);
  spinbutton = gtk_spin_button_new (GTK_ADJUSTMENT (spinbutton_adj), 1, 0);
  gtk_widget_show (spinbutton);
  gtk_fixed_put (GTK_FIXED (fixed1), spinbutton, 184, 176);
  gtk_widget_set_size_request (spinbutton, 60, 27);

  label1 = gtk_label_new (_("Code ouvrage"));
  gtk_widget_show (label1);
  gtk_fixed_put (GTK_FIXED (fixed1), label1, 24, 40);
  gtk_widget_set_size_request (label1, 96, 16);

  label2 = gtk_label_new (_("Titre ouvrage"));
  gtk_widget_show (label2);
  gtk_fixed_put (GTK_FIXED (fixed1), label2, 8, 128);
  gtk_widget_set_size_request (label2, 128, 16);

  label3 = gtk_label_new (_("Nombre de pages"));
  gtk_widget_show (label3);
  gtk_fixed_put (GTK_FIXED (fixed1), label3, 8, 184);
  gtk_widget_set_size_request (label3, 152, 16);

  combobox = gtk_combo_box_new_text ();
  gtk_widget_show (combobox);
  gtk_fixed_put (GTK_FIXED (fixed1), combobox, 152, 24);
  gtk_widget_set_size_request (combobox, 160, 40);
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox), _("TU1679"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox), _("TU2654"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox), _("TU3978"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox), _("TU3999"));

  recherche = gtk_button_new ();
  gtk_widget_show (recherche);
  gtk_fixed_put (GTK_FIXED (fixed1), recherche, 88, 240);
  gtk_widget_set_size_request (recherche, 200, 32);

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

  g_signal_connect ((gpointer) recherche, "clicked",
                    G_CALLBACK (on_recherche_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (window1, window1, "window1");
  GLADE_HOOKUP_OBJECT (window1, fixed1, "fixed1");
  GLADE_HOOKUP_OBJECT (window1, entry, "entry");
  GLADE_HOOKUP_OBJECT (window1, spinbutton, "spinbutton");
  GLADE_HOOKUP_OBJECT (window1, label1, "label1");
  GLADE_HOOKUP_OBJECT (window1, label2, "label2");
  GLADE_HOOKUP_OBJECT (window1, label3, "label3");
  GLADE_HOOKUP_OBJECT (window1, combobox, "combobox");
  GLADE_HOOKUP_OBJECT (window1, recherche, "recherche");
  GLADE_HOOKUP_OBJECT (window1, alignment1, "alignment1");
  GLADE_HOOKUP_OBJECT (window1, hbox1, "hbox1");
  GLADE_HOOKUP_OBJECT (window1, image1, "image1");
  GLADE_HOOKUP_OBJECT (window1, label4, "label4");

  return window1;
}

