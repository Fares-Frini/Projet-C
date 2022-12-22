#include <stdio.h>
#include <gtk/gtk.h>

typedef struct 
{
    char name[20];
    int day;
    int month;
    int year;
    int class;
}child;
int registerr(child p,char *filename);
