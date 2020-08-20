#include "uvsqgraphics.h"
int tab [20], tri[20];

void trieur()
{
	int i,j,k,l; POINT p1, p2;
	
	for (j = 1; j < 20; j++)
	{
		k = j-1;
		l = j-1;
		for (i = j; i < 20; i++)
		{
			if (tab[k] > tab[i])
			{
				
				tri[l] = tab [i];
				tab [i] = tab [k];
				
				tab[k] = tri [l];
				
				
			}
			else
			{
				tri[l] = tab[k];
			}
		}
		
		
	}
	tri[19] = tab[19];
	fill_screen(noir);
	for (i = 0; i < 20 ; i++) 
	{
		p1.x = 100+20*i;  p1.y=50;
		p2.x = 100+20*i+19;  p2.y=50 + 3*tri[i];
		draw_fill_rectangle (p1,p2,bleu);
	}

	
}

int main()
{
init_graphics(600,400);

// Debut du code

int i;
POINT p1;
POINT p2;


for (i = 0; i < 20 ; i++) 
{
	tab[i] = alea_int(100);
	p1.x = 100+20*i;  p1.y=50;
	p2.x = 100+20*i+19;  p2.y=50 + 3*tab[i];
	draw_fill_rectangle (p1,p2,bleu);
}
wait_clic();
trieur();







// Fin du code

wait_escape();
exit(0);
}
