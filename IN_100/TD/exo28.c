#include "uvsqgraphics.h"

int main()
{
init_graphics(1280,720);

// Debut du code
POINT P;
POINT p1;
POINT p2;
int x;

p1.x=640; p1.y=0;
p2.x=640; p2.y=720;

x=0;

draw_line(p1,p2,blanc);
while (x < 5)
	{
		P=wait_clic();

		if (P.x<p1.x)
			{
				draw_circle(P,50,red);
			}
			else if (P.x>p1.x)
				{
					draw_circle(P,50,bleu);
				}
		x+=1;
	}

// Fin du code

wait_escape();
exit(0);
}
