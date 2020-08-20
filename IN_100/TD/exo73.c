#include "uvsqgraphics.h"
POINT A[20]; int B[20];



int main()
{
init_graphics(800,800);

// Debut du code
int i; 

for (i = 0; i < 20; i++)
{
	A[i].x = alea_int(800); A[i].y =alea_int(800);
	B[i] = alea_int(100);

}

for (i = 0; i < 20; i++)
{
	draw_circle(A[i], B[i], red);	
}




// Fin du code

wait_escape();
exit(0);
}
