#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"

void on_treeview_row_activated(GtkTreeView *treeview,
                               GtkTreePath *path,
                               GtkTreeViewColumn *column,
                               gpointer user_data)
{
}

void on_ajout_button_clicked(GtkWidget *objet_graphique,
                             gpointer user_data)
{
    GtkWidget *ajout;
    ajout = create_ajouter();
    gtk_widget_show(ajout);
}

void on_modifier_button_clicked(GtkWidget *objet_graphique,
                                gpointer user_data)
{
    GtkWidget *conf;
    GtkWidget *ajout;
    conf = create_confirmer();
    gtk_widget_show(conf);
    ajout = lookup_widget(objet_graphique, "modifier");
    gtk_widget_hide(ajout);
}

void on_supprimer_button_clicked(GtkWidget *objet_graphique,
                                 gpointer user_data)
{
    GtkWidget *conf;
    conf = create_confirmer();
    gtk_widget_show(conf);
}

void on_raffraichir_button_clicked(GtkWidget *objet_graphique,
                                   gpointer user_data)
{
}

void on_appliquer_bv_button_clicked(GtkWidget *objet_graphique,
                                    gpointer user_data)
{
}

void on_recherche_button_clicked(GtkWidget *objet_graphique,
                                 gpointer user_data)
{
}

void on_deconexion_clicked(GtkWidget *objet_graphique,
                           gpointer user_data)
{
    GtkWidget *Affichage;
    GtkWidget *authentification;
    Affichage = lookup_widget(objet_graphique, "Affichage");
    gtk_widget_hide(Affichage);
    authentification = create_authentification();
    gtk_widget_show(authentification);
}

void on_valid_auth_admin_clicked(GtkWidget *objet_graphique,
                                 gpointer user_data)
{
    Admin a;
    char admin[20] = "admin.txt";
    GtkWidget *input_id;
    GtkWidget *input_log;
    GtkWidget *input_mdp;
    input_id = lookup_widget(objet_graphique, "auth_id_entry");
    input_mdp = lookup_widget(objet_graphique, "auth_mdp_entry");
    input_log = lookup_widget(objet_graphique, "auth_login_entry");
    a.id = *gtk_entry_get_text(GTK_ENTRY(input_id));
    strcpy(a.login, gtk_entry_get_text(GTK_ENTRY(input_log)));
    strcpy(a.mdp, gtk_entry_get_text(GTK_ENTRY(input_mdp)));
    if (auth(a, admin))
    {
        GtkWidget *Affichage;
        GtkWidget *authentification;
        authentification = lookup_widget(objet_graphique, "authentification");
        gtk_widget_hide(authentification);
        Affichage = create_Affichage();
        gtk_widget_show(Affichage);
    }
}

void on_ajouter_button_clicked(GtkWidget *objet_graphique,
                               gpointer user_data)
{
    char filename[20];
    Utilisateur p;
    GtkWidget *input_nom;
    GtkWidget *input_prenom;
    GtkWidget *input_cin;
    GtkWidget *jour;
    GtkWidget *mois;
    GtkWidget *annee;
    jour = lookup_widget(objet_graphique, "jour_spin");
    mois = lookup_widget(objet_graphique, "mois_spin");
    annee = lookup_widget(objet_graphique, "annee_spin");
    input_nom = lookup_widget(objet_graphique, "auth_nom_entry");
    input_prenom = lookup_widget(objet_graphique, "auth_prenom_entry");
    input_cin = lookup_widget(objet_graphique, "auth_cin_entry");
    p.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
    p.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
    p.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
    strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(input_nom)));
    strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(input_prenom)));
    strcpy(p.cin,gtk_entry_get_text(GTK_ENTRY(input_cin)));
    ajouter(p,filename);    
    if ()
    {
        GtkWidget *conf;
        GtkWidget *ajout;
        conf = create_confirmer();
        gtk_widget_show(conf);
        ajout = lookup_widget(objet_graphique, "ajouter");
        gtk_widget_hide(ajout);
    }
}

void on_confirmer_button_clicked(GtkWidget *objet_graphique,
                                 gpointer user_data)
{
    GtkWidget *ajout;
    GtkWidget *conf;
    conf = lookup_widget(objet_graphique, "confirmer");
    gtk_widget_hide(conf);
}

void on_confirmer_annuler_button_clicked(GtkWidget *objet_graphique,
                                         gpointer user_data)
{
    GtkWidget *conf;
    conf = lookup_widget(objet_graphique, "confirmer");
    gtk_widget_hide(conf);
}

void on_continuer_button_clicked(GtkWidget *objet_graphique,
                                 gpointer user_data)
{
}

void on_modifier_modifier_button_clicked(GtkWidget *objet_graphique,
                                         gpointer user_data)
{
    GtkWidget *conf;
    conf = create_confirmer();
    gtk_widget_show(conf);
}
