#include "uvsqgraphics.h"

int main()
{
init_graphics(512,512);

// Debut du code
POINT p1;
POINT p2;
COULEUR coul;
int i;



p1.x=0; p1.y=0;
p2.x=512; p2.y=2;


for (i = 0; i<256; i++)
	{
		coul = couleur_RGB(255,i,i);
		draw_rectangle(p1,p2,coul);
		p1.y+=2; p2.y+=2;
	}


// Fin du code

wait_escape();
exit(0);
}
