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
create_faresfrini_ajoututilisateur_window (void)
{
  GtkWidget *faresfrini_ajoututilisateur_window;
  GtkWidget *fixed1;
  GtkWidget *faresfrini_entry_nom;
  GtkWidget *faresfrini_entry_cin;
  GtkWidget *faresfrini_entry_prenom;
  GtkObject *faresfrini_spin_jour_adj;
  GtkWidget *faresfrini_spin_jour;
  GtkObject *fars_adj;
  GtkWidget *fars;
  GtkObject *spinbutton3_adj;
  GtkWidget *spinbutton3;
  GtkWidget *faresfrini_label_nom;
  GtkWidget *faresfrini_label_tireajout;
  GtkWidget *faresfrini_label_prenom;
  GtkWidget *faresfrini_label_CIN;
  GtkWidget *faresfrini_label_jourajout;
  GtkWidget *label6;
  GtkWidget *label7;
  GtkWidget *label8;
  GtkWidget *button1;
  GtkWidget *alignment1;
  GtkWidget *hbox1;
  GtkWidget *image1;
  GtkWidget *label9;
  GtkWidget *faresfrini_radiobutton_femme;
  GSList *faresfrini_radiobutton_femme_group = NULL;
  GtkWidget *faresfrini_radiobuton_homme;

  faresfrini_ajoututilisateur_window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (faresfrini_ajoututilisateur_window), _("Ajout d'un Utilisateur"));

  fixed1 = gtk_fixed_new ();
  gtk_widget_show (fixed1);
  gtk_container_add (GTK_CONTAINER (faresfrini_ajoututilisateur_window), fixed1);

  faresfrini_entry_nom = gtk_entry_new ();
  gtk_widget_show (faresfrini_entry_nom);
  gtk_fixed_put (GTK_FIXED (fixed1), faresfrini_entry_nom, 72, 88);
  gtk_widget_set_size_request (faresfrini_entry_nom, 130, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (faresfrini_entry_nom), 8226);

  faresfrini_entry_cin = gtk_entry_new ();
  gtk_widget_show (faresfrini_entry_cin);
  gtk_fixed_put (GTK_FIXED (fixed1), faresfrini_entry_cin, 72, 154);
  gtk_widget_set_size_request (faresfrini_entry_cin, 130, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (faresfrini_entry_cin), 8226);

  faresfrini_entry_prenom = gtk_entry_new ();
  gtk_widget_show (faresfrini_entry_prenom);
  gtk_fixed_put (GTK_FIXED (fixed1), faresfrini_entry_prenom, 272, 88);
  gtk_widget_set_size_request (faresfrini_entry_prenom, 130, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (faresfrini_entry_prenom), 8226);

  faresfrini_spin_jour_adj = gtk_adjustment_new (1, 0, 100, 1, 10, 10);
  faresfrini_spin_jour = gtk_spin_button_new (GTK_ADJUSTMENT (faresfrini_spin_jour_adj), 1, 0);
  gtk_widget_show (faresfrini_spin_jour);
  gtk_fixed_put (GTK_FIXED (fixed1), faresfrini_spin_jour, 88, 216);
  gtk_widget_set_size_request (faresfrini_spin_jour, 60, 27);

  fars_adj = gtk_adjustment_new (1, 0, 100, 1, 10, 10);
  fars = gtk_spin_button_new (GTK_ADJUSTMENT (fars_adj), 1, 0);
  gtk_widget_show (fars);
  gtk_fixed_put (GTK_FIXED (fixed1), fars, 200, 216);
  gtk_widget_set_size_request (fars, 60, 27);

  spinbutton3_adj = gtk_adjustment_new (1, 0, 100, 1, 10, 10);
  spinbutton3 = gtk_spin_button_new (GTK_ADJUSTMENT (spinbutton3_adj), 1, 0);
  gtk_widget_show (spinbutton3);
  gtk_fixed_put (GTK_FIXED (fixed1), spinbutton3, 312, 216);
  gtk_widget_set_size_request (spinbutton3, 60, 27);

  faresfrini_label_nom = gtk_label_new (_("Nom"));
  gtk_widget_show (faresfrini_label_nom);
  gtk_fixed_put (GTK_FIXED (fixed1), faresfrini_label_nom, 8, 88);
  gtk_widget_set_size_request (faresfrini_label_nom, 73, 25);

  faresfrini_label_tireajout = gtk_label_new (_("Ajout D'un Utilisateur"));
  gtk_widget_show (faresfrini_label_tireajout);
  gtk_fixed_put (GTK_FIXED (fixed1), faresfrini_label_tireajout, 136, 16);
  gtk_widget_set_size_request (faresfrini_label_tireajout, 200, 32);

  faresfrini_label_prenom = gtk_label_new (_("Prenom"));
  gtk_widget_show (faresfrini_label_prenom);
  gtk_fixed_put (GTK_FIXED (fixed1), faresfrini_label_prenom, 208, 88);
  gtk_widget_set_size_request (faresfrini_label_prenom, 73, 25);

  faresfrini_label_CIN = gtk_label_new (_("CIN"));
  gtk_widget_show (faresfrini_label_CIN);
  gtk_fixed_put (GTK_FIXED (fixed1), faresfrini_label_CIN, 24, 160);
  gtk_widget_set_size_request (faresfrini_label_CIN, 41, 17);

  faresfrini_label_jourajout = gtk_label_new (_("Jour"));
  gtk_widget_show (faresfrini_label_jourajout);
  gtk_fixed_put (GTK_FIXED (fixed1), faresfrini_label_jourajout, 40, 217);
  gtk_widget_set_size_request (faresfrini_label_jourajout, 56, 24);

  label6 = gtk_label_new (_("mois"));
  gtk_widget_show (label6);
  gtk_fixed_put (GTK_FIXED (fixed1), label6, 152, 216);
  gtk_widget_set_size_request (label6, 48, 25);

  label7 = gtk_label_new (_("Ann\303\251e"));
  gtk_widget_show (label7);
  gtk_fixed_put (GTK_FIXED (fixed1), label7, 256, 216);
  gtk_widget_set_size_request (label7, 57, 24);

  label8 = gtk_label_new (_("Date de Naissance"));
  gtk_widget_show (label8);
  gtk_fixed_put (GTK_FIXED (fixed1), label8, 24, 190);
  gtk_widget_set_size_request (label8, 136, 25);

  button1 = gtk_button_new ();
  gtk_widget_show (button1);
  gtk_fixed_put (GTK_FIXED (fixed1), button1, 160, 264);
  gtk_widget_set_size_request (button1, 120, 32);

  alignment1 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment1);
  gtk_container_add (GTK_CONTAINER (button1), alignment1);

  hbox1 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox1);
  gtk_container_add (GTK_CONTAINER (alignment1), hbox1);

  image1 = gtk_image_new_from_stock ("gtk-add", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image1);
  gtk_box_pack_start (GTK_BOX (hbox1), image1, FALSE, FALSE, 0);

  label9 = gtk_label_new_with_mnemonic (_("Ajouter"));
  gtk_widget_show (label9);
  gtk_box_pack_start (GTK_BOX (hbox1), label9, FALSE, FALSE, 0);

  faresfrini_radiobutton_femme = gtk_radio_button_new_with_mnemonic (NULL, _("Femme"));
  gtk_widget_show (faresfrini_radiobutton_femme);
  gtk_fixed_put (GTK_FIXED (fixed1), faresfrini_radiobutton_femme, 216, 160);
  gtk_widget_set_size_request (faresfrini_radiobutton_femme, 116, 24);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (faresfrini_radiobutton_femme), faresfrini_radiobutton_femme_group);
  faresfrini_radiobutton_femme_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (faresfrini_radiobutton_femme));

  faresfrini_radiobuton_homme = gtk_radio_button_new_with_mnemonic (NULL, _("Homme"));
  gtk_widget_show (faresfrini_radiobuton_homme);
  gtk_fixed_put (GTK_FIXED (fixed1), faresfrini_radiobuton_homme, 312, 160);
  gtk_widget_set_size_request (faresfrini_radiobuton_homme, 116, 24);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (faresfrini_radiobuton_homme), faresfrini_radiobutton_femme_group);
  faresfrini_radiobutton_femme_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (faresfrini_radiobuton_homme));

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (faresfrini_ajoututilisateur_window, faresfrini_ajoututilisateur_window, "faresfrini_ajoututilisateur_window");
  GLADE_HOOKUP_OBJECT (faresfrini_ajoututilisateur_window, fixed1, "fixed1");
  GLADE_HOOKUP_OBJECT (faresfrini_ajoututilisateur_window, faresfrini_entry_nom, "faresfrini_entry_nom");
  GLADE_HOOKUP_OBJECT (faresfrini_ajoututilisateur_window, faresfrini_entry_cin, "faresfrini_entry_cin");
  GLADE_HOOKUP_OBJECT (faresfrini_ajoututilisateur_window, faresfrini_entry_prenom, "faresfrini_entry_prenom");
  GLADE_HOOKUP_OBJECT (faresfrini_ajoututilisateur_window, faresfrini_spin_jour, "faresfrini_spin_jour");
  GLADE_HOOKUP_OBJECT (faresfrini_ajoututilisateur_window, fars, "fars");
  GLADE_HOOKUP_OBJECT (faresfrini_ajoututilisateur_window, spinbutton3, "spinbutton3");
  GLADE_HOOKUP_OBJECT (faresfrini_ajoututilisateur_window, faresfrini_label_nom, "faresfrini_label_nom");
  GLADE_HOOKUP_OBJECT (faresfrini_ajoututilisateur_window, faresfrini_label_tireajout, "faresfrini_label_tireajout");
  GLADE_HOOKUP_OBJECT (faresfrini_ajoututilisateur_window, faresfrini_label_prenom, "faresfrini_label_prenom");
  GLADE_HOOKUP_OBJECT (faresfrini_ajoututilisateur_window, faresfrini_label_CIN, "faresfrini_label_CIN");
  GLADE_HOOKUP_OBJECT (faresfrini_ajoututilisateur_window, faresfrini_label_jourajout, "faresfrini_label_jourajout");
  GLADE_HOOKUP_OBJECT (faresfrini_ajoututilisateur_window, label6, "label6");
  GLADE_HOOKUP_OBJECT (faresfrini_ajoututilisateur_window, label7, "label7");
  GLADE_HOOKUP_OBJECT (faresfrini_ajoututilisateur_window, label8, "label8");
  GLADE_HOOKUP_OBJECT (faresfrini_ajoututilisateur_window, button1, "button1");
  GLADE_HOOKUP_OBJECT (faresfrini_ajoututilisateur_window, alignment1, "alignment1");
  GLADE_HOOKUP_OBJECT (faresfrini_ajoututilisateur_window, hbox1, "hbox1");
  GLADE_HOOKUP_OBJECT (faresfrini_ajoututilisateur_window, image1, "image1");
  GLADE_HOOKUP_OBJECT (faresfrini_ajoututilisateur_window, label9, "label9");
  GLADE_HOOKUP_OBJECT (faresfrini_ajoututilisateur_window, faresfrini_radiobutton_femme, "faresfrini_radiobutton_femme");
  GLADE_HOOKUP_OBJECT (faresfrini_ajoututilisateur_window, faresfrini_radiobuton_homme, "faresfrini_radiobuton_homme");

  return faresfrini_ajoututilisateur_window;
}

