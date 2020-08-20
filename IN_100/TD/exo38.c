#include "uvsqgraphics.h"

#define DIAM 10

int main()
{
init_graphics(1440,800);

// Debut du code
POINT tab[10];
int i;
POINT p;
int a;
int t;
a = 0;
wait_clic();
t = get_key();
write_int(t);
for (i = 0; i < 10 ; i++)
{
	p = wait_clic();
	draw_circle(p,DIAM,red);
	tab[i] = p;
}
while (a < 10)
{
	p = wait_clic();
	for (i = 0; i < 10 ; i++)
	{
		if (((p.x <=tab[i].x + DIAM)&&(p.x >= tab[i].x - DIAM))&&((p.y <= tab[i].y + DIAM)&&(p.y >= tab[i].y - DIAM)))
		{
			draw_circle(tab[i],DIAM,noir);
			a=a+1;
		}
	}
}




// Fin du code

wait_escape();
exit(0);
}
