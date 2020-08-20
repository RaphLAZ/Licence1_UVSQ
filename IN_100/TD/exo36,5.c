#include "uvsqgraphics.h"


int main()
{
init_graphics(400,400);

// Debut du code
POINT tab[10];
int i;
POINT p;

for (i = 0; i <10 ; i++)
{
	p = wait_clic();
	draw_circle(p,10,red);
	tab[i] = p;
}

p = wait_clic();

for (i = 0; i < 10 ; i++)
{
	draw_circle(tab[i],10,bleu);
}




// Fin du code

wait_escape();
exit(0);
}
