#include "point.h"
#include<stdio.h>
int main()
{

Point p1={1, 0,0,"rouge"} ,p2={2, 1,1,"noir"};

Point p= chercher(9,"point.txt");
if(p.id==-1)
printf("inexistant");
else
printf("%d %s %d %d\n",p.id,p.couleur,p.x,p.y);

}
