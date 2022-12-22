#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "user.h"
#include "authentification.h"
#include "admin.h"
#include "observateur.h"
#include "bv.h"

int sexe = 1, nationalite = 1, Role = 1;
int l = 1, choix[] = {0, 0}, prof[] = {0, 0, 0, 0, 0, 0};
int x = 30;
int y = 30;
int c = 1;

void on_RG_radiobuttonH_toggled(GtkToggleButton *togglebutton,
                                gpointer user_data)
{
  if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
  {
    sexe = 2;
  }
}

void on_RG_radiobuttonT_toggled(GtkToggleButton *togglebutton,
                                gpointer user_data)
{
  if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
  {
    nationalite = 1;
  }
}

void on_RG_radiobuttonAutre_toggled(GtkToggleButton *togglebutton,
                                    gpointer user_data)
{
  if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
  {
    nationalite = 2;
  }
}

void on_RG_radiobuttonC_toggled(GtkToggleButton *togglebutton,
                                gpointer user_data)
{
  if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
  {
    l = 3;
  }
}

void on_RG_radiobuttonD_toggled(GtkToggleButton *togglebutton,
                                gpointer user_data)
{
  if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
  {
    l = 2;
  }
}

void on_RG_radiobuttonM_toggled(GtkToggleButton *togglebutton,
                                gpointer user_data)
{
  if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
  {
    l = 1;
  }
}

void on_RG_checkbuttonA_toggled(GtkToggleButton *togglebutton,
                                gpointer user_data)
{
  if (gtk_toggle_button_get_active(GTK_CHECK_BUTTON(togglebutton)))
  {
    choix[1] = 2;
  }
}

void on_RG_checkbuttonE_toggled(GtkToggleButton *togglebutton,
                                gpointer user_data)
{
  if (gtk_toggle_button_get_active(GTK_CHECK_BUTTON(togglebutton)))
  {
    choix[0] = 1;
  }
}

void on_RG_buttonACC_clicked(GtkButton *button,
                             gpointer user_data)
{
  GtkWidget *RG_GestionUser;
  GtkWidget *RG_windowNU;
  RG_windowNU = lookup_widget(button, "RG_windowNU");
  gtk_widget_hide(RG_windowNU);
  RG_GestionUser = create_RG_GestionUser();
  gtk_widget_show(RG_GestionUser);
}

void on_RG_buttonAJ_clicked(GtkWidget *objet_graphique,
                            gpointer user_data)
{
  int x, tab[2] = {1, 1}, i;
  char filename[200] = "user.txt", cin[20];

  User U;
  GtkWidget *RG_entrynom;
  GtkWidget *RG_entryPrenom;
  GtkWidget *RG_entryCIN;
  GtkWidget *RG_spinbuttonJour;
  GtkWidget *RG_spinbuttonMois;
  GtkWidget *RG_spinbuttonannee;
  GtkWidget *RG_radiobuttonT;
  GtkWidget *RG_radiobuttonAutre;
  GtkWidget *RG_comboboxentryG;
  GtkWidget *comboboxentryM;
  GtkWidget *RG_spinbuttonNBV;
  GtkWidget *RG_checkbuttonA;
  GtkWidget *RG_checkbuttonE;

  RG_entrynom = lookup_widget(objet_graphique, "RG_entrynom");
  RG_entryPrenom = lookup_widget(objet_graphique, "RG_entryPrenom");
  RG_entryCIN = lookup_widget(objet_graphique, "RG_entryCIN");
  RG_spinbuttonJour = lookup_widget(objet_graphique, "RG_spinbuttonJour");
  RG_spinbuttonMois = lookup_widget(objet_graphique, "RG_spinbuttonMois");
  RG_spinbuttonannee = lookup_widget(objet_graphique, "RG_spinbuttonannee");
  RG_spinbuttonNBV = lookup_widget(objet_graphique, "RG_spinbuttonNBV");
  RG_comboboxentryG = lookup_widget(objet_graphique, "RG_comboboxentryG");
  comboboxentryM = lookup_widget(objet_graphique, "comboboxentryM");
  RG_checkbuttonE = lookup_widget(objet_graphique, "RG_checkbuttonE");
  RG_checkbuttonA = lookup_widget(objet_graphique, "RG_checkbuttonA");

  U.d.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(RG_spinbuttonJour));
  U.d.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(RG_spinbuttonMois));
  U.d.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(RG_spinbuttonannee));
  U.idBV = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(RG_spinbuttonNBV));
  strcpy(U.Nom, gtk_entry_get_text(GTK_ENTRY(RG_entrynom)));
  strcpy(U.Prenom, gtk_entry_get_text(GTK_ENTRY(RG_entryPrenom)));
  strcpy(U.gouvernorat, gtk_combo_box_get_active_text(GTK_COMBO_BOX(RG_comboboxentryG)));
  strcpy(U.municipalite, gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentryM)));
  strcpy(cin, gtk_entry_get_text(GTK_ENTRY(RG_entryCIN)));
  U.sexe = sexe;
  U.etatSocial = l;
  U.Vote = -1;
  U.nationalite = nationalite;
  if (tab[0] == 1)
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(RG_checkbuttonA), TRUE);
  if (tab[1] == 2)
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(RG_checkbuttonE), TRUE);

  U.cin = atoi(cin);
  U.Role = tab[i];
  x = ajouter("User.txt", U);
}

void on_RG_buttonAff_clicked(GtkWidget *objet,
                             gpointer user_data)
{
  GtkWidget *RG_GestionUser;
  GtkWidget *RG_windowNU;
  GtkWidget *RG_treeviewUser;
  RG_windowNU = lookup_widget(objet, "RG_windowNU");
  RG_GestionUser = lookup_widget(objet, "RG_GestionUser ");
  RG_GestionUser = create_RG_GestionUser();
  RG_treeviewUser = lookup_widget(RG_GestionUser, "RG_treeviewUser");
  affiche_userr(RG_treeviewUser);
}

void on_buttonCV_clicked(GtkButton *button,
                         gpointer user_data)
{
}

void on_SR_buttonAV_clicked(GtkButton *button,
                            gpointer user_data)
{
}

void on_SR_buttonML_clicked(GtkButton *button,
                            gpointer user_data)
{
}

void on_SRbuttonSL_clicked(GtkButton *button,
                           gpointer user_data)
{
}

void on_SR_buttonCHER_clicked(GtkButton *button,
                              gpointer user_data)
{
}

void on_buttonPRE2_clicked(GtkButton *button,
                           gpointer user_data)
{
}

void on_droitebutton_toggled(GtkToggleButton *togglebutton,
                             gpointer user_data)
{
}

void on_SR_radiobuttonG_toggled(GtkToggleButton *togglebutton,
                                gpointer user_data)
{
}

void on_centrebutton_toggled(GtkToggleButton *togglebutton,
                             gpointer user_data)
{
}

void on_buttonCA_clicked(GtkButton *button,
                         gpointer user_data)
{
}

void on_SR_buttonPR_clicked(GtkButton *button,
                            gpointer user_data)
{
}

void on_SR_afficherListe_clicked(GtkButton *button,
                                 gpointer user_data)
{
}

void on_RG_checkbuttonHote_toggled(GtkToggleButton *togglebutton,
                                   gpointer user_data)
{
  if (gtk_toggle_button_get_active(GTK_CHECK_BUTTON(togglebutton)))
  {
    prof[1] = 2;
  }
}

void on_RG_checkbuttonObservateur_toggled(GtkToggleButton *togglebutton,
                                          gpointer user_data)
{
  if (gtk_toggle_button_get_active(GTK_CHECK_BUTTON(togglebutton)))
  {
    prof[1] = 2;
  }
}

