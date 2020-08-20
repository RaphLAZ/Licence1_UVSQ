#include "uvsqgraphics.h"

int main()
{
init_graphics(1280,720);

// Debut du code
POINT p1;
POINT p2;
POINT p3;
POINT p4;
int compteur;

p1.x=0; p1.y=0;
p2.x=0; p2.y=720;
p3.x=0; p3.y=0;
p4.x=1280; p4.y=0;
compteur = 0;

while (p1.x < 1280)
	{
		draw_line(p1,p2,blanc);
		draw_line(p3,p4,blanc);
		p1.x += 100;
		p2.x += 100;
		p3.y += 100;
		p4.y += 100;
		compteur += 1;
	}

// Fin du code

wait_escape();
exit(0);
}
