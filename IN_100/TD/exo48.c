#include "uvsqgraphics.h"


void dessine_quadrilataire(POINT p1,POINT p2,POINT p3,POINT p4,COULEUR c)
{
	p1 = wait_clic();
	p2 = wait_clic();
	p3 = wait_clic();
	p4 = wait_clic();
	POINT A,B,C,D;
	if (p1.y>=p2.y && p1.y>=p3.y && p1.y>=p4.y) // si p1 en haut
	{
		A = p1;
		if ((p2.x<=p3.x && p2.x>=p4.x) || (p2.x>=p3.x && p2.x<=p4.x))
		{
			D = p2;
			if (p3.x>p4.x)
			{
				B = p4;
				C = p3;
			}
			else
			{
				B = p3;
				C = p4;
			}
		}
		else if ((p3.x<=p2.x && p3.x>=p4.x) || (p3.x>=p2.x && p3.x<=p4.x))
		{
			D = p3;
			if (p2.x>p4.x)
			{
				B = p4;
				C = p2;
			}
			else 
			{
				B = p2;
				C = p4;
			}
		}
		else
		{
			D = p4;
			if (p2.x>p3.x)
			{
				B = p3;
				C = p2;
			}
			else
			{
				B = p2;
				C = p3;
			}
		}
	}
	else if (p2.y>=p1.y && p2.y>=p3.y && p2.y>=p4.y) // si p2 e haut
	{
		A = p2;
		if ((p1.x<=p3.x && p1.x>=p4.x) || (p1.x>=p3.x && p1.x<=p4.x))
		{
			D = p1;
			if (p3.x>p4.x)
			{
				B = p4;
				C = p3;
			}
			else
			{
				B = p3;
				C = p4;
			}
		}
		else if ((p3.x<=p1.x && p3.x>=p4.x) || (p3.x>=p1.x && p3.x<=p4.x))
		{
			D = p3;
			if (p1.x>p4.x)
			{
				B = p4;
				C = p1;
			}
			else 
			{
				B = p1;
				C = p4;
			}
		}
		else
		{
			D = p4;
			if (p1.x>p3.x)
			{
				B = p3;
				C = p1;
			}
			else
			{
				B = p1;
				C = p3;
			}
		}
	}
	else if (p3.y>=p1.y && p3.y>=p2.y && p3.y>=p4.y) // si p3 en haut
	{
		A = p3;
		if ((p2.x<=p1.x && p2.x>=p4.x) || (p2.x>=p1.x && p2.x<=p4.x))
		{
			D = p2;
			if (p1.x>p4.x)
			{
				B = p4;
				C = p1;
			}
			else
			{
				B = p1;
				C = p4;
			}
		}
		else if ((p1.x<=p2.x && p1.x>=p4.x) || (p1.x>=p2.x && p1.x<=p4.x))
		{
			D = p1;
			if (p2.x>p4.x)
			{
				B = p4;
				C = p2;
			}
			else 
			{
				B = p2;
				C = p4;
			}
		}
		else
		{
			D = p4;
			if (p2.x>p1.x)
			{
				B = p1;
				C = p2;
			}
			else
			{
				B = p2;
				C = p1;
			}
		}
	}
	else     										// si p4 en haut
	{	
		A = p4;
		if ((p2.x<=p3.x && p2.x>=p1.x) || (p2.x>=p3.x && p2.x<=p1.x))
		{
			D = p2;
			if (p3.x>p1.x)
			{
				B = p1;
				C = p3;
			}
			else
			{
				B = p3;
				C = p1;
			}
		}
		else if ((p3.x<=p2.x && p3.x>=p1.x) || (p3.x>=p2.x && p3.x<=p1.x))
		{
			D = p3;
			if (p2.x>p1.x)
			{
				B = p1;
				C = p2;
			}
			else 
			{
				B = p2;
				C = p1;
			}
		}
		else
		{
			D = p1;
			if (p2.x>=p3.x)
			{
				B = p3;
				C = p2;
			}
			else
			{
				B = p2;
				C = p3;
			}
		}
	}
	
	
	if (D.y>=C.y && D.y>=B.y)
	{
		if (D.x<=A.x)
		{
			draw_line(A,D,c);
			draw_line(D,B,c);
			draw_line(C,B,c);
			draw_line(C,A,c);
		}
		else
		{
			draw_line(A,D,c);
			draw_line(D,C,c);
			draw_line(C,B,c);
			draw_line(B,A,c);
		}
	}
	else
	{	
		draw_line(A,B,c);
		draw_line(A,C,c);
		draw_line(C,D,c);
		draw_line(B,D,c);
	}
}

int main()
{
init_graphics(1440,800);

// Debut du code
POINT p1,p2,p3,p4; int i;

for (i = 0; i < 10 ; i++)
{
	dessine_quadrilataire(p1, p2, p3, p4, red);
}



// Fin du code

wait_escape();
exit(0);
}
