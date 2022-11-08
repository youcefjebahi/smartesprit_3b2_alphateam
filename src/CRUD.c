#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include "callbacks.h"
#include<string.h>


void ajouter_stock( stock c){
FILE*f=NULL;
f=fopen("stocks.txt","a+");//(+) creation du fichier sil nexsite pas
fprintf(f,"%s %s %s %s %s\n",c.id,c.nom,c.quantite,c.date,c.fournisseur);
fclose(f);

}
void modifier_stock(stock c)
{
FILE *f=NULL;
FILE *f1=NULL;
stock m;
f=fopen("stocks.txt","r");

f1=fopen("ancien.txt","w+");
while(fscanf(f,"%s %s %s %s %s\n",m.id,m.nom,m.quantite,m.date,m.fournisseur)!=EOF){
if( strcmp(m.id,c.id)==0 )
{
fprintf(f1,"%s %s %s %s %s\n",c.id,c.nom,c.quantite,c.date,c.fournisseur);
}
else
{
fprintf(f1,"%s %s %s %s %s\n",m.id,m.nom,m.quantite,m.date,m.fournisseur);
}

}
fclose(f);
fclose(f1);
remove("stocks.txt");
rename("ancien.txt","stocks.txt");
}
int exist_stock(char*id){
FILE*f=NULL;
 stock c;
f=fopen("stocks.txt","r");
while(fscanf(f,"%s %s %s %s %s\n",c.id,c.nom,c.quantite,c.date,c.fournisseur)!=EOF){
if(strcmp(c.id,id)==0)return 1;
}
fclose(f);
return 0;
}


void supprimer_stock(char*id){
FILE*f=NULL;
FILE*f1=NULL;
stock c ;
f=fopen("stocks.txt","r");

f1=fopen("ancien.txt","w+");
while(fscanf(f,"%s %s %s %s %s\n",c.id,c.nom,c.quantite,c.date,c.fournisseur)!=EOF){
if(strcmp(id,c.id)!=0)fprintf(f1,"%s %s %s %s %s\n",c.id,c.nom,c.quantite,c.date,c.fournisseur);
}
fclose(f);
fclose(f1);
remove("stocks.txt");
rename("ancien.txt","stocks.txt");
}
void rupture()
{
stock c;
FILE*f=NULL;
FILE*f1=NULL;
f=fopen("stocks.txt","r");
f1=fopen("rupture.txt","a+");
while(fscanf(f,"%s %s %s %s %s\n",c.id,c.nom,c.quantite,c.date,c.fournisseur)!=EOF){
if(strcmp(c.quantite,"0")==0)fprintf(f1,"%s %s %s %s %s\n",c.id,c.nom,c.quantite,c.date,c.fournisseur);
}
fclose(f);
fclose(f1);
}


