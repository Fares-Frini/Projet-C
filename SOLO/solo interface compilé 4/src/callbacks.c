#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"
int sexe = 1, role = 1;
int choixmodif[]={0,0,0,0,0};
void on_modifier_button_clicked(GtkWidget *objet_graphique,
                                gpointer user_data)
{
    GtkWidget *conf;
    conf = create_modifier();
    gtk_widget_show(conf);
    
}

void on_supprimer_button_clicked(GtkWidget *objet_graphique,
                                 gpointer user_data)
{
    GtkWidget *conf;
    conf = create_confirmer_supp();
    gtk_widget_show(conf);
}

void on_recherche_button_clicked(GtkWidget *objet_graphique,
                                 gpointer user_data)
{
}

void on_treeview_row_activated(GtkTreeView *treeview,
                               GtkTreePath *path,
                               GtkTreeViewColumn *column,
                               gpointer user_data)
{
    GtkTreeIter iter;
    gchar *nom;
    gchar *prenom;
    gchar *date;
    gchar *sexe;
    gchar *cin;
    gchar *bv;
    gchar *etat;
    gchar *vote;
    int Cin;
    char id[10];
    GtkTreeModel *model = gtk_tree_view_get_model(treeview);
    if (gtk_tree_model_get_iter(model, &iter, path))
    {
        FILE *f;
        f = fopen("supp.txt", "w");
        if (f != NULL)
        {
            gtk_tree_model_get(GTK_LIST_STORE(model), &iter, 0, &cin, 1, &nom, 2, &prenom, 3, &date, 4, &sexe, 5, &etat, 6, &bv, 7, &vote, -1);
            fprintf(f, "%s", prenom);
            fclose(f);
        }
    }
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

void on_appliquer_bv_button_clicked(GtkWidget *objet_graphique,
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

void on_raffraichir_button_clicked(GtkWidget *objet_graphique,
                                   gpointer user_data)
{
    GtkWidget *afficher, *w1;
    GtkWidget *treeview;
    w1 = lookup_widget(objet_graphique, "Affichage");
    afficher = create_Affichage();
    gtk_widget_show(afficher);
    gtk_widget_hide(w1);
    treeview = lookup_widget(afficher, "treeview");
    /*  vider(treeview);*/
    convert();
    Afficher_Personne(treeview);
}

void on_verifier_clicked(GtkWidget *objet_graphique,
                         gpointer user_data)
{
}

void on_valid_auth_admin_clicked(GtkWidget *objet_graphique,
                                 gpointer user_data)
{
    Admin a;
    char admin[20] = "admin.txt", id[10];
    GtkWidget *input_id;
    GtkWidget *input_log;
    GtkWidget *input_mdp;
    input_id = lookup_widget(objet_graphique, "auth_id_entry");
    input_mdp = lookup_widget(objet_graphique, "auth_mdp_entry");
    input_log = lookup_widget(objet_graphique, "auth_login_entry");
    strcpy(id, gtk_entry_get_text(GTK_ENTRY(input_id)));
    strcpy(a.login, gtk_entry_get_text(GTK_ENTRY(input_log)));
    strcpy(a.mdp, gtk_entry_get_text(GTK_ENTRY(input_mdp)));
    if (auth(a, admin, id) == 1)
    {
        char connected[20] = "ADMIN:", ID[20] = "ID:";
        GtkWidget *Affichage;
        GtkWidget *authentification;
        GtkWidget *treeview;
        convert();
        authentification = lookup_widget(objet_graphique, "authentification");
        gtk_widget_hide(authentification);
        Affichage = lookup_widget(objet_graphique, "Affichage");
        Affichage = create_Affichage();
        gtk_widget_show(Affichage);
        treeview = lookup_widget(Affichage, "treeview");
        Afficher_Personne(treeview);
        GtkWidget *outputid;
        GtkWidget *outputname;
        outputid = lookup_widget(Affichage, "id_admin");
        strcat(connected, a.login);
        strcat(ID, id);
        gtk_label_set_text(GTK_LABEL(outputid), ID);
        outputname = lookup_widget(Affichage, "label_admin");
        gtk_label_set_text(GTK_LABEL(outputname), connected);
    }
    else
    {
        GtkWidget *refu;
        refu = create_auth_echec();
        gtk_widget_show(refu);
    }
}

void on_ajouter_button_clicked(GtkWidget *objet_graphique,
                               gpointer user_data)
{
    char filename[20] = "utilisateur.txt", cin[12], filenametemp[20] = "utilisateurtemp.txt";
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
    input_nom = lookup_widget(objet_graphique, "ajouter_nom_entry");
    input_prenom = lookup_widget(objet_graphique, "ajouter_prenom_entry");
    input_cin = lookup_widget(objet_graphique, "ajouter_cin_entry");
    p.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
    p.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
    p.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
    strcpy(p.nom, gtk_entry_get_text(GTK_ENTRY(input_nom)));
    strcpy(p.prenom, gtk_entry_get_text(GTK_ENTRY(input_prenom)));
    strcpy(cin, gtk_entry_get_text(GTK_ENTRY(input_cin)));
    p.sexe = sexe;
    p.etat = role;
    p.vote = -1;
    p.bv = 0;
    p.cin = atoi(cin);
    if (verifierajout(p, filename) == 1)
    {
        GtkWidget *conf;
        GtkWidget *ajout;
        conf = create_confirmer_ajout();
        gtk_widget_show(conf);
        ajout = lookup_widget(objet_graphique, "ajouter");
        gtk_widget_hide(ajout);
        ajoutertemp(p, filenametemp);
    }
    else if (verifierajout(p, filename) == 0)
    {
        GtkWidget *output;
        output = lookup_widget(objet_graphique, "ajouter_erreur_label");
        gtk_label_set_text(GTK_LABEL(output), "Veillez verifiez votre CIN");
    }
    else if (verifierajout(p, filename) == 2)
    {
        GtkWidget *output;
        output = lookup_widget(objet_graphique, "ajouter_erreur_label");
        gtk_label_set_text(GTK_LABEL(output), "Date de Naissance Invalide");
    }
    else if (verifierajout(p, filename) == 3)
    {
        GtkWidget *output;
        output = lookup_widget(objet_graphique, "ajouter_erreur_label");
        gtk_label_set_text(GTK_LABEL(output), "L'utilisateur existe deja");
    }
    else if (verifierajout(p, filename) == 4)
    {
        GtkWidget *output;
        output = lookup_widget(objet_graphique, "ajouter_erreur_label");
        gtk_label_set_text(GTK_LABEL(output), "L'utilisateur doit avoir 18 Ans");
    }
}

void on_ajouter_homme_radiobutton_toggled(GtkToggleButton *togglebutton,
                                          gpointer user_data)
{
    if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
    {
        sexe = 1;
    }
}

void on_ajouter_femme_radiobutton_toggled(GtkToggleButton *togglebutton,
                                          gpointer user_data)
{
    if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
        sexe = 2;
}

void on_ajouter_role_electeur_radiobutton_toggled(GtkToggleButton *togglebutton,
                                                  gpointer user_data)
{
    if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
    {
        role = 1;
    }
}

void on_ajouter_role_agentbv_radiobutton_toggled(GtkToggleButton *togglebutton,
                                                 gpointer user_data)
{
    if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
    {
        role = 2;
    }
}

void on_confirmer_annuler_button_clicked(GtkWidget *objet_graphique,
                                         gpointer user_data)
{
    GtkWidget *annajout;
    annajout = lookup_widget(objet_graphique, "confirmer_ajout");
    gtk_widget_hide(annajout);
    GtkWidget *conf;
    conf = lookup_widget(objet_graphique, "confirmer");
    gtk_widget_hide(conf);
    GtkWidget *conf2;
    conf2 = lookup_widget(objet_graphique, "confirmer_supp");
    gtk_widget_hide(conf2);
}

void on_confirmer_ajout_button_clicked(GtkWidget *objet_graphique,
                                       gpointer user_data)
{
    Utilisateur p;
    int R = 0;
    char filename[20] = "utilisateur.txt", tempfilename[20] = "utilisateurtemp.txt";
    R = ajouter(p, filename);
    if (R)
    {
        GtkWidget *ajout;
        ajout = create_resultat_ajout_succ();
        gtk_widget_show(ajout);
        GtkWidget *conf;
        conf = lookup_widget(objet_graphique, "confirmer_ajout");
        gtk_widget_hide(conf);
    }
    else
    {
        GtkWidget *ajout;
        ajout = create_resultat_ajout_echec();
        gtk_widget_show(ajout);
    }
    GtkWidget *conf;
    conf = lookup_widget(objet_graphique, "confirmer_ajout");
    gtk_widget_hide(conf);
}

void on_continuer_button_clicked(GtkWidget *objet_graphique,
                                 gpointer user_data)
{
    GtkWidget *cont;
    cont = lookup_widget(objet_graphique, "resultat_ajout_echec");
    gtk_widget_hide(cont);
    GtkWidget *cont2;
    cont2 = lookup_widget(objet_graphique, "resultat_ajout_succ");
    gtk_widget_hide(cont2);
    GtkWidget *cont3;
    cont3 = lookup_widget(objet_graphique, "auth_echec");
    gtk_widget_hide(cont3);
    GtkWidget *cont5;
    cont5 = lookup_widget(objet_graphique, "resultat_supp_succ");
    gtk_widget_hide(cont5);
    GtkWidget *cont6;
    cont6 = lookup_widget(objet_graphique, "resultat_supp_echec");
    gtk_widget_hide(cont6);
}

void on_modifier_modifier_button_clicked(GtkWidget *objet_graphique,
                                         gpointer user_data)
{
}

void on_modif_nom_check_toggled(GtkToggleButton *togglebutton,
                                gpointer user_data)
{
    if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
    {
        choixmodif[1]=1;
    }
}

void on_confirmer_supp_supp_button_clicked(GtkWidget *objet_graphique,
                                           gpointer user_data)
{
    char filename[20] = "supp.txt";
    int R, E;
    R = cin(filename);
    E = supprimer(R, "utilisateur.txt");
    if (E == 1)
    {
        GtkWidget *ajout;
        ajout = create_resultat_supp_succ();
        gtk_widget_show(ajout);
    }
    else
    {
        GtkWidget *ajout;
        ajout = create_resultat_supp_echec();
        gtk_widget_show(ajout);
    }
    GtkWidget *treeview;
    GtkWidget *afficher;
    afficher = create_Affichage();
    treeview = lookup_widget(afficher, "treeview");
    Afficher_Personne(treeview);
    GtkWidget *cont4;
    cont4 = lookup_widget(objet_graphique, "confirmer_supp");
    gtk_widget_hide(cont4);
}

void on_confirmer_modifier_button_clicked(GtkWidget *objet_graphique,
                                          gpointer user_data)
{
}

void on_valider_modif_nom_clicked(GtkWidget *objet_graphique,
                                  gpointer user_data)
{
}

void on_valider_modif_preno_clicked(GtkWidget *objet_graphique,
                                    gpointer user_data)
{
}

void on_valider_modif_age_clicked(GtkWidget *objet_graphique,
                                  gpointer user_data)
{
}

void on_modif_sexe_femme_toggled(GtkToggleButton *togglebutton,
                                 gpointer user_data)
{
}

void on_modif_sexe_homme_toggled(GtkToggleButton *togglebutton,
                                 gpointer user_data)
{
}

void on_valider_modif_sexe_clicked(GtkWidget *objet_graphique,
                                   gpointer user_data)
{
}

void on_modif_etat_electeur_toggled(GtkToggleButton *togglebutton,
                                    gpointer user_data)
{
}

void on_modif_etat_agentbv_toggled(GtkToggleButton *togglebutton,
                                   gpointer user_data)
{
}

void on_modif_etat_valider_clicked(GtkWidget *objet_graphique,
                                   gpointer user_data)
{
}
