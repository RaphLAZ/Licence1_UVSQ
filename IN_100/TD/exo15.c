#include "uvsqgraphics.h"

int main()
{
init_graphics(1280,720);

// Debut du code
POINT point;
POINT point2;
POINT p1;
POINT p2;

p1.x=640; p1.y=0;
p2.x=640; p2.y=720;

draw_line(p1,p2,blanc);

point=wait_clic();
point2=wait_clic();

if (point.x<p1.x)
	{
		if (point2.x<p1.x)
			{
			draw_line(point,point2,bleu);
			}
		else
			{
			draw_line(point,point2,red);
			}
	}
	else if (point.x>p1.x)
		{
			if (point2.x>p1.x)
				{
				draw_line(point,point2,bleu);
				}
			else
				{
				draw_line(point,point2,red);
				}
		}

// Fin du code

wait_escape();
exit(0);
}
