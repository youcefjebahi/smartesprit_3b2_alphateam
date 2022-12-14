/*
 * Initial main.c file generated by Glade. Edit as required.
 * Glade will not overwrite this file.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "interface.h"
#include "support.h"

int
main (int argc, char *argv[])
{
//  GtkWidget *acceuil;
//  GtkWidget *gestion;
  GtkWidget *smart_esprit;


#ifdef ENABLE_NLS
  bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);
#endif

  gtk_set_locale ();
  gtk_init (&argc, &argv);

  add_pixmap_directory (PACKAGE_DATA_DIR "/" PACKAGE "/pixmaps");

  /*
   * The following code was added by Glade to create one of each component
   * (except popup menus), just so that you see something after building
   * the project. Delete any components that you don't want shown initially.
   */
  //acceuil = create_acceuil ();
  //gtk_widget_show (acceuil);
  /*gestion = create_gestion ();
  gtk_widget_show (gestion);
  menu = create_menu ();
  gtk_widget_show (menu);
  administrateur = create_administrateur ();
  gtk_widget_show (administrateur);
  ajoutermenu = create_ajoutermenu ();
  gtk_widget_show (ajoutermenu);
  modifiermenu = create_modifiermenu ();
  gtk_widget_show (modifiermenu);
  recherchemenu = create_recherchemenu ();
  gtk_widget_show (recherchemenu);
  meilleur_menu = create_meilleur_menu ();
  gtk_widget_show (meilleur_menu);
  gestioncapt = create_gestioncapt ();
  gtk_widget_show (gestioncapt);
  techcapt = create_techcapt ();
  gtk_widget_show (techcapt);
  window_gestion = create_window_gestion ();
  gtk_widget_show (window_gestion);
  window_ajout = create_window_ajout ();
  gtk_widget_show (window_ajout);
  window_modification = create_window_modification ();
  gtk_widget_show (window_modification);
  window_affichage = create_window_affichage ();
  gtk_widget_show (window_affichage);
  confirmer_supprission = create_confirmer_supprission ();
  gtk_widget_show (confirmer_supprission);
  confirmer_modification = create_confirmer_modification ();
  gtk_widget_show (confirmer_modification);
  window_quitter = create_window_quitter ();
  gtk_widget_show (window_quitter);*/
  smart_esprit = create_smart_esprit ();
  gtk_widget_show (smart_esprit);

  gtk_main ();
  return 0;
}