GtkWidget*
create_faresfrini_confirmerajout_window (void)
{
  GtkWidget *faresfrini_confirmerajout_window;
  GtkWidget *fixed2;
  GtkWidget *label10;
  GtkWidget *button3;
  GtkWidget *alignment3;
  GtkWidget *hbox3;
  GtkWidget *image3;
  GtkWidget *label12;
  GtkWidget *button2;
  GtkWidget *alignment2;
  GtkWidget *hbox2;
  GtkWidget *image2;
  GtkWidget *label11;

  faresfrini_confirmerajout_window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (faresfrini_confirmerajout_window), _("Confirmer"));

  fixed2 = gtk_fixed_new ();
  gtk_widget_show (fixed2);
  gtk_container_add (GTK_CONTAINER (faresfrini_confirmerajout_window), fixed2);

  label10 = gtk_label_new (_("Voulez vous vraiment ajouter cet Utilisateur"));
  gtk_widget_show (label10);
  gtk_fixed_put (GTK_FIXED (fixed2), label10, 40, 56);
  gtk_widget_set_size_request (label10, 320, 48);

  button3 = gtk_button_new ();
  gtk_widget_show (button3);
  gtk_fixed_put (GTK_FIXED (fixed2), button3, 224, 160);
  gtk_widget_set_size_request (button3, 120, 40);

  alignment3 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment3);
  gtk_container_add (GTK_CONTAINER (button3), alignment3);

  hbox3 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox3);
  gtk_container_add (GTK_CONTAINER (alignment3), hbox3);

  image3 = gtk_image_new_from_stock ("gtk-apply", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image3);
  gtk_box_pack_start (GTK_BOX (hbox3), image3, FALSE, FALSE, 0);

  label12 = gtk_label_new_with_mnemonic (_("Confirmer"));
  gtk_widget_show (label12);
  gtk_box_pack_start (GTK_BOX (hbox3), label12, FALSE, FALSE, 0);

  button2 = gtk_button_new ();
  gtk_widget_show (button2);
  gtk_fixed_put (GTK_FIXED (fixed2), button2, 64, 160);
  gtk_widget_set_size_request (button2, 120, 40);

  alignment2 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment2);
  gtk_container_add (GTK_CONTAINER (button2), alignment2);

  hbox2 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox2);
  gtk_container_add (GTK_CONTAINER (alignment2), hbox2);

  image2 = gtk_image_new_from_stock ("gtk-cancel", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image2);
  gtk_box_pack_start (GTK_BOX (hbox2), image2, FALSE, FALSE, 0);

  label11 = gtk_label_new_with_mnemonic (_("Annuler"));
  gtk_widget_show (label11);
  gtk_box_pack_start (GTK_BOX (hbox2), label11, FALSE, FALSE, 0);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (faresfrini_confirmerajout_window, faresfrini_confirmerajout_window, "faresfrini_confirmerajout_window");
  GLADE_HOOKUP_OBJECT (faresfrini_confirmerajout_window, fixed2, "fixed2");
  GLADE_HOOKUP_OBJECT (faresfrini_confirmerajout_window, label10, "label10");
  GLADE_HOOKUP_OBJECT (faresfrini_confirmerajout_window, button3, "button3");
  GLADE_HOOKUP_OBJECT (faresfrini_confirmerajout_window, alignment3, "alignment3");
  GLADE_HOOKUP_OBJECT (faresfrini_confirmerajout_window, hbox3, "hbox3");
  GLADE_HOOKUP_OBJECT (faresfrini_confirmerajout_window, image3, "image3");
  GLADE_HOOKUP_OBJECT (faresfrini_confirmerajout_window, label12, "label12");
  GLADE_HOOKUP_OBJECT (faresfrini_confirmerajout_window, button2, "button2");
  GLADE_HOOKUP_OBJECT (faresfrini_confirmerajout_window, alignment2, "alignment2");
  GLADE_HOOKUP_OBJECT (faresfrini_confirmerajout_window, hbox2, "hbox2");
  GLADE_HOOKUP_OBJECT (faresfrini_confirmerajout_window, image2, "image2");
  GLADE_HOOKUP_OBJECT (faresfrini_confirmerajout_window, label11, "label11");

  return faresfrini_confirmerajout_window;
}

