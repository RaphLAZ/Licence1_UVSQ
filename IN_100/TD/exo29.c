#include "uvsqgraphics.h"

int main()
{
init_graphics(1280,720);

// Debut du code
POINT p1;
POINT p2;
int x;
POINT p;



x=0;


p1.x=0; p1.y=0;
p2.x=10; p2.y=10;


draw_fill_rectangle(p1,p2,blanc);

while (x<5)
	{
		p=wait_clic();
		if (((p.x<p2.x)&&(p.x>p1.x))&&((p.y<p2.y)&&(p.y>p1.y)))
			{
				wait_escape();
			}
		else
			{
				draw_circle(p,100,blanc);
				
			}
	}
		

// Fin du code

wait_escape();
exit(0);
}
