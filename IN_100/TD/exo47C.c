#include "uvsqgraphics.h"


void dessine_ellipse(POINT f1 ,POINT f2 ,int dist , COULEUR c)
{
	int i, j, a, b; POINT m;
	f1.x = 730; f1.y =400;
	f2.x = 720; f2.y = 400;
	for (i = 0; i < 1440; i++)
	{
		m.x = i;
		for (j = 0; j < 800; j++)
		{
			m.y = j;
			f1.y = m.y;
			a = distance(f1,m);
			b = distance(f2,m);
			if (a == b)
			{
				draw_pixel(m, c);
			}
			
		}
	}
	
	
	
	
	
	
	

}

int main()
{
init_graphics(1440,800);

// Debut du code
COULEUR c; POINT f1, f2; int dist;
c = red;
//f1 = wait_clic();
//f2 = wait_clic();
dessine_ellipse(f1,f2, dist, c);

// Fin du code

wait_escape();
exit(0);
}
