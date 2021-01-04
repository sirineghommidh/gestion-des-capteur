#ifndef FONCTIONS_H_ 
#define FONCTIONS_H_ 
#include <gtk/gtk.h>

typedef struct
{
   char jour[5];
   char mois[5];
   char annee[7];

}date;


typedef struct
{
char nom[20];
char id[20];
char type[15];
char position[20];
char valeur[50];
char etat[10];
date d;
}capteur;


void ajouter(capteur cii);
void modifier(char idmodif[],capteur sii);
capteur chercher(char idch[]);
void supprimer(char idsupp[]);
void afficher(GtkWidget *liste);
void affichervaleur(GtkWidget *liste);


#endif 
