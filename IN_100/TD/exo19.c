#include "uvsqgraphics.h"

int main()
{
init_graphics(1280,720);

// Debut du code
POINT point;
POINT p1;
POINT p2;
POINT p3;
POINT p4;

p1.x=427; p1.y=0;
p2.x=427; p2.y=720;
p3.x=854; p3.y=0;
p4.x=854; p4.y=720;

draw_line(p1,p2,blanc);
draw_line(p3,p4,blanc);

point=wait_clic();


if (point.x<p1.x)
	{
		draw_circle(point,50,bleu);
	}
	else if (point.x>p4.x)
		{
			draw_circle(point,50,rouge);
		}
	else
		{
			draw_circle(point,50,blanc);
		}
	

// Fin du code

wait_escape();
exit(0);
}
