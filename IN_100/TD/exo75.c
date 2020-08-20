#include "uvsqgraphics.h"
POINT A[20]; int B[20];



int main()
{
init_graphics(800,800);

// Debut du code
int i,k; POINT p;

for (i = 0; i < 20; i++)
{
	B[i] = 20;
	A[i] = wait_clic();
	draw_circle(A[i], B[i], red);
}
k = 0;
while (k < 20)
{
	p = wait_clic();
	for (i = 0; i < 20; i++)
	{
		if (p.x < A[i].x + B[i] && p.x > A[i].x - B[i] && p.y < A[i].y + B[i] && p.y > A[i].y - B[i])
		{
			draw_circle(A[i], B[i], noir);
			B[i] -= 5;
			if (B[i])
			{
				draw_circle(A[i], B[i], red);
			}
			else 
			{
				k += 1;
			}
			
		}
		else
		{
			if (B[i])
			{
				draw_circle(A[i], B[i], noir);
				B[i] += 5;
				draw_circle(A[i], B[i], red);
			}
			else
			{
			}
		}
	}
	
}


// Fin du code

wait_escape();
exit(0);
}
