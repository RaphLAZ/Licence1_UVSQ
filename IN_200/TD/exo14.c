#include "uvsqgraphics.h"
struct balle
{
	POINT centre;
	int rayon;
	int test;
	COULEUR coul;
	int dx, dy;
};

typedef struct balle BALLE;



BALLE init_balle()
{
	BALLE b;
	
	b.centre.x = 700;
	b.centre.y = 400;
	b.rayon = 25;
	b.test = 20;
	b.coul = magenta;
	b.dx = 2;
	b.dy = 3;
	
	return b;	
}

BALLE deplace_balle(BALLE b)
{
	b.centre.x += b.dx; b.centre.y += b.dy;
	return b;
}

void effacer_balle(BALLE b)
{
	draw_fill_circle(b.centre,b.rayon,noir);
}

void affiche_balle(BALLE b)
{
	draw_fill_circle(b.centre,b.rayon,b.coul);
	draw_fill_circle(b.centre,b.test,cyan);
}

BALLE rebond_balle(BALLE b)
{
	if (b.centre.x - b.rayon <= 0)
	{
		b.dx = -b.dx;
	}
	if (b.centre.x + b.rayon >= 1400)
	{
		b.dx = -b.dx;
	}
	if (b.centre.y - b.rayon <= 0)
	{
		b.dy = -b.dy;
	}
	if (b.centre.y + b.rayon >= 800)
	{
		b.dy = -b.dy;
	}
	return b;
}

int main()
{
init_graphics(1400,800);

// Debut du code
int i=0;
BALLE b;
b = init_balle();
affiche_balle(b);
wait_clic();
affiche_auto_off();

while (i==0)
{
	effacer_balle(b);
	b = deplace_balle(b);
	affiche_balle(b);
	attendre(10);
	b = rebond_balle(b);
	affiche_all();
}

// Fin du code

wait_escape();
exit(0);
}