void on_RG_checkbuttonInterprete_toggled(GtkToggleButton *togglebutton,
                                         gpointer user_data)
{
  if (gtk_toggle_button_get_active(GTK_CHECK_BUTTON(togglebutton)))
  {
    prof[0] = 1;
  }
}

void on_RG_checkbuttonJournalist_toggled(GtkToggleButton *togglebutton,
                                         gpointer user_data)
{
  if (gtk_toggle_button_get_active(GTK_CHECK_BUTTON(togglebutton)))
  {
    prof[3] = 4;
  }
}

void on_RG_checkbuttonAmbassadeur_toggled(GtkToggleButton *togglebutton,
                                          gpointer user_data)
{
  if (gtk_toggle_button_get_active(GTK_CHECK_BUTTON(togglebutton)))
  {
    prof[2] = 3;
  }
}

void on_RG_checkbuttonActiviste_toggled(GtkToggleButton *togglebutton,
                                        gpointer user_data)
{
  if (gtk_toggle_button_get_active(GTK_CHECK_BUTTON(togglebutton)))
  {
    prof[1] = 2;
  }
}

void on_RG_button2ACC_clicked(GtkButton *button,
                              gpointer user_data)
{
}

void on_RG_button2A_clicked(GtkWidget *objet_graphique,
                            gpointer user_data)
{
  char idob[20], idbv[20], filename[200] = "observateur.txt", tab[6] = {0, 0, 0, 0, 0, 0};
  observateur o;
  int x;

  GtkWidget *RG_entryidob;
  GtkWidget *RG_entryNomOB;
  GtkWidget *RG_entryPRO;
  GtkWidget *RG_comboboxentryNAT;
  GtkWidget *RG_spinbutton5AGE;
  GtkWidget *RG_comboboxIDBV;
  GtkWidget *RG_checkbuttonHote;
  GtkWidget *RG_checkbuttonActivist;
  GtkWidget *RG_checkbuttonInter;
  GtkWidget *RG_checkbuttonJournaliste;
  GtkWidget *RG_checkbuttonAmbass;
  GtkWidget *RG_checkbuttonobs;
  RG_entryidob = lookup_widget(objet_graphique, "RG_entryidob");
  RG_entryNomOB = lookup_widget(objet_graphique, "RG_entryNomOB");
  RG_entryPRO = lookup_widget(objet_graphique, "RG_entryPRO");
  RG_comboboxIDBV = lookup_widget(objet_graphique, "RG_comboboxIDBV");
  RG_spinbutton5AGE = lookup_widget(objet_graphique, "RG_spinbutton5AGE");
  RG_comboboxentryNAT = lookup_widget(objet_graphique, "RG_comboboxentryNAT");
  RG_checkbuttonHote = lookup_widget(objet_graphique, "RG_checkbuttonHote");
  RG_checkbuttonActivist = lookup_widget(objet_graphique, "RG_checkbuttonActivist");
  RG_checkbuttonInter = lookup_widget(objet_graphique, "RG_checkbuttonInter");
  RG_checkbuttonJournaliste = lookup_widget(objet_graphique, "RG_checkbuttonJournaliste");
  RG_checkbuttonAmbass = lookup_widget(objet_graphique, "RG_checkbuttonAmbass");
  RG_checkbuttonobs = lookup_widget(objet_graphique, "RG_checkbuttonobs");
  o.age = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(RG_spinbutton5AGE));
  strcpy(o.nom, gtk_entry_get_text(GTK_ENTRY(RG_entryNomOB)));
  strcpy(o.prenom, gtk_entry_get_text(GTK_ENTRY(RG_entryPRO)));
  strcpy(idob, gtk_entry_get_text(GTK_ENTRY(RG_entryidob)));
  strcpy(o.idBV, gtk_combo_box_get_active_text(GTK_COMBO_BOX(RG_comboboxIDBV)));
  strcpy(o.nationalite, gtk_combo_box_get_active_text(GTK_COMBO_BOX(RG_comboboxentryNAT)));
  o.idob = atoi(idob);
  o.idBV = atoi(idbv);
  if (sexe == 1)
  {
    strcpy(o.sexe, "homme");
  }
  else
  {
    strcpy(o.sexe, "femme");
  }
  if (tab[0] == 1)
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(RG_checkbuttonHote), TRUE);
  if (tab[1] == 1)
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(RG_checkbuttonAmbass), TRUE);
  if (tab[2] == 1)
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(RG_checkbuttonobs), TRUE);
  if (tab[3] == 1)
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(RG_checkbuttonJournaliste), TRUE);
  if (tab[4] == 1)
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(RG_checkbuttonActivist), TRUE);

  x = ajouter_observateur("observateur.txt", o);
}

void on_RG_buttonA1_clicked(GtkButton *button,
                            gpointer user_data)
{
  GtkWidget *RG_EA1;
  GtkWidget *RG_windowPrincipale;
  RG_EA1 = lookup_widget(button, "RG_EA1");
  gtk_widget_hide(RG_EA1);
  RG_windowPrincipale = create_RG_windowPrincipale();
  gtk_widget_show(RG_windowPrincipale);
}

void on_RG_buttonC_clicked(GtkButton *button,
                           gpointer user_data)
{
  /*admin A;
 int inputmp,inputid;
 int trouve;
 int r=0;

 GtkWidget * RG_entryIDA;
 GtkWidget * RG_entrymp1;
 GtkWidget * connexion;
 GtkWidget * RG_windowEspaceAdmin;
 GtkWidget * RG_EA1;
 connexion = lookup_widget (objet_graphique,"RG_buttonC");
 RG_entryIDA = lookup_widget(objet_graphique,"RG_entryIDA");
 RG_entrymp1 = lookup_widget(objet_graphique,"RG_entrymp1");


 strcpy(A.id,gtk_entry_get_text(GTK_ENTRY(RG_entryIDA)));
 strcpy(A.mp,gtk_entry_get_text(GTK_ENTRY(RG_entrymp1)));
 inputmp=atoi( RG_entrymp1);
 inputid=atoi(RG_entryIDA);
 trouve= verif(inputid,inputmp);


 if (trouve==1)
{
  RG_windowEspaceAdmin= create_RG_windowEspaceAdmin();
  gtk_widget_show (RG_windowEspaceAdmin);

}*/
  GtkWidget *RG_EA1;
  GtkWidget *RG_windowEspaceAdmin;
  RG_EA1 = lookup_widget(button, "RG_EA1");
  gtk_widget_hide(RG_EA1);
  RG_windowEspaceAdmin = create_RG_windowEspaceAdmin();
  gtk_widget_show(RG_windowEspaceAdmin);
}

void on_RG_buttonAnnulerSuppU_clicked(GtkButton *button,
                                      gpointer user_data)
{
  GtkWidget *RG_windowCSU;
  GtkWidget *RG_GestionUser;
  RG_windowCSU = lookup_widget(button, "RG_windowCSU");
  gtk_widget_hide(RG_windowCSU);
  RG_GestionUser = create_RG_GestionUser();
  gtk_widget_show(RG_GestionUser);
}

void on_RG_buttonconfirmerSupprission_clicked(GtkButton *button,
                                              gpointer user_data)
{
  User U;
  GtkWidget *RG_entryIDSUPP;
  GtkWidget *RG_labelERREURSUPP;
  RG_entryIDSUPP = lookup_widget(button, "RG_entryIDSUPP");
  RG_labelERREURSUPP = lookup_widget(button, "RG_labelERREURSUPP");
  char id[50] = "", err[50] = "";
  strcpy(id, gtk_entry_get_text(GTK_ENTRY(RG_entryIDSUPP)));
  U.cin = atoi(id);
  int a = supprimer("User.txt", U.cin);
  if (a == 1)
  {
    strcpy(err, "Supprimer avec succes");
    gtk_label_set_text(GTK_LABEL(RG_labelERREURSUPP), err);
  }
  else
  {
    strcpy(err, "Id introuvable!");
    gtk_label_set_text(GTK_LABEL(RG_labelERREURSUPP), err);
  }
}

