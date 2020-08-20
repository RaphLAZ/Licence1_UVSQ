#include "uvsqgraphics.h"

int main()
{
init_graphics(1280,720);

// Debut du code
POINT point;

point=wait_clic();

if ((point.x%2==0)&&(point.y%2==0))
	{
		draw_circle(point,50,red);
	}
	else if ((point.x%2==0)&&(point.y%2!=0))
		{
			draw_circle(point,50,jaune);
		}
		else if ((point.x%2!=0)&&(point.y%2==0))
			{
				draw_circle(point,50,bleu);
			}
			else
				{
					draw_circle(point,50,vert);
				}
point=wait_clic();

if ((point.x%2==0)&&(point.y%2==0))
	{
		draw_circle(point,50,red);
	}
	else if ((point.x%2==0)&&(point.y%2!=0))
		{
			draw_circle(point,50,jaune);
		}
		else if ((point.x%2!=0)&&(point.y%2==0))
			{
				draw_circle(point,50,bleu);
			}
			else
				{
					draw_circle(point,50,vert);
				}
point=wait_clic();

if ((point.x%2==0)&&(point.y%2==0))
	{
		draw_circle(point,50,red);
	}
	else if ((point.x%2==0)&&(point.y%2!=0))
		{
			draw_circle(point,50,jaune);
		}
		else if ((point.x%2!=0)&&(point.y%2==0))
			{
				draw_circle(point,50,bleu);
			}
			else
				{
					draw_circle(point,50,vert);
				}

// Fin du code

wait_escape();
exit(0);
}
