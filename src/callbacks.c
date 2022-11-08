#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include"tree.h"
#include"CRUD.h"
#include"menu.h"
#include"menu.c"
#include "capteur.h"
#include "capteur.c"
#include "etudiants.h"

GtkWidget *acceuil, *window, *gestion;

int x=0;
int z=0;
int x1,y1,z1[4]={0,0,0,0};

//connecter
void
on_button_connecter15_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Us, *Pa, *label241, *entry13;
char username[20];
char password[20];
int role;


Us=lookup_widget(objet, "entry12");
Pa=lookup_widget(objet, "entry13");

strcpy(username,gtk_entry_get_text(GTK_ENTRY(Us)));
strcpy(password, gtk_entry_get_text(GTK_ENTRY(Pa)));

role=verif(username, password);

if(role==1)
{
label241 = lookup_widget(objet, "label241");
gtk_label_set_text(GTK_LABEL(label241),"");
entry13= lookup_widget(objet, "entry13");
gtk_entry_set_text(GTK_LABEL(entry13),"");
window=create_window_gestion ();
gtk_widget_show (window);
acceuil=lookup_widget(objet,"smart_esprit");
gtk_widget_hide (acceuil);
}
if(role==2)
{
label241 = lookup_widget(objet, "label241");
gtk_label_set_text(GTK_LABEL(label241),"");
entry13= lookup_widget(objet, "entry13");
gtk_entry_set_text(GTK_LABEL(entry13),"");
window=create_menu();
gtk_widget_show (window);
acceuil=lookup_widget(objet,"smart_esprit");
gtk_widget_hide (acceuil);
}
if(role==3)
{
label241 = lookup_widget(objet, "label241");
gtk_label_set_text(GTK_LABEL(label241),"");
entry13= lookup_widget(objet, "entry13");
gtk_entry_set_text(GTK_LABEL(entry13),"");
window=create_gestioncapt ();
gtk_widget_show (window);
acceuil=lookup_widget(objet,"smart_esprit");
gtk_widget_hide (acceuil);
}
if(role==4)
{
label241 = lookup_widget(objet, "label241");
gtk_label_set_text(GTK_LABEL(label241),"");
entry13= lookup_widget(objet, "entry13");
gtk_entry_set_text(GTK_LABEL(entry13),"");
/*preparation du treeView*/
GtkWidget *p;
GtkWidget *p1;
GtkWidget *p2;
acceuil=lookup_widget(objet,"smart_esprit");
gtk_widget_hide (acceuil);
gestion=create_gestion ();
gtk_widget_show (gestion);
p=lookup_widget(gestion,"treeview1");
p1=lookup_widget(gestion,"treeview2");
p2=lookup_widget(gestion,"treeview3");
i=0;
j=0;
k=0;
Afficherstock(p,"stocks.txt");
Afficherstock1(p1,"stocks.txt");
Afficherstock3(p2,"stocks.txt");
}
if(role==0)
{
label241 = lookup_widget(objet, "label241");
gtk_label_set_text(GTK_LABEL(label241),"Verifiez vos informations!");
}
}


//connecter avec entrer

void
on_entry13_activate                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Us, *Pa, *label241, *entry13;
char username[20];
char password[20];
int role;


Us=lookup_widget(objet, "entry12");
Pa=lookup_widget(objet, "entry13");

strcpy(username,gtk_entry_get_text(GTK_ENTRY(Us)));
strcpy(password, gtk_entry_get_text(GTK_ENTRY(Pa)));

role=verif(username, password);

if(role==1)
{
label241 = lookup_widget(objet, "label241");
gtk_label_set_text(GTK_LABEL(label241),"");
entry13= lookup_widget(objet, "entry13");
gtk_entry_set_text(GTK_LABEL(entry13),"");
window=create_window_gestion ();
gtk_widget_show (window);
acceuil=lookup_widget(objet,"smart_esprit");
gtk_widget_hide (acceuil);
}
if(role==2)
{
label241 = lookup_widget(objet, "label241");
gtk_label_set_text(GTK_LABEL(label241),"");
entry13= lookup_widget(objet, "entry13");
gtk_entry_set_text(GTK_LABEL(entry13),"");
window=create_menu();
gtk_widget_show (window);
acceuil=lookup_widget(objet,"smart_esprit");
gtk_widget_hide (acceuil);
}
if(role==3)
{
label241 = lookup_widget(objet, "label241");
gtk_label_set_text(GTK_LABEL(label241),"");
entry13= lookup_widget(objet, "entry13");
gtk_entry_set_text(GTK_LABEL(entry13),"");
window=create_gestioncapt ();
gtk_widget_show (window);
acceuil=lookup_widget(objet,"smart_esprit");
gtk_widget_hide (acceuil);
}
if(role==4)
{
label241 = lookup_widget(objet, "label241");
gtk_label_set_text(GTK_LABEL(label241),"");
entry13= lookup_widget(objet, "entry13");
gtk_entry_set_text(GTK_LABEL(entry13),"");
/*preparation du treeView*/
GtkWidget *p;
GtkWidget *p1;
GtkWidget *p2;
acceuil=lookup_widget(objet,"smart_esprit");
gtk_widget_hide (acceuil);
gestion=create_gestion ();
gtk_widget_show (gestion);
p=lookup_widget(gestion,"treeview1");
p1=lookup_widget(gestion,"treeview2");
p2=lookup_widget(gestion,"treeview3");
i=0;
j=0;
k=0;
Afficherstock(p,"stocks.txt");
Afficherstock1(p1,"stocks.txt");
Afficherstock3(p2,"stocks.txt");
}
if(role==0)
{
label241 = lookup_widget(objet, "label241");
gtk_label_set_text(GTK_LABEL(label241),"Verifiez vos informations!");
}
}





//void
/*on_Modifierstock_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
       	 stock c;
     strcpy(c.id,gtk_label_get_text(GTK_LABEL(lookup_widget(gestion,"entryl11"))));
        strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestion,"entry6"))));
        strcpy(c.prixunitaire,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestion,"entry7"))));
        strcpy(c.date,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestion,"entry9"))));
        strcpy(c.fournisseur,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestion,"entry8"))));


        modifier_stock(c);
//mise ajour du tree view 
        Afficherstock(lookup_widget(gestion,"treeview1"),"stocks.txt");
		gtk_widget_show(lookup_widget(gestion,"label37"));




}*/


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)//signale du treeView (Double click)
{
	gchar *id;
        gchar *nom;
        gchar *quantite;
        gchar *date;
        gchar *fournisseur;
        int x;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget *p=lookup_widget(gestion,"treeview1");
        GtkTreeSelection *selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {
		gtk_widget_hide(lookup_widget(gestion,"label37"));//cacher label modifier avec succees
		
                gtk_tree_model_get (model,&iter,0,&id,1,&nom,2,&quantite,3,&date,4,&fournisseur,-1);//recuperer les information de la ligne selectionneé
		//remplir les champs de entry
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestion,"entry6")),nom);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestion,"entry7")),quantite);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestion,"entry9")),date);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestion,"entry8")),fournisseur);



                GtkWidget* msgid=lookup_widget(gestion,"label20");
                GtkWidget* msg1=lookup_widget(gestion,"label36");
                gtk_label_set_text(GTK_LABEL(msgid),id);
                gtk_widget_show(msgid);
                gtk_widget_show(msg1);
                gtk_widget_show(lookup_widget(gestion,"button4"));//afficher le bouton modifier
                gtk_notebook_prev_page(GTK_NOTEBOOK(lookup_widget(gestion,"notebook1")));//redirection vers la page precedente
        }



}



void
on_GestionAcceuil_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
/*GtkWidget *image;
image= lookup_widget(button, "image11");*/
//gtk_widget_set_name(image,"image");
//gtk_widget_show(image);
//gtk_box_pack_start(GTK_BOX(hbox2),image,TRUE,TRUE,0);
//gtk_misc_set_alignement(GTK_MISC(image),0.01,0.01);

gtk_widget_show (acceuil);
gtk_widget_destroy (gestion);

//gtk_widget_show(lookup_widget(gestion,"image11"));
}


void
on_AjouterSTOCK_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

 stock c;
GtkWidget *entryNom;
GtkWidget *entryid;
GtkWidget *entryquantite;
GtkWidget *entrydate;
GtkWidget *entryfournisseur;
GtkWidget *labelid;
GtkWidget *labelnom;
GtkWidget *labelquantite;
GtkWidget *labeldate;
GtkWidget *labelfournisseur;
GtkWidget *existe;
GtkWidget* success;
int b=1;
strcpy(c.fournisseur,"date");

//prixunitaire=lookup_widget(gestion,"spinbutton1");
entryid=lookup_widget(gestion,"entry5");
entryNom=lookup_widget(gestion,"entry1");
entryquantite=lookup_widget(gestion,"spinbutton1");
entrydate=lookup_widget(gestion,"entry4");
entryfournisseur=lookup_widget(gestion,"combobox1");

labelid=lookup_widget(gestion,"label13");
labelnom=lookup_widget(gestion,"label7");
labelquantite=lookup_widget(gestion,"label8");
labeldate=lookup_widget(gestion,"label9");
labelfournisseur=lookup_widget(gestion,"label10");
existe=lookup_widget(gestion,"label34");
success=lookup_widget(gestion,"label35");
if(strcmp("Date fixe",gtk_combo_box_get_active_text(GTK_COMBO_BOX(entryfournisseur)))==0)
strcpy(c.fournisseur,"Datefixe");
else
strcpy(c.fournisseur,"Datevariable");
        strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(entryid) ) );
        strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(entryNom) ) );
        strcpy(c.quantite,gtk_entry_get_text(GTK_ENTRY(entryquantite) ) );
        strcpy(c.date,gtk_entry_get_text(GTK_ENTRY(entrydate) ) );
       // strcpy(c.fournisseur,gtk_entry_get_text(GTK_ENTRY(entryfournisseur) ) );

 gtk_widget_hide (success);