GtkWidget*
create_faresfrini_confirmermodif_window (void)
{
  GtkWidget *faresfrini_confirmermodif_window;
  GtkWidget *fixed3;
  GtkWidget *label13;
  GtkWidget *button4;
  GtkWidget *alignment4;
  GtkWidget *hbox4;
  GtkWidget *image4;
  GtkWidget *label14;
  GtkWidget *button5;
  GtkWidget *alignment5;
  GtkWidget *hbox5;
  GtkWidget *image5;
  GtkWidget *label15;

  faresfrini_confirmermodif_window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (faresfrini_confirmermodif_window), _("Confirmer"));

  fixed3 = gtk_fixed_new ();
  gtk_widget_show (fixed3);
  gtk_container_add (GTK_CONTAINER (faresfrini_confirmermodif_window), fixed3);

  label13 = gtk_label_new (_("Voulez vous Vraiment Modifier \n                   cet Utilisateur"));
  gtk_widget_show (label13);
  gtk_fixed_put (GTK_FIXED (fixed3), label13, 64, 64);
  gtk_widget_set_size_request (label13, 272, 72);

  button4 = gtk_button_new ();
  gtk_widget_show (button4);
  gtk_fixed_put (GTK_FIXED (fixed3), button4, 48, 160);
  gtk_widget_set_size_request (button4, 120, 45);

  alignment4 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment4);
  gtk_container_add (GTK_CONTAINER (button4), alignment4);

  hbox4 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox4);
  gtk_container_add (GTK_CONTAINER (alignment4), hbox4);

  image4 = gtk_image_new_from_stock ("gtk-cancel", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image4);
  gtk_box_pack_start (GTK_BOX (hbox4), image4, FALSE, FALSE, 0);

  label14 = gtk_label_new_with_mnemonic (_("Annuler"));
  gtk_widget_show (label14);
  gtk_box_pack_start (GTK_BOX (hbox4), label14, FALSE, FALSE, 0);

  button5 = gtk_button_new ();
  gtk_widget_show (button5);
  gtk_fixed_put (GTK_FIXED (fixed3), button5, 208, 160);
  gtk_widget_set_size_request (button5, 120, 45);

  alignment5 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment5);
  gtk_container_add (GTK_CONTAINER (button5), alignment5);

  hbox5 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox5);
  gtk_container_add (GTK_CONTAINER (alignment5), hbox5);

  image5 = gtk_image_new_from_stock ("gtk-apply", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image5);
  gtk_box_pack_start (GTK_BOX (hbox5), image5, FALSE, FALSE, 0);

  label15 = gtk_label_new_with_mnemonic (_("Confirmer"));
  gtk_widget_show (label15);
  gtk_box_pack_start (GTK_BOX (hbox5), label15, FALSE, FALSE, 0);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (faresfrini_confirmermodif_window, faresfrini_confirmermodif_window, "faresfrini_confirmermodif_window");
  GLADE_HOOKUP_OBJECT (faresfrini_confirmermodif_window, fixed3, "fixed3");
  GLADE_HOOKUP_OBJECT (faresfrini_confirmermodif_window, label13, "label13");
  GLADE_HOOKUP_OBJECT (faresfrini_confirmermodif_window, button4, "button4");
  GLADE_HOOKUP_OBJECT (faresfrini_confirmermodif_window, alignment4, "alignment4");
  GLADE_HOOKUP_OBJECT (faresfrini_confirmermodif_window, hbox4, "hbox4");
  GLADE_HOOKUP_OBJECT (faresfrini_confirmermodif_window, image4, "image4");
  GLADE_HOOKUP_OBJECT (faresfrini_confirmermodif_window, label14, "label14");
  GLADE_HOOKUP_OBJECT (faresfrini_confirmermodif_window, button5, "button5");
  GLADE_HOOKUP_OBJECT (faresfrini_confirmermodif_window, alignment5, "alignment5");
  GLADE_HOOKUP_OBJECT (faresfrini_confirmermodif_window, hbox5, "hbox5");
  GLADE_HOOKUP_OBJECT (faresfrini_confirmermodif_window, image5, "image5");
  GLADE_HOOKUP_OBJECT (faresfrini_confirmermodif_window, label15, "label15");

  return faresfrini_confirmermodif_window;
}

