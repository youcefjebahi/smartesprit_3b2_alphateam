#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "capteur.h"
enum{
	CCAPTREF,
	CCAPTZONE,
	CCAPTVALMIN,
	CCAPTVALMAX,
	CETAT,
	CTYPE1,
	COLUMNS1
};
void ajout_capt(capteur c ){
    	FILE *f,*f0,*f1,*f2,*f3,*f4,*f5,*f6,*f7;
	f=fopen("capteur.txt","a+");
	f0=fopen("temperature.txt","a+");
	f1=fopen("mouvement.txt","a+");
	f2=fopen("smoke.txt","a+");
	f3=fopen("debit.txt","a+");
	f4=fopen("temperaturedef.txt","a+");
	f5=fopen("mouvementdef.txt","a+");
	f6=fopen("smokedef.txt","a+");
	f7=fopen("debitdef.txt","a+");
	if(c.type==0 && (c.c.captvaleurmin<10 || c.c.captvaleurmax>30))
		c.etat=0;
	if(c.type==3 && (c.c.captvaleurmin<0 || c.c.captvaleurmax>30))
		c.etat=0;
	if(f!=NULL){
		fprintf(f,"%s %d %d %d %d %d\n",c.captref,c.captzone,c.c.captvaleurmin,c.c.captvaleurmax,c.etat,c.type);
		if(c.etat==1)
		{
			switch(c.type)
			{
				case 0:
					fprintf(f0,"%s %d %d %d %d %d\n",c.captref,c.captzone,c.c.captvaleurmin,c.c.captvaleurmax,c.etat,c.type);
					break;
				case 1:
					fprintf(f1,"%s %d %d %d %d %d\n",c.captref,c.captzone,c.c.captvaleurmin,c.c.captvaleurmax,c.etat,c.type);
					break;
				case 2:
					fprintf(f2,"%s %d %d %d %d %d\n",c.captref,c.captzone,c.c.captvaleurmin,c.c.captvaleurmax,c.etat,c.type);
					break;
				case 3:
					fprintf(f3,"%s %d %d %d %d %d\n",c.captref,c.captzone,c.c.captvaleurmin,c.c.captvaleurmax,c.etat,c.type);
					break;
			}
		}
		else
		{
			switch(c.type)
			{
				case 0:
					fprintf(f4,"%s %d %d %d %d %d\n",c.captref,c.captzone,c.c.captvaleurmin,c.c.captvaleurmax,c.etat,c.type);
					break;
				case 1:
					fprintf(f5,"%s %d %d %d %d %d\n",c.captref,c.captzone,c.c.captvaleurmin,c.c.captvaleurmax,c.etat,c.type);
					break;
				case 2:
					fprintf(f6,"%s %d %d %d %d %d\n",c.captref,c.captzone,c.c.captvaleurmin,c.c.captvaleurmax,c.etat,c.type);
					break;
				case 3:
					fprintf(f7,"%s %d %d %d %d %d\n",c.captref,c.captzone,c.c.captvaleurmin,c.c.captvaleurmax,c.etat,c.type);
					break;
			}
		}
	}
	fclose(f);
	fclose(f0);
	fclose(f1);
	fclose(f2);
	fclose(f3);
	fclose(f4);
	fclose(f5);
	fclose(f6);
	fclose(f7);
}
void supprimer_capt(char ref[],char file[20]){
	capteur c;
	FILE *f,*ftmp;
	f=fopen(file,"r");
	ftmp=fopen("tmp.txt","a+");
	while(fscanf(f,"%s %d %d %d %d %d\n",c.captref,&c.captzone,&c.c.captvaleurmin,&c.c.captvaleurmax,&c.etat,&c.type)!=EOF)
		{
			if(strcmp(c.captref,ref)!=0){
				fprintf(ftmp,"%s %d %d %d %d %d\n",c.captref,c.captzone,c.c.captvaleurmin,c.c.captvaleurmax,c.etat,c.type);
			}
		}
	fclose(ftmp);
	fclose(f);
	remove(file);
	rename("tmp.txt",file);	
}
void modifier_capt(capteur c1){
	capteur c;
	FILE *f,*ftmp;
	f=fopen("capteur.txt","r");
	ftmp=fopen("tmp.txt","a+");
	while(fscanf(f,"%s %d %d %d %d %d\n",c.captref,&c.captzone,&c.c.captvaleurmin,&c.c.captvaleurmax,&c.etat,&c.type)!=EOF)
		{
			if(strcmp(c.captref,c1.captref)!=0){
				fprintf(ftmp,"%s %d %d %d %d %d\n",c.captref,c.captzone,c.c.captvaleurmin,c.c.captvaleurmax,c.etat,c.type);
			}
			else
				fprintf(ftmp,"%s %d %d %d %d %d\n",c1.captref,c1.captzone,c1.c.captvaleurmin,c1.c.captvaleurmax,c1.etat,c1.type);
		}
	fclose(ftmp);
	fclose(f);
	remove("capteur.txt");
	rename("tmp.txt","capteur.txt");	
}
void capteurdefectueux(){
	FILE *f,*g;
	f=fopen("temperature.txt","r");
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
	//printf("le nombre des capteurs defectueux est:%d/%d\n",nb,n);
//return nb;
}
void afficher_capt(GtkWidget *liste,char file[20])
{

	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter ;
	GtkListStore *store;
	capteur c;
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model(liste);
	if(store==NULL){
		
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Reference",renderer,"text",CCAPTREF,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("zone de capteur",renderer,"text",CCAPTZONE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		 renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Valeur Max ",renderer,"text",CCAPTVALMIN,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column); 

		 renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Valeur Min ",renderer,"text",CCAPTVALMAX,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column); 

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Etat",renderer,"text",CETAT,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Type",renderer,"text",CTYPE1,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	
	}
		  
	store=gtk_list_store_new(COLUMNS1,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING);
	f=fopen(file,"r");
	if(f==NULL){return;}
	else
	{
		while(fscanf(f,"%s %d %d %d %d %d\n",c.captref,&c.captzone,&c.c.captvaleurmin,&c.c.captvaleurmax,&c.etat,&c.type)!=EOF)
		{
			if(c.etat==0 && c.type==0)
			{ 
				gtk_list_store_append(store,&iter);
		  							gtk_list_store_set(store,&iter,CCAPTREF,c.captref,CCAPTZONE,c.captzone,CCAPTVALMIN,c.c.captvaleurmin,CCAPTVALMAX,c.c.captvaleurmax,CETAT,"En Panne",CTYPE1,"Temperature",-1);
			}
			else if(c.etat==0 && c.type==1)
			{ 
				gtk_list_store_append(store,&iter);
		  							gtk_list_store_set(store,&iter,CCAPTREF,c.captref,CCAPTZONE,c.captzone,CCAPTVALMIN,c.c.captvaleurmin,CCAPTVALMAX,c.c.captvaleurmax,CETAT,"En Panne",CTYPE1,"Mouvement",-1);
			}
			else if(c.etat==0 && c.type==2)
			{ 
				gtk_list_store_append(store,&iter);
		  							gtk_list_store_set(store,&iter,CCAPTREF,c.captref,CCAPTZONE,c.captzone,CCAPTVALMIN,c.c.captvaleurmin,CCAPTVALMAX,c.c.captvaleurmax,CETAT,"En Panne",CTYPE1,"Fumer",-1);
			}
			else if(c.etat==0 && c.type==3)
			{ 
				gtk_list_store_append(store,&iter);
		  							gtk_list_store_set(store,&iter,CCAPTREF,c.captref,CCAPTZONE,c.captzone,CCAPTVALMIN,c.c.captvaleurmin,CCAPTVALMAX,c.c.captvaleurmax,CETAT,"En Panne",CTYPE1,"Debit",-1);
			}
			else if(c.etat==1 && c.type==0)
			{ 
				gtk_list_store_append(store,&iter);
		  							gtk_list_store_set(store,&iter,CCAPTREF,c.captref,CCAPTZONE,c.captzone,CCAPTVALMIN,c.c.captvaleurmin,CCAPTVALMAX,c.c.captvaleurmax,CETAT,"OK",CTYPE1,"Temperature",-1);
			}
			else if(c.etat==1 && c.type==1)
			{ 
				gtk_list_store_append(store,&iter);
		  							gtk_list_store_set(store,&iter,CCAPTREF,c.captref,CCAPTZONE,c.captzone,CCAPTVALMIN,c.c.captvaleurmin,CCAPTVALMAX,c.c.captvaleurmax,CETAT,"OK",CTYPE1,"Mouvement",-1);
			}
			else if(c.etat==1 && c.type==2)
			{ 
				gtk_list_store_append(store,&iter);
		  							gtk_list_store_set(store,&iter,CCAPTREF,c.captref,CCAPTZONE,c.captzone,CCAPTVALMIN,c.c.captvaleurmin,CCAPTVALMAX,c.c.captvaleurmax,CETAT,"OK",CTYPE1,"Fumer",-1);
			}
			else 
			{ 
				gtk_list_store_append(store,&iter);
		  							gtk_list_store_set(store,&iter,CCAPTREF,c.captref,CCAPTZONE,c.captzone,CCAPTVALMIN,c.c.captvaleurmin,CCAPTVALMAX,c.c.captvaleurmax,CETAT,"OK",CTYPE1,"Debit",-1);
			}
		}
		
/*

		 while(fscanf(f,"%s %s %d %d %d %d \n",captref,captzone,&captvaleurmin,&captvaleurmax,&etat,&type)!=EOF)
		 {
			gtk_list_store_append(store,&iter);
		  	gtk_list_store_set(store,&iter,CCAPTREF,captref,CCAPTZONE,captzone,CCAPTVALMIN,captvaleurmin,CCAPTVALMAX,captvaleurmax,CETAT,etat,CTYPE1,type,-1);
		 }
	 fclose(f);
*/
	 gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	 g_object_unref(store);
	}

}
/*void affichage_capt(int *n,capteur T[]){
	int i;
	for(i=0;i<*n;i++){
		if(T[i].etat==0){
			if(T[i].type==0){
				printf("%s %s %d %d %s %s\n",T[i].captref,T[i].captzone,T[i].c.captvaleurmin,T[i].c.captvaleurmax,"EN PANNE","Temperature");
			}
			else if(T[i].type==1){
				printf("%s %s %d %d %s %s\n",T[i].captref,T[i].captzone,T[i].c.captvaleurmin,T[i].c.captvaleurmax,"EN PANNE","debit");
			}
			else if(T[i].type==2){
				printf("%s %s %d %d %s %s\n",T[i].captref,T[i].captzone,T[i].c.captvaleurmin,T[i].c.captvaleurmax,"EN PANNE","fumee");
			}
			else{
				printf("%s %s %d %d %s %s\n",T[i].captref,T[i].captzone,T[i].c.captvaleurmin,T[i].c.captvaleurmax,"EN PANNE","mouvement");
			}
		}
		else{
			if(T[i].type==0){
				printf("%s %s %d %d %s %s\n",T[i].captref,T[i].captzone,T[i].c.captvaleurmin,T[i].c.captvaleurmax,"OK","Temperature");
			}
			else if(T[i].type==1){
				printf("%s %s %d %d %s %s\n",T[i].captref,T[i].captzone,T[i].c.captvaleurmin,T[i].c.captvaleurmax,"OK","debit");
			}
			else if(T[i].type==2){
				printf("%s %s %d %d %s %s\n",T[i].captref,T[i].captzone,T[i].c.captvaleurmin,T[i].c.captvaleurmax,"OK","fumee");
			}
			else{
				printf("%s %s %d %d %s %s\n",T[i].captref,T[i].captzone,T[i].c.captvaleurmin,T[i].c.captvaleurmax,"OK","mouvement");
			}
		}
	}
}*/
void rechercher( char ref[]){
	capteur c;
	FILE *f,*ftmp;
	f=fopen("capteur.txt","r");
	ftmp=fopen("recherche.txt","a+");
	while(fscanf(f,"%s %d %d %d %d %d\n",c.captref,&c.captzone,&c.c.captvaleurmin,&c.c.captvaleurmax,&c.etat,&c.type)!=EOF)
		{
			if(strcmp(c.captref,ref)==0){
				fprintf(ftmp,"%s %d %d %d %d %d\n",c.captref,c.captzone,c.c.captvaleurmin,c.c.captvaleurmax,c.etat,c.type);
			}
		}
	fclose(ftmp);
	fclose(f);
	
}
void capteurparchoix(int z1[])
{
	capteur c;
	FILE *f,*f0,*f1,*f2,*f3;
	f=fopen("capteurchoix.txt","a+");
	f0=fopen("temperaturedef.txt","r");
	f1=fopen("mouvementdef.txt","r");
	f2=fopen("smokedef.txt","r");
	f3=fopen("debitdef.txt","r");
	if(f!=NULL)
	{
		if(z1[0]==1)
		{
			while(fscanf(f0,"%s %d %d %d %d %d\n",c.captref,&c.captzone,&c.c.captvaleurmin,&c.c.captvaleurmax,&c.etat,&c.type)!=EOF)
			{
				fprintf(f,"%s %d %d %d %d %d\n",c.captref,c.captzone,c.c.captvaleurmin,c.c.captvaleurmax,c.etat,c.type);
			}
		}
		if(z1[1]==1)
		{
			while(fscanf(f1,"%s %d %d %d %d %d\n",c.captref,&c.captzone,&c.c.captvaleurmin,&c.c.captvaleurmax,&c.etat,&c.type)!=EOF)
			{
				fprintf(f,"%s %d %d %d %d %d\n",c.captref,c.captzone,c.c.captvaleurmin,c.c.captvaleurmax,c.etat,c.type);
			}
		}
		if(z1[2]==1)
		{
			while(fscanf(f2,"%s %d %d %d %d %d\n",c.captref,&c.captzone,&c.c.captvaleurmin,&c.c.captvaleurmax,&c.etat,&c.type)!=EOF)
			{
				fprintf(f,"%s %d %d %d %d %d\n",c.captref,c.captzone,c.c.captvaleurmin,c.c.captvaleurmax,c.etat,c.type);
			}
		}
		if(z1[3]==1)
		{
			while(fscanf(f3,"%s %d %d %d %d %d\n",c.captref,&c.captzone,&c.c.captvaleurmin,&c.c.captvaleurmax,&c.etat,&c.type)!=EOF)
			{
				fprintf(f,"%s %d %d %d %d %d\n",c.captref,c.captzone,c.c.captvaleurmin,c.c.captvaleurmax,c.etat,c.type);
			}
		}
	}
	fclose(f);
	fclose(f0);
	fclose(f1);
	fclose(f2);
	fclose(f3);
}
int existcapt(char ref[20]){
	FILE *f;
	capteur c;
	f=fopen("capteur.txt","r");
	if(f!=NULL){
		while(fscanf(f,"%s %d %d %d %d %d\n",c.captref,&c.captzone,&c.c.captvaleurmin,&c.c.captvaleurmax,&c.etat,&c.type)!=EOF)
		{
			if(strcmp(c.captref,ref)==0)
				return 1;
		}

	}
	return 0;
}



