#include "uvsqgraphics.h"

void my_draw_triangle(POINT p1, POINT p2, POINT p3, COULEUR c)
{
	draw_line(p1,p2,c);
	draw_line(p2,p3,c);
	draw_line(p3,p1,c);
}

void my_draw_triangle_clic(COULEUR c)
{
	POINT p1,p2,p3;
	p1 = wait_clic();
	p2 = wait_clic();
	p3 = wait_clic();
	draw_line(p1,p2,c);
	draw_line(p2,p3,c);
	draw_line(p3,p1,c);
}

int main()
{
init_graphics(1440,800);

// Debut du code
POINT a,b,d; int i;
COULEUR c = blanc;

for (i = 0; i < 10; i++)
{
	a = wait_clic();
	b = wait_clic();
	d = wait_clic();
	my_draw_triangle(a,b,d,c);
}

for (i = 0; i < 10; i++)
{
	my_draw_triangle_clic(c);
}




// Fin du code

wait_escape();
exit(0);
}