// controle saisie
if(strcmp(c.id,"")==0){
		  gtk_widget_show (labelid);
b=0;
}
else {
		  gtk_widget_hide(labelid);
}

if(strcmp(c.nom,"")==0){
		  gtk_widget_show (labelnom);
b=0;
}
else {
		  gtk_widget_hide(labelnom);
}
if(strcmp(c.quantite,"")==0){
		  gtk_widget_show (labelquantite);
b=0;
}
else {
		  gtk_widget_hide(labelquantite);
}
if(strcmp(c.date,"")==0){
		  gtk_widget_show (labeldate);
b=0;
}
else {
		  gtk_widget_hide(labeldate);
}
/*if(strcmp(c.fournisseur,"date")==0){
		  gtk_widget_show (labelfournisseur);
b=0;
}
else {
		  gtk_widget_hide(labelfournisseur);
}*/





        if(b==0)
        {

				  gtk_widget_show (existe);
        }
        else {
						  gtk_widget_hide (existe);
                ajouter_stock(c);

						  gtk_widget_show (success);
        }
//mise a jour du treeView
        GtkWidget* p=lookup_widget(gestion,"treeview1");

        Afficherstock(p,"stocks.txt");
}














void
on_SupprimerSTOCK_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* p;
        GtkWidget *label;
        gchar* id;//gchar* type gtk ==> chaine en c car la fonction gtk_tree_model_get naccepte que gchar*
        label=lookup_widget(gestion,"label23");
        p=lookup_widget(gestion,"treeview1");




        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
     if(z==1){
   if (gtk_tree_selection_get_selected(selection, &model, &iter))//test sur la ligne selectionnée
        {  gtk_tree_model_get (model,&iter,0,&id,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView

           supprimer_stock(id);// supprimer la ligne du fichier

           gtk_widget_hide (label);}
else{
                gtk_widget_show (label);
        }

}
}

void
on_chercherSTOCKclicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *p1;
GtkWidget *entry;
GtkWidget *labelnom;
GtkWidget *nbResultat;
GtkWidget *message;
char nom[30];
char chnb[30];
int b=0,nb;
entry=lookup_widget(gestion,"entry10");
labelnom=lookup_widget(gestion,"label28");
p1=lookup_widget(gestion,"treeview2");
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(entry)));

if(strcmp(nom,"")==0){
  gtk_widget_show (labelnom);b=0;
}else{
b=1;
gtk_widget_hide (labelnom);}

if(b==0){return;}else{

nb=Chercherstock(p1,"stocks.txt",nom);
/* afficher le nombre de resultats obtenue par la recherche */
sprintf(chnb,"%d",nb);//conversion int==> chaine car la fonction gtk_label_set_text naccepte que chaine
nbResultat=lookup_widget(gestion,"label27");
message=lookup_widget(gestion,"label26");
gtk_label_set_text(GTK_LABEL(nbResultat),chnb);

//gtk_widget_show (nbResultat);
gtk_widget_show (message);



}

}


void
on_ModifierStock_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *labelid;
GtkWidget *labelnom;
GtkWidget *labeldate;
GtkWidget *existe;
 stock c;
int b=1;
// char id;
//FILE*f=NULL;

//prixunitaire=lookup_widget(gestion,"spinbutton1");

GtkWidget* success;
labelid=lookup_widget(gestion,"label42");
labelnom=lookup_widget(gestion,"label43");
labeldate=lookup_widget(gestion,"label44");
existe=lookup_widget(gestion,"label45");

success=lookup_widget(gestion,"label37");

        strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestion,"entry11"))));
//f=fopen("stock.txt","r");
//while(fscanf(f,"%s %s %s %s %s\n",c.id,c.nom,c.quantite,c.date,c.fournisseur)!=EOF)
  //      {
	//if( strcmp(id,c.id)==0){
	 //sprintf(entry6,"%s",c.nom);
	//}}
        strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestion,"entry6"))));
        strcpy(c.quantite,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestion,"spinbutton2"))));
        strcpy(c.date,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestion,"entry9"))));
       // strcpy(c.fournisseur,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestion,"entry8"))));
 gtk_widget_hide (success);
if(x==1)
	strcpy(c.fournisseur,"datefixe");

else
	strcpy(c.fournisseur,"datevariable");
if(strcmp(c.id,"")==0){
		  gtk_widget_show (labelid);
b=0;
}
else {
		  gtk_widget_hide(labelid);
}

if(strcmp(c.nom,"")==0){
		  gtk_widget_show (labelnom);
b=0;
}
else {
		  gtk_widget_hide(labelnom);
}

if(strcmp(c.date,"")==0){
		  gtk_widget_show (labeldate);
b=0;
}
else {
		  gtk_widget_hide(labeldate);
}
 if(b==0)
        {

				  gtk_widget_show (existe);
        }
        else {
						  gtk_widget_hide (existe);
               modifier_stock(c);

						 gtk_widget_show(success);
        }
		
	//supprimer_stock(c.id);
        //ajouter_stock(c);
                   //    gtk_widget_show (success);
//mise ajour du tree view 
       Afficherstock(lookup_widget(gestion,"treeview1"),"stocks.txt");
	
//}
}

void
on_rupture_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
remove("rupture.txt");
rupture();
 Afficherstock3(lookup_widget(gestion,"treeview3"),"rupture.txt");

}

void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	{
		x=0;
	}
}

void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{


if(gtk_toggle_button_get_active(togglebutton))
	z=1;
else
	z=0;

}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	{
		x=1;
	}
}



void
on_treeview1_menu_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
int i=0,n=0;
	Menu c3,T[1000];
	FILE *ff=NULL;
	ff=fopen("menu.txt","r");
	if(ff!=NULL){
			
		while(!feof(ff))
		{
			fscanf(ff,"%s %s %s %s %f\n",c3.id,c3.type,c3.jour,c3.menu,&c3.dechet);
			strcpy(T[i].id,c3.id);
			strcpy(T[i].type,c3.type);
			strcpy(T[i].jour,c3.jour);
			strcpy(T[i].menu,c3.menu);
			T[i].dechet=c3.dechet;
			
			i++;
		}
		fclose(ff);
	n=i;
	}
	GtkTreeIter iter;
 	gchar *id;
	



	GtkTreeModel *model = gtk_tree_view_get_model(treeview);
	if (gtk_tree_model_get_iter(model,&iter,path))
	{
		gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0,&id,-1);
		supprimer_menu(id);
	} 
FILE *f1=NULL;
	f1=fopen("menu1.txt","a+");
	
	if(f1!=NULL)
	{
		for(i=0;i<n;i++){
			fprintf(f1,"%s %s %s %s %f\n",T[i].id,T[i].type,T[i].jour,T[i].menu,T[i].dechet);
		}
	}
	else
		printf("\n Not Found");
	remove("menu.txt");
	rename("menu1.txt","menu.txt");
	fclose(f1);

}


void
on_ajoutermenu_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
 GtkWidget *windowespace_ajoute, *windowespace_technicien;
	windowespace_ajoute=lookup_widget (objet_graphique,"ajoutermenu");
	windowespace_ajoute=create_ajoutermenu();
	gtk_widget_show (windowespace_ajoute);

	windowespace_technicien=lookup_widget (objet_graphique,"menu");
	gtk_widget_destroy(windowespace_technicien);
}


void
on_recherchemenu_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)

{
GtkWidget *windowespace_recherche, *windowespace_technicien;
	windowespace_recherche=lookup_widget (objet_graphique,"recherchemenu");
	windowespace_recherche=create_recherchemenu();
	gtk_widget_show(windowespace_recherche);

	windowespace_technicien=lookup_widget (objet_graphique,"menu");
	gtk_widget_destroy(windowespace_technicien);
}


void
on_modifiermenu_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *windowespace_modifier, *windowespace_technicien;
	windowespace_modifier=lookup_widget (objet_graphique,"modifiermenu");
	windowespace_modifier=create_modifiermenu();
	gtk_widget_show (windowespace_modifier);

	windowespace_technicien=lookup_widget (objet_graphique,"menu");
	gtk_widget_destroy(windowespace_technicien);

}


void
on_supprimermenu_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *menu,*treeview;
	GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
	gchar* id;
	gchar type;
	gchar jour;
	gchar menu1;
	gfloat dechet;
	
	menu=lookup_widget(objet_graphique,"menu");
        treeview=lookup_widget(menu,"treeview1_menu");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {
		gtk_tree_model_get (model,&iter,0,&id,1,&type,2,&jour,3,&menu1,4,&dechet,-1);
		supprimer_menu(id);
		
		
	}
}


void
on_meilleurmenu_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowespace_meilleur_menu, *windowespace_technicien;
	windowespace_meilleur_menu=lookup_widget (objet_graphique,"meilleur_menu");
	windowespace_meilleur_menu=create_meilleur_menu();
	gtk_widget_show (windowespace_meilleur_menu);

	windowespace_technicien=lookup_widget (windowespace_meilleur_menu,"menu");

}


