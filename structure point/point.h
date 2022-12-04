#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

typedef struct
{
int id;
int x,y;
char couleur [20];
}Point;

int ajouter(Point p , char filename []);
int modifier(int id, Point nouv, char * filename);
int supprimer(int id, char * filename);
Point chercher(int id, char * filename);

#endif // POINT_H_INCLUDED