void on_OZ_button29_clicked(GtkButton *button,
                            gpointer user_data)
{
}

void on_OZ_button28_clicked(GtkButton *button,
                            gpointer user_data)
{
}

void on_OZ_treeview_row_activated(GtkTreeView *treeview,
                                  GtkTreePath *path,
                                  GtkTreeViewColumn *column,
                                  gpointer user_data)
{
}

void on_OZ_button30_clicked(GtkButton *button,
                            gpointer user_data)
{
}

void on_OZ_ajouterRec_clicked(GtkButton *button,
                              gpointer user_data)
{
}

void on_OZ_modifierRec_clicked(GtkButton *button,
                               gpointer user_data)
{
}

void on_OZ_chercherRec_clicked(GtkButton *button,
                               gpointer user_data)
{
}

void on_OZ_actualiser_clicked(GtkButton *button,
                              gpointer user_data)
{
}

void on_OZ_supprimerRec_clicked(GtkButton *button,
                                gpointer user_data)
{
}

void on_OZ_button34_clicked(GtkButton *button,
                            gpointer user_data)
{
}

void on_OZ_radiobutton1_toggled(GtkToggleButton *togglebutton,
                                gpointer user_data)
{
}

void on_OZ_radiobutton4_toggled(GtkToggleButton *togglebutton,
                                gpointer user_data)
{
}

void on_OZ_radiobutton3_toggled(GtkToggleButton *togglebutton,
                                gpointer user_data)
{
}

void on_OZ_button35_clicked(GtkButton *button,
                            gpointer user_data)
{
}

void on_OZ_button37_clicked(GtkButton *button,
                            gpointer user_data)
{
}

void on_button36_clicked(GtkButton *button,
                         gpointer user_data)
{
}

void on_OZ_radiobuttonc_toggled(GtkToggleButton *togglebutton,
                                gpointer user_data)
{
}

void on_OZ_radiobuttona_toggled(GtkToggleButton *togglebutton,
                                gpointer user_data)
{
}

void on_OZ_radiobuttonb_toggled(GtkToggleButton *togglebutton,
                                gpointer user_data)
{
}

void on_OZ_button39_clicked(GtkButton *button,
                            gpointer user_data)
{
}

void on_OZ_button38_clicked(GtkButton *button,
                            gpointer user_data)
{
}

void on_FSBVbutton_ACC_RELOAD_BV_clicked(GtkWidget *objet,
                                         gpointer user_data)
{
  GtkWidget *FS_windowBVacc, *w1;
  GtkWidget *treeview;

  w1 = lookup_widget(objet, "FS_windowBVacc");
  FS_windowBVacc = create_FS_windowBVacc();

  gtk_widget_show(FS_windowBVacc);
  gtk_widget_hide(w1);
  treeview = lookup_widget(FS_windowBVacc, "FSBVtreeview_ACC_TV_BV");
  // vider(treeview);
  Afficher_Bureau_de_Vote(treeview);
  /*
  treeview = lookup_widget(FS_windowBVacc, "FSBVtreeview_ACC_TV_BV");
  Afficher_Bureau_de_Vote(treeview);
  FS_windowBVacc = lookup_widget(button, "FS_windowBVacc");
    gtk_widget_show (FS_windowBVacc);
  */
}

void on_FSBVbutton_ACC_AJ_BV_clicked(GtkWidget *button,
                                     gpointer user_data)
{
  GtkWidget *FS_windowBVacc;
  GtkWidget *FS_windowBVaj;

  FS_windowBVacc = lookup_widget(button, "FS_windowBVacc");
  gtk_widget_hide(FS_windowBVacc);
  FS_windowBVaj = create_FS_windowBVaj();
  gtk_widget_show(FS_windowBVaj);
}

void on_FSBVbutton_ACC_SUPP_BV_clicked(GtkWidget *button,
                                       gpointer user_data)
{
  GtkWidget *FS_windowBVacc;
  GtkWidget *FS_windowBVsupp;
  FS_windowBVacc = lookup_widget(button, "FS_windowBVacc");
  gtk_widget_hide(FS_windowBVacc);
  FS_windowBVsupp = create_FS_windowBVsupp();
  gtk_widget_show(FS_windowBVsupp);
}

void on_FSBVbutton_ACC_MOD_BV_clicked(GtkWidget *button,
                                      gpointer user_data)
{
  GtkWidget *FS_windowBVacc;
  GtkWidget *FS_windowBVmod;

  FS_windowBVacc = lookup_widget(button, "FS_windowBVacc");
  gtk_widget_hide(FS_windowBVacc);
  FS_windowBVmod = create_FS_windowBVmod();
  gtk_widget_show(FS_windowBVmod);
}

void on_FSBVradiobutton_AJ_CPT_ELEC1_BV_toggled(GtkToggleButton *togglebutton,
                                                gpointer user_data)

{
  if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
  {
    x = 30;
  }
}

void on_FSBVradiobutton_AJ_CPT_ELEC2_BV_toggled(GtkToggleButton *togglebutton,
                                                gpointer user_data)

{
  if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
  {
    x = 60;
  }
}

void on_FSBVradiobutton_AJ_CPT_ELEC3_BV_toggled(GtkToggleButton *togglebutton,
                                                gpointer user_data)

{
  if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
  {
    x = 90;
  }
}

void on_FSBVbutton_AJ_ANNULER_BV_clicked(GtkWidget *button,
                                         gpointer user_data)
{
  GtkWidget *FS_windowBVacc;
  GtkWidget *FS_windowBVaj;
  FS_windowBVacc = create_FS_windowBVacc();
  gtk_widget_show(FS_windowBVacc);
  FS_windowBVaj = lookup_widget(button, "FS_windowBVaj");
  gtk_widget_hide(FS_windowBVaj);
  GtkWidget *treeview;
  treeview = lookup_widget(FS_windowBVacc, "FSBVtreeview_ACC_TV_BV");
  Afficher_Bureau_de_Vote(treeview);
}

void on_FSBVbutton_AJ_AJ_BV_clicked(GtkWidget *button,
                                    gpointer user_data)
{
  GtkWidget *FS_windowBVacc;
  GtkWidget *FS_windowBVaj;

  FS_windowBVacc = create_FS_windowBVacc();
  gtk_widget_show(FS_windowBVacc);
  FS_windowBVaj = lookup_widget(button, "FS_windowBVaj");
  gtk_widget_hide(FS_windowBVaj);

  GtkWidget *treeview;
  treeview = lookup_widget(FS_windowBVacc, "FSBVtreeview_ACC_TV_BV");
  Afficher_Bureau_de_Vote(treeview);

  GtkWidget *ID, *IDAGBV, *Region, *Municipalite, *Adresse, *salle, *cpt_obser, *cpt_elec1, *cpt_elec2, *cpt_elec3, *check;
  GtkWidget *tree_bv;
  BVOTE p;
  int a;
  int n = 0;
  char f[30];
  char s[30];
  int v;
  int ss;
  char msg[20];
  int bn;

  ID = lookup_widget(GTK_WIDGET(button), "FSBVentry_AJ_ID_BV");
  IDAGBV = lookup_widget(GTK_WIDGET(button), "FSBVentry_AJ_IDAG_BV");
  Region = lookup_widget(GTK_WIDGET(button), "FSBVcomboAJ_REG_BV");
  Municipalite = lookup_widget(GTK_WIDGET(button), "FSBVcomboAJ_MN_BV");
  Adresse = lookup_widget(GTK_WIDGET(button), "FSBVentry_AJ_ADRESSE_BV");
  salle = lookup_widget(GTK_WIDGET(button), "FSBVspinbutton_AJ_SALLE_BV");
  cpt_obser = lookup_widget(GTK_WIDGET(button), "FSBVspinbutton_AJ_CPT_OBSER_BV");
  cpt_elec1 = lookup_widget(GTK_WIDGET(button), "FSBVradiobutton_AJ_CPT_ELEC1_BV");
  cpt_elec2 = lookup_widget(GTK_WIDGET(button), "FSBVradiobutton_AJ_CPT_ELEC2_BV");
  cpt_elec3 = lookup_widget(GTK_WIDGET(button), "FSBVradiobutton_AJ_CPT_ELEC3_BV");

  p.ID = atoi(gtk_entry_get_text(GTK_ENTRY(ID)));
  p.IDAGBV = atoi(gtk_entry_get_text(GTK_ENTRY(IDAGBV)));
  strcpy(p.Adresse, gtk_entry_get_text(GTK_ENTRY(Adresse)));
  strcpy(p.Region, gtk_combo_box_get_active_text(GTK_COMBO_BOX(Region)));
  strcpy(p.Mnp, gtk_combo_box_get_active_text(GTK_COMBO_BOX(Municipalite)));

  p.salle = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(salle));
  p.cpt_obser = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(cpt_obser));

  p.cpt_elec = x;

  a = ajouterbv(p);
}

