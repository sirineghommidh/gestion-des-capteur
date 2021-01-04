#include <string.h>
#include <ctype.h>
#include "fonction.h"
#include <stdio.h>
#include <gtk/gtk.h>
int verif(char log[],char Pw[])
{
int trouve=-1;
FILE *f=NULL;
char ch1[20];
char ch2[20];
f=fopen("utilisateur.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%s %s\n",ch1,ch2)!=EOF)
{
if((strcmp(ch1,log)==0)&&(strcmp(ch2,Pw)==0))
trouve=1;
}
fclose(f);
}
return trouve;
}