void
on_retourmenu_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
gtk_widget_show (acceuil);
gtk_widget_destroy (window);
}



void
on_affichermenu_clicked                ( GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget  *windowespace_technicien,*treeview;
	windowespace_technicien=lookup_widget (objet_graphique,"menu");
	treeview=lookup_widget(windowespace_technicien,"treeview1_menu");
	
	
	int i=0,n=0;
	Menu c3,T[1000];
	FILE *ff=NULL;
	ff=fopen("menu.txt","r");
	if(ff!=NULL){
			
		while(!feof(ff))
		{
			fscanf(ff,"%s %s %s %s %f\n",c3.id,c3.type,c3.jour,c3.menu,&c3.dechet);
			strcpy(T[i].id,c3.id);
			strcpy(T[i].type,c3.type);
			strcpy(T[i].jour,c3.jour);
			strcpy(T[i].menu,c3.menu);
			T[i].dechet=c3.dechet;
			i++;
		}
		fclose(ff);
	n=i;
	}
	afficher_menu(treeview,&n,T);

}


void
on_button9menu_clicked                 ( GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
	int i=0,n=0;
	Menu c3,T[1000];
	FILE *ff=NULL;
	ff=fopen("menu.txt","r");
	if(ff!=NULL){
			
		while(!feof(ff))
		{
			fscanf(ff,"%s %s %s %s %f\n",c3.id,c3.type,c3.jour,c3.menu,&c3.dechet);
			strcpy(T[i].id,c3.id);
			strcpy(T[i].type,c3.type);
			strcpy(T[i].jour,c3.jour);
			strcpy(T[i].menu,c3.menu);
			T[i].dechet=c3.dechet;
			i++;
		}
		fclose(ff);
	n=i;
	}
	GtkWidget *id,*type,*jour,*menu,*dechet,*labelid,*labelmenu;
	char id1[20],type1[20],menu1[20];
	int jour1,b=1;
	float dechet1;;
	Menu c;
	id=lookup_widget (objet_graphique,"entry3_menu");
	jour=lookup_widget (objet_graphique,"spinbutton1_menu");
	menu=lookup_widget (objet_graphique,"entry9_menu");
	type=lookup_widget (objet_graphique,"combobox1_menu");
	dechet=lookup_widget (objet_graphique,"entry7_menu");
	strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(id)));
	strcpy(c.menu,gtk_entry_get_text(GTK_ENTRY(menu)));
	if(strcmp("Petit dejeuner",gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)))==0)
		strcpy(c.type,"1");
	else if(strcmp("Dejeuner",gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)))==0)
		strcpy(c.type,"2");
	else if(strcmp("Diner",gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)))==0)
		strcpy(c.type,"3");
	
	jour1=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
	sprintf(c.jour,"%d",jour1);
	c.dechet=atoi(gtk_entry_get_text(GTK_ENTRY(dechet)));
	labelid=lookup_widget(objet_graphique,"label74_menu");
	labelmenu=lookup_widget(objet_graphique,"label75_menu");
	gtk_widget_hide(labelid);
	gtk_widget_hide(labelmenu);
	if(strcmp(c.id,"")==0){
	gtk_widget_show(labelid);
	b=0;}
	else{
	gtk_widget_hide(labelid);}
	if(strcmp(c.menu,"")==0){
	gtk_widget_show(labelmenu);
	b=0;}
	else{
	gtk_widget_hide(labelmenu);}
	
	if(b==1){
	ajout_menu(c,&n,T);
	FILE *f1=NULL;
	f1=fopen("menu1.txt","a+");
	
	if(f1!=NULL)
	{
		for(i=0;i<n;i++){
			fprintf(f1,"%s %s %s %s %f\n",T[i].id,T[i].type,T[i].jour,T[i].menu,T[i].dechet);
		}
	}
	else
		printf("\n Not Found");
	remove("menu.txt");
	rename("menu1.txt","menu.txt");
	fclose(f1);





}
}


void
on_button10menu_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowespace_technicien, *fenetre_ajout_modif;
fenetre_ajout_modif=lookup_widget(objet_graphique,"ajoutermenu");
windowespace_technicien=lookup_widget(objet_graphique,"menu");

gtk_widget_destroy(fenetre_ajout_modif);
windowespace_technicien=create_menu();
gtk_widget_show(windowespace_technicien);

}


void
on_button11menu_clicked                ( GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
int i=0,n=0,b=1;
	Menu c3,T[1000];
	FILE *ff=NULL;
	ff=fopen("menu.txt","r");
	if(ff!=NULL){
			
		while(!feof(ff))
		{
			fscanf(ff,"%s %s %s %s %f\n",c3.id,c3.type,c3.jour,c3.menu,&c3.dechet);
			strcpy(T[i].id,c3.id);
			strcpy(T[i].type,c3.type);
			strcpy(T[i].jour,c3.jour);
			strcpy(T[i].menu,c3.menu);
			T[i].dechet=c3.dechet;
			i++;
		}
		fclose(ff);
	n=i;
	}
	GtkWidget *id,*type,*jour,*menu,*dechet,*labelid,*labelmenu;
	char id1[20],menu1[20],type1[20];
	int jour1;
	float dechet1;
	Menu c;
	id=lookup_widget (objet_graphique,"entry4_menu");
	jour=lookup_widget (objet_graphique,"spinbutton4_menu");
	menu=lookup_widget (objet_graphique,"entry8_menu");
	type=lookup_widget (objet_graphique,"comboboxentry2_menu");
	dechet=lookup_widget (objet_graphique,"entry10_menu");
	strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(id)));
	strcpy(c.menu,gtk_entry_get_text(GTK_ENTRY(menu)));
	if(strcmp("Petit dejeuner",gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)))==0)
		strcpy(c.type,"1");
	else if(strcmp("Dejeuner",gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)))==0)
		strcpy(c.type,"2");
	else if(strcmp("Diner",gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)))==0)
		strcpy(c.type,"3");
	
	jour1=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
	sprintf(c.jour,"%d",jour1);
	c.dechet=atoi(gtk_entry_get_text(GTK_ENTRY(dechet)));
	labelid=lookup_widget(objet_graphique,"label77_menu");
	labelmenu=lookup_widget(objet_graphique,"label79_menu");
	gtk_widget_hide(labelid);
	gtk_widget_hide(labelmenu);
	if(strcmp(c.id,"")==0){
	gtk_widget_show(labelid);
	b=0;}
	else{
	gtk_widget_hide(labelid);}
	if(strcmp(c.menu,"")==0){
	gtk_widget_show(labelmenu);
	b=0;}
	else{
	gtk_widget_hide(labelmenu);}
	
	if(b==1){
	modifier_menu(c.id,c,&n,T);}
	FILE *f1=NULL;
	f1=fopen("menu1.txt","a+");
	
	if(f1!=NULL)
	{
		for(i=0;i<n;i++){
			fprintf(f1,"%s %s %s %s %f\n",T[i].id,T[i].type,T[i].jour,T[i].menu,T[i].dechet);
		}
	}
	else
		printf("\n Not Found");
	remove("menu.txt");
	rename("menu1.txt","menu.txt");
	fclose(f1);


}


void
on_button12_menu_clicked               ( GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowespace_technicien, *fenetre_ajout_modifier;
fenetre_ajout_modifier=lookup_widget(objet_graphique,"modifiermenu");
windowespace_technicien=lookup_widget(objet_graphique,"menu");

gtk_widget_destroy(fenetre_ajout_modifier);
windowespace_technicien=create_menu();
gtk_widget_show(windowespace_technicien);}


void
on_button16menu_clicked                ( GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowespace_technicien, *fenetre_ajout_recherche;
fenetre_ajout_recherche=lookup_widget(objet_graphique,"recherchemenu");
windowespace_technicien=lookup_widget(objet_graphique,"menu");

gtk_widget_destroy(fenetre_ajout_recherche);
windowespace_technicien=create_menu();
gtk_widget_show(windowespace_technicien);
}


void
on_button1menu_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget  *windowespace_meilleur_menu, *windowespace_menu;
	
	windowespace_meilleur_menu=lookup_widget (objet_graphique,"meilleur_menu");
	gtk_widget_destroy(windowespace_meilleur_menu);
	windowespace_menu=lookup_widget (objet_graphique,"menu");
	windowespace_menu=create_menu();
	gtk_widget_show (windowespace_menu);
}


void
on_button2menu_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowespace_meilleur_menu, *aff1,*aff2,*aff3;
	aff1=lookup_widget(objet_graphique,"label59_menu");
	aff2=lookup_widget(objet_graphique,"label61_menu");
	aff3=lookup_widget(objet_graphique,"label63_menu");
	char ch1[10],ch2[10],ch3[10];
	dechets m;
	m=meilleur_menu();
	
	sprintf(ch1,"%d",m.jour);
	sprintf(ch2,"%d",m.type);
	sprintf(ch3,"%f",m.dechet);
	
	gtk_label_set_text(GTK_LABEL(aff1),ch1);
	gtk_label_set_text(GTK_LABEL(aff2),ch2);
	gtk_label_set_text(GTK_LABEL(aff3),ch3);
}