GtkWidget*
create_faresfrini_confirmersupp_window (void)
{
  GtkWidget *faresfrini_confirmersupp_window;
  GtkWidget *fixed4;
  GtkWidget *button6;
  GtkWidget *alignment6;
  GtkWidget *hbox6;
  GtkWidget *image6;
  GtkWidget *label17;
  GtkWidget *button7;
  GtkWidget *alignment7;
  GtkWidget *hbox7;
  GtkWidget *image7;
  GtkWidget *label18;
  GtkWidget *label16;

  faresfrini_confirmersupp_window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (faresfrini_confirmersupp_window), _("Confirmer"));

  fixed4 = gtk_fixed_new ();
  gtk_widget_show (fixed4);
  gtk_container_add (GTK_CONTAINER (faresfrini_confirmersupp_window), fixed4);

  button6 = gtk_button_new ();
  gtk_widget_show (button6);
  gtk_fixed_put (GTK_FIXED (fixed4), button6, 88, 192);
  gtk_widget_set_size_request (button6, 96, 32);

  alignment6 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment6);
  gtk_container_add (GTK_CONTAINER (button6), alignment6);

  hbox6 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox6);
  gtk_container_add (GTK_CONTAINER (alignment6), hbox6);

  image6 = gtk_image_new_from_stock ("gtk-cancel", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image6);
  gtk_box_pack_start (GTK_BOX (hbox6), image6, FALSE, FALSE, 0);

  label17 = gtk_label_new_with_mnemonic (_("Annuler"));
  gtk_widget_show (label17);
  gtk_box_pack_start (GTK_BOX (hbox6), label17, FALSE, FALSE, 0);

  button7 = gtk_button_new ();
  gtk_widget_show (button7);
  gtk_fixed_put (GTK_FIXED (fixed4), button7, 216, 192);
  gtk_widget_set_size_request (button7, 96, 32);

  alignment7 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment7);
  gtk_container_add (GTK_CONTAINER (button7), alignment7);

  hbox7 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox7);
  gtk_container_add (GTK_CONTAINER (alignment7), hbox7);

  image7 = gtk_image_new_from_stock ("gtk-apply", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image7);
  gtk_box_pack_start (GTK_BOX (hbox7), image7, FALSE, FALSE, 0);

  label18 = gtk_label_new_with_mnemonic (_("Confirmer"));
  gtk_widget_show (label18);
  gtk_box_pack_start (GTK_BOX (hbox7), label18, FALSE, FALSE, 0);

  label16 = gtk_label_new (_("voulez vous vraiment Supprimer cet Utilisateur \n         (Toutes les donn\303\251es seront predues)"));
  gtk_widget_show (label16);
  gtk_fixed_put (GTK_FIXED (fixed4), label16, 64, 56);
  gtk_widget_set_size_request (label16, 320, 80);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (faresfrini_confirmersupp_window, faresfrini_confirmersupp_window, "faresfrini_confirmersupp_window");
  GLADE_HOOKUP_OBJECT (faresfrini_confirmersupp_window, fixed4, "fixed4");
  GLADE_HOOKUP_OBJECT (faresfrini_confirmersupp_window, button6, "button6");
  GLADE_HOOKUP_OBJECT (faresfrini_confirmersupp_window, alignment6, "alignment6");
  GLADE_HOOKUP_OBJECT (faresfrini_confirmersupp_window, hbox6, "hbox6");
  GLADE_HOOKUP_OBJECT (faresfrini_confirmersupp_window, image6, "image6");
  GLADE_HOOKUP_OBJECT (faresfrini_confirmersupp_window, label17, "label17");
  GLADE_HOOKUP_OBJECT (faresfrini_confirmersupp_window, button7, "button7");
  GLADE_HOOKUP_OBJECT (faresfrini_confirmersupp_window, alignment7, "alignment7");
  GLADE_HOOKUP_OBJECT (faresfrini_confirmersupp_window, hbox7, "hbox7");
  GLADE_HOOKUP_OBJECT (faresfrini_confirmersupp_window, image7, "image7");
  GLADE_HOOKUP_OBJECT (faresfrini_confirmersupp_window, label18, "label18");
  GLADE_HOOKUP_OBJECT (faresfrini_confirmersupp_window, label16, "label16");

  return faresfrini_confirmersupp_window;
}

