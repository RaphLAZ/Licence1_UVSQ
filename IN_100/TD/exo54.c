#include "uvsqgraphics.h"


int main()
{
init_graphics(1440,800);

// Debut du code
int i,j; POINT p1,p2,p;

j=0;
p1.x = 720; p1.y = 0;
p2.x = 720; p2.y = 800;
draw_line(p1,p2,blanc);
for (i = 0; i < 20; i++)
{
	p = wait_clic();
	if (p.x < 720)
	{
		draw_circle(p,50,red);
		j = 0;
	}
	else if (j>0)
	{
		draw_circle(p,50,blue);
	}
	else
	{
		j = 1;
	}
}

// Fin du code

wait_escape();
exit(0);
}
