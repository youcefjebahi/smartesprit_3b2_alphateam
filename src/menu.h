#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <gtk/gtk.h>
typedef struct{
char id[15];
char type[15];
char jour[15];
char menu[100];
float dechet;
}Menu;
typedef struct {
int jour;
int type;
float dechet;
}dechets;
void ajout_menu(Menu c ,int *n,Menu T[]);
void supprimer_menu(char ref[]);
void modifier_menu(char ref[],Menu c ,int *n,Menu T[]);

dechets meilleur_menu();
void afficher_menu(GtkWidget *liste,int *n,Menu T[]);
Menu rechercher1( char ref[],int *n,Menu T[]);
int verif(char user[],char passe[]);

#endif 

