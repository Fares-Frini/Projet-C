#include "fonction.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>


ouvrage chercher(char *code,char *filename)
{
    ouvrage p;
    FILE *f;
    f=fopen(filename,"r");
    while (fscanf(f,"%s %s %d",p.code,p.titre,&p.nb_pages))
    {
        if (strcmp(p.code,code)==0)
        {
            fclose(f);
            return p;
        }
        
    }
    
    
    
    
}