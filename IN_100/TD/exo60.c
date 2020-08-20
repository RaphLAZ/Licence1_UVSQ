#include "uvsqgraphics.h"

void plateau()
{
	POINT p1, p2; int i, j;
	for (i = 0; i < 800; i+= 80)
	{
		for (j = 0; j < 800 ; j+= 80)
		{
			p1.x= j; p1.y = i;
			p2.x= j+ 80; p2.y = i+80;
			draw_rectangle(p1, p2, blanc);
		}
		
	}
}
	
void initialise_plateau()
{
	int i,j,k; POINT p;
	for (i = 40; i < 800; i+= 80)
	{
		for (j = 40; j < 800; j+=80)
		{
			p.x = j; p.y = i;
			k = alea_int(2);
			if (k == 1)
			{
				draw_circle(p,30,blanc);
			}
			else
			{
				draw_fill_circle(p,30,blanc);
			}
		}
		
	}
	
}

int main()
{
init_graphics(800,800);

// Debut du code

plateau();
initialise_plateau();



// Fin du code

wait_escape();
exit(0);
}
