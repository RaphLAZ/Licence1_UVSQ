#include "uvsqgraphics.h"

void dessine_cercle_couleur(int rayon)
{
	POINT p = wait_clic();
	COULEUR c = rouge;
	draw_fill_circle(p,rayon,c);
	POINT p1;
	int i;
	int a = 0;
	for (i = 0; i < 10 ; i--)
	{
		a += 1;
		if (a==1)
		{
			c = bleu;
		}
		else if (a==2)
		{
			c = blanc;
		}
		else if (a==3)
		{
			c = rouge;
		}
		POINT p1 = wait_clic();
		if (((p1.x <=p.x + rayon)&&(p1.x >= p.x - rayon))&&((p1.y <= p.y + rayon)&&(p1.y >= p.y - rayon)))
		{
		draw_fill_circle(p,rayon,c);
		}
		else
		{
			wait_escape();
		}
		if (a==3)
		{
			a=0;
		}
	}	
	
}

int main()
{
init_graphics(1440,800);

// Debut du code
int rayon = lire_entier_clavier();
dessine_cercle_couleur(rayon);






// Fin du code

wait_escape();
exit(0);
}
