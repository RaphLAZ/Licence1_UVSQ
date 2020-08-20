#include "uvsqgraphics.h"

void dessine_mickey(POINT centre, int rayon, COULEUR c)
{
	POINT p1; POINT p2;
	draw_fill_circle(centre,rayon,c);
	p1.x = centre.x + rayon; p1.y = centre.y + rayon;
	p2.x = centre.x - rayon; p2.y = centre.y + rayon;
	draw_fill_circle(p1,rayon/2,c);
	draw_fill_circle(p2,rayon/2,c);
	
}

int main()
{
init_graphics(1440,800);

// Debut du code
POINT centre; int rayon; COULEUR c;

centre = wait_clic();
rayon = lire_entier_clavier();
c = blanc;


dessine_mickey(centre,rayon,c);




// Fin du code

wait_escape();
exit(0);
}
