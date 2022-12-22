#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED
#include <stdio.h>
#include <gtk/gtk.h>

typedef struct Ouvrage
{
    char code[20];
    char titre[20];
    int nb_pages;
}ouvrage;

ouvrage chercher(char *code,char *filename);







#endif