void on_FSBVcheckbutton_AJ_CHECK_BV_toggled(GtkToggleButton *togglebutton,
                                            gpointer user_data)
{
  if (gtk_toggle_button_get_active(togglebutton))
  {
    c = 1;
  }
}

void on_FSBVradiobutton_MOD_CPT_ELEC1_BV_toggled(GtkToggleButton *togglebutton,
                                                 gpointer user_data)
{
  if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
  {
    y = 30;
  }
}

void on_FSBVradiobutton_MOD_CPT_ELEC2_BV_toggled(GtkToggleButton *togglebutton,
                                                 gpointer user_data)
{
  if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
  {
    y = 60;
  }
}

void on_FSBVradiobutton_MOD_CPT_ELEC3_BV_toggled(GtkToggleButton *togglebutton,
                                                 gpointer user_data)
{
  if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
  {
    y = 90;
  }
}

void on_FSBVbutton_MOD_MODIFIER_BV_clicked(GtkWidget *button,
                                           gpointer user_data)
{
  GtkWidget *FS_windowBVacc;
  GtkWidget *FS_windowBVmod;
  FS_windowBVacc = create_FS_windowBVacc();
  gtk_widget_show(FS_windowBVacc);
  FS_windowBVmod = lookup_widget(button, "FS_windowBVmod");
  gtk_widget_hide(FS_windowBVmod);
  GtkWidget *treeview;
  treeview = lookup_widget(FS_windowBVacc, "FSBVtreeview_ACC_TV_BV");

  GtkWidget *ID, *IDAGBV, *Region, *Municipalite, *Adresse, *salle, *cpt_obser, *cpt_elec1, *cpt_elec2, *cpt_elec3, *check;
  GtkWidget *tree_bv;
  // BVOTE p;
  BVOTE nouv;
  int a;
  int ID_modifier;
  int n = 0;
  char f[30];
  char s[30];
  int v;
  int ss;
  char msg[20];
  int bn;
  // char ID[20];
  // int i,n;

  ID = lookup_widget(GTK_WIDGET(button), "FSBVentry_MOD_ID_BV");
  IDAGBV = lookup_widget(GTK_WIDGET(button), "FSBVentry_MOD_IDAG_BV");
  Region = lookup_widget(GTK_WIDGET(button), "FSBVcombobox_MOD_REG_BV");
  Municipalite = lookup_widget(GTK_WIDGET(button), "FSBVcombobox_MOD_MNP_BV");
  Adresse = lookup_widget(GTK_WIDGET(button), "FSBVentry_MOD_ADRESSE_BV");
  salle = lookup_widget(GTK_WIDGET(button), "FSBVspinbutton_MOD_SALLE_BV");
  cpt_obser = lookup_widget(GTK_WIDGET(button), "FSBVspinbutton_MOD_CPT_OBSER_BV");
  cpt_elec1 = lookup_widget(GTK_WIDGET(button), "FSBVradiobutton_MOD_CPT_ELEC1_BV");
  cpt_elec2 = lookup_widget(GTK_WIDGET(button), "FSBVradiobutton_MOD_CPT_ELEC2_BV");
  cpt_elec3 = lookup_widget(GTK_WIDGET(button), "FSBVradiobutton_MOD_CPT_ELEC3_BV");

  ID_modifier = atoi(gtk_entry_get_text(GTK_ENTRY(ID)));
  nouv.IDAGBV = atoi(gtk_entry_get_text(GTK_ENTRY(IDAGBV)));
  strcpy(nouv.Adresse, gtk_entry_get_text(GTK_ENTRY(Adresse)));
  // strcpy(p.ID,gtk_combo_box_get_active_text(GTK_COMBO_BOX(p.ID)));
  strcpy(nouv.Region, gtk_combo_box_get_active_text(GTK_COMBO_BOX(Region)));
  strcpy(nouv.Mnp, gtk_combo_box_get_active_text(GTK_COMBO_BOX(Municipalite)));
  /*
  for(i=0;i<n;i++)
   gtk_combo_box_append_text (GTK_COMBO_BOX (ID), _(ID[i]));
  */
  nouv.salle = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(salle));
  nouv.cpt_obser = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(cpt_obser));
  nouv.cpt_elec = y;

  // p.ID==ID_modifier;
  // if(recherchebv(ID_modifier)!=0)
  modifierbv(ID_modifier, nouv);
  Afficher_Bureau_de_Vote(treeview);
}

void on_FSBVbutton_MOD_ANNULER_BV_clicked(GtkWidget *button,
                                          gpointer user_data)
{
  GtkWidget *FS_windowBVacc;
  GtkWidget *FS_windowBVmod;

  FS_windowBVacc = create_FS_windowBVacc();
  gtk_widget_show(FS_windowBVacc);
  FS_windowBVmod = lookup_widget(button, "FS_windowBVmod");
  gtk_widget_hide(FS_windowBVmod);
  GtkWidget *treeview;
  treeview = lookup_widget(FS_windowBVacc, "FSBVtreeview_ACC_TV_BV");
  Afficher_Bureau_de_Vote(treeview);
}

void on_FSBVbutton_SUPP_NON_BV_clicked(GtkWidget *button,
                                       gpointer user_data)
{
  GtkWidget *FS_windowBVacc;
  GtkWidget *FS_windowBVsupp;
  FS_windowBVacc = create_FS_windowBVacc();
  gtk_widget_show(FS_windowBVacc);
  FS_windowBVsupp = lookup_widget(button, "FS_windowBVsupp");
  gtk_widget_hide(FS_windowBVsupp);
  GtkWidget *treeview;
  treeview = lookup_widget(FS_windowBVacc, "FSBVtreeview_ACC_TV_BV");
  Afficher_Bureau_de_Vote(treeview);

  int t, val;
  char mot[20];
  GtkWidget *input1;

  input1 = lookup_widget(GTK_WIDGET(button), "FSBVentry6969");

  val = atoi(gtk_entry_get_text(GTK_ENTRY(input1)));

  supprimerbv(val);
}

