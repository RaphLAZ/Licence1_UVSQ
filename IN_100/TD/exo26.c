#include "uvsqgraphics.h"

int main()
{
init_graphics(1280,720);

// Debut du code
POINT p1;
POINT p2;
int x;
POINT p;



x=0;


p1.x=540; p1.y=260;
p2.x=740; p2.y=460;


draw_rectangle(p1,p2,blanc);

while (x<5)
	{
		p=wait_clic();
		if (((p.x<740)&&(p.x>540))&&((p.y<460)&&(p.y>260)))
			{
				draw_fill_rectangle(p1,p2,blanc);
				p=wait_clic();
				if (((p.x<740)&&(p.x>540))&&((p.y<460)&&(p.y>260)))
					{
						draw_fill_rectangle(p1,p2,noir);
						draw_rectangle(p1,p2,blanc);
					}
				else
					{
						wait_escape();
					}
			}
		else
			{
				wait_escape();
			}
	}
		

// Fin du code

wait_escape();
exit(0);
}
