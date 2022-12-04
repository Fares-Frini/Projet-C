#include <gtk/gtk.h>


void
on_treeview_row_activated              (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_ajout_button_clicked                (GtkWidget *objet_graphique,
                                        gpointer         user_data);

void
on_modifier_button_clicked             (GtkWidget *objet_graphique,
                                        gpointer         user_data);

void
on_supprimer_button_clicked            (GtkWidget *objet_graphique,
                                        gpointer         user_data);

void
on_raffraichir_button_clicked          (GtkWidget *objet_graphique,
                                        gpointer         user_data);

void
on_appliquer_bv_button_clicked         (GtkWidget *objet_graphique,
                                        gpointer         user_data);

void
on_recherche_button_clicked            (GtkWidget *objet_graphique,
                                        gpointer         user_data);

void
on_deconexion_clicked                  (GtkWidget *objet_graphique,
                                        gpointer         user_data);

void
on_bv_auto_checkbox_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_valid_auth_admin_clicked            (GtkWidget *objet_graphique,
                                        gpointer         user_data);

void
on_ajouter_button_clicked              (GtkWidget *objet_graphique,
                                        gpointer         user_data);

void
on_ajouter_homme_radiobutton_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_ajouter_femme_radiobutton_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_confirmer_annuler_button_clicked    (GtkWidget *objet_graphique,
                                        gpointer         user_data);

void
on_confirmer_ajout_button_clicked      (GtkWidget *objet_graphique,
                                        gpointer         user_data);

void
on_continuer_button_clicked            (GtkWidget *objet_graphique,
                                        gpointer         user_data);

void
on_modifier_modifier_button_clicked    (GtkWidget *objet_graphique,
                                        gpointer         user_data);

void
on_confirmer_supp_supp_button_clicked  (GtkWidget *objet_graphique,
                                        gpointer         user_data);

void
on_confirmer_modifier_button_clicked   (GtkWidget *objet_graphique,
                                        gpointer         user_data);
