#include <stdio.h>
#include <gtk/gtk.h>
#include <string.h>
#include <ctype.h>
#include "capteur.h"



enum
 {
  ENOM,
  EID,
  ETYPE,
  EPOSITION,
  EVALEUR,
  EETAT,
  EJOUR,
  EMOIS,
  EANNE,
  COLUMNS,
  };
//ajouter
void ajouter(capteur cii)
{

    FILE *f;
    f=NULL;
    f=fopen("capteurs.txt","a+");

    fprintf(f,"%s %s %s %s %s %s %s %s %s\n",cii.nom,cii.id,cii.type,cii.position,cii.valeur,cii.etat,cii.d.jour,cii.d.mois,cii.d.annee);
fclose(f);

}


//modifier
void modifier(char idmodif[],capteur sii)
{
  FILE *f;
    FILE *ftemp;
    ftemp=NULL;
    capteur cii;
   
    f=fopen("capteurs.txt","r+");
    ftemp=fopen("capteurs.txt.temp","a+");
    if (f!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s %s %s %s %s\n",cii.nom,cii.id,cii.type,cii.position,cii.valeur,cii.etat,cii.d.jour,cii.d.mois,cii.d.annee)!=EOF)
        {
            if(strcmp(idmodif,cii.id)==0)
            {
		       strcpy(cii.id,sii.id);
		       strcpy(cii.valeur,sii.valeur);
		       strcpy(cii.nom,sii.nom);
                       strcpy(cii.position,sii.position);
                       strcpy(cii.etat,sii.etat);
                       strcpy(cii.type,sii.type);
                       strcpy(cii.d.jour,sii.d.jour);
                       strcpy(cii.d.mois,sii.d.mois);
                       strcpy(cii.d.annee,sii.d.annee);
                       
            }
            fprintf(ftemp,"%s %s %s %s %s %s %s %s %s\n",cii.nom,cii.id,cii.type,cii.position,cii.valeur,cii.etat,cii.d.jour,cii.d.mois,cii.d.annee);
        }

    }
    fclose(ftemp);
    fclose(f);
    remove("capteurs.txt");
    rename("capteurs.txt.temp","capteurs.txt");


}


//chercher
capteur chercher(char idch[])
{
 FILE *f;
   
    capteur cii;
   
   
    f=fopen("capteurs.txt","r+");
    
    if (f!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s %s %s %s %s\n",cii.nom,cii.id,cii.type,cii.position,cii.valeur,cii.etat,cii.d.jour,cii.d.mois,cii.d.annee)!=EOF)
        {
            if(strcmp(idch,cii.id)==0)
            {
		      return cii;
            }
          
        }

    }
    
    fclose(f);


}
 //supprimer


void supprimer(char idsupp[])
{
    FILE *f;
    FILE *ftemp;
    ftemp=NULL;
    capteur cii;
    char id0[15];
    strcpy(id0,"sSs");
   
    f=fopen("capteurs.txt","r+");
    ftemp=fopen("capteurs.txt.temp","a+");
    if (f!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s %s %s %s %s\n",cii.nom,cii.id,cii.type,cii.position,cii.valeur,cii.etat,cii.d.jour,cii.d.mois,cii.d.annee)!=EOF)
        {
            if(strcmp(idsupp,cii.id)==0)
            {
		       strcpy(cii.id,id0);
		       
            }
            if(strcmp(id0,cii.id)!=0)
               {
                 fprintf(ftemp,"%s %s %s %s %s %s %s %s %s\n",cii.nom,cii.id,cii.type,cii.position,cii.valeur,cii.etat,cii.d.jour,cii.d.mois,cii.d.annee);
               }
         }
    }
    fclose(ftemp);
    fclose(f);
    remove("capteurs.txt");
    rename("capteurs.txt.temp","capteurs.txt");
}

void afficher(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char nom[20];
char id[20];
char type[15];
char position[20];
char valeur[30];
char etat[50];
char jour[5];
char mois[5];
char anne[7];

store=NULL;


FILE *f;

store=gtk_tree_view_get_model(liste);


if(store==NULL)
{
renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Nom",renderer, "text",ENOM,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("ID",renderer, "text",EID,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Type",renderer, "text",ETYPE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Position",renderer, "text",EPOSITION,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("valeur",renderer,"text",EVALEUR,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Etat",renderer, "text",EETAT,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Jour",renderer, "text",EJOUR,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Mois",renderer, "text",EMOIS,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Année",renderer, "text",EANNE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f = fopen("capteurs.txt","r");
if(f==NULL)
{
  return;
}
else
{

while(fscanf(f,"%s %s %s %s %s %s %s %s %s\n",nom,id,type,position,valeur,etat,jour,mois,anne)!=EOF)
  {
    gtk_list_store_append (store,&iter);
gtk_list_store_set(store,&iter,ENOM,nom,EID,id,ETYPE,type,EPOSITION,position,EVALEUR,valeur,EETAT,etat,EJOUR,jour,EMOIS,mois,EANNE,anne, -1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}


void affichervaleur(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char nom[20];
char id[20];
char type[15];
char position[20];
char valeur[30];
char etat[50];
char jour[5];
char mois[5];
char anne[7];

store=NULL;


FILE *f;

store=gtk_tree_view_get_model(liste);


if(store==NULL)
{
renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Nom",renderer, "text",ENOM,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("ID",renderer, "text",EID,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Type",renderer, "text",ETYPE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Position",renderer, "text",EPOSITION,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("valeur",renderer,"text",EVALEUR,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Etat",renderer, "text",EETAT,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Jour",renderer, "text",EJOUR,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Mois",renderer, "text",EMOIS,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer =gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Année",renderer, "text",EANNE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f = fopen("capteurs.txt","r");
if(f==NULL)
{
  return;
}
else
{

while(fscanf(f,"%s %s %s %s %s %s %s %s %s\n",nom,id,type,position,valeur,etat,jour,mois,anne)!=EOF)
  {      g_print("%f\n",atof(valeur));
	if (((atof(valeur)<0)||(atof(valeur)>100 ))&&(strcmp(type,"humidite")==0))
	

         {
          gtk_list_store_append (store,&iter);
          gtk_list_store_set(store,&iter,ENOM,nom,EID,id,ETYPE,type,EPOSITION,position,EVALEUR,valeur,EETAT,etat,EJOUR,jour,EMOIS,mois,EANNE,anne, -1);
         }
	
	if (((atof(valeur)<-10)||(atof(valeur)>60 ))&&(strcmp(type,"temperature")==0))
	

         {
          gtk_list_store_append (store,&iter);
          gtk_list_store_set(store,&iter,ENOM,nom,EID,id,ETYPE,type,EPOSITION,position,EVALEUR,valeur,EETAT,etat,EJOUR,jour,EMOIS,mois,EANNE,anne, -1);
         }

	if (((atof(valeur)<0)||(atof(valeur)>2 ))&&(strcmp(type,"hydraulique")==0))
	

         {
          gtk_list_store_append (store,&iter);
          gtk_list_store_set(store,&iter,ENOM,nom,EID,id,ETYPE,type,EPOSITION,position,EVALEUR,valeur,EETAT,etat,EJOUR,jour,EMOIS,mois,EANNE,anne, -1);
         }
  }
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}

