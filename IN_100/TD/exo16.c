#include "uvsqgraphics.h"

int main()
{
init_graphics(1280,720);

// Debut du code
POINT p;
POINT p1;
POINT p2;

p = wait_clic();
p2 = wait_clic();
p1 = wait_clic();

draw_fill_triangle(p,p1,p2,red);


// Fin du code

wait_escape();
exit(0);
}
