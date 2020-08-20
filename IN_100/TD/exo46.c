#include "uvsqgraphics.h"

POINT p; int nbre; COULEUR courante;
void dessine_couleurs()
{
	POINT p1; POINT p2;
	int i = 255;
	p1.x = 1440; p1.y = 0;
	p2.x = 1340; p2.y = 100;
	COULEUR c = couleur_RGB(i,0,0);
	draw_fill_rectangle(p1,p2,c);
	p1.x -= 100;
	p2.x = p1.x - 100;
	c = couleur_RGB(0,i,0);
	draw_fill_rectangle(p1,p2,c);
	p1.x -= 100;
	p2.x = p1.x - 100;
	c = couleur_RGB(0,0,i);
	draw_fill_rectangle(p1,p2,c);
	p1.x -= 100;
	p2.x = p1.x - 100;
	c = couleur_RGB(i,i,i);
	draw_fill_rectangle(p1,p2,c);	
} 

COULEUR choix_couleur(POINT p)
{
	int i = 255;
	if (1340 <= p.x && p.x <= 1440 && 0 <= p.y && p.y <= 100)
	{
		return couleur_RGB(i,0,0);
	}
	else if (((p.x <= 1340)&&(p.x>=1240))&&((p.y<=100)&&(p.y>=0)))
	{
		return couleur_RGB(0,i,0);
	}
	else if (((p.x <= 1240)&&(p.x>=1140))&&((p.y<=100)&&(p.y>=0)))
	{
		return couleur_RGB(0,0,i);
	}
	else if (((p.x <= 1140)&&(p.x>=1040))&&((p.y<=100)&&(p.y>=0)))
	{
		return couleur_RGB(i,i,i);
	}
	else 
	return noir;
	
}

void dessine_cercle()
{
	COULEUR coul;
	p = wait_clic();
	coul = choix_couleur(p);
	if(coul == noir)
	{
		draw_circle(p,30,courante);
		nbre+=1;
	}
	else
	courante = coul;
}
int main()
{
init_graphics(1440,800);

// Debut du code
dessine_couleurs();
courante = blanc;
nbre = 0;
while (nbre < 21) dessine_cercle();



// Fin du code

wait_escape();
exit(0);
}
