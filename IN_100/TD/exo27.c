#include "uvsqgraphics.h"

int main()
{
init_graphics(1280,720);

// Debut du code
POINT p1;
POINT p2;
int compteur;

p1.x=0; p1.y=0;
p2.x=0; p2.y=720;

compteur = 0;

while (compteur < 13)
	{
		compteur += 1;
		p1.x += 100;
		p2.x += 100;
		if (compteur%2==0)
			{
				draw_line(p1,p2,bleu);
			}
		else
			{
				draw_line(p1,p2,rouge);
			}
	}

// Fin du code

wait_escape();
exit(0);
}