void
on_button15menu_clicked                ( GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *id,*aff1,*aff2,*aff3,*aff4,*aff5;
	char ref[20],resultat[1000];
	id=lookup_widget(objet_graphique,"entry6menu");
	aff1=lookup_widget(objet_graphique,"label56_menu");
	aff2=lookup_widget(objet_graphique,"label67_menu");
	aff3=lookup_widget(objet_graphique,"label69_menu");
	aff4=lookup_widget(objet_graphique,"label71_menu");
	aff5=lookup_widget(objet_graphique,"label73_menu");
	int i=0,n=0;
	Menu c3,T[1000];
	FILE *ff=NULL;
	ff=fopen("menu.txt","r");
	if(ff!=NULL){
			
		while(!feof(ff))
		{
			fscanf(ff,"%s %s %s %s %f\n",c3.id,c3.type,c3.jour,c3.menu,&c3.dechet);
			strcpy(T[i].id,c3.id);
			strcpy(T[i].type,c3.type);
			strcpy(T[i].jour,c3.jour);
			strcpy(T[i].menu,c3.menu);
			T[i].dechet=c3.dechet;
		
			i++;
		}
		fclose(ff);
	n=i;
	}
	Menu c1;
	strcpy(ref,gtk_entry_get_text(GTK_ENTRY(id)));
	c1=rechercher1(ref,&n,T);

	sprintf(resultat,"%f",c1.dechet);
	
	
gtk_label_set_text(GTK_LABEL(aff1),c1.id);
gtk_label_set_text(GTK_LABEL(aff2),c1.type);
gtk_label_set_text(GTK_LABEL(aff3),c1.jour);
gtk_label_set_text(GTK_LABEL(aff4),c1.menu);
gtk_label_set_text(GTK_LABEL(aff5),resultat);


}


void
on_loginmenu_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
FILE *f=NULL;
	 GtkWidget *ID,*password, *windowespace_technicien, *windowespace_administrateur,*aff;
	GtkWidget* output ;
	char login1[20]; 
	char passw[20];
	int trouve;
	ID = lookup_widget(objet_graphique, "entry1user") ;
	password = lookup_widget(objet_graphique, "entry2passe") ;
	strcpy(login1, gtk_entry_get_text(GTK_ENTRY(ID)));
	strcpy(passw, gtk_entry_get_text(GTK_ENTRY(password)));
	trouve=verif(login1,passw);
	if (trouve==1)
{
	{windowespace_technicien=create_menu();
	gtk_widget_show (windowespace_technicien);}
	windowespace_administrateur=lookup_widget (objet_graphique,"administrateur");
	gtk_widget_destroy(windowespace_administrateur);
	windowespace_technicien=lookup_widget (objet_graphique,"menu");}
	else{
	windowespace_administrateur=lookup_widget (objet_graphique,"administrateur");
	windowespace_administrateur=lookup_widget (objet_graphique,"administrateur");

	aff=lookup_widget(objet_graphique,"label56");
	char resultat[200];
	strcpy(resultat,"le mot de passe est incorrect  ");
	gtk_label_set_text(GTK_LABEL(aff),resultat);
}
}







void
on_radiobutton1_capt_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	{
		y1=1;
	}
}


void
on_button5add_clicked                 ( GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{

	
	GtkWidget *captref,*captzone,*captmin,*captmax,*capttype,*label19capt;
	
	capteur c;
	captref=lookup_widget (objet_graphique,"entry2capt");
	captmax=lookup_widget (objet_graphique,"spinbutton1_capt");
	captmin=lookup_widget (objet_graphique,"spinbutton2_capt");
	capttype=lookup_widget (objet_graphique,"comboboxtype_capteur");
	captzone=lookup_widget (objet_graphique,"comboboxentrytype");
	strcpy(c.captref,gtk_entry_get_text(GTK_ENTRY(captref)));
	if(strcmp("1",gtk_combo_box_get_active_text(GTK_COMBO_BOX(captzone)))==0)
		c.captzone=1;
	else if(strcmp("2",gtk_combo_box_get_active_text(GTK_COMBO_BOX(captzone)))==0)
		c.captzone=2;
	
	else
		c.captzone=3;
	if(strcmp("Temperature",gtk_combo_box_get_active_text(GTK_COMBO_BOX(capttype)))==0)
		c.type=0;
	else if(strcmp("Mouvement",gtk_combo_box_get_active_text(GTK_COMBO_BOX(capttype)))==0)
		c.type=1;
	else if(strcmp("Fumer",gtk_combo_box_get_active_text(GTK_COMBO_BOX(capttype)))==0)
		c.type=2;
	else
		c.type=3;
	
	c.c.captvaleurmax=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (captmax));
	c.c.captvaleurmin=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (captmin));
	c.etat=y1;
	ajout_capt(c);
	label19capt=lookup_widget(objet_graphique,"label19capt");
	gtk_label_set_text(GTK_LABEL(label19capt),"verifier vos données");
}


void
on_treeview2_capt_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_checkbutton4_capt_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
		z1[3]=1;

}


void
on_checkbutton3_capt_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
		z1[2]=1;
}


void
on_checkbutton2_capt_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
		z1[1]=1;
}


void
on_checkbutton1_capt_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
		z1[0]=1;

}


void
on_buttondeffective_clicked            (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *gestioncapt,*treeview,*cb1,*cb2,*cb3,*cb4;
	gestioncapt=lookup_widget (objet_graphique,"gestioncapt");
	cb1=lookup_widget (objet_graphique,"checkbutton1_capt");
	cb2=lookup_widget (objet_graphique,"checkbutton2_capt");
	cb3=lookup_widget (objet_graphique,"checkbutton3_capt");
	cb4=lookup_widget (objet_graphique,"checkbutton4_capt");
	treeview=lookup_widget (gestioncapt,"treeview2_capt");
	capteurparchoix(z1);
	afficher_capt(treeview,"capteurchoix.txt");
	remove("capteurchoix.txt");
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(cb1), FALSE);
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(cb2), FALSE);
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(cb3), FALSE);
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(cb4), FALSE);
	z1[0]=0;
	z1[1]=0;
	z1[2]=0;
	z1[3]=0;
}


void
on_button6_capt_clicked                ( GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{

	GtkWidget *captref,*captzone,*captmin,*captmax,*capttype,*label26capt;
	
	capteur c;
	captref=lookup_widget (objet_graphique,"entry3capt");
	captmax=lookup_widget (objet_graphique,"spinbutton3_capt");
	captmin=lookup_widget (objet_graphique,"spinbutton4_capt");
	capttype=lookup_widget (objet_graphique,"comboboxentry5_capt");
	captzone=lookup_widget (objet_graphique,"comboboxentry2_capt");
	strcpy(c.captref,gtk_entry_get_text(GTK_ENTRY(captref)));
	if(strcmp("1",gtk_combo_box_get_active_text(GTK_COMBO_BOX(captzone)))==0)
		c.captzone=1;
	else if(strcmp("2",gtk_combo_box_get_active_text(GTK_COMBO_BOX(captzone)))==0)
		c.captzone=2;
	
	else
		c.captzone=3;
	if(strcmp("Temperature",gtk_combo_box_get_active_text(GTK_COMBO_BOX(capttype)))==0)
		c.type=0;
	else if(strcmp("Mouvement",gtk_combo_box_get_active_text(GTK_COMBO_BOX(capttype)))==0)
		c.type=1;
	else if(strcmp("Fumer",gtk_combo_box_get_active_text(GTK_COMBO_BOX(capttype)))==0)
		c.type=2;
	else
		c.type=3;
	
	c.c.captvaleurmax=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (captmax));
	c.c.captvaleurmin=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (captmin));
	c.etat=x;
	modifier_capt(c);
	label26capt=lookup_widget(objet_graphique,"label26capt");
	gtk_label_set_text(GTK_LABEL(label26capt),"Modification Enregistrée");
	
}



void
on_login_clicked                       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	FILE *f=NULL;
	 GtkWidget *ID,*password, *windowespace_technicien, *windowespace_techcapt;
	GtkWidget* output ;
	char login1[20]; 
	char passw[20];
	int trouve; 
	ID = lookup_widget(objet_graphique, "entry1user_capt") ;
	password = lookup_widget(objet_graphique, "entry2passe_capt") ;
	strcpy(login1, gtk_entry_get_text(GTK_ENTRY(ID)));
	strcpy(passw, gtk_entry_get_text(GTK_ENTRY(password)));
	trouve=verif2(login1,passw);
	if (trouve==1){
	{windowespace_technicien=create_gestioncapt();
	gtk_widget_show (windowespace_technicien);}
	//ouvrir le fichier
	f=fopen("utilisateur.txt","a+");
	if (f!=NULL)
	{ 
		fprintf(f,"%s %s \n",login1,passw);
		fclose(f);

	}
	else 
		printf("\n Not found");
	windowespace_techcapt=lookup_widget (objet_graphique,"techcapt");
	gtk_widget_destroy(windowespace_techcapt);
	windowespace_technicien=lookup_widget (objet_graphique,"gestioncapt");}
}


void
on_button3refresh_clicked              ( GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *gestioncapt,*treeview1_capt,*label27erreurrecherche,*label11capt,*label19capt,*label26capt;
	gestioncapt=lookup_widget (objet_graphique,"gestioncapt");
	treeview1_capt=lookup_widget (gestioncapt,"treeview1_capt");
	afficher_capt(treeview1_capt,"capteur.txt");
	label27erreurrecherche=lookup_widget(objet_graphique,"label27erreurrecherche");
	gtk_label_set_text(GTK_LABEL(label27erreurrecherche),"");
	label11capt=lookup_widget(objet_graphique,"label11capt");
	gtk_label_set_text(GTK_LABEL(label11capt),"");
	label19capt=lookup_widget(objet_graphique,"label19capt");
	gtk_label_set_text(GTK_LABEL(label19capt),"");
	label26capt=lookup_widget(objet_graphique,"label26capt");
	gtk_label_set_text(GTK_LABEL(label26capt),"");
}


