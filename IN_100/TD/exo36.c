#include "uvsqgraphics.h"

int main()
{
init_graphics(1440,800);

// Debut du code
POINT p1;
POINT p2;
POINT p3;
POINT p4;
POINT p5;
POINT p6;
POINT p7;
POINT p8;
POINT p9;
POINT p10;
POINT p;

p1 = wait_clic();
draw_circle(p1,10,rouge);
p2 = wait_clic();
draw_circle(p2,10,rouge);
p3 = wait_clic();
draw_circle(p3,10,rouge);
p4 = wait_clic();
draw_circle(p4,10,rouge);
p5 = wait_clic();
draw_circle(p5,10,rouge);
p6 = wait_clic();
draw_circle(p6,10,rouge);
p7 = wait_clic();
draw_circle(p7,10,rouge);
p8 = wait_clic();
draw_circle(p8,10,rouge);
p9 = wait_clic();
draw_circle(p9,10,rouge);
p10 = wait_clic();
draw_circle(p10,10,rouge);

p = wait_clic();


draw_circle(p1,10,bleu);
draw_circle(p2,10,bleu);
draw_circle(p3,10,bleu);
draw_circle(p4,10,bleu);
draw_circle(p5,10,bleu);
draw_circle(p6,10,bleu);
draw_circle(p7,10,bleu);
draw_circle(p8,10,bleu);
draw_circle(p9,10,bleu);
draw_circle(p10,10,bleu);
// Fin du code

wait_escape();
exit(0);
}
