#include "uvsqgraphics.h"
COULEUR T1[256];

void remplir_gris()
{
	int i;
	for (i = 0; i < 256 ; i++)
	{
		T1[i] = couleur_RGB(i,i,i);
	}
	
}

void horizontale()
{
	int i; POINT p1,p2;
	for (i = 0; i < 256; i++)
	{
		p1.x = i*2; p1.y = 512;
		p2.x = p1.x + 2; p2.y = 0;
		draw_fill_rectangle(p1,p2,T1[i]);
	}
	
}

int main()
{
init_graphics(512,512);

// Debut du code



// Fin du code

wait_escape();
exit(0);
}
