#include "uvsqgraphics.h"



int main()
{
	
init_graphics(900,900);

// Debut du code
POINT p;

// par defaut on est en "affiche auto_on"
p = wait_clic();
draw_fill_circle(p,200,blue);
p = wait_clic();
draw_fill_circle(p,200,red);

//on passe en off
affiche_auto_off();
p = wait_clic();
draw_fill_circle(p,200,vert);
p = wait_clic();
draw_fill_circle(p,200,jaune);
//il faut faire une affiche all pour que ca s'affiche.
affiche_all();
//on est toujours en off
p = wait_clic();
draw_fill_circle(p,200,gris);
p = wait_clic();
draw_fill_circle(p,200,orange);
//il faut faire une affiche all pour que ca s'affiche.
affiche_all();

//on repasse en on
affiche_auto_on();
p = wait_clic();
draw_fill_circle(p,200,cyan);
p = wait_clic();
draw_fill_circle(p,200,magenta);


// Fin du code

wait_escape();
exit(0);
}
