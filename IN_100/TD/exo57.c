#include "uvsqgraphics.h"

void echequie()
{
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
}

void tour(POINT p1, COULEUR c)
{
	echequie();
	draw_fill_circle(p1,25,c);
}
int main()
{
init_graphics(800,800);

// Debut du code
POINT p,centre;
int i,j;
centre.x = 50; centre.y = 50;
tour(centre,red);

/* TOUR
for (i = 0; i < 10; i++)
{
	p = wait_clic();
	
	if (p.x>= centre.x -50 && p.x<= centre.x + 50)
	{
		if (p.y < centre.y - 50)
		{
			centre.y -= 50;
			while (centre.y > p.y)
			{
				centre.y -= 100;
			}
			centre.y += 50;
			fill_screen(noir);
			tour(centre,red);
		}
		else if (p.y > centre.y + 50)
		{
			centre.y +=50;
			while (centre.y < p.y)
			{
				centre.y += 100;
			}
			centre.y -= 50;
			fill_screen(noir);
			tour(centre,red);
		}
	}
	else if (p.y>= centre.y -50 && p.y<= centre.y + 50)
	{
		if (p.x < centre.x - 50)
		{
			centre.x -= 50;
			while (centre.x > p.x)
			{
				centre.x -= 100;
			}
			centre.x += 50;
			fill_screen(noir);
			tour(centre,red);
		}
		else if (p.x > centre.x + 50)
		{
			centre.x +=50;
			while (centre.x < p.x)
			{
				centre.x += 100;
			}
			centre.x -= 50;
			fill_screen(noir);
			tour(centre,red);
		}
	}
}
	
*/

/* Reine
for (i = 0; i < 10; i++)
{
	p = wait_clic();
	
	if (p.x>= centre.x -50 && p.x<= centre.x + 50)
	{
		if (p.y < centre.y - 50)
		{
			centre.y -= 50;
			while (centre.y > p.y)
			{
				centre.y -= 100;
			}
			centre.y += 50;
			fill_screen(noir);
			tour(centre,red);
		}
		else if (p.y > centre.y + 50)
		{
			centre.y +=50;
			while (centre.y < p.y)
			{
				centre.y += 100;
			}
			centre.y -= 50;
			fill_screen(noir);
			tour(centre,red);
		}
	}
	else if (p.y>= centre.y -50 && p.y<= centre.y + 50)
	{
		if (p.x < centre.x - 50)
		{
			centre.x -= 50;
			while (centre.x > p.x)
			{
				centre.x -= 100;
			}
			centre.x += 50;
			fill_screen(noir);
			tour(centre,red);
		}
		else if (p.x > centre.x + 50)
		{
			centre.x +=50;
			while (centre.x < p.x)
			{
				centre.x += 100;
			}
			centre.x -= 50;
			fill_screen(noir);
			tour(centre,red);
		}
	}
	for (j = 0; j < 9; j++)
	{
		if ((p.x >= j*100 + centre.x - 50 && p.x <= j*100 + centre.x + 50) && (p.y >= j*100 + centre.y - 50 && p.y <= j*100 + centre.y + 50))
		{
			centre.x += j*100; centre.y += j*100;
			fill_screen(noir);
			tour(centre,red);
		}
		else if ((p.x >=centre.x - 50 - j*100 && p.x <= centre.x + 50 - j*100) && (p.y >= j*100 + centre.y - 50 && p.y <= j*100 + centre.y + 50))
		{
			centre.x -= j*100; centre.y += j*100;
			fill_screen(noir);
			tour(centre,red);
		}
		else if ((p.x >= j*100 + centre.x - 50 && p.x <= j*100 + centre.x + 50) && (p.y >= centre.y - 50 - j*100 && p.y <= centre.y + 50 - j*100))
		{
			centre.x += j*100; centre.y -= j*100;
			fill_screen(noir);
			tour(centre,red);
		}
		else if ((p.x >=centre.x - 50 - j*100 && p.x <= centre.x + 50 - j*100) && (p.y >= centre.y - 50 - j*100 && p.y <= centre.y + 50 - j*100))
		{
			centre.x -= j*100; centre.y -= j*100;
			fill_screen(noir);
			tour(centre,red);
		}
	}
	
} */

/* Chevalier
for (i = 0; i < 10; i++)
{
	p = wait_clic();
	if (p.x >= centre.x + 150 && p.x <= centre.x + 250)
	{
		if (p.y >= centre.y + 50 && p.y <= centre.y + 150)
		{
			centre.x += 200; centre.y += 100;
			fill_screen(noir);
			tour(centre,red);
		}
		else if (p.y <= centre.y - 50 && p.y >= centre.y - 150)
		{
			centre.x += 200; centre.y -= 100;
			fill_screen(noir);
			tour(centre,red);
		}
	}
	else if (p.x >= centre.x - 250 && p.x <= centre.x - 150)
	{
		if (p.y >= centre.y + 50 && p.y <= centre.y + 150)
		{
			centre.x -= 200; centre.y += 100;
			fill_screen(noir);
			tour(centre,red);
		}
		else if (p.y <= centre.y - 50 && p.y >= centre.y - 150)
		{
			centre.x -= 200; centre.y -= 100;
			fill_screen(noir);
			tour(centre,red);
		}
	}
	else if (p.y >= centre.y + 150 && p.y <= centre.y + 250)
	{
		if (p.x >= centre.x + 50 && p.x <= centre.x + 150)
		{
			centre.y += 200; centre.x += 100;
			fill_screen(noir);
			tour(centre,red);
		}
		else if (p.x <= centre.x - 50 && p.x >= centre.x - 150)
		{
			centre.y += 200; centre.x -= 100;
			fill_screen(noir);
			tour(centre,red);
		}
	}
	else if (p.y >= centre.y - 250 && p.y <= centre.y - 150)
	{
		if (p.x >= centre.x + 50 && p.x <= centre.x + 150)
		{
			centre.y -= 200; centre.x += 100;
			fill_screen(noir);
			tour(centre,red);
		}
		else if (p.x <= centre.x - 50 && p.x >= centre.x - 150)
		{
			centre.y -= 200; centre.x -= 100;
			fill_screen(noir);
			tour(centre,red);
		}
	}
} */

// Fin du code

wait_escape();
exit(0);
}
