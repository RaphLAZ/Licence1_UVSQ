#include "uvsqgraphics.h"


int main()
{
init_graphics(800,800);

// Debut du code
int i,j,k;
POINT p1,p2;
k = 0;
for (i = 0; i < 800 ; i += 100)
{
	
	for (j = 0; j < 800 ; j+= 100)
	{
		p1.x= j; p1.y = i;
		p2.x= j+100; p2.y = i+100;
		if (k == 0)
		{
			draw_fill_rectangle(p1,p2,blanc);
		}
		k = 1 - k;
	}
	k = 1 - k;
}

// Fin du code

wait_escape();
exit(0);
}
