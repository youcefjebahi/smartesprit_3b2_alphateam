#include <gtk/gtk.h>
GtkWidget *acceuil;
  GtkWidget *gestion;
  GtkWidget *administrateur;
typedef struct stock stock;
struct stock{
char id[30];
char nom[30];
char quantite[30];
char date[30];
char fournisseur[25];
};

int i,j,k;  

void
on_GestionAcceuil_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_Modifierstock_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);


void
on_Reserver_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_AjouterSTOCK_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_SupprimerSTOCK_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_chercherSTOCKclicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_Modifierstock_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_ModifierStock_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_rupture_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_treeview1_menu_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_ajoutermenu_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_recherchemenu_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_modifiermenu_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_supprimermenu_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data);
void
on_meilleurmenu_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_retourmenu_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_affichermenu_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button9menu_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data);
void
on_button10menu_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button11menu_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button12_menu_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button16menu_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button1menu_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button2menu_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data);


void
on_button15menu_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_loginmenu_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data);






void
on_button5add_clicked                  ( GtkWidget      *objet_graphique,
                                        gpointer         user_data);

void
on_treeview2_capt_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_checkbutton4_capt_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton3_capt_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton2_capt_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton1_capt_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttondeffective_clicked            ( GtkWidget      *objet_graphique,
                                        gpointer         user_data);



void
on_button6_capt_clicked                ( GtkWidget      *objet_graphique,
                                        gpointer         user_data);

void
on_login_clicked                       ( GtkWidget      *objet_graphique,
                                        gpointer         user_data);

void
on_button3refresh_clicked              ( GtkWidget      *objet_graphique,
                                        gpointer         user_data);

void
on_button1serch_clicked                ( GtkWidget      *objet_graphique,
                                        gpointer         user_data);

void
on_radiobutton2_capt_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton1_capt_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton4_capt_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton3_capt_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button4delate_clicked               ( GtkWidget      *objet_graphique,
                                        gpointer         user_data);

void
on_button2home_clicked                 ( GtkWidget      *objet_graphique,
                                        gpointer         user_data);


void
on_button_ajouter_clicked              (GtkButton       *objet,
                                        gpointer         user_data);

void
on_button_retour_ajout_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_ajouter_clicked              (GtkButton       *objet,
                                        gpointer         user_data);

void
on_button_afficher_ajout_clicked       (GtkButton       *objet,
                                        gpointer         user_data);

void
on_button_modifier_clicked             (GtkButton       *objet,
                                        gpointer         user_data);

void
on_button_retour_modification_clicked  (GtkButton       *objet,
                                        gpointer         user_data);

void
on_button_afficher_modification_clicked
                                        (GtkButton       *objet,
                                        gpointer         user_data);


void
on_entry_rechercher_delete_text        (GtkWidget       *objet,
                                        gint             start_pos,
                                        gint             end_pos,
                                        gpointer         user_data);

void
on_entry_rechercher_activate           (GtkEntry        *objet,
                                        gpointer         user_data);

void
on_button_retour_affichage_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_modifier0_clicked            (GtkButton       *objet,
                                        gpointer         user_data);

void
on_button_supprimer_clicked            (GtkButton       *objet,
                                        gpointer         user_data);


void
on_button_retour_recherche_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_rechercher_clicked           (GtkButton       *objet,
                                        gpointer         user_data);

void
on_confirmer_supp_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_annuler_supp_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_confirmer_modif_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_confirmer_quitter_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_annuler_quitter_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_annuler_modif_clicked               (GtkButton       *button,
                                        gpointer         user_data);



void
on_button_ajouter_etudiant_clicked     (GtkButton       *objet,
                                        gpointer         user_data);


void
on_window_gestion_show                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_afficher_liste_clicked       (GtkButton       *objet,
                                        gpointer         user_data);
void
on_button_connecter15_clicked          (GtkWidget       *objet,
                                        gpointer         user_data);


void
on_quitter_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_home_etudiant_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_confirmer_acc_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_annuler_acc_clicked                 (GtkButton       *button,
                                        gpointer         user_data);


void
on_entry13_activate                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeview4capt_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button16capt_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button30_cap_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data);