void
on_button1serch_clicked                ( GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *ref,*treeview,*gestioncapt,*label27erreurrecherche;
	char ref1[20];
	gestioncapt=lookup_widget (objet_graphique,"gestioncapt");
	treeview=lookup_widget (gestioncapt,"treeview1_capt");
	ref=lookup_widget (objet_graphique,"entry1capt");
	strcpy(ref1,gtk_entry_get_text(GTK_ENTRY(ref)));
	if(strcmp(ref1,"")!=0)
	{
		if(existcapt(ref1))
		{
			rechercher(ref1);
			afficher_capt(treeview,"recherche.txt");
			remove("recherche.txt");
		}
		else{
			label27erreurrecherche=lookup_widget(objet_graphique,"label27erreurrecherche");
			gtk_label_set_text(GTK_LABEL(label27erreurrecherche),"Reference n'existe pas");
		}
	}
	else
		afficher_capt(treeview,"capteur.txt");
}


void
on_radiobutton2_capt_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	{
		y1=0;
	}
}





void
on_radiobutton4_capt_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	{
		x1=0;
	}
}


void
on_radiobutton3_capt_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	{
		x1=1;
	}
}


void
on_button4delate_clicked               ( GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *gestioncapt,*treeview,*label11capt;
	GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
	gchar* ref;
	gint zone;
	gint min;
	gint max;
	gint etat;
	gint type;
	
	gestioncapt=lookup_widget(objet_graphique,"gestioncapt");
        treeview=lookup_widget(gestioncapt,"treeview1_capt");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {
		gtk_tree_model_get (model,&iter,0,&ref,1,&zone,2,&min,3,&max,4,&etat,5,&type,-1);
		supprimer_capt(ref,"capteur.txt");
		supprimer_capt(ref,"temperature.txt");
		supprimer_capt(ref,"mouvement.txt");
		supprimer_capt(ref,"smoke.txt");
		supprimer_capt(ref,"debit.txt");
		supprimer_capt(ref,"temperaturedef.txt");
		supprimer_capt(ref,"mouvementdef.txt");
		supprimer_capt(ref,"smokedef.txt");
		supprimer_capt(ref,"debitdef.txt");
		afficher_capt(treeview,"capteur.txt");
		label11capt=lookup_widget(objet_graphique,"label11capt");
		gtk_label_set_text(GTK_LABEL(label11capt),"capteur supprimée");
	}
}


void
on_button2home_clicked                 ( GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
gtk_widget_show (acceuil);
gtk_widget_destroy (window);
}










//agent de foyer

etudiant E, E1;
char fichier[20]="Etudiants.txt";
int trouve;
GtkWidget *nom,*prenom,*id,*niveau,*date_naissance,*telephone,*mail,*adresse,*type_chambre,*numero_chambre,*debut_sej,*fin_sej;
GtkWidget *window_gestion;
GtkWidget *window_ajout;
GtkWidget *window_modification;
GtkWidget *window_affichage;
GtkWidget *confirmer_supprission;
GtkWidget *confirmer_modification;
GtkWidget *window_quitter;
GtkWidget *confirmer_acceuil;
GtkTreeModel *model;
GtkTreeIter iter;
GtkTreeSelection *selection;
gchar *Nom, *Prenom, *Id, *Niveau, *DateNaissance, *Sexe, *Telephone, *Mail, *Adresse, *TypeChambre, *NumeroChambre, *DebutSejour, *FinSejour, *ids;
char id1[20], idm[20];

//dashboard etudiants
void
on_window_gestion_show                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
int t[]={0,0,0,0,0};
	int i, s=0;
	char t0[5], t1[5], t2[5], t3[5], t4[5], total[5];
	nb_etudiant_niv4(t,fichier);
for(i=0;i<5;i++) s+=t[i];
	sprintf(t0,"%d",t[0]);
	sprintf(t1,"%d",t[1]);
	sprintf(t2,"%d",t[2]);
	sprintf(t3,"%d",t[3]);
	sprintf(t4,"%d",t[4]);
sprintf(total,"%d",s);

	GtkWidget *label_total;
	label_total = lookup_widget(objet, "label_nombre_total");
	gtk_label_set_text(GTK_LABEL(label_total),total);
	
	GtkWidget *label_nombre1;
	label_nombre1 = lookup_widget(objet, "label_nombre1");
	gtk_label_set_text(GTK_LABEL(label_nombre1),t0);

	GtkWidget *label_nombre2;
	label_nombre2 = lookup_widget(objet, "label_nombre2");
	gtk_label_set_text(GTK_LABEL(label_nombre2),t1);

	GtkWidget *label_nombre3;
	label_nombre3 = lookup_widget(objet, "label_nombre3");
	gtk_label_set_text(GTK_LABEL(label_nombre3),t2);

	GtkWidget *label_nombre4;
	label_nombre4 = lookup_widget(objet, "label_nombre4");
	gtk_label_set_text(GTK_LABEL(label_nombre4),t3);

	GtkWidget *label_nombre5;
	label_nombre5 = lookup_widget(objet, "label_nombre5");
	gtk_label_set_text(GTK_LABEL(label_nombre5),t4);
}

//ajout d'etudiant

void
on_button_ajouter_etudiant_clicked     (GtkButton       *objet,
                                        gpointer         user_data)
{
	window_ajout = create_window_ajout ();
	gtk_widget_show (window_ajout);
	window_gestion = lookup_widget(objet, "window_gestion");
	gtk_widget_hide (window_gestion);
}

//retour ajout
void
on_button_retour_ajout_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
	gtk_widget_hide (window_ajout);
	gtk_widget_show (window_gestion);
}

//ajouter
void
on_button_ajouter_clicked              (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *label_exist_ajout, *label_ajoute, *j, *radiobutton_homme, *radiobutton_femme;
int i, l, n, z, espace, k=0;
char *info;
char esp[2];
char label[13][40]={"label_nom_manquant","label_prenom_manquant", "label_id_manquant", "label_niveau_manquant", "label_naissance_manquant", "label_sexe_manquant", "label_telephone_manquant", "label_mail_manquant", "label_adresse_manquant", "label_type_chambre_manquant", "label_numero_chambre_manquant", "label_debut_sejour_manquant", "label_fin_sejour_manquant"};

	nom=lookup_widget(objet, "entry_nom");
	prenom=lookup_widget(objet, "entry_prenom");
	id=lookup_widget(objet, "entry_id");
	niveau=lookup_widget(objet, "spinbutton_niveau");
	date_naissance=lookup_widget(objet, "entry_naissance");
	radiobutton_homme= lookup_widget(objet, "radiobutton_homme");
	radiobutton_femme= lookup_widget(objet, "radiobutton_femme");
	telephone=lookup_widget(objet, "entry_telephone");
	mail=lookup_widget(objet, "entry_mail");
	adresse=lookup_widget(objet, "entry_adresse");
	type_chambre=lookup_widget(objet, "combobox_type_chambre");
	numero_chambre=lookup_widget(objet, "entry_numero_chambre");
	debut_sej=lookup_widget(objet, "entry_debut_sejour");
	fin_sej=lookup_widget(objet, "entry_fin_sejour");

for(i=0;i<13;i++)
{
switch(i)
{
case 0:
	n=strlen(gtk_entry_get_text(GTK_ENTRY(nom)));
	info=(char*) malloc(n);
	strcpy(info,gtk_entry_get_text(GTK_ENTRY(nom)));
	l=20;
	break;
case 1:
	n=strlen(gtk_entry_get_text(GTK_ENTRY(prenom)));
	info=(char*) malloc(n);
	strcpy(info,gtk_entry_get_text(GTK_ENTRY(prenom)));
	l=20;
	break;
case 2:
	n=strlen(gtk_entry_get_text(GTK_ENTRY(id)));
	info=(char*) malloc(n);
	strcpy(info,gtk_entry_get_text(GTK_ENTRY(id)));
	l=20;
	break;
case 3:
	n=5;
	info=(char*) malloc(n);
	sprintf(info,"%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (niveau)));
	l=5;
	break;
case 4:
	n=strlen(gtk_entry_get_text(GTK_ENTRY(date_naissance)));
	info=(char*) malloc(n);
	strcpy(info,gtk_entry_get_text(GTK_ENTRY(date_naissance)));
	l=15;
	break;
case 5:
	n=20;
	info=(char*) malloc(n);
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(radiobutton_homme))) strcpy(info,"homme");
	else if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(radiobutton_femme))) strcpy(info,"femme");
	else strcpy(info,"");
	l=20;
	break;
case 6:
	n=strlen(gtk_entry_get_text(GTK_ENTRY(telephone)));
	info=(char*) malloc(n);
	strcpy(info,gtk_entry_get_text(GTK_ENTRY(telephone)));
	l=20;
	break;
case 7:
	n=strlen(gtk_entry_get_text(GTK_ENTRY(mail)));
	info=(char*) malloc(n);
	strcpy(info,gtk_entry_get_text(GTK_ENTRY(mail)));
	l=40;
	break;
case 8:
	n=strlen(gtk_entry_get_text(GTK_ENTRY(adresse)));
	info=(char*) malloc(n);
	strcpy(info,gtk_entry_get_text(GTK_ENTRY(adresse)));
	l=100;
	break;