GtkWidget*
create_faresfrini_modif_window (void)
{
  GtkWidget *faresfrini_modif_window;
  GtkWidget *fixed5;
  GtkWidget *label19;
  GtkWidget *label20;
  GtkWidget *combobox1;
  GtkWidget *entry4;
  GtkWidget *button8;
  GtkWidget *alignment8;
  GtkWidget *hbox8;
  GtkWidget *image8;
  GtkWidget *label21;

  faresfrini_modif_window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (faresfrini_modif_window), _("Modification"));

  fixed5 = gtk_fixed_new ();
  gtk_widget_show (fixed5);
  gtk_container_add (GTK_CONTAINER (faresfrini_modif_window), fixed5);

  label19 = gtk_label_new (_("Modification D'un Utilisateur"));
  gtk_widget_show (label19);
  gtk_fixed_put (GTK_FIXED (fixed5), label19, 72, 24);
  gtk_widget_set_size_request (label19, 232, 40);

  label20 = gtk_label_new (_("Information \303\240 modifier"));
  gtk_widget_show (label20);
  gtk_fixed_put (GTK_FIXED (fixed5), label20, 16, 80);
  gtk_widget_set_size_request (label20, 208, 40);

  combobox1 = gtk_combo_box_new_text ();
  gtk_widget_show (combobox1);
  gtk_fixed_put (GTK_FIXED (fixed5), combobox1, 40, 128);
  gtk_widget_set_size_request (combobox1, 160, 40);
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox1), _("."));

  entry4 = gtk_entry_new ();
  gtk_widget_show (entry4);
  gtk_fixed_put (GTK_FIXED (fixed5), entry4, 40, 208);
  gtk_widget_set_size_request (entry4, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry4), 8226);

  button8 = gtk_button_new ();
  gtk_widget_show (button8);
  gtk_fixed_put (GTK_FIXED (fixed5), button8, 112, 248);
  gtk_widget_set_size_request (button8, 128, 37);

  alignment8 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment8);
  gtk_container_add (GTK_CONTAINER (button8), alignment8);

  hbox8 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox8);
  gtk_container_add (GTK_CONTAINER (alignment8), hbox8);

  image8 = gtk_image_new_from_stock ("gtk-apply", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image8);
  gtk_box_pack_start (GTK_BOX (hbox8), image8, FALSE, FALSE, 0);

  label21 = gtk_label_new_with_mnemonic (_("Appliquer"));
  gtk_widget_show (label21);
  gtk_box_pack_start (GTK_BOX (hbox8), label21, FALSE, FALSE, 0);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (faresfrini_modif_window, faresfrini_modif_window, "faresfrini_modif_window");
  GLADE_HOOKUP_OBJECT (faresfrini_modif_window, fixed5, "fixed5");
  GLADE_HOOKUP_OBJECT (faresfrini_modif_window, label19, "label19");
  GLADE_HOOKUP_OBJECT (faresfrini_modif_window, label20, "label20");
  GLADE_HOOKUP_OBJECT (faresfrini_modif_window, combobox1, "combobox1");
  GLADE_HOOKUP_OBJECT (faresfrini_modif_window, entry4, "entry4");
  GLADE_HOOKUP_OBJECT (faresfrini_modif_window, button8, "button8");
  GLADE_HOOKUP_OBJECT (faresfrini_modif_window, alignment8, "alignment8");
  GLADE_HOOKUP_OBJECT (faresfrini_modif_window, hbox8, "hbox8");
  GLADE_HOOKUP_OBJECT (faresfrini_modif_window, image8, "image8");
  GLADE_HOOKUP_OBJECT (faresfrini_modif_window, label21, "label21");

  return faresfrini_modif_window;
}

