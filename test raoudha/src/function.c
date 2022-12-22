#include "function.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>

int registerr(child p,char *filename)
{
    FILE *f;
    f=fopen(filename,"a");
    if (f!=NULL)
    {
        fprintf(f,"%s %d %d %d %d\n",p.name,p.day,p.month,p.year,p.class);
        fclose(f);
        return 1;
    }else 
        return 0;
    
}