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
POINT p6;
POINT p7;
POINT p8;
POINT p9;
POINT p10;

p5.x=10; p5.y=10;
p10.x=390; p10.y=10;

while ((p5.x < 400)&&(p5.y < 400))
	{
		p1.x=p5.x-10; p1.y=p5.y-10;
		p2.x=p5.x+10; p2.y=p5.y-10;
		p3.x=p5.x-10; p3.y=p5.y+10;
		p4.x=p5.x+10; p4.y=p5.y+10;
		draw_line(p1,p4,blanc);
		draw_line(p2,p3,blanc);
		p5.x+=20; p5.y+=20;
		
		p6.x=p10.x-10; p6.y=p10.y-10;
		p7.x=p10.x+10; p7.y=p10.y-10;
		p8.x=p10.x-10; p8.y=p10.y+10;
		p9.x=p10.x+10; p9.y=p10.y+10;
		draw_line(p6,p9,blanc);
		draw_line(p7,p8,blanc);
		p10.x-=20; p10.y+=20;
	}


// Fin du code

wait_escape();
exit(0);
}
