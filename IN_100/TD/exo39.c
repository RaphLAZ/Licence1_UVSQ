#include "uvsqgraphics.h"

#define DIAM 10

int main()
{
init_graphics(1440,800);

// Debut du code
int tab [20];
int i;
POINT p1;
POINT p2;

for (i = 0; i < 20 ; i++) 
{
	tab[i] = alea_int(100);
	p1.x = 100+20*i;  p1.y=50;
	p2.x = 100+20*i+19;  p2.y=50 + 3*tab[i];
	draw_fill_rectangle (p1,p2,bleu);
}





// Fin du code

wait_escape();
exit(0);
}
