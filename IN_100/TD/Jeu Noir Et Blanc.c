#include "uvsqgraphics.h"
int plateau[800][800],i,j;

void intro()
{
	POINT p,p1,p2,centre; int k;

	centre.x = 400; centre.y = 600;
	aff_pol_centre("Jeu noir et blanc", 42 , centre , blanc);
	p1.x = 350; p1.y = 375;
	p2.x = 450; p2.y = 425;
	draw_fill_rectangle(p1,p2,blanc);
	centre.x = 400; centre.y = 400;
	aff_pol_centre("play",30,centre,noir);
	k = 0;
	while (k==0)
	{
		p1.x = 350; p1.y = 375;
		p2.x = 450; p2.y = 425;
		p = wait_clic();
		if (p.x <= p2.x && p.x >= p1.x && p.y >= p1.y && p.y <= p2.y)
		{
			draw_fill_rectangle(p1,p2,noir);
			draw_rectangle(p1,p2,blanc);
			centre.x = 400; centre.y = 400;
			aff_pol_centre("play",30,centre,blanc);
			k += 1;
			attendre(200);
			fill_screen(noir);
		}
		else
		{
		}
	}
}

void affiche_plateau()
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
	POINT p; 
	for (i = 40; i < 800; i+= 80)
	{
		for (j = 40; j < 800; j+=80)
		{
			p.x = j; p.y = i;
			
			plateau[i][j] = alea_int(2);
			
			if (plateau[i][j] == 1)
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

void modifie_plateau(POINT p)
{
	p = wait_clic();
	POINT p1,p2;
	for (i = 0; i < 800; i+= 80)
	{
		for (j = 0; j < 800 ; j+= 80)
		{
			p1.x= j; p1.y = i;
			p2.x= j+ 80; p2.y = i+80;
			if (p1.x<=p.x && p.x<=p2.x && p1.y<=p.y && p.y<=p2.y)
			{
				p.x = p1.x + 40; p.y = p1.y + 40;
				plateau[p.y][p.x] = 1 - plateau[p.y][p.x];
				if (plateau[p.y][p.x] == 1)
				{
					draw_fill_circle(p,30,noir);
					draw_circle(p,30,blanc);
				}
				else
				{
					draw_fill_circle(p,30,blanc);
				}
				p.y += 80;
				if (p.y < 800)
				{
					plateau[p.y][p.x] = 1 - plateau[p.y][p.x];
					if (plateau[p.y][p.x] == 1)
					{
						draw_fill_circle(p,30,noir);
						draw_circle(p,30,blanc);
					}
					else
					{
						draw_fill_circle(p,30,blanc);
					}
				}
				p.y -= 160;
				if (0 < p.y)	
				{
					plateau[p.y][p.x] = 1 - plateau[p.y][p.x];
					if (plateau[p.y][p.x] == 1)
					{
						draw_fill_circle(p,30,noir);
						draw_circle(p,30,blanc);
					}
					else
					{
						draw_fill_circle(p,30,blanc);
					}
				}
				p.x += 80; p.y += 80;
				if (p.x<800)
				{
					plateau[p.y][p.x] = 1 - plateau[p.y][p.x];
					if (plateau[p.y][p.x] == 1)
					{
						draw_fill_circle(p,30,noir);
						draw_circle(p,30,blanc);
					}
					else
					{
						draw_fill_circle(p,30,blanc);
					}
				}
				p.x -= 160;
				if (0 < p.x)
				{
					plateau[p.y][p.x] = 1 - plateau[p.y][p.x];
					if (plateau[p.y][p.x] == 1)
					{
						draw_fill_circle(p,30,noir);
						draw_circle(p,30,blanc);
					}
					else
					{
						draw_fill_circle(p,30,blanc);
					}
				}
			}
		}
		
	}
}

int encore()
{
	int k,l;
	k = 0;
	l = 0;
	for (i = 40; i < 800; i+= 80)
	{
		for (j = 40; j < 800; j+=80)
		{
			
			if (plateau[i][j] == 1)
			{
				k +=1;
			}
			else
			{
				l +=1;
			}
		}
		
	}
	if (k == 100 || l == 100)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void jeu()
{
	POINT p; int j,k;

intro();
affiche_plateau();
initialise_plateau();
k = encore();
j = 0;
while (k != 0)
{
	modifie_plateau(p);
	k = encore();
	j += 1;
	if (j >= 100)
	{
		k = 0;
	}
	else
	{
	}
}
}


int main()
{
init_graphics(800,800);

// Debut du code

jeu();



// Fin du code

wait_escape();
exit(0);
}
