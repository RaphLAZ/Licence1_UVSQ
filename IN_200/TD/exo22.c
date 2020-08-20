#include "uvsqgraphics.h"

struct raquette
{
	POINT centre;
	int longeur;
	int largeur;
	COULEUR coul;
	
};

typedef struct raquette RAQUETTE;



RAQUETTE init_raquette()
{
	RAQUETTE r;
	r.centre.x = 400 ;
	r.centre.y = 100 ;
	r.longeur = 40 ;
	r.largeur = 10 ;
	r.coul = gris;
	
	
	return r;	
}

RAQUETTE deplace_raquette(RAQUETTE r)
{
	POINT a; int d,g;
	d = r.centre.x +(r.longeur/2);
	g = r.centre.x -(r.longeur/2);
	a = get_arrow();
	if ( a.x <0)
	{
		if (g > 0)
		{
			r.centre.x += a.x*3;
		}
		else
		{
		}
	}
	else if ( a.x > 0)
	{
		if (d < 800)
		{
			r.centre.x += a.x*3;
		}
		else
		{
		}
		
	}
	printf("%d\n", r.centre.x);
	return r;
}

void affiche_raquette(RAQUETTE r)
{
	POINT a,b;
	a.x = r.centre.x - (r.longeur/2); a.y = r.centre.y - (r.largeur/2);
	b.x = r.centre.x + (r.longeur/2); b.y = r.centre.y + (r.largeur/2);
	draw_fill_rectangle(a,b,r.coul);
}

void efface_raquette(RAQUETTE r)
{
	POINT a,b;
	a.x = r.centre.x - (r.longeur/2); a.y = r.centre.y - (r.largeur/2);
	b.x = r.centre.x + (r.longeur/2); b.y = r.centre.y + (r.largeur/2);
	draw_fill_rectangle(a,b,noir);
}

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
	
	b.centre.x = 400;
	b.centre.y = 400;
	b.rayon = 10;
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
}

BALLE rebond_balle(BALLE b, RAQUETTE r)
{
	POINT a,c;
	a.x = r.centre.x - (r.longeur/2); a.y = r.centre.y - (r.largeur/2);
	c.x = r.centre.x + (r.longeur/2); c.y = r.centre.y + (r.largeur/2);
	if (b.centre.x - b.rayon <= 0)
	{
		b.dx = -b.dx;
	}
	else if (b.centre.x + b.rayon >= 800)
	{
		b.dx = -b.dx;
	}
	else if (b.centre.y <= 0)
	{
		effacer_balle(b);
		b = init_balle();
	}
	else if (b.centre.y + b.rayon >= 800)
	{
		b.dy = -b.dy;
	}
	else if (a.x <= b.centre.x && c.x >= b.centre.x)
	{
		if (b.centre.y - b.rayon <= c.y )
		{
			b.dy = -b.dy;
		}
	}
	return b;
}

int main()
{
init_graphics(800,800);

// Debut du code
RAQUETTE r; int i; BALLE b;
r = init_raquette();
b = init_balle();
affiche_balle(b);
affiche_raquette(r);
wait_clic();
affiche_auto_off();
i = 0;
while (i == 0)
{
	efface_raquette(r);
	effacer_balle(b);
	r = deplace_raquette(r);
	b = deplace_balle(b);
	affiche_raquette(r);
	affiche_balle(b);
	b = rebond_balle(b, r);
	affiche_all();
	attendre(5);
}

// Fin du code

wait_escape();
exit(0);
}
