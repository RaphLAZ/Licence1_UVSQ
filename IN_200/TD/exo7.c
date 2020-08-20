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

int main()
{
init_graphics(1000,800);

// Debut du code

// Fin du code

wait_escape();
exit(0);
}