case 9:
	n=15;
	info=(char*) malloc(n);
	if(gtk_combo_box_get_active_text(GTK_COMBO_BOX(type_chambre))!=NULL) strcpy(info,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type_chambre)));
	else strcpy(info,"");
	l=15;
	break;
case 10:
	n=strlen(gtk_entry_get_text(GTK_ENTRY(numero_chambre)));
	info=(char*) malloc(n);
	strcpy(info,gtk_entry_get_text(GTK_ENTRY(numero_chambre)));
	l=10;
	break;
case 11:
	n=strlen(gtk_entry_get_text(GTK_ENTRY(debut_sej)));
	info=(char*) malloc(n);
	strcpy(info,gtk_entry_get_text(GTK_ENTRY(debut_sej)));
	l=15;
	break;
case 12:
	n=strlen(gtk_entry_get_text(GTK_ENTRY(fin_sej)));
	info=(char*) malloc(n);
	strcpy(info,gtk_entry_get_text(GTK_ENTRY(fin_sej)));
	l=15;
	break;
}
z=0;
espace=0;
strcpy(esp, " ");
while(espace==0 && (z < strlen(info)))
{
if(info[z]==esp[0]) espace=1;
z++;
}

if(strcmp(info,"")==0)
{
	j = lookup_widget(objet, label[i]);
	gtk_label_set_text(GTK_LABEL(j),"* manquant");
	label_ajoute = lookup_widget(objet, "label_ajoute");
	gtk_label_set_text(GTK_LABEL(label_ajoute),"");
	label_exist_ajout = lookup_widget(objet, "label_exist_ajout");
	gtk_label_set_text(GTK_LABEL(label_exist_ajout),"");
}
else if (strlen(info)>l)
{
	j = lookup_widget(objet, label[i]);
	gtk_label_set_text(GTK_LABEL(j),"*taille très grande");
}
else if (espace)
{
	j = lookup_widget(objet, label[i]);
	gtk_label_set_text(GTK_LABEL(j),"*mettez ( _ ) au lieu de espace");
}
else
{
	j = lookup_widget(objet, label[i]);
	gtk_label_set_text(GTK_LABEL(j),"");
	k++;
}
free(info);
}

if(k==13)
{
	strcpy(E.nom, gtk_entry_get_text(GTK_ENTRY(nom)));
	strcpy(E.prenom, gtk_entry_get_text(GTK_ENTRY(prenom)));
	strcpy(E.id, gtk_entry_get_text(GTK_ENTRY(id)));
	sprintf(E.niveau,"%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (niveau)));
	strcpy(E.date_naissance, gtk_entry_get_text(GTK_ENTRY(date_naissance)));
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(radiobutton_homme))) strcpy(E.sexe,"homme");
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(radiobutton_femme))) strcpy(E.sexe,"femme");
	strcpy(E.telephone, gtk_entry_get_text(GTK_ENTRY(telephone)));
	strcpy(E.mail, gtk_entry_get_text(GTK_ENTRY(mail)));
	strcpy(E.adresse, gtk_entry_get_text(GTK_ENTRY(adresse)));
	strcpy(E.type_chambre,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type_chambre)));
	strcpy(E.num_chambre, gtk_entry_get_text(GTK_ENTRY(numero_chambre)));
	strcpy(E.debut_sej, gtk_entry_get_text(GTK_ENTRY(debut_sej)));
	strcpy(E.fin_sej, gtk_entry_get_text(GTK_ENTRY(fin_sej)));

strcpy(id1, gtk_entry_get_text(GTK_ENTRY(id)));
trouve=0;
E1=rechercher4(id1,&trouve,fichier);
if(!trouve)
{
	ajouter4(E, fichier);
	label_ajoute = lookup_widget(objet, "label_ajoute");
	gtk_label_set_text(GTK_LABEL(label_ajoute),"Etudiant ajouté");
	label_exist_ajout = lookup_widget(objet, "label_exist_ajout");
	gtk_label_set_text(GTK_LABEL(label_exist_ajout),"");
}
else
{
	label_exist_ajout = lookup_widget(objet, "label_exist_ajout");
	gtk_label_set_text(GTK_LABEL(label_exist_ajout),"Id existe déjà!");
	label_ajoute = lookup_widget(objet, "label_ajoute");
	gtk_label_set_text(GTK_LABEL(label_ajoute),"");
}
}	
}

//affichage après ajout

void
on_button_afficher_ajout_clicked       (GtkButton       *objet,
                                       gpointer         user_data)
{
gtk_widget_hide (window_ajout);

	window_affichage = lookup_widget(objet, "window_affichage");
	window_affichage = create_window_affichage ();
	GtkWidget *treeview;
	treeview=lookup_widget(window_affichage,"treeview_etud");
        afficher_list_complete4(treeview);
 	gtk_widget_show (window_affichage);
}

//afficher liste

void
on_button_afficher_liste_clicked       (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview;

	window_affichage = create_window_affichage ();
	treeview=lookup_widget(window_affichage,"treeview_etud");
        afficher_list_complete4(treeview);
	window_gestion = lookup_widget(objet, "window_gestion");
	gtk_widget_hide (window_gestion);
	gtk_widget_show (window_affichage);
}

//retour après affichage

void
on_button_retour_affichage_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
	gtk_widget_hide (window_affichage);
	gtk_widget_show (window_gestion);
}

//modification sur la ligne sélectionné

void
on_button_modifier0_clicked            (GtkButton       *objet,
                                        gpointer         user_data)
{
	GtkWidget *treeview;
	GtkWidget *label_selectionnez;
	GtkWidget *label_supprime;
	treeview=lookup_widget(window_affichage,"treeview_etud");
	selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview));
	if(gtk_tree_selection_get_selected(selection, &model, &iter))
	{
		label_selectionnez = lookup_widget(objet, "label_selectionnez");
		gtk_label_set_text(GTK_LABEL(label_selectionnez),"");
		label_supprime = lookup_widget(objet, "label_supprime");
		gtk_label_set_text(GTK_LABEL(label_supprime),"");
		confirmer_modification=create_confirmer_modification ();
		gtk_widget_show (confirmer_modification);
	}
	else
	{
		label_selectionnez = lookup_widget(objet, "label_selectionnez");
		gtk_label_set_text(GTK_LABEL(label_selectionnez),"Selectionnez un étudiant pour modifier!");
		label_supprime = lookup_widget(objet, "label_supprime");
		gtk_label_set_text(GTK_LABEL(label_supprime),"");
	}
}

//modifier

void
on_button_modifier_clicked             (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *label_existe_modification, *label_modifie, *j, *radiobutton_homme2, *radiobutton_femme2;
int i, l, n, z, espace, k=0;
char *info;
char esp[2];
char label2[13][40]={"label_nom_manquant2","label_prenom_manquant2", "label_id_manquant2", "label_niveau_manquant2", "label_naissance_manquant2", "label_sexe_manquant2", "label_telephone_manquant2", "label_mail_manquant2", "label_adresse_manquant2", "label_type_chambre_manquant2", "label_numero_chambre_manquant2", "label_debut_sejour_manquant2", "label_fin_sejour_manquant2"};


	nom=lookup_widget(objet, "entry_nom2");
	prenom=lookup_widget(objet, "entry_prenom2");
	id=lookup_widget(objet, "entry_id2");
	niveau=lookup_widget(objet, "spinbutton_niveau2");
	date_naissance=lookup_widget(objet, "entry_naissance2");
	radiobutton_homme2= lookup_widget(objet, "radiobutton_homme2");
	radiobutton_femme2= lookup_widget(objet, "radiobutton_femme2");
	telephone=lookup_widget(objet, "entry_telephone2");
	mail=lookup_widget(objet, "entry_mail2");
	adresse=lookup_widget(objet, "entry_adresse2");
	type_chambre=lookup_widget(objet, "combobox_type_chambre2");
	numero_chambre=lookup_widget(objet, "entry_numero_chambre2");
	debut_sej=lookup_widget(objet, "entry_debut_sejour2");
	fin_sej=lookup_widget(objet, "entry_fin_sejour2");

for(i=0;i<13;i++)
{
switch(i)
{
case 0:
	n=strlen(gtk_entry_get_text(GTK_ENTRY(nom)));
	info=(char*) malloc(n);
	strcpy(info,gtk_entry_get_text(GTK_ENTRY(nom)));
	l=20;
	break;
case 1:
	n=strlen(gtk_entry_get_text(GTK_ENTRY(prenom)));
	info=(char*) malloc(n);
	strcpy(info,gtk_entry_get_text(GTK_ENTRY(prenom)));
	l=20;
	break;
case 2:
	n=strlen(gtk_entry_get_text(GTK_ENTRY(id)));
	info=(char*) malloc(n);
	strcpy(info,gtk_entry_get_text(GTK_ENTRY(id)));
	l=20;
	break;
case 3:
	n=5;
	info=(char*) malloc(n);
	sprintf(info,"%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (niveau)));
	l=5;
	break;
case 4:
	n=strlen(gtk_entry_get_text(GTK_ENTRY(date_naissance)));
	info=(char*) malloc(n);
	strcpy(info,gtk_entry_get_text(GTK_ENTRY(date_naissance)));
	l=15;
	break;
case 5:
	n=20;
	info=(char*) malloc(n);
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(radiobutton_homme2))) strcpy(info,"homme");
	else if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(radiobutton_femme2))) strcpy(info,"femme");
	else strcpy(info,"");
	l=20;
	break;
