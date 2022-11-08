#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#include <gtk/gtk.h>
#include "interface.h"
#include "callbacks.h"
#include "tree.h"

GtkListStore *adstore;//creation du modele de type liste
GtkTreeViewColumn *adcolumn;//visualisation des colonnes
GtkCellRenderer *cellad;//afficheur de cellule(text,image..)
FILE *f;

void Afficherstock(GtkWidget* treeview1,char*l)
{

stock c;


        // Creation du modele 
        adstore = gtk_list_store_new(5,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING);
        // Insertion des elements 
        f=fopen(l,"r");
while(fscanf(f,"%s %s %s %s %s\n",c.id,c.nom,c.quantite,c.date,c.fournisseur)!=EOF)
        {GtkTreeIter pIter;

         // Creation de la nouvelle ligne 
         gtk_list_store_append(adstore, &pIter);
         // Mise a jour des donnees 
         gtk_list_store_set(adstore, &pIter,
                            0,c.id,
                            1,c.nom,
                            2,c.quantite,
                            3,c.date,
                            4,c.fournisseur,
                            -1);}
        fclose(f);

	// Creation de la 1ere colonne 
if(i==0)
	{cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("ID",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        // Ajouter la 1er colonne à la vue 
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	// Creation de la 2eme colonne 
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("NOM",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	// Ajouter la 2emme colonne à la vue 
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	// Creation de la 3eme colonne 
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Quntite",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	// Ajouter la 3emme colonne à la vue 
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	// Creation de la 4eme colonne 
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("DATE",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	// Ajouter la 4emme colonne à la vue 
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	// Creation de la 5eme colonne 
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Stocker avec",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	// Ajouter la 5emme colonne à la vue 
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	i++;}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );

}



void Afficherstock1(GtkWidget* treeview1,char*l)
{

stock c;


        // Creation du modele 
        adstore = gtk_list_store_new(5,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING);
        // Insertion des elements 
        f=fopen(l,"r");
while(fscanf(f,"%s %s %s %s %s\n",c.id,c.nom,c.quantite,c.date,c.fournisseur)!=EOF)
        {GtkTreeIter pIter;
	
         // Creation de la nouvelle ligne 
         gtk_list_store_append(adstore, &pIter);
         // Mise a jour des donnees 
         gtk_list_store_set(adstore, &pIter,
                            0,c.id,
                            1,c.nom,
                            2,c.quantite,
                            3,c.date,
                            4,c.fournisseur,
                            -1);}
        fclose(f);

	// Creation de la 1ere colonne 
if(j==0)
	{cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("ID",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        // Ajouter la 1er colonne à la vue 
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	// Creation de la 2eme colonne 
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("NOM",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	// Ajouter la 2emme colonne à la vue 
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	// Creation de la 3eme colonne 
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Quantite",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	// Ajouter la 3emme colonne à la vue 
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	// Creation de la 4eme colonne 
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("DATE",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	// Ajouter la 4emme colonne à la vue 
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	// Creation de la 5eme colonne 
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Stocker avec",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	// Ajouter la 5emme colonne à la vue 
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);



	j++;}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );

}



int Chercherstock(GtkWidget* treeview1,char*l,char*nom)
{

stock c;
int nb=0;

        // Creation du modele 
        adstore = gtk_list_store_new(5,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING);
        // Insertion des elements 
        f=fopen(l,"r");
while(fscanf(f,"%s %s %s %s %s\n",c.id,c.nom,c.quantite,c.date,c.fournisseur)!=EOF)
        {
	if( strcmp(nom,c.id)==0){ nb++;
	GtkTreeIter pIter;
         // Creation de la nouvelle ligne 
         gtk_list_store_append(adstore, &pIter);
         // Mise a jour des donnees 
         gtk_list_store_set(adstore, &pIter,
                            0,c.id,
                            1,c.nom,
                            2,c.quantite,
                            3,c.date,
                            4,c.fournisseur,
                            -1);}
}
        fclose(f);

	// Creation de la 1ere colonne 
if(j==0)
	{cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("ID",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        // Ajouter la 1er colonne à la vue 
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	// Creation de la 2eme colonne 
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("NOM",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	// Ajouter la 2emme colonne à la vue 
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	// Creation de la 3eme colonne 
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Quantite",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	// Ajouter la 3emme colonne à la vue 
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	// Creation de la 4eme colonne 
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("DATE",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	// Ajouter la 4emme colonne à la vue 
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	// Creation de la 5eme colonne 
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Stocker avec",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	// Ajouter la 5emme colonne à la vue 
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);




	j++;}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );
return nb;
}
void Afficherstock3(GtkWidget* treeview3,char*l)
{

stock c;


        // Creation du modele 
        adstore = gtk_list_store_new(5,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING);
        // Insertion des elements 
        f=fopen(l,"r");
while(fscanf(f,"%s %s %s %s %s\n",c.id,c.nom,c.quantite,c.date,c.fournisseur)!=EOF)
        {GtkTreeIter pIter;

         // Creation de la nouvelle ligne 
         gtk_list_store_append(adstore, &pIter);
         // Mise a jour des donnees 
         gtk_list_store_set(adstore, &pIter,
                            0,c.id,
                            1,c.nom,
                            2,c.quantite,
                            3,c.date,
                            4,c.fournisseur,
                            -1);}
        fclose(f);

	// Creation de la 1ere colonne 
if(k==0)
	{cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("ID",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        // Ajouter la 1er colonne à la vue 
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview3), adcolumn);


	// Creation de la 2eme colonne 
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("NOM",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	// Ajouter la 2emme colonne à la vue 
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview3), adcolumn);

	// Creation de la 3eme colonne 
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Quantite",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	// Ajouter la 3emme colonne à la vue 
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview3), adcolumn);

	// Creation de la 4eme colonne 
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("DATE",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	// Ajouter la 4emme colonne à la vue 
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview3), adcolumn);

	// Creation de la 5eme colonne 
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Stocker avec",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	// Ajouter la 5emme colonne à la vue 
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview3), adcolumn);


	k++;}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview3),
                                  GTK_TREE_MODEL(adstore)  );

}



