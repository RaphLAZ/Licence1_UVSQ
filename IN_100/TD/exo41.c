#include "uvsqgraphics.h"

void dessine_croix(POINT centre, int largeur, COULEUR c)
{
	POINT p1;
	POINT p2;
	POINT p3;
	POINT p4;
	p1.x = centre.x + largeur; p1.y = centre.y + largeur;
	p2.x = centre.x + largeur; p2.y = centre.y - largeur;
	p3.x = centre.x - largeur; p3.y = centre.y + largeur;
	p4.x = centre.x - largeur; p4.y = centre.y - largeur;
	draw_line(p1,p4,c);
	draw_line(p2,p3,c);
}

int main()
{
init_graphics(1440,800);

// Debut du code
POINT centre; int largeur; COULEUR c;

centre = wait_clic();
largeur = lire_entier_clavier();
c = rouge;


dessine_croix(centre,largeur,c);




// Fin du code

wait_escape();
exit(0);
}
