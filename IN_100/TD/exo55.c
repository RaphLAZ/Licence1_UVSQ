#include "uvsqgraphics.h"


int main()
{
init_graphics(1440,800);

// Debut du code
int i,j,k,l; POINT p1,p2,p;

j=0;k=0;l=0;
p1.x = 480; p1.y = 0;
p2.x = 480; p2.y = 800;
draw_line(p1,p2,blanc);
p1.x += 480;
p2.x += 480;
draw_line(p1,p2,blanc);
for (i = 0; i < 20; i++)
{
	p = wait_clic();
	if (p.x < 480)
	{
		if (j == 0)
		{
			p1.x = 0; p1.y = 0;
			p2.x = 480; p2.y = 800;
			draw_fill_rectangle(p1,p2,blue);
		}
		else
		{
			p1.x = 0; p1.y = 0;
			p2.x = 480; p2.y = 800;
			draw_fill_rectangle(p1,p2,noir);
		}
		j = 1 - j;
	}
	else if (p.x > 960)
	{
		if (k == 0)
		{
			p1.x = 960; p1.y = 0;
			p2.x = 1440; p2.y = 800;
			draw_fill_rectangle(p1,p2,rouge);
		}
		else
		{
			p1.x = 960; p1.y = 0;
			p2.x = 1440; p2.y = 800;
			draw_fill_rectangle(p1,p2,noir);
		}
		k = 1 - k;
	}
	else
	{
		if (l == 0)
		{
			p1.x = 480; p1.y = 0;
			p2.x = 960; p2.y = 800;
			draw_fill_rectangle(p1,p2,blanc);
		}
		else
		{
			p1.x = 480; p1.y = 0;
			p2.x = 960; p2.y = 800;
			draw_fill_rectangle(p1,p2,noir);
		}
		l = 1 - l;
	}
}

// Fin du code

wait_escape();
exit(0);
}
