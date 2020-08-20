#include "uvsqgraphics.h"

#define DIAM 10

int main()
{
init_graphics(1440,800);

// Debut du code
POINT tab[10];
int i;
POINT p;

for (i = 0; i < 10 ; i++)
{
	p = wait_clic();
	draw_circle(p,DIAM,red);
	tab[i] = p;
}


for (i = 9; i >= 0 ; i--)
{
	p = wait_clic();
	draw_circle(tab[i],DIAM,noir);
}




// Fin du code

wait_escape();
exit(0);
}
