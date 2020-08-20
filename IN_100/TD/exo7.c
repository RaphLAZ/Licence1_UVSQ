#include "uvsqgraphics.h"

int main()
{
init_graphics(900,600);

// Debut du code
int a;
int b;

a=(10/3)*3;
b=(10*3)/3;


write_int (a);
wait_clic();
write_int (b);


// Fin du code

wait_escape();
exit(0);
}
