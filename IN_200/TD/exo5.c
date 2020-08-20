#include "uvsqgraphics.h"

void efface_affiche(POINT ancien, POINT nouveau)
{
	draw_fill_circle(ancien,25,noir);
	draw_fill_circle(nouveau,25,red);
}

POINT deplace_balle(POINT ancien, int dx, int dy)
{
	ancien.x += dx; ancien.y += dy;
	return ancien;
}

void affiche_balle(POINT p)
{
	draw_fill_circle(p,25,red);
}

void efface_balle(POINT p)
{
	draw_fill_circle(p,25,noir);
}
POINT init_balle(int x, int y)
{
	POINT a;
	a.x = x; a.y = y;
	return a;
}
int trop_haut(POINT p, int r)
{
	if (p.y+r > 800)
	{
		return 1;
	}
	else return 0;
}

int main()
{
init_graphics(1000,800);

// Debut du code
POINT a; int i; int y = 3;
a = init_balle(50,50);
affiche_balle(a);
for (i = 0; i < 500; i++)
{
	efface_affiche(a,deplace_balle(a,2,y));
	a= deplace_balle(a,2,y);
	if (trop_haut(deplace_balle(a,2,y), 25))
	{
		y= -2;
	}
	attendre(5);
}

// Fin du code

wait_escape();
exit(0);
}
