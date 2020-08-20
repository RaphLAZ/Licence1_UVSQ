#include "uvsqgraphics.h"

struct balle
{
	POINT centre;
	int rayon;
	COULEUR coul;
	int dx, dy;
};

typedef struct balle BALLE;



BALLE init_balle()
{
	BALLE b;
	
	while (((b.centre.x <= 100) || (b.centre.x >= 300)) || ((b.centre.x <= 240) && (b.centre.x >= 160)))
	{
		b.centre.x = alea_int(300);
	}
	while ((b.centre.y <= 100) || (b.centre.y >= 300))
	{
		b.centre.y = alea_int(300);
	}
	while ((b.rayon < 5) || (b.rayon > 30))
	{
		b.rayon = alea_int(30);
	}
	b.coul = couleur_RGB(alea_int(255),alea_int(255),alea_int(255));
	while (b.coul == couleur_RGB(alea_int(0),alea_int(0),alea_int(0)))
	{
		b.coul = couleur_RGB(alea_int(255),alea_int(255),alea_int(255));
	}
	b.dx = alea_int(10) - 5;
	while (b.dx == 0)
	{
		b.dx = alea_int(10) - 5;
	}
	b.dy = alea_int(10) - 5;
	while (b.dy == 0)
	{
		b.dy = alea_int(10) - 5;
	}
	
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
}

BALLE rebond_balle(BALLE b)
{
	if (b.centre.x - b.rayon <= 0)
	{
		b.dx = -b.dx;
	}
	if (b.centre.x + b.rayon >= 400)
	{
		b.dx = -b.dx;
	}
	if (b.centre.y - b.rayon <= 0)
	{
		b.dy = -b.dy;
	}
	if (b.centre.y + b.rayon >= 400)
	{
		b.dy = -b.dy;
	}
	if (b.centre.x < 200)
	{
		if (b.centre.x + b.rayon >= 200)
		{
			b.dx =  -b.dx;
		}
	}
	else 
	{
		if (b.centre.x - b.rayon <= 200)
		{
			b.dx = -b.dx;
		}
	}
	return b;
}

void mur()
{
	POINT a,c;
	a.x = 200; a.y = 0;
	c.x = 200; c.y = 400;
	draw_line(a,c,blanc);	
}

int main()
{
init_graphics(400,400);

// Debut du code
int i=0; int n = 100;
BALLE b[n];
mur();
for (i = 0; i < n; i++)
{
	b[i] = init_balle();
	affiche_balle(b[i]);
	affiche_auto_off();
}
i = n;
while (i==n)
{
		for (i = 0; i < n ; i++)
	{
		effacer_balle(b[i]);
	}
			for (i = 0; i < n ; i++)
	{
		b[i] = deplace_balle(b[i]);
	}
			for (i = 0; i < n ; i++)
	{
		affiche_balle(b[i]);
		b[i] = rebond_balle(b[i]);
		mur();
	}
	affiche_all();
	attendre(10);
}


// Fin du code

wait_escape();
exit(0);
}
