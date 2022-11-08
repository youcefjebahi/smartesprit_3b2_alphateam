#ifndef CAPTEUR_H_INCLUDED
#define CAPTEUR_H_INCLUDED
#include <gtk/gtk.h>

typedef struct{
int jour;
int heure;
int numC;
float valT;
}capteurTemperature;
typedef struct{
int jour;
int mois;
int annee;
}datecapt;
typedef struct{
int captvaleurmin;
int captvaleurmax;
}caractcap;
typedef struct{
	char captref[20];
	int captzone;
	caractcap c;
	datecapt d;
	int etat;
	int type;
}capteur;

int verif2(char user[],char passe[]);
void ajout_capt(capteur c );
void supprimer_capt(char ref[],char file[20]);
void modifier_capt(capteur c1);
void affichage_capt(int *n,capteur T[]);
void capteurdefectueux();
void afficher_capt(GtkWidget *liste,char file[20]);
void rechercher( char ref[]);
void capteurparchoix(int z1[]);
int existcapt(char ref[20]);
void afficher_captdefectueux(GtkWidget *liste,char*l);


#endif // CAPTEUR_H_INCLUDED

