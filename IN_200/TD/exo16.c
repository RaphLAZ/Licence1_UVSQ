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
	r.longeur = 30 ;
	r.largeur = 20 ;
	r.coul = gris;
	
	
	return r;	
}



int main()
{
init_graphics(800,800);

// Debut du code




// Fin du code

wait_escape();
exit(0);
}
