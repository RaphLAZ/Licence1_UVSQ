#include "uvsqgraphics.h"
POINT bg; int lg;

void carre_croix()
{
	POINT a;
	a.x=bg.x+lg; a.y=bg.y+lg;
	draw_rectangle(bg,a,blanc);
	draw_line(bg,a,blanc);
	a.y-=lg; bg.y+=lg;
	draw_line(bg,a,blanc);
	bg.y-=lg;
}

void boucle(int ligne, int colonne)
{
	int i; int j;
	for (j = 0; j < colonne; j++)
	{
		for (i = 0; i < ligne ; i++)
		{
			carre_croix();
			bg.x+=lg;
		}
		for (i = 0; i < ligne ; i++)
		{
			bg.x-=lg;
		}
		bg.y+=lg;
	}	
	
}

int main()
{
init_graphics(1440,800);

// Debut du code

bg = wait_clic();
lg = 100;
boucle(3,4);



// Fin du code

wait_escape();
exit(0);
}