case 6:
	n=strlen(gtk_entry_get_text(GTK_ENTRY(telephone)));
	info=(char*) malloc(n);
	strcpy(info,gtk_entry_get_text(GTK_ENTRY(telephone)));
	l=20;
	break;
case 7:
	n=strlen(gtk_entry_get_text(GTK_ENTRY(mail)));
	info=(char*) malloc(n);
	strcpy(info,gtk_entry_get_text(GTK_ENTRY(mail)));
	l=40;
	break;
case 8:
	n=strlen(gtk_entry_get_text(GTK_ENTRY(adresse)));
	info=(char*) malloc(n);
	strcpy(info,gtk_entry_get_text(GTK_ENTRY(adresse)));
	l=100;
	break;
case 9:
	n=15;
	info=(char*) malloc(n);
	if(gtk_combo_box_get_active_text(GTK_COMBO_BOX(type_chambre))!=NULL) strcpy(info,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type_chambre)));
	else strcpy(info,"");
	l=15;
	break;
case 10:
	n=strlen(gtk_entry_get_text(GTK_ENTRY(numero_chambre)));
	info=(char*) malloc(n);
	strcpy(info,gtk_entry_get_text(GTK_ENTRY(numero_chambre)));
	l=10;
	break;
case 11:
	n=strlen(gtk_entry_get_text(GTK_ENTRY(debut_sej)));
	info=(char*) malloc(n);
	strcpy(info,gtk_entry_get_text(GTK_ENTRY(debut_sej)));
	l=15;
	break;
case 12:
	n=strlen(gtk_entry_get_text(GTK_ENTRY(fin_sej)));
	info=(char*) malloc(n);
	strcpy(info,gtk_entry_get_text(GTK_ENTRY(fin_sej)));
	l=15;
	break;
}
z=0;
espace=0;
strcpy(esp, " ");
while(espace==0 && (z < strlen(info)))
{
if(info[z]==esp[0]) espace=1;
z++;
}

if(strcmp(info,"")==0)
{
	j = lookup_widget(objet, label2[i]);
	gtk_label_set_text(GTK_LABEL(j),"* manquant");
	label_modifie = lookup_widget(objet, "label_modifie");
	gtk_label_set_text(GTK_LABEL(label_modifie),"");
	label_existe_modification = lookup_widget(objet, "label_existe_modification");
	gtk_label_set_text(GTK_LABEL(label_existe_modification),"");
}
else if (strlen(info)>l)
{
	j = lookup_widget(objet, label2[i]);
	gtk_label_set_text(GTK_LABEL(j),"*taille très grande");
}
else if (espace)
{
	j = lookup_widget(objet, label2[i]);
	gtk_label_set_text(GTK_LABEL(j),"*mettez ( _ ) au lieu de espace");
}
else
{
	j = lookup_widget(objet, label2[i]);
	gtk_label_set_text(GTK_LABEL(j),"");
	k++;
}
free(info);
}

if(k==13)
{

	strcpy(E.nom, gtk_entry_get_text(GTK_ENTRY(nom)));
	strcpy(E.prenom, gtk_entry_get_text(GTK_ENTRY(prenom)));
	strcpy(E.id, gtk_entry_get_text(GTK_ENTRY(id)));
	sprintf(E.niveau,"%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (niveau)));
	strcpy(E.date_naissance, gtk_entry_get_text(GTK_ENTRY(date_naissance)));
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(radiobutton_homme2)))	strcpy(E.sexe,"homme");
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(radiobutton_femme2)))	strcpy(E.sexe,"femme");
	strcpy(E.telephone, gtk_entry_get_text(GTK_ENTRY(telephone)));
	strcpy(E.mail, gtk_entry_get_text(GTK_ENTRY(mail)));
	strcpy(E.adresse, gtk_entry_get_text(GTK_ENTRY(adresse)));
	strcpy(E.type_chambre, gtk_combo_box_get_active_text(GTK_COMBO_BOX(type_chambre)));
	strcpy(E.num_chambre, gtk_entry_get_text(GTK_ENTRY(numero_chambre)));
	strcpy(E.debut_sej, gtk_entry_get_text(GTK_ENTRY(debut_sej)));
	strcpy(E.fin_sej, gtk_entry_get_text(GTK_ENTRY(fin_sej)));

strcpy(id1, gtk_entry_get_text(GTK_ENTRY(id)));
trouve=0;
E1=rechercher4(id1,&trouve,fichier);
if(!trouve || (trouve&&(strcmp(idm,E.id)==0)))
{
int trouve1=0;
E1=rechercher4(idm,&trouve1,fichier);
if(trouve1)
{
	modifier4(idm, E, fichier);
	label_modifie = lookup_widget(objet, "label_modifie");
	gtk_label_set_text(GTK_LABEL(label_modifie),"Etudiant modifié");
	label_existe_modification = lookup_widget(objet, "label_existe_modification");
	gtk_label_set_text(GTK_LABEL(label_existe_modification),"");
}
else
{
	label_modifie = lookup_widget(objet, "label_modifie");
	gtk_label_set_text(GTK_LABEL(label_modifie),"Déjà modifié");
	label_existe_modification = lookup_widget(objet, "label_existe_modification");
	gtk_label_set_text(GTK_LABEL(label_existe_modification),"");
}

}
if(trouve && (strcmp(idm,E.id)!=0))
{
int trouve1=0;
E1=rechercher4(idm,&trouve1,fichier);
if(trouve1)
{

	label_existe_modification = lookup_widget(objet, "label_existe_modification");
	gtk_label_set_text(GTK_LABEL(label_existe_modification),"Id existe déjà!");
	label_modifie = lookup_widget(objet, "label_modifie");
	gtk_label_set_text(GTK_LABEL(label_modifie),"");
}
else
{
	label_modifie = lookup_widget(objet, "label_modifie");
	gtk_label_set_text(GTK_LABEL(label_modifie),"Déjà modifié");
}
}
}	
}
//confirmer modification

void
on_confirmer_modif_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{

	gtk_tree_model_get (model,&iter,0, &Nom, 1, &Prenom, 2, &Id, 3, &Niveau, 4, &DateNaissance, 5, &Sexe, 6, &Telephone, 7, &Mail, 8, &Adresse, 9, &TypeChambre, 10, &NumeroChambre, 11, &DebutSejour, 12, &FinSejour,-1);

window_modification = create_window_modification ();
gtk_widget_show (window_modification);

	GtkWidget *entry_nom2, *entry_prenom2, *entry_id2, *spinbutton_niveau2, *entry_naissance2, *radiobutton_homme2, *radiobutton_femme2, *entry_telephone2, *entry_mail2, *entry_adresse2, *combobox_type_chambre2, *entry_numero_chambre2, *entry_debut_sejour2, *entry_fin_sejour2;
	entry_nom2 = lookup_widget(window_modification, "entry_nom2");
	gtk_entry_set_text(GTK_LABEL(entry_nom2),Nom);
	entry_prenom2= lookup_widget(window_modification, "entry_prenom2");
	gtk_entry_set_text(GTK_LABEL(entry_prenom2),Prenom);
	entry_id2= lookup_widget(window_modification, "entry_id2");
	gtk_entry_set_text(GTK_LABEL(entry_id2),Id);
spinbutton_niveau2= lookup_widget(window_modification, "spinbutton_niveau2");
gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinbutton_niveau2),atoi(Niveau));
	entry_naissance2= lookup_widget(window_modification, "entry_naissance2");
	gtk_entry_set_text(GTK_LABEL(entry_naissance2),DateNaissance);
radiobutton_homme2= lookup_widget(window_modification, "radiobutton_homme2");
radiobutton_femme2= lookup_widget(window_modification, "radiobutton_femme2");
if(strcmp(Sexe,"homme")==0) gtk_toggle_button_set_active(GTK_RADIO_BUTTON(radiobutton_homme2),TRUE);
else gtk_toggle_button_set_active(GTK_RADIO_BUTTON(radiobutton_femme2),TRUE); 
	entry_telephone2= lookup_widget(window_modification, "entry_telephone2");
	gtk_entry_set_text(GTK_LABEL(entry_telephone2),Telephone);
	entry_mail2= lookup_widget(window_modification, "entry_mail2");
	gtk_entry_set_text(GTK_LABEL(entry_mail2),Mail);
	entry_adresse2= lookup_widget(window_modification, "entry_adresse2");
	gtk_entry_set_text(GTK_LABEL(entry_adresse2),Adresse);
combobox_type_chambre2= lookup_widget(window_modification, "combobox_type_chambre2");
char chambres[4][20]={"Chambre_à_1","Chambre_à_2","Chambre_à_3","Chambre_à_4"};
int i=0;
while(i<4 && (strcmp(TypeChambre,chambres[i])!=0)) {i++;}
gtk_combo_box_set_active(GTK_COMBO_BOX(combobox_type_chambre2),i);
	entry_numero_chambre2= lookup_widget(window_modification, "entry_numero_chambre2");
	gtk_entry_set_text(GTK_LABEL(entry_numero_chambre2),NumeroChambre);
	entry_debut_sejour2= lookup_widget(window_modification, "entry_debut_sejour2");
	gtk_entry_set_text(GTK_LABEL(entry_debut_sejour2),DebutSejour);
	entry_fin_sejour2= lookup_widget(window_modification, "entry_fin_sejour2");
	gtk_entry_set_text(GTK_LABEL(entry_fin_sejour2),FinSejour);
