#include "uvsqgraphics.h"

int main()
{
int taille;
taille = 200;
init_graphics(taille,taille);

// Debut du code
POINT p1;
int cercle;

cercle = 10;
p1.x=100; p1.y=100;

while (cercle < 110)
	{
		draw_circle(p1,cercle,blanc);
		cercle += 10;
	}


// Fin du code

wait_escape();
exit(0);
}
