#include "uvsqgraphics.h"
COULEUR T1[256]; POINT T2[513][513];

void remplir_gris()
{
	int i;
	for (i = 0; i < 256 ; i++)
	{
		T1[i] = couleur_RGB(i,i,i);
	}
	
}

void horizontale()
{
	int i; POINT p1,p2;
	for (i = 0; i < 256; i++)
	{
		p1.x = i*2; p1.y = 512;
		p2.x = p1.x + 2; p2.y = 0;
		draw_fill_rectangle(p1,p2,T1[i]);
	}
	
}

void verticale()
{
	int i; POINT p1,p2;
	for (i = 0; i < 256; i++)
	{
		p1.x=512; p1.y = i*2;
		p2.x = 0; p2.y = p1.y + 2;
		draw_fill_rectangle(p1,p2,T1[i]);
	}
}
	
void remplir_rouge()
{
	int i;
	for (i = 0; i < 256 ; i++)
	{
		T1[i] = couleur_RGB(i,0,0);
	}
}

void remplir_rouge_bleu()
{
	int i,j; COULEUR c; POINT p1,p2;
	for (i = 0; i < 512; i++)
	{
		for (j = 0; j <512 ; j++)
		{
			p1.x = 2*i; p1.y = 2*j;
			p2.x = 2*i+2; p2.y = 2*j+2;
			c = couleur_RGB(i,0,j);
			draw_rectangle(p1,p2,c);
		}
		
	}
}


int main()
{
init_graphics(512,512);

// Debut du code
remplir_rouge_bleu();


// Fin du code

wait_escape();
exit(0);
}
