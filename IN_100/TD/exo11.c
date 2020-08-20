#include "uvsqgraphics.h"

int main()
{
init_graphics(1280,720);

// Debut du code
POINT a;
POINT b;
POINT c;

a.x=100; b.x=100;
a.y = lire_entier_clavier();
b.y = lire_entier_clavier();

draw_circle(a,5,red);
draw_circle(b,5,red);
draw_line(a,b,red);

c.x= lire_entier_clavier();
c.y= b.y+((a.y-b.y)/2);
draw_line(a,c,red);
draw_line(b,c,red);
draw_circle(c,5,red);


// Fin du code

wait_escape();
exit(0);
}
