#include "point.h"
#include<stdio.h>
int main()
{
int r;
Point p;
r=ajouter(p,"point.txt");
if(r=1)
	{
	printf("le point a été rajouté"); 
	}else
		{
		printf("rip");
		}
}