void on_RG_treeviewUser_row_activated(GtkTreeView *treeview,
                                      GtkTreePath *path,
                                      GtkTreeViewColumn *column,
                                      gpointer user_data)
{
  GtkTreeIter iter;
  gchar *Nom;
  gchar *Prenom;
  gchar *date;
  gchar *sexe;
  gchar *cin;
  gchar *idBV;
  gchar *etatSocial;
  gchar *Role;
  gchar *municipalite;
  gchar *gouvernorat;
  gchar *Vote;
  User U;
  int Cin;
  GtkTreeModel *model = gtk_tree_view_get_model(treeview);
  if (gtk_tree_model_get_iter(model, &iter, path))

  {
    gtk_tree_model_get(GTK_LIST_STORE(model), &iter, 0, &cin, 1, &Nom, 2, &Prenom, 3, &date, 4, &sexe, 5, &etatSocial, 6, &Role, 7, &municipalite, 8, &gouvernorat, 9, &idBV, 10, &Vote, -1);
    strcpy(U.cin, cin);
    strcpy(U.Nom, Nom);
    strcpy(U.Prenom, Prenom);

    strcpy(U.sexe, sexe);
    strcpy(U.idBV, idBV);
    strcpy(U.etatSocial, etatSocial);
    strcpy(U.municipalite, municipalite);
    strcpy(U.Role, Role);
    strcpy(U.gouvernorat, gouvernorat);
    strcpy(U.Vote, Vote);

    affiche_userr(treeview);
  }
}

void on_RG_buttonAjouter_clicked(GtkButton *button,
                                 gpointer user_data)
{
  GtkWidget *RG_GestionUser;
  GtkWidget *RG_windowNU;
  RG_GestionUser = lookup_widget(button, "RG_GestionUser");
  gtk_widget_hide(RG_GestionUser);
  RG_windowNU = create_RG_windowNU();
  gtk_widget_show(RG_windowNU);
}

void on_RG_buttonModifier_clicked(GtkButton *button,
                                  gpointer user_data)
{
  GtkWidget *RG_GestionUser;
  GtkWidget *RG_windowDemade_modif;
  RG_GestionUser = lookup_widget(button, "RG_GestionUser");
  gtk_widget_hide(RG_GestionUser);
  RG_windowDemade_modif = create_RG_windowDemade_modif();
  gtk_widget_show(RG_windowDemade_modif);
}

void on_RG_buttonRetour_clicked(GtkButton *button,
                                gpointer user_data)
{
  GtkWidget *RG_GestionUser;
  GtkWidget *RG_windowEspaceAdmin;
  RG_GestionUser = lookup_widget(button, "RG_GestionUser");
  gtk_widget_hide(RG_GestionUser);
  RG_windowEspaceAdmin = create_RG_windowEspaceAdmin();
  gtk_widget_show(RG_windowEspaceAdmin);
}

void on_RG_buttonActualiser_clicked(GtkWidget *objet,
                                    gpointer user_data)
{
  GtkWidget *RG_GestionUser, *w1;
  GtkWidget *treeview;

  w1 = lookup_widget(objet, "RG_GestionUser");
  RG_GestionUser = create_RG_GestionUser();

  gtk_widget_show(RG_GestionUser);
  gtk_widget_hide(w1);
  treeview = lookup_widget(RG_GestionUser, "RG_treeviewUser");
  // vider(treeview);

  affiche_userr(treeview);
}

void on_RG_buttonSupprimer_clicked(GtkButton *button,
                                   gpointer user_data)
{
  GtkWidget *RG_GestionUser;
  GtkWidget *RG_windowCSU;
  RG_GestionUser = lookup_widget(button, "RG_GestionUser");
  gtk_widget_hide(RG_GestionUser);
  RG_windowCSU = create_RG_windowCSU();
  gtk_widget_show(RG_windowCSU);
}

void on_RG_ButtonEA_clicked(GtkWidget *button,
                            gpointer user_data)
{
  GtkWidget *RG_windowPrincipale;
  GtkWidget *RG_EA1;
  GtkWidget *RG_treeviewUser;
  RG_windowPrincipale = lookup_widget(button, "RG_windowPrincipale");
  gtk_widget_hide(RG_windowPrincipale);
  RG_EA1 = create_RG_EA1();
  gtk_widget_show(RG_EA1);
  
}


void on_RG_buttonER_clicked(GtkButton *button,
                            gpointer user_data)
{
  GtkWidget *RG_windowPrincipale;
  GtkWidget *OZ_windowER;
  RG_windowPrincipale = lookup_widget(button, "RG_windowPrincipale");
  gtk_widget_hide(RG_windowPrincipale);
  OZ_windowER = create_OZ_windowER();
  gtk_widget_show(OZ_windowER);
}

void on_RG_buttonEE_clicked(GtkButton *button,
                            gpointer user_data)
{
  GtkWidget *RG_windowPrincipale;
  GtkWidget *HB_windowGE;
  RG_windowPrincipale = lookup_widget(button, "RG_windowPrincipale");
  gtk_widget_hide(RG_windowPrincipale);
  HB_windowGE = create_HB_windowGE();
  gtk_widget_show(HB_windowGE);
}

void on_RG_buttonEBV_clicked(GtkButton *button,
                             gpointer user_data)
{
  GtkWidget *RG_windowPrincipale;
  GtkWidget *RG_windowEspaceBV;
  RG_windowPrincipale = lookup_widget(button, "RG_windowPrincipale");
  gtk_widget_hide(RG_windowPrincipale);
  RG_windowEspaceBV = create_RG_windowEspaceBV();
  gtk_widget_show(RG_windowEspaceBV);
}

void on_RG_buttonStats_clicked(GtkButton *button,
                               gpointer user_data)
{
  GtkWidget *RG_windowPrincipale;
  GtkWidget *Stat__stiques;
  RG_windowPrincipale = lookup_widget(button, "RG_windowPrincipale");
  gtk_widget_hide(RG_windowPrincipale);
  Stat__stiques = create_Stat__stiques();
  gtk_widget_show(Stat__stiques);
}

void on_RG_buttonAccueil_clicked(GtkButton *button,
                                 gpointer user_data)
{
  GtkWidget *RG_windowEspaceAdmin;
  GtkWidget *RG_windowPrincipale;
  RG_windowEspaceAdmin = lookup_widget(button, "RG_windowEspaceAdmin");
  gtk_widget_hide(RG_windowEspaceAdmin);
  RG_windowPrincipale = create_RG_windowPrincipale();
  gtk_widget_show(RG_windowPrincipale);
}

void on_RG_ButtonGBV_clicked(GtkButton *button,
                             gpointer user_data)
{
  GtkWidget *RG_windowEspaceBV;
  GtkWidget *RG_windowEspaceAdmin;
  RG_windowEspaceAdmin = lookup_widget(button, "RG_windowEspaceAdmin");
  gtk_widget_hide(RG_windowEspaceAdmin);
  RG_windowEspaceBV = create_RG_windowEspaceBV();
  gtk_widget_show(RG_windowEspaceBV);
}

void on_RG_buttonGE_clicked(GtkButton *button,
                            gpointer user_data)
{
  GtkWidget *RG_windowEspaceAdmin;
  GtkWidget *HB_windowGE;
  RG_windowEspaceAdmin = lookup_widget(button, "RG_windowEspaceAdmin");
  gtk_widget_hide(RG_windowEspaceAdmin);
  HB_windowGE = create_HB_windowGE();
  gtk_widget_show(HB_windowGE);
}

void on_RG_buttonGU_clicked(GtkWidget *button,
                            gpointer user_data)
{
  GtkWidget *RG_windowEspaceAdmin;
  GtkWidget *RG_GestionUser;
  GtkWidget *RG_treeviewUser;
  RG_windowEspaceAdmin = lookup_widget(button, "RG_windowEspaceAdmin");
  gtk_widget_hide(RG_windowEspaceAdmin);
  RG_GestionUser = create_RG_GestionUser();
  gtk_widget_show(RG_GestionUser);
  RG_treeviewUser = lookup_widget(RG_GestionUser, "RG_treeviewUser");
  affiche_userr(RG_treeviewUser);
}

