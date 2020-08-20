#include "uvsqgraphics.h"

int main()
{
init_graphics(1280,720);

// Debut du code
POINT A;
POINT B;
POINT C;
POINT D;
POINT E;
POINT F;
POINT G;
POINT h;
POINT i;
int k;

h.x = 1; h.y=1;
i.x = 1280; i.y = 720;
k= 0;
while (k<11)
{
G = wait_clic();

draw_fill_rectangle(h,i,noir);

draw_circle(G,100,blanc);

A.x = G.x + 100; A.y = G.y;
B.x = G.x + 50; B.y = G.y + 87;
C.x = G.x - 50; C.y = G.y + 87;
D.x = G.x - 100; D.y = G.y;
E.x = G.x - 50; E.y = G.y - 87;
F.x = G.x + 50; F.y = G.y -87;

draw_line(A,B,red);
draw_line(B,C,red);
draw_line(C,D,red);
draw_line(D,E,red);
draw_line(E,F,red);
draw_line(F,A,red);

k = k+1;
}

// Fin du code

wait_escape();
exit(0);
}
