#include "uvsqgraphics.h"

POINT centre, centre_precedent;

void efface_affiche()
{
	draw_fill_circle(centre_precedent,30,noir);
	draw_fill_circle(centre,30,bleu);
}

void plus_ou_moins(POINT p)
{
	centre_precedent = centre;
	if (p.y > centre.y)
	{
		centre.y += 2;
	}
	if (p.y < centre.y)
	{
		centre.y -= 2;
	}
}

int main()
{
init_graphics(1440,800);

// Debut du code
int i;
POINT p;

centre_precedent.x = 0;
centre_precedent.y = 0;

centre.x = 200;
centre.y = 200;

for (i = 0; i < 1000; i++)
{
	p = get_mouse();
	efface_affiche();
	plus_ou_moins(p);
}

// Fin du code

wait_escape();
exit(0);
}
