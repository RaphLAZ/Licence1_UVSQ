#include "uvsqgraphics.h"
int a_qui_de_jouer;

void quadrillage()
{
	POINT p1, p2;
	int i,j;
	p1.x = 0; p1.y = 0;

	for (i = 0; i < 300; i+=100)
	{
		for (j = 0; j < 300; j+=100)
		{
			p2.y = 300; p2.x = j;
			p1.y = 0; p1.x = j;
			draw_line(p1,p2,blanc);
		}	
		p2. x = 300; p2.y = i;
		p1.x = 0; p1.y = i;
		draw_line(p1,p2,blanc);
	}
}

void croix(POINT p)
{
	POINT p1,p2;
	p1.x = p.x-25; p1.y = p.y-25;
	p2.x = p.x+25; p2.y = p.y+25;
	draw_line(p1,p2,blanc);
	p1.y += 50; p2.y -= 50;
	draw_line(p1,p2,blanc);
}

void dessine_action(POINT p)
{
	POINT centre;
	if (p.x <= 100 && p.y <= 100)
	{
		centre.x = 50; centre.y = 50;
		if (a_qui_de_jouer == 0)
		{
			croix(centre);
		}
		else 
		{
			draw_circle(centre,25,blanc);
		}
	}
	else if (p.x >= 200 && p.y <= 100)
	{
		centre.x = 250; centre.y = 50;
		if (a_qui_de_jouer == 0)
		{
			croix(centre);
		}
		else 
		{
			draw_circle(centre,25,blanc);
		}
	}
	else if (p.x <= 100 && p.y >= 200)
	{
		centre.x = 50; centre.y = 250;
		if (a_qui_de_jouer == 0)
		{
			croix(centre);
		}
		else 
		{
			draw_circle(centre,25,blanc);
		}
	}
	else if (p.x >= 200 && p.y >= 200)
	{
		centre.x = 250; centre.y = 250;
		if (a_qui_de_jouer == 0)
		{
			croix(centre);
		}
		else 
		{
			draw_circle(centre,25,blanc);
		}
	}
	else if (p.x >= 200 && p.y >= 100 && p.y <= 200)
	{
		centre.x = 250; centre.y = 150;
		if (a_qui_de_jouer == 0)
		{
			croix(centre);
		}
		else 
		{
			draw_circle(centre,25,blanc);
		}
	}
	else if (p.x <= 100 && p.y >= 100 && p.y <= 200)
	{
		centre.x = 50; centre.y = 150;
		if (a_qui_de_jouer == 0)
		{
			croix(centre);
		}
		else 
		{
			draw_circle(centre,25,blanc);
		}
	}
	else if (p.x >= 100 && p.x <= 200 && p.y <= 100)
	{
		centre.x = 150; centre.y = 50;
		if (a_qui_de_jouer == 0)
		{
			croix(centre);
		}
		else 
		{
			draw_circle(centre,25,blanc);
		}
	}
	else if (p.x <= 200 && p.x >= 100 && p.y >= 200)
	{
		centre.x = 150; centre.y = 250;
		if (a_qui_de_jouer == 0)
		{
			croix(centre);
		}
		else 
		{
			draw_circle(centre,25,blanc);
		}
	}
	else
	{
		centre.x = 150; centre.y = 150;
		if (a_qui_de_jouer == 0)
		{
			croix(centre);
		}
		else 
		{
			draw_circle(centre,25,blanc);
		}
	}
}


int main()
{
init_graphics(300,300);

// Debut du code
int i; POINT p;
a_qui_de_jouer = 0;
quadrillage();
for (i = 0; i < 9; i++)
{
	{
		p = wait_clic();
		dessine_action(p);
		a_qui_de_jouer = 1 - a_qui_de_jouer;
	}
}




// Fin du code

wait_escape();
exit(0);
}
