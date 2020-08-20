#include "uvsqgraphics.h"
int haut_ou_bas;
int gauche_ou_droite;
int ou_ca;

void qui_dit_ou_c_est(POINT p)
{
	if (p.y<=200)
	{
		haut_ou_bas = 0;
	}
	else
	{
		haut_ou_bas = 1;
	}
	if (p.x<=200)
	{
		gauche_ou_droite = 0;
	}
	else
	{
		gauche_ou_droite = 1;
	}
}

void calcul_ou_ca()
{
	if (haut_ou_bas == 0)
	{
		if (gauche_ou_droite == 0)
		{
			ou_ca = 0;
		}
		else
		{
			ou_ca = 1;
		}
	}
	else 
	{
		if (gauche_ou_droite == 0)
		{
			ou_ca = 2;
		}
		else
		{
			ou_ca = 3;
		}
	}
}

void dessine_cercle_couleur(POINT centre)
{
	COULEUR c;
	if (ou_ca == 0)
	{
		c = blue;
	}
	else if (ou_ca == 1)
	{
		c = red;
	}
	else if (ou_ca == 2)
	{
		c = green;
	}
	else
	{
		c = yellow;
	}
	draw_circle(centre, 100, c);
}

int main()
{
init_graphics(400,400);
int i;
POINT centre, p;
// Debut du code

centre.x = 200; centre.y = 200;
for (i = 0; i < 20; i++)
{
	p = wait_clic();
	qui_dit_ou_c_est(p);
	calcul_ou_ca();
	dessine_cercle_couleur(centre);
}



// Fin du code

wait_escape();
exit(0);
}
