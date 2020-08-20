#include "uvsqgraphics.h"

void dessine_line_h(COULEUR c)
{
	POINT p1; POINT p2;
	p1.y = 0; p2.y = 800;
	for (p1.x = 0; p1.x < 1500 ; p1.x += 100)
	{
		p2.x = p1.x;
		draw_line(p1,p2,c);
	}
	
}
void dessine_line_v(COULEUR c)
{
	POINT p1; POINT p2;
	p1.x = 0; p2.x = 1440;
	for (p1.y = 0; p1.y < 801 ; p1.y += 100)
	{
		p2.y = p1.y;
		draw_line(p1,p2,c);
	}
	
}
void dessine_cadrillage(COULEUR c)
{
	dessine_line_h(c);
	dessine_line_v(c);
}
int main()
{
init_graphics(1440,800);

// Debut du code

dessine_cadrillage(blanc);





// Fin du code

wait_escape();
exit(0);
}
