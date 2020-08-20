#include "uvsqgraphics.h"

int main()
{
init_graphics(900,600);

// Debut du code
int a;
int b;

a = 5;
b = a;
a = a+2;

write_int (b);


// Fin du code

wait_escape();
exit(0);
}