void on_RG_buttonAgeMoy_clicked(GtkWidget *objet_graphique,
                                gpointer user_data)
{
  User U;
  GtkWidget *RG_labelAGEmoy, *RG_buttonAgeMoy;
  int K;
  char ch[100];
  K = agemoyen("user.txt", U);
  RG_buttonAgeMoy = lookup_widget(objet_graphique, "RG_buttonAgeMoy");
  RG_labelAGEmoy = lookup_widget(objet_graphique, "RG_labelAGEmoy");
  sprintf(ch, " %d", K);
  gtk_label_set_text(GTK_LABEL(RG_labelAGEmoy), ch);
}

void on_RG_buttonnbob_clicked(GtkWidget *objet_graphique,
                              gpointer user_data)
{
  GtkWidget *RG_labelNBtotOBS, *RG_buttonnbob;
  int K;
  char ch[100];
  K = nbobservateur("observateur.txt");
  RG_buttonnbob = lookup_widget(objet_graphique, "RG_buttonnbob");
  RG_labelNBtotOBS = lookup_widget(objet_graphique, "RG_labelNBtotOBS");
  sprintf(ch, " %d", K);
  gtk_label_set_text(GTK_LABEL(RG_labelNBtotOBS), ch);
}

void on_RG_buttonTauxobs_clicked(GtkWidget *objet_graphique,
                                 gpointer user_data)
{
}

void on_RG_buttonSRetour_clicked(GtkButton *button,
                                 gpointer user_data)
{
  GtkWidget *Statestiques;
  GtkWidget *RG_windowPrincipale;
  Statestiques = lookup_widget(button, "Statestiques");
  gtk_widget_hide(Statestiques);
  RG_windowPrincipale = create_RG_windowPrincipale();
  gtk_widget_show(RG_windowPrincipale);
}

void on_RG_buttonSAccueil_clicked(GtkButton *button,
                                  gpointer user_data)
{
  GtkWidget *Statestiques;
  GtkWidget *RG_windowPrincipale;
  Statestiques = lookup_widget(button, "Statestiques");
  gtk_widget_hide(Statestiques);
  RG_windowPrincipale = create_RG_windowPrincipale();
  gtk_widget_show(RG_windowPrincipale);
}

void on_radiobuttonNewCel_toggled(GtkToggleButton *togglebutton,
                                  gpointer user_data)
{
  if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
  {
    l = 3;
  }
}

void on_RG_radiobuttonNewDiv_toggled(GtkToggleButton *togglebutton,
                                     gpointer user_data)
{
  if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
  {
    l = 2;
  }
}

void on_RG_radiobuttonNewMarie_toggled(GtkToggleButton *togglebutton,
                                       gpointer user_data)
{
  if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
  {
    l = 1;
  }
}

void on_RG_checkbuttonNewE_toggled(GtkToggleButton *togglebutton,
                                   gpointer user_data)
{
  if (gtk_toggle_button_get_active(GTK_CHECK_BUTTON(togglebutton)))
  {
    choix[1] = 1;
  }
}

void on_RG_buttonModUtilisateur_clicked(GtkButton *button,
                                        gpointer user_data)
{
}

void on_RG_buttonAcceuilMod_clicked(GtkButton *button,
                                    gpointer user_data)
{
}

void on_RG_buttonMODAff_clicked(GtkButton *button,
                                gpointer user_data)
{
}

void on_buttonPRE1_clicked(GtkButton *button,
                           gpointer user_data)
{
}

void on_SR_buttonSV1_clicked(GtkButton *button,
                             gpointer user_data)
{
}

void on_buttonSupp_clicked(GtkButton *button,
                           gpointer user_data)
{
}

void on_buttonPRE4_clicked(GtkButton *button,
                           gpointer user_data)
{
}

void on_buttonC_clicked(GtkButton *button,
                        gpointer user_data)
{
}

void on_button72_clicked(GtkButton *button,
                         gpointer user_data)
{
}

void on_radiobuttonDR_toggled(GtkToggleButton *togglebutton,
                              gpointer user_data)
{
}

void on_radiobuttonG_toggled(GtkToggleButton *togglebutton,
                             gpointer user_data)
{
}

void on_buttonModifier_clicked(GtkButton *button,
                               gpointer user_data)
{
}

void on_button73_clicked(GtkButton *button,
                         gpointer user_data)
{
}

void on_radiobuttonC_toggled(GtkToggleButton *togglebutton,
                             gpointer user_data)
{
}

void on_treeview5_row_activated(GtkTreeView *treeview,
                                GtkTreePath *path,
                                GtkTreeViewColumn *column,
                                gpointer user_data)
{
}

void on_SR_buttonACTUALISER_clicked(GtkButton *button,
                                    gpointer user_data)
{
}

void on_SR_buttonPRE5_clicked(GtkButton *button,
                              gpointer user_data)
{
}

void on_SR_buttonCHERCHER_clicked(GtkButton *button,
                                  gpointer user_data)
{
}

void on_SR_buttonPRE6_clicked(GtkButton *button,
                              gpointer user_data)
{
}

void on_HB_buttonAE1_clicked(GtkButton *button,
                             gpointer user_data)
{
}

void on_HB_buttonME1_clicked(GtkButton *button,
                             gpointer user_data)
{
}

void on_HB_buttonSE1_clicked(GtkButton *button,
                             gpointer user_data)
{
}

void on_RG_buttonS_clicked(GtkButton *button,
                           gpointer user_data)
{
}

void on_HB_buttona2_clicked(GtkButton *button,
                            gpointer user_data)
{
}

void on_HB_buttonm_clicked(GtkButton *button,
                           gpointer user_data)
{
}

void on_HB_buttonPrecedent_clicked(GtkButton *button,
                                   gpointer user_data)
{
}

void on_HB_buttonOK_AE_clicked(GtkButton *button,
                               gpointer user_data)
{
}

void on_HB_radiobuttonAjouter_toggled(GtkToggleButton *togglebutton,
                                      gpointer user_data)
{
}

void on_HB_checkbuttonModifier_toggled(GtkToggleButton *togglebutton,
                                       gpointer user_data)
{
}

void on_HB_buttonMenu_clicked(GtkButton *button,
                              gpointer user_data)
{
}

void on_HB_button52_clicked(GtkButton *button,
                            gpointer user_data)
{
}

void on_HB_button51_clicked(GtkButton *button,
                            gpointer user_data)
{
}

void on_buttonM_Re_ID_clicked(GtkButton *button,
                              gpointer user_data)
{
}

void on_treeview1_row_activated(GtkTreeView *treeview,
                                GtkTreePath *path,
                                GtkTreeViewColumn *column,
                                gpointer user_data)
{
}

void on_HB_buttonPr_clicked(GtkButton *button,
                            gpointer user_data)
{
}

void on_buttonS_Re_ID_clicked(GtkButton *button,
                              gpointer user_data)
{
}

void on_HB_buttonS_clicked(GtkButton *button,
                           gpointer user_data)
{
}

void on_RG_treeview4OBS_row_activated(GtkTreeView *treeview,
                                      GtkTreePath *path,
                                      GtkTreeViewColumn *column,
                                      gpointer user_data)
{
}

void on_RG_buttonAOBS_clicked(GtkButton *button,
                              gpointer user_data)
{
  GtkWidget *RG_windowGestionO;
  GtkWidget *RG_windowEspaceBV;
  RG_windowGestionO = lookup_widget(button, "RG_windowGestionO");
  gtk_widget_hide(RG_windowGestionO);
  RG_windowEspaceBV = create_RG_windowEspaceBV();
  gtk_widget_show(RG_windowEspaceBV);
}