strcpy(idm,Id);
gtk_widget_hide(window_affichage);
gtk_widget_hide(confirmer_modification);
}

//annuler modification

void
on_annuler_modif_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_hide (confirmer_modification);
}
//retour après modification

void
on_button_retour_modification_clicked  (GtkButton       *objet,
                                        gpointer         user_data)
{
	gtk_widget_hide (window_modification);
	window_affichage = lookup_widget(objet, "window_affichage");
	window_affichage = create_window_affichage ();
	GtkWidget *treeview;
	treeview=lookup_widget(window_affichage,"treeview_etud");
        afficher_list_complete4(treeview);
 	gtk_widget_show (window_affichage);
}

//affichage après modification

void
on_button_afficher_modification_clicked
                                        (GtkButton       *objet,
                                        gpointer         user_data)
{
gtk_widget_hide (window_modification);
	window_affichage = lookup_widget(objet, "window_affichage");
	window_affichage = create_window_affichage ();
	GtkWidget *treeview;
	treeview=lookup_widget(window_affichage,"treeview_etud");
        afficher_list_complete4(treeview);
 	gtk_widget_show (window_affichage);
}



//supprission de la ligne sélectionné

void
on_button_supprimer_clicked            (GtkButton       *objet,
                                        gpointer         user_data)
{
	GtkWidget *treeview;
	GtkWidget *label_selectionnez;
	GtkWidget *label_supprime;
	treeview=lookup_widget(window_affichage,"treeview_etud");
	selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview));

	if(gtk_tree_selection_get_selected(selection, &model, &iter))
	{
		label_selectionnez = lookup_widget(objet, "label_selectionnez");
		gtk_label_set_text(GTK_LABEL(label_selectionnez),"");
		label_supprime = lookup_widget(objet, "label_supprime");
		gtk_label_set_text(GTK_LABEL(label_supprime),"");
		confirmer_supprission=create_confirmer_supprission ();
		gtk_widget_show (confirmer_supprission);
	}
	else
	{
		label_selectionnez = lookup_widget(objet, "label_selectionnez");
		gtk_label_set_text(GTK_LABEL(label_selectionnez),"Selectionnez un étudiant pour supprimer!");
		label_supprime = lookup_widget(objet, "label_supprime");
		gtk_label_set_text(GTK_LABEL(label_supprime),"");
	}
}

//supprimer

void
on_confirmer_supp_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
	gtk_tree_model_get (model,&iter,2,&ids,-1);
	gtk_list_store_remove(GTK_LIST_STORE(model),&iter);
	supprimer4(ids, fichier);
	GtkWidget *label_supprime;
	label_supprime = lookup_widget(window_affichage, "label_supprime");
	gtk_label_set_text(GTK_LABEL(label_supprime),"etudiant supprimé!");
	gtk_widget_hide (confirmer_supprission);
}

//annuler supprission

void
on_annuler_supp_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_hide (confirmer_supprission);
}



//rechercher

void
on_button_rechercher_clicked           (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *button_retour_recherche, *label_supprime;
trouve=0;
id=lookup_widget(objet, "entry_rechercher");
strcpy(id1, gtk_entry_get_text(GTK_ENTRY(id)));
E=rechercher4(id1,&trouve,fichier);
if(trouve)
{
	
	gtk_widget_hide (window_affichage);
	window_affichage=create_window_affichage();
	gtk_widget_show (window_affichage);
	GtkWidget *treeview;
	treeview=lookup_widget(window_affichage,"treeview_etud");
        afficher_etudiant4(treeview, E);
	button_retour_recherche= lookup_widget(window_affichage, "button_retour_recherche");
	gtk_widget_show (button_retour_recherche);
	label_supprime = lookup_widget(objet, "label_supprime");
	gtk_label_set_text(GTK_LABEL(label_supprime),"");
}
else
{
	GtkWidget *label_non_trouve;
	label_non_trouve = lookup_widget(objet, "label_non_trouve");
	gtk_label_set_text(GTK_LABEL(label_non_trouve),"Non trouvé!");
	label_supprime = lookup_widget(objet, "label_supprime");
	gtk_label_set_text(GTK_LABEL(label_supprime),"");
}

}

//effacer texte de la recherche

void
on_entry_rechercher_delete_text        (GtkWidget       *objet,
                                        gint             start_pos,
                                        gint             end_pos,
                                        gpointer         user_data)
{
GtkWidget *label_non_trouve;
	label_non_trouve = lookup_widget(objet, "label_non_trouve");
	gtk_label_set_text(GTK_LABEL(label_non_trouve),"");
}

//recherche avec entrer

void
on_entry_rechercher_activate           (GtkEntry        *objet,
                                        gpointer         user_data)
{
GtkWidget *button_retour_recherche, *label_supprime;
trouve=0;
id=lookup_widget(objet, "entry_rechercher");
strcpy(id1, gtk_entry_get_text(GTK_ENTRY(id)));
E=rechercher4(id1,&trouve,fichier);
if(trouve)
{
	gtk_widget_hide (window_affichage);
	window_affichage=create_window_affichage();
	gtk_widget_show (window_affichage);
	GtkWidget *treeview;
	treeview=lookup_widget(window_affichage,"treeview_etud");
        afficher_etudiant4(treeview, E);
	button_retour_recherche= lookup_widget(window_affichage, "button_retour_recherche");
	gtk_widget_show (button_retour_recherche);
	label_supprime = lookup_widget(objet, "label_supprime");
	gtk_label_set_text(GTK_LABEL(label_supprime),"");
}
else
{

	GtkWidget *label_non_trouve;
	label_non_trouve = lookup_widget(objet, "label_non_trouve");
	gtk_label_set_text(GTK_LABEL(label_non_trouve),"Non trouvé!");
	label_supprime = lookup_widget(objet, "label_supprime");
	gtk_label_set_text(GTK_LABEL(label_supprime),"");

}
}

//retour après recherche

void
on_button_retour_recherche_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
	gtk_widget_hide (window_affichage);
	window_affichage=create_window_affichage();
	gtk_widget_show (window_affichage);
	GtkWidget *treeview;
	treeview=lookup_widget(window_affichage,"treeview_etud");
	afficher_list_complete4(treeview);
}


//retour acceuil après gestion des étudiant

void
on_button_home_etudiant_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
	confirmer_acceuil=create_confirmer_acceuil ();
	gtk_widget_show (confirmer_acceuil);
}

//confirmer retour acceuil

void
on_confirmer_acc_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
	gtk_widget_show (acceuil);
	gtk_widget_destroy (window);
	gtk_widget_destroy (window_ajout);
	gtk_widget_destroy (window_modification);
	gtk_widget_destroy (window_affichage);
	gtk_widget_hide (confirmer_acceuil);
}
//annuler retour acceuil
void
on_annuler_acc_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
	gtk_widget_hide (confirmer_acceuil);
}


//quitter
void
on_quitter_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
	window_quitter=create_window_quitter ();
	gtk_widget_show (window_quitter);
}

//confirmer quitter
void
on_confirmer_quitter_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
	gtk_main_quit();
}

//annuler quitter
void
on_annuler_quitter_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
	gtk_widget_hide (window_quitter);
}


void
on_treeview4capt_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkWidget *gestioncapt;	
	GtkTreeIter iter;
	gchar* jour;
	gchar* heure;

	gchar* nmrcapt;
	gchar* valtemp;
	
	
	capteurTemperature c;

	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	if (gtk_tree_model_get_iter(model, &iter, path))
	{
		//obtention des valeurs de la ligne selectionnée

		gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &jour, 1, &heure, 2, &nmrcapt, 3, &valtemp, -1);
		//copie des valeurs dans la variable P de type personne pour le passer  à la fonction de suppression
		strcpy(jour,jour);
		strcpy(heure,heure);
		strcpy(nmrcapt,nmrcapt);
		strcpy(valtemp,valtemp);
		
		//mise a jour de l'affichage de la treeview
		afficher_captdefectueux(treeview,"capteurdefectueux.txt");
}
}


void
on_button16capt_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *gestioncapt,*treeview4capt;
	gestioncapt=lookup_widget (objet_graphique,"gestioncapt");
	treeview4capt=lookup_widget (gestioncapt,"treeview4capt");
	afficher_captdefectueux(treeview4capt,"capteurdefectueux.txt");
}


void
on_button30_cap_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
 	char resultat[200]="";
	//char ch[1000];

	GtkWidget *aff,*aff1;
	
	FILE *f,*g;
	f=fopen("temperature1.txt","r");
	g=fopen("capteurdefectueux.txt","a+");
	capteurTemperature c,T[5000];
	int i=0,n=0,nb=0;
	if(f!=NULL){
			
			while(!feof(f))
			{
				fscanf(f,"%d %d %d %f\n",&c.jour,&c.heure,&c.numC,&c.valT);
				
				T[i].jour=c.jour;
				T[i].heure=c.heure;
				T[i].numC=c.numC;
				T[i].valT=c.valT;
				i++;
			}
			fclose(f);
			n=i;
	}
	for(i=0;i<n;i++){
		if(T[i].valT<10 || T[i].valT>30){
			fprintf(g,"%d %d %d %f\n",T[i].jour,T[i].heure,T[i].numC,T[i].valT);
			nb++;
		}
	}
	sprintf(resultat,"le nombre de capteur defecteux est :%d/%d\n",nb,n);

        aff=lookup_widget(objet_graphique,"label29_capt");
	gtk_label_set_text(GTK_LABEL(aff),resultat);

}

