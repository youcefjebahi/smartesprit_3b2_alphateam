#include <gtk/gtk.h>
typedef struct
{
    char nom[20];
    char prenom[20];
    char id[20];
    char niveau[5];
    char date_naissance[15];
    char sexe [20];
    char telephone[20];
    char mail[40];
    char adresse[100];
    char type_chambre[15];
    char num_chambre[10];
    char debut_sej[15];
    char fin_sej[15];
} etudiant;

void ajouter4(etudiant E, char fichier[]);
etudiant rechercher4(char id[],int* trouve, char fichier[]);
void modifier4(char id[], etudiant E, char fichier[]);
void supprimer4(char id[], char fichier[]);
void nb_etudiant_niv4(int t[], char fichier[]);
void afficher4(char fichier[]);

void afficher_etudiant4(GtkWidget *liste, etudiant E);
void afficher_list_complete4(GtkWidget *liste);
void vider4(GtkWidget *liste);

