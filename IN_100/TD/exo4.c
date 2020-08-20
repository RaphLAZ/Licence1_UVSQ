#include "uvsqgraphics.h"

int main()
{
init_graphics(1280,720);

// Debut du code
POINT p;
POINT EB;
POINT EH;

p = wait_clic();

draw_circle(p,100,red);

p = wait_clic();

EB.x=0; EB.y=0;
EH.x=1280; EH.y=720;
draw_fill_rectangle(EB,EH,black);

draw_circle(p,100,red);

p = wait_clic();

EB.x=0; EB.y=0;
EH.x=1280; EH.y=720;
draw_fill_rectangle(EB,EH,black);

draw_circle(p,100,red);

p = wait_clic();

EB.x=0; EB.y=0;
EH.x=1280; EH.y=720;
draw_fill_rectangle(EB,EH,black);

draw_circle(p,100,red);

p = wait_clic();

EB.x=0; EB.y=0;
EH.x=1280; EH.y=720;
draw_fill_rectangle(EB,EH,black);

draw_circle(p,100,red);

p = wait_clic();

EB.x=0; EB.y=0;
EH.x=1280; EH.y=720;
draw_fill_rectangle(EB,EH,black);

draw_circle(p,100,red);

p = wait_clic();

EB.x=0; EB.y=0;
EH.x=1280; EH.y=720;
draw_fill_rectangle(EB,EH,black);

draw_circle(p,100,red);

p = wait_clic();

EB.x=0; EB.y=0;
EH.x=1280; EH.y=720;
draw_fill_rectangle(EB,EH,black);

draw_circle(p,100,red);

p = wait_clic();

EB.x=0; EB.y=0;
EH.x=1280; EH.y=720;
draw_fill_rectangle(EB,EH,black);

draw_circle(p,100,red);

p = wait_clic();

EB.x=0; EB.y=0;
EH.x=1280; EH.y=720;
draw_fill_rectangle(EB,EH,black);

draw_circle(p,100,red);





 


// Fin du code

wait_escape();
exit(0);
}