void on_RG_buttonMOBS_clicked(GtkButton *button,
                              gpointer user_data)
{
}

void on_RG_buttonDELOBS_clicked(GtkButton *button,
                                gpointer user_data)
{
}

void on_RG_buttonADDOBS_clicked(GtkButton *button,
                                gpointer user_data)
{
  GtkWidget *RG_windowGestionO;
  GtkWidget *RG_Ajout_Observateur;
  RG_windowGestionO = lookup_widget(button, "RG_windowGestionO");
  gtk_widget_hide(RG_windowGestionO);
  RG_Ajout_Observateur = create_RG_Ajout_Observateur();
  gtk_widget_show(RG_Ajout_Observateur);
}

void on_buttongestionBV_clicked(GtkButton *button,
                                gpointer user_data)
{
  GtkWidget *RG_windowEspaceBV;
  GtkWidget *FS_windowBVacc;
  RG_windowEspaceBV = lookup_widget(button, "RG_windowEspaceBV");
  gtk_widget_hide(RG_windowEspaceBV);
  FS_windowBVacc = create_FS_windowBVacc();
  gtk_widget_show(FS_windowBVacc);
}

void on_buttonGestionObs_clicked(GtkButton *button,
                                 gpointer user_data)
{
  GtkWidget *RG_windowEspaceBV;
  GtkWidget *RG_windowGestionO;
  RG_windowEspaceBV = lookup_widget(button, "RG_windowEspaceBV");
  gtk_widget_hide(RG_windowEspaceBV);
  RG_windowGestionO = create_RG_windowGestionO();
  gtk_widget_show(RG_windowGestionO);
}

void on_buttonHome_clicked(GtkButton *button,
                           gpointer user_data)
{
  GtkWidget *RG_windowEspaceBV;
  GtkWidget *RG_windowPrincipale;
  RG_windowEspaceBV = lookup_widget(button, "RG_windowEspaceBV");
  gtk_widget_hide(RG_windowEspaceBV);
  RG_windowPrincipale = create_RG_windowPrincipale();
  gtk_widget_show(RG_windowPrincipale);
}

void on_FSBVtreeview_ACC_TV_BV_row_activated(GtkTreeView *treeview,
                                             GtkTreePath *path,
                                             GtkTreeViewColumn *column,
                                             gpointer user_data)
{
  int f;
  int v;
  int a;
  int supp;
  GtkTreeIter iter;
  gchar *id;
  gchar *idagbv;
  gchar *region;
  gchar *mnp;
  gchar *adresse;
  gchar *salle;
  gchar *cpt_obser;
  gchar *cpt_elec;
  BVOTE p;
  BUVOTE b;
  // char ID_supprimer[30];

  GtkTreeModel *model = gtk_tree_view_get_model(treeview);
  if (gtk_tree_model_get_iter(model, &iter, path))
  {

    gtk_tree_model_get(GTK_LIST_STORE(model), &iter, 0, &id, 1, &idagbv, 2, &region, 3, &mnp, 3, &adresse, 4, &salle, 5, &cpt_elec, 6, &cpt_obser, -1);
    //
    /*
            p.ID=atoi(id);
      strcpy(p.Region,region);
      strcpy(p.Mnp,mnp);
      strcpy(p.Adresse,adresse);
      p.IDAGBV=atoi(idagbv);
      p.salle=atoi(salle);
      p.cpt_obser=atoi(cpt_obser);
      p.cpt_elec=atoi(cpt_elec);
    */
    // a=supprimer(ID_supprimer,"/home/fadi/Bureau/gladee final/projectEM/bureauvote.txt");
    // a=supprimer(ID_supprimer);

    strcpy(b.ID, id);
    strcpy(b.IDAGBV, idagbv);
    strcpy(b.Region, region);
    strcpy(b.Mnp, mnp);
    strcpy(b.Adresse, adresse);
    strcpy(b.salle, salle);
    strcpy(b.cpt_elec, cpt_elec);
    strcpy(b.cpt_obser, cpt_obser);
    /*if(strcmp(b.ID,id)==0)
    {
          ID_supprimer==id;
                }
       //p.ID= atoi ( f );
    */
    // p.ID=f;
    //
    // f==ID_supprimer;
    /// if(recherchebv(ID_supprimer)!=0)
    // supprimer_bv(p);
    // ssupprimerbv(p);
    // supp= supprimerbv(ID_supprimer);
    supprimerr_bv(b);

    //

    Afficher_Bureau_de_Vote(treeview);
  }
}

void on_FSBVbutton_ACC_RECH_BV_clicked(GtkWidget *objet,
                                       gpointer user_data)
{
  GtkWidget *FS_windowBVacc, *w1;
  GtkWidget *treeview;

  w1 = lookup_widget(objet, "FS_windowBVacc");
  FS_windowBVacc = create_FS_windowBVacc();

  gtk_widget_show(FS_windowBVacc);
  gtk_widget_hide(w1);
  treeview = lookup_widget(FS_windowBVacc, "FSBVtreeview_ACC_TV_BV");
  // vider(treeview);
  Afficher_Bureau_de_Vote(treeview);

  // GtkWidget *FS_windowBVacc;
  // GtkWidget *treeview;
  GtkWidget *ID;
  int rech;
  int ID_recherche;
  BVOTE p;

  ID = lookup_widget(GTK_WIDGET(objet), "FSBVentry122221");
  p.ID = atoi(gtk_entry_get_text(GTK_ENTRY(ID)));
  rech = recherchebv(ID_recherche);
}

void on_FSBVbuttonRetour_clicked(GtkWidget *button,
                                 gpointer user_data)
{
  GtkWidget *RG_windowEspaceBV;
  GtkWidget *FS_windowBVacc;
  FS_windowBVacc = lookup_widget(button, "FS_windowBVacc");
  gtk_widget_hide(FS_windowBVacc);
  RG_windowEspaceBV = create_RG_windowEspaceBV();
  gtk_widget_show(RG_windowEspaceBV);
}