enum
{
	EJOUR,
	EHEURE,
	ENMRCAPT,
	EVALTEMP,
	COLUMNSA,
};

/**----------------[Afficher]----------------**/
void afficher_captdefectueux(GtkWidget *liste,char*l)
{

FILE*f;
capteurTemperature c;

	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	int jourc,heurec,numC;
	float valT;
	char jour[30];
	char heure[30];
	char nmrcapt[30];
	char valtemp[30];
	sprintf(jour,"%d",jourc);
	sprintf(heure,"%d",heurec);
	sprintf(nmrcapt,"%d",numC);
	sprintf(valtemp,"%f",valT);
	
	store=NULL;
	store=gtk_tree_view_get_model(liste);

if (store==NULL)
{
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("jour", renderer, "text",EJOUR, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("heure", renderer, "text",EHEURE, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("nmrcapt", renderer, "text",ENMRCAPT, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("valtemp", renderer, "text",EVALTEMP, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	
}
	store=gtk_list_store_new (COLUMNSA, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);


	f=fopen("capteurdefectueux.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f = fopen("capteurdefectueux.txt","r");
		while(fscanf(f,"%s %s %s %s\n",jour,heure,nmrcapt,valtemp)!=EOF)
		{
			gtk_list_store_append (store, &iter);
			gtk_list_store_set (store,&iter,EJOUR,jour,EHEURE,heure,ENMRCAPT,nmrcapt,EVALTEMP,valtemp, -1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
		g_object_unref (store);
	}
}



int verif2(char user[],char passe[])
{ 
int trouve =-1;
FILE *f=NULL;
char ch1[20];
char ch2[20];
f=fopen("utilisateur.txt","r");
if (f!=NULL)
{
while(fscanf(f,"%s %s ",ch1,ch2)!=EOF)
{
if((strcmp(ch1,user)==0)&&(strcmp(ch2,passe)==0))
trouve=1;
}
fclose(f);
}
return (trouve);
}

