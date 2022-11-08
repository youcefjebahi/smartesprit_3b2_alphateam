#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
enum{
	CID,
	CTYPE,
	CJOUR,
	CMENU,
	CDECHET,
	COLUMNS
};
void ajout_menu(Menu c ,int *n,Menu T[]){
    	strcpy(T[*n].id,c.id);
	strcpy(T[*n].type,c.type);
	strcpy(T[*n].jour,c.jour);
	strcpy(T[*n].menu,c.menu);
	T[*n].dechet=c.dechet;
	*n=*n+1;
}

void supprimer_menu(char id[])
{
	Menu c;
	FILE *f,*f1;
	f=fopen("menu.txt","r");
	f1=fopen("ancien.txt","a+");
	while(fscanf(f,"%s %s %s %s %f\n",c.id,c.type,c.jour,c.menu,&c.dechet)!=EOF)
		{
			if(strcmp(c.id,id)!=0)
			{
				fprintf(f1,"%s %s %s %s %f\n",c.id,c.type,c.jour,c.menu,&c.dechet);
			}
		}
	fclose(f1);
	fclose(f);
	remove("menu.txt");
	rename("ancien.txt","menu.txt");	
}
void modifier_menu(char id[],Menu c ,int *n,Menu T[]){
	int i,x=0;
	for(i=0;i<*n;i++){
		if(strcmp(T[i].id,id)==0){
			strcpy(T[i].type,c.type);
			strcpy(T[i].jour,c.jour);
			strcpy(T[i].menu,c.menu);
			T[i].dechet=c.dechet;
                        x=1;
		}
	}
     if(x==0)
		printf("menu non trouver\n");
}

void afficher_menu(GtkWidget *liste,int *n,Menu T[])
{

	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter ;
	GtkListStore *store;
	char id[20];
	char type[20];
	char jour[20];
	char menu[20];
	int dechet;
	int i;
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model(liste);
	if(store==NULL){
		
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("id",renderer,"text",CID,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",CTYPE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		 renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("jour",renderer,"text",CJOUR,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column); 

		 renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("menu",renderer,"text",CMENU,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column); 

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("dechet",renderer,"text",CDECHET,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		
	}
		  
	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_FLOAT);
	f=fopen("menu.txt","r");
	if(f==NULL){return;}
	else
	{

		for(i=0;i<*n;i++){
			gtk_list_store_append(store,&iter);
		  					gtk_list_store_set(store,&iter,CID,T[i].id,CTYPE,T[i].type,CJOUR,T[i].jour,CMENU,T[i].menu,CDECHET,T[i].dechet,-1);
		
		}
		

	 gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	 g_object_unref(store);
	}

}

Menu rechercher1( char id[],int *n,Menu T[]){
	int i;
	for(i=0;i<*n;i++){
		if(strcmp(T[i].id,id)==0){
			return T[i];
		}
	}
}
Menu * getDonner(int *n){
	int i=0;
	*n=0;
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
	*n=i;
	}
	return T;
}
dechets meilleur_menu()
{
int jour,type;
float dechet;
dechets m;
FILE *f=NULL;
f=fopen("dechets.txt","r");

if (f!=NULL)
{
 fscanf(f,"%d %d %f \n",&m.jour,&m.type,&m.dechet);
while(fscanf(f,"%d %d %f \n",&jour,&type,&dechet)!=EOF)
{

if (dechet<=m.dechet){
m.jour=jour;
m.type=type;
m.dechet=dechet;
}
}
fclose(f);

return m;
}

}
int verif(char user[],char passe[])
{ 
FILE *f=NULL;
char ch1[20];
char ch2[20];
int role;
int trouve=0;
f=fopen("utilisateur.txt","r");
if (f!=NULL)
{
while(fscanf(f,"%s %s %d",ch1,ch2,&role)!=EOF)
{
if((strcmp(ch1,user)==0)&&(strcmp(ch2,passe)==0))
trouve=role;
}
fclose(f);
}

return (trouve);
}