void on_RG_buttonMODifier_clicked(GtkWidget *objet_graphique,
                                  gpointer user_data)
{
  GtkWidget *RG_entryNewName;
  GtkWidget *RG_entryNewPrenom;
  GtkWidget *RG_entryNewCIN;
  GtkWidget *RG_spinbuttonNewidBV;
  GtkWidget *RG_entryNewVote;
  GtkWidget *RG_spinbuttonNewJ;
  GtkWidget *RG_spinbuttonNewMois;
  GtkWidget *RG_spinbuttonNewAnnee;
  GtkWidget *RG_radiobuttonNewF;
  GtkWidget *GR_radiobuttonNewH;
  GtkWidget *RG_radiobuttonNewT;
  GtkWidget *RG_radiobuttonNewA;
  GtkWidget *RG_comboboxentryNewG;
  GtkWidget *RG_comboboxentryNewM;
  GtkWidget *RG_radiobuttonNewMarie;
  GtkWidget *RG_radiobuttonNewDiv;
  GtkWidget *radiobuttonNewCel;
  GtkWidget *RG_checkbuttonNewAgent;
  GtkWidget *RG_checkbuttonNewE;
  GtkWidget *RG_labelErreur;
  GtkWidget *RG_entryIDUSER;
  User U;
  FILE *f = NULL;
  int a = 0;
  int cin;
  char cin1[20];
  char err[20];

  RG_entryIDUSER = lookup_widget(objet_graphique, "RG_entryIDUSER");
  RG_labelErreur = lookup_widget(objet_graphique, "RG_labelErreur");
  strcpy(cin, gtk_entry_get_text(GTK_ENTRY(RG_entryIDUSER)));

  f = fopen("User.txt", "r");
  if (f != NULL)
  {
    while ((fscanf(f, "%s %s %d %d/%d/%d %d %d %s %s %d %d %d \n", U.Nom, U.Prenom, &U.cin, &U.d.jour, &U.d.mois, &U.d.annee, &U.sexe, &U.etatSocial, U.municipalite, U.gouvernorat, &U.Role, &U.idBV, &U.Vote) != EOF))
    {
      if (U.cin == cin)
      {
        GtkWidget *RG_windowDemade_modif;
        GtkWidget *RG_windowModifUser;
        RG_windowDemade_modif = lookup_widget(objet_graphique, "RG_windowDemade_modif");
        RG_windowModifUser = create_RG_windowModifUser();
        gtk_widget_show(RG_windowModifUser);
        gtk_widget_hide(RG_windowDemade_modif);
        RG_entryNewName = lookup_widget(RG_windowModifUser, "RG_entryNewName");
        RG_entryNewPrenom = lookup_widget(RG_windowModifUser, "RG_entryNewPrenom");
        RG_entryNewCIN = lookup_widget(RG_windowModifUser, "RG_entryNewCIN");
        RG_spinbuttonNewidBV = lookup_widget(RG_windowModifUser, "RG_spinbuttonNewidBV");
        RG_entryNewVote = lookup_widget(RG_windowModifUser, "RG_entryNewVote");
        RG_comboboxentryNewG = lookup_widget(RG_windowModifUser, "RG_comboboxentryNewG");
        RG_spinbuttonNewJ = lookup_widget(RG_windowModifUser, "RG_spinbuttonNewJ");
        RG_spinbuttonNewMois = lookup_widget(RG_windowModifUser, "RG_spinbuttonNewMois");
        RG_spinbuttonNewAnnee = lookup_widget(RG_windowModifUser, "RG_spinbuttonNewAnnee");
        RG_radiobuttonNewF = lookup_widget(RG_windowModifUser, "RG_radiobuttonNewF");
        GR_radiobuttonNewH = lookup_widget(RG_windowModifUser, "GR_radiobuttonNewH");
        RG_radiobuttonNewT = lookup_widget(RG_windowModifUser, "RG_radiobuttonNewT");
        RG_radiobuttonNewA = lookup_widget(RG_windowModifUser, "RG_radiobuttonNewA");
        RG_comboboxentryNewG = lookup_widget(RG_windowModifUser, "RG_comboboxentryNewG");
        RG_comboboxentryNewM = lookup_widget(RG_windowModifUser, "RG_comboboxentryNewM");
        RG_radiobuttonNewMarie = lookup_widget(RG_windowModifUser, "RG_radiobuttonNewMarie");
        RG_radiobuttonNewDiv = lookup_widget(RG_windowModifUser, "RG_radiobuttonNewDiv");
        radiobuttonNewCel = lookup_widget(RG_windowModifUser, "radiobuttonNewCel");
        RG_checkbuttonNewAgent = lookup_widget(RG_windowModifUser, "RG_checkbuttonNewAgent");
        RG_checkbuttonNewE = lookup_widget(RG_windowModifUser, "RG_checkbuttonNewE");
        sprintf(cin1, "%d", U.cin);
        gtk_entry_set_text(GTK_ENTRY(RG_entryNewCIN), cin1);
        if (strcmp(U.municipalite, "Ben Arous") == 0)
        {
          gtk_combo_box_set_active(GTK_COMBO_BOX(RG_comboboxentryNewM), 0);
        }
        if (strcmp(U.municipalite, "Ezzahra") == 0)
        {
          gtk_combo_box_set_active(GTK_COMBO_BOX(RG_comboboxentryNewM), 0);
        }
        if (strcmp(U.municipalite, "Fouchana") == 0)
        {
          gtk_combo_box_set_active(GTK_COMBO_BOX(RG_comboboxentryNewM), 0);
        }
        if (strcmp(U.municipalite, "Rad\303\251s") == 0)
        {
          gtk_combo_box_set_active(GTK_COMBO_BOX(RG_comboboxentryNewM), 0);
        }
        if (strcmp(U.municipalite, "M\303\251grine") == 0)
        {
          gtk_combo_box_set_active(GTK_COMBO_BOX(RG_comboboxentryNewM), 0);
        }
        if (strcmp(U.gouvernorat, "Tunis") == 0)
        {
          gtk_combo_box_set_active(GTK_COMBO_BOX(RG_comboboxentryNewG), 0);
        }
        if (strcmp(U.gouvernorat, "Sfax") == 0)
        {
          gtk_combo_box_set_active(GTK_COMBO_BOX(RG_comboboxentryNewG), 0);
        }
        if (strcmp(U.gouvernorat, "Sousse") == 0)
        {
          gtk_combo_box_set_active(GTK_COMBO_BOX(RG_comboboxentryNewG), 0);
        }
        if (strcmp(U.gouvernorat, "Kairouan") == 0)
        {
          gtk_combo_box_set_active(GTK_COMBO_BOX(RG_comboboxentryNewG), 0);
        }
        if (strcmp(U.gouvernorat, "Bizerte") == 0)
        {
          gtk_combo_box_set_active(GTK_COMBO_BOX(RG_comboboxentryNewG), 0);
        }
        if (strcmp(U.gouvernorat, "Gabes") == 0)
        {
          gtk_combo_box_set_active(GTK_COMBO_BOX(RG_comboboxentryNewG), 0);
        }
        if (strcmp(U.gouvernorat, "Ben Arous") == 0)
        {
          gtk_combo_box_set_active(GTK_COMBO_BOX(RG_comboboxentryNewG), 0);
        }
        if (strcmp(U.gouvernorat, "Ariana") == 0)
        {
          gtk_combo_box_set_active(GTK_COMBO_BOX(RG_comboboxentryNewG), 0);
        }
        if (strcmp(U.gouvernorat, "Monastir") == 0)
        {
          gtk_combo_box_set_active(GTK_COMBO_BOX(RG_comboboxentryNewG), 0);
        }
        if (strcmp(U.gouvernorat, "Mednine") == 0)
        {
          gtk_combo_box_set_active(GTK_COMBO_BOX(RG_comboboxentryNewG), 0);
        }

        gtk_entry_set_text(GTK_ENTRY(RG_entryNewName), U.Nom);
        gtk_entry_set_text(GTK_ENTRY(RG_entryNewPrenom), U.Prenom);
        gtk_spin_button_set_value(RG_spinbuttonNewJ, U.d.jour);
        gtk_spin_button_set_value(RG_spinbuttonNewMois, U.d.mois);
        gtk_spin_button_set_value(RG_spinbuttonNewAnnee, U.d.annee);
        gtk_spin_button_set_value(RG_spinbuttonNewidBV, U.idBV);
        gtk_entry_set_text(GTK_ENTRY(RG_entryNewVote), U.Vote);

        a = 1;
        break;
      }
    }
    fclose(f);
  }

  if (a == 0)
  {
    strcpy(err, "id introuvable");
    gtk_label_set_text(GTK_LABEL(RG_labelErreur), err);
  }
  GtkWidget *RG_windowDemade_modif;
  GtkWidget *RG_windowModifUser;
  RG_windowDemade_modif = lookup_widget(objet_graphique, "RG_windowDemade_modif");
  gtk_widget_hide(RG_windowDemade_modif);
  RG_windowModifUser = create_RG_windowModifUser();
  gtk_widget_show(RG_windowModifUser);

  if (a == 1)
  {
    GtkWidget *RG_windowDemade_modif;
    GtkWidget *RG_windowModifUser;
    RG_windowDemade_modif = lookup_widget(objet_graphique, "RG_windowDemade_modif");
    gtk_widget_hide(RG_windowDemade_modif);
    RG_windowModifUser = create_RG_windowModifUser();
    gtk_widget_show(RG_windowModifUser);
  }
}
