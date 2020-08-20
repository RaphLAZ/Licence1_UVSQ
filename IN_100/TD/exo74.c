#include "uvsqgraphics.h"
#define rayon 20
POINT A[20]; int b,c;



int main()
{
init_graphics(800,800);

// Debut du code
int i,k,j; POINT p, centre;
centre.x = 400; centre.y = 400;
for (i = 0; i < 20; i++)
{
	p = wait_clic();
	A[i] = p;
	draw_circle(p, rayon, red);

}
for (j = 0; j <20; j++)
{
	p = wait_clic();
	k = 0;
	for (i = 1; i < 20; i++)
	{
		c = distance(A[i], centre);
		b = distance(A[k], centre);
		if (c-b > 0)
		{
			k = i;
		}	
	}
	c = distance(p, centre);
	b = distance(A[k], centre);
	if (c-b < 0)
	{
		draw_circle(A[k], rayon, noir);
		A[k] = p;
		draw_circle(p, rayon, red);
	}
}






// Fin du code

wait_escape();
exit(0);
}
