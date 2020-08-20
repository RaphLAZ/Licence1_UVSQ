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

p1.x=640; p1.y=0;
p2.x=640; p2.y=720;
p3.x=0; p3.y=360;
p4.x=1280; p4.y=360;

draw_line(p1,p2,blanc);
draw_line(p3,p4,blanc);

point=wait_clic();


if (((point.x<p1.x)&&(point.y>p4.y))||((point.x>p1.x)&&(point.y<p4.y)))
	{
		draw_circle(point,50,bleu);
	}
	else
		{
			draw_circle(point,50,red);
		}
	

// Fin du code

wait_escape();
exit(0);
}
