#include "uvsqgraphics.h"


int main()
{
init_graphics(512,512);

// Debut du code
int i,j;
POINT p1, p2;
COULEUR R;

for (i = 0; i<256; i++)
{
	for (j=0; j<256; j++)
		{
			p1.x=2*i; p1.y=2*j;
			p2.x=2*i+2; p2.y=2*j+2;
			R = couleur_RGB(i,0,255-j);
			draw_fill_rectangle(p1,p2,R);
			
		}
}





// Fin du code

wait_escape();
exit(0);
}