GtkWidget*
create_faresfrini_gestionutilisateur_window (void)
{
  GtkWidget *faresfrini_gestionutilisateur_window;
  GtkWidget *fixed6;
  GtkWidget *button9;
  GtkWidget *image9;
  GtkWidget *button10;
  GtkWidget *alignment9;
  GtkWidget *hbox9;
  GtkWidget *image10;
  GtkWidget *label22;
  GtkWidget *button11;
  GtkWidget *alignment10;
  GtkWidget *hbox10;
  GtkWidget *image11;
  GtkWidget *label23;
  GtkWidget *button12;
  GtkWidget *alignment11;
  GtkWidget *hbox11;
  GtkWidget *image12;
  GtkWidget *label24;
  GtkWidget *treeview1;
  GtkWidget *checkbutton1;
  GtkWidget *alignment12;
  GtkWidget *hbox12;
  GtkWidget *image13;
  GtkWidget *label26;
  GtkWidget *label25;
  GtkWidget *label29;
  GtkWidget *label27;
  GtkWidget *combobox2;
  GtkWidget *button13;
  GtkWidget *alignment13;
  GtkWidget *hbox13;
  GtkWidget *image14;
  GtkWidget *label28;
  GtkWidget *label30;
  GtkWidget *label31;
  GtkWidget *button14;
  GtkWidget *alignment14;
  GtkWidget *hbox14;
  GtkWidget *image16;
  GtkWidget *label32;
  GtkWidget *image15;

  faresfrini_gestionutilisateur_window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (faresfrini_gestionutilisateur_window), _("window6"));

  fixed6 = gtk_fixed_new ();
  gtk_widget_show (fixed6);
  gtk_container_add (GTK_CONTAINER (faresfrini_gestionutilisateur_window), fixed6);

  button9 = gtk_button_new ();
  gtk_widget_show (button9);
  gtk_fixed_put (GTK_FIXED (fixed6), button9, 24, 16);
  gtk_widget_set_size_request (button9, 80, 32);

  image9 = gtk_image_new_from_stock ("gtk-go-back", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image9);
  gtk_container_add (GTK_CONTAINER (button9), image9);

  button10 = gtk_button_new ();
  gtk_widget_show (button10);
  gtk_fixed_put (GTK_FIXED (fixed6), button10, 32, 72);
  gtk_widget_set_size_request (button10, 96, 40);

  alignment9 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment9);
  gtk_container_add (GTK_CONTAINER (button10), alignment9);

  hbox9 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox9);
  gtk_container_add (GTK_CONTAINER (alignment9), hbox9);

  image10 = gtk_image_new_from_stock ("gtk-add", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image10);
  gtk_box_pack_start (GTK_BOX (hbox9), image10, FALSE, FALSE, 0);

  label22 = gtk_label_new_with_mnemonic (_("Ajouter"));
  gtk_widget_show (label22);
  gtk_box_pack_start (GTK_BOX (hbox9), label22, FALSE, FALSE, 0);

  button11 = gtk_button_new ();
  gtk_widget_show (button11);
  gtk_fixed_put (GTK_FIXED (fixed6), button11, 136, 72);
  gtk_widget_set_size_request (button11, 96, 40);

  alignment10 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment10);
  gtk_container_add (GTK_CONTAINER (button11), alignment10);

  hbox10 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox10);
  gtk_container_add (GTK_CONTAINER (alignment10), hbox10);

  image11 = gtk_image_new_from_stock ("gtk-edit", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image11);
  gtk_box_pack_start (GTK_BOX (hbox10), image11, FALSE, FALSE, 0);

  label23 = gtk_label_new_with_mnemonic (_("Modifier"));
  gtk_widget_show (label23);
  gtk_box_pack_start (GTK_BOX (hbox10), label23, FALSE, FALSE, 0);

  button12 = gtk_button_new ();
  gtk_widget_show (button12);
  gtk_fixed_put (GTK_FIXED (fixed6), button12, 240, 72);
  gtk_widget_set_size_request (button12, 96, 40);

  alignment11 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment11);
  gtk_container_add (GTK_CONTAINER (button12), alignment11);

  hbox11 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox11);
  gtk_container_add (GTK_CONTAINER (alignment11), hbox11);

  image12 = gtk_image_new_from_stock ("gtk-delete", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image12);
  gtk_box_pack_start (GTK_BOX (hbox11), image12, FALSE, FALSE, 0);

  label24 = gtk_label_new_with_mnemonic (_("Supprimer"));
  gtk_widget_show (label24);
  gtk_box_pack_start (GTK_BOX (hbox11), label24, FALSE, FALSE, 0);

  treeview1 = gtk_tree_view_new ();
  gtk_widget_show (treeview1);
  gtk_fixed_put (GTK_FIXED (fixed6), treeview1, 0, 144);
  gtk_widget_set_size_request (treeview1, 300, 200);

  checkbutton1 = gtk_check_button_new ();
  gtk_widget_show (checkbutton1);
  gtk_fixed_put (GTK_FIXED (fixed6), checkbutton1, 480, 136);
  gtk_widget_set_size_request (checkbutton1, 184, 24);

  alignment12 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment12);
  gtk_container_add (GTK_CONTAINER (checkbutton1), alignment12);

  hbox12 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox12);
  gtk_container_add (GTK_CONTAINER (alignment12), hbox12);

  image13 = gtk_image_new_from_stock ("gtk-select-color", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image13);
  gtk_box_pack_start (GTK_BOX (hbox12), image13, FALSE, FALSE, 0);

  label26 = gtk_label_new_with_mnemonic (_("Assignement Auto"));
  gtk_widget_show (label26);
  gtk_box_pack_start (GTK_BOX (hbox12), label26, FALSE, FALSE, 0);

  label25 = gtk_label_new (_("Assignement du bureau de vote"));
  gtk_widget_show (label25);
  gtk_fixed_put (GTK_FIXED (fixed6), label25, 440, 72);
  gtk_widget_set_size_request (label25, 256, 32);

  label29 = gtk_label_new (_("Gestion Utilisateur"));
  gtk_widget_show (label29);
  gtk_fixed_put (GTK_FIXED (fixed6), label29, 248, 8);
  gtk_widget_set_size_request (label29, 184, 40);

  label27 = gtk_label_new (_("Assignement Manuel "));
  gtk_widget_show (label27);
  gtk_fixed_put (GTK_FIXED (fixed6), label27, 472, 176);
  gtk_widget_set_size_request (label27, 184, 24);

  combobox2 = gtk_combo_box_new_text ();
  gtk_widget_show (combobox2);
  gtk_fixed_put (GTK_FIXED (fixed6), combobox2, 424, 216);
  gtk_widget_set_size_request (combobox2, 128, 39);
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox2), _("1"));

  button13 = gtk_button_new ();
  gtk_widget_show (button13);
  gtk_fixed_put (GTK_FIXED (fixed6), button13, 560, 216);
  gtk_widget_set_size_request (button13, 104, 39);

  alignment13 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment13);
  gtk_container_add (GTK_CONTAINER (button13), alignment13);

  hbox13 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox13);
  gtk_container_add (GTK_CONTAINER (alignment13), hbox13);

  image14 = gtk_image_new_from_stock ("gtk-apply", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image14);
  gtk_box_pack_start (GTK_BOX (hbox13), image14, FALSE, FALSE, 0);

  label28 = gtk_label_new_with_mnemonic (_("Appliquer"));
  gtk_widget_show (label28);
  gtk_box_pack_start (GTK_BOX (hbox13), label28, FALSE, FALSE, 0);

  label30 = gtk_label_new (_("Nom admin"));
  gtk_widget_show (label30);
  gtk_fixed_put (GTK_FIXED (fixed6), label30, 520, 288);
  gtk_widget_set_size_request (label30, 112, 32);

  label31 = gtk_label_new (_("Identifiant"));
  gtk_widget_show (label31);
  gtk_fixed_put (GTK_FIXED (fixed6), label31, 536, 320);
  gtk_widget_set_size_request (label31, 96, 24);

  button14 = gtk_button_new ();
  gtk_widget_show (button14);
  gtk_fixed_put (GTK_FIXED (fixed6), button14, 528, 352);
  gtk_widget_set_size_request (button14, 128, 32);

  alignment14 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment14);
  gtk_container_add (GTK_CONTAINER (button14), alignment14);

  hbox14 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox14);
  gtk_container_add (GTK_CONTAINER (alignment14), hbox14);

  image16 = gtk_image_new_from_stock ("gtk-quit", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image16);
  gtk_box_pack_start (GTK_BOX (hbox14), image16, FALSE, FALSE, 0);

  label32 = gtk_label_new_with_mnemonic (_("D\303\251connexion"));
  gtk_widget_show (label32);
  gtk_box_pack_start (GTK_BOX (hbox14), label32, FALSE, FALSE, 0);

  image15 = create_pixmap (faresfrini_gestionutilisateur_window, NULL);
  gtk_widget_show (image15);
  gtk_fixed_put (GTK_FIXED (fixed6), image15, 416, 280);
  gtk_widget_set_size_request (image15, 104, 104);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (faresfrini_gestionutilisateur_window, faresfrini_gestionutilisateur_window, "faresfrini_gestionutilisateur_window");
  GLADE_HOOKUP_OBJECT (faresfrini_gestionutilisateur_window, fixed6, "fixed6");
  GLADE_HOOKUP_OBJECT (faresfrini_gestionutilisateur_window, button9, "button9");
  GLADE_HOOKUP_OBJECT (faresfrini_gestionutilisateur_window, image9, "image9");
  GLADE_HOOKUP_OBJECT (faresfrini_gestionutilisateur_window, button10, "button10");
  GLADE_HOOKUP_OBJECT (faresfrini_gestionutilisateur_window, alignment9, "alignment9");
  GLADE_HOOKUP_OBJECT (faresfrini_gestionutilisateur_window, hbox9, "hbox9");
  GLADE_HOOKUP_OBJECT (faresfrini_gestionutilisateur_window, image10, "image10");
  GLADE_HOOKUP_OBJECT (faresfrini_gestionutilisateur_window, label22, "label22");
  GLADE_HOOKUP_OBJECT (faresfrini_gestionutilisateur_window, button11, "button11");
  GLADE_HOOKUP_OBJECT (faresfrini_gestionutilisateur_window, alignment10, "alignment10");
  GLADE_HOOKUP_OBJECT (faresfrini_gestionutilisateur_window, hbox10, "hbox10");
  GLADE_HOOKUP_OBJECT (faresfrini_gestionutilisateur_window, image11, "image11");
  GLADE_HOOKUP_OBJECT (faresfrini_gestionutilisateur_window, label23, "label23");
  GLADE_HOOKUP_OBJECT (faresfrini_gestionutilisateur_window, button12, "button12");
  GLADE_HOOKUP_OBJECT (faresfrini_gestionutilisateur_window, alignment11, "alignment11");
  GLADE_HOOKUP_OBJECT (faresfrini_gestionutilisateur_window, hbox11, "hbox11");
  GLADE_HOOKUP_OBJECT (faresfrini_gestionutilisateur_window, image12, "image12");
  GLADE_HOOKUP_OBJECT (faresfrini_gestionutilisateur_window, label24, "label24");
  GLADE_HOOKUP_OBJECT (faresfrini_gestionutilisateur_window, treeview1, "treeview1");
  GLADE_HOOKUP_OBJECT (faresfrini_gestionutilisateur_window, checkbutton1, "checkbutton1");
  GLADE_HOOKUP_OBJECT (faresfrini_gestionutilisateur_window, alignment12, "alignment12");
  GLADE_HOOKUP_OBJECT (faresfrini_gestionutilisateur_window, hbox12, "hbox12");
  GLADE_HOOKUP_OBJECT (faresfrini_gestionutilisateur_window, image13, "image13");
  GLADE_HOOKUP_OBJECT (faresfrini_gestionutilisateur_window, label26, "label26");
  GLADE_HOOKUP_OBJECT (faresfrini_gestionutilisateur_window, label25, "label25");
  GLADE_HOOKUP_OBJECT (faresfrini_gestionutilisateur_window, label29, "label29");
  GLADE_HOOKUP_OBJECT (faresfrini_gestionutilisateur_window, label27, "label27");
  GLADE_HOOKUP_OBJECT (faresfrini_gestionutilisateur_window, combobox2, "combobox2");
  GLADE_HOOKUP_OBJECT (faresfrini_gestionutilisateur_window, button13, "button13");
  GLADE_HOOKUP_OBJECT (faresfrini_gestionutilisateur_window, alignment13, "alignment13");
  GLADE_HOOKUP_OBJECT (faresfrini_gestionutilisateur_window, hbox13, "hbox13");
  GLADE_HOOKUP_OBJECT (faresfrini_gestionutilisateur_window, image14, "image14");
  GLADE_HOOKUP_OBJECT (faresfrini_gestionutilisateur_window, label28, "label28");
  GLADE_HOOKUP_OBJECT (faresfrini_gestionutilisateur_window, label30, "label30");
  GLADE_HOOKUP_OBJECT (faresfrini_gestionutilisateur_window, label31, "label31");
  GLADE_HOOKUP_OBJECT (faresfrini_gestionutilisateur_window, button14, "button14");
  GLADE_HOOKUP_OBJECT (faresfrini_gestionutilisateur_window, alignment14, "alignment14");
  GLADE_HOOKUP_OBJECT (faresfrini_gestionutilisateur_window, hbox14, "hbox14");
  GLADE_HOOKUP_OBJECT (faresfrini_gestionutilisateur_window, image16, "image16");
  GLADE_HOOKUP_OBJECT (faresfrini_gestionutilisateur_window, label32, "label32");
  GLADE_HOOKUP_OBJECT (faresfrini_gestionutilisateur_window, image15, "image15");

  return faresfrini_gestionutilisateur_window;
}

