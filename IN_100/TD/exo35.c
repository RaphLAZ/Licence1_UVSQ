
#include "uvsqgraphics.h"

int main()
{
init_graphics(512,512);

// Debut du code
POINT p1;
POINT p2;
COULEUR coul;
int i;
int j;




for (i = 0; i<256; i++)
	{
		for (j=0; j<256; j++)
			{
				p1.x=2*i; p1.y=2*j;
				p2.x=2*i+2; p2.y=2*j+2;
				coul = couleur_RGB(i,100,j);
				draw_rectangle(p1,p2,coul);
				
			}
	}


// Fin du code

wait_escape();
exit(0);
}
