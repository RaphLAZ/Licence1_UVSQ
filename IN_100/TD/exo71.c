#include "uvsqgraphics.h"


int main()
{
init_graphics(1440,800);

// Debut du code
int tab [20];
int i,k;
POINT p1;
POINT p2;
POINT p,p3;

for (i = 0; i < 20 ; i++) 
{
	tab[i] = alea_int(100);
	p1.x = 100+20*i;  p1.y=50;
	p2.x = 100+20*i+19;  p2.y=50 + 3*tab[i];
	draw_fill_rectangle (p1,p2,bleu);
}
k = 0;
for (i = 1; i < 20; i++)
{
	p1.x = 100+20*i;  p1.y=50;
	p2.x = 100+20*i+19;  p2.y=50 + 3*tab[i];
	p3.x = 100+20*k;  p3.y=50;
	p.x = 100+20*k+19;  p.y=50 + 3*tab[k];
	if (p.y > p2.y)
	{
		k = i;
	}
	else
	{
	}
}
fill_screen(noir);
for (i = 0; i < 20; i++)
{
	if (i == 0 || i == k)
	{
		p1.x = 100+20*0;  p1.y=50;
		p2.x = 100+20*0+19;  p2.y=50 + 3*tab[k];
		p3.x = 100+20*k;  p3.y=50;
		p.x = 100+20*k+19;  p.y=50 + 3*tab[0];
		draw_fill_rectangle(p1,p2,rouge);
		draw_fill_rectangle(p3,p,bleu);
	}
	else 
	{
			p1.x = 100+20*i;  p1.y=50;
		p2.x = 100+20*i+19;  p2.y=50 + 3*tab[i];
		draw_fill_rectangle (p1,p2,bleu);
	}
}







// Fin du code

wait_escape();
exit(0);
}
