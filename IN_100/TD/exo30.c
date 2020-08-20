#include "uvsqgraphics.h"

int main()
{
init_graphics(400,400);

// Debut du code
POINT p1;
POINT p2;
POINT p3;
POINT p4;
POINT p5;

p5.x=10; p5.y=10;

while ((p5.x < 400)&&(p5.y < 400))
	{
		p1.x=p5.x-10; p1.y=p5.y-10;
		p2.x=p5.x+10; p2.y=p5.y-10;
		p3.x=p5.x-10; p3.y=p5.y+10;
		p4.x=p5.x+10; p4.y=p5.y+10;
		draw_line(p1,p4,blanc);
		draw_line(p2,p3,blanc);
		p5.x+=20; p5.y+=20;
	}


// Fin du code

wait_escape();
exit(0);
}
