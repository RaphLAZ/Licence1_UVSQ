#include "uvsqgraphics.h"

int main()
{
init_graphics(900,600);

// Debut du code
int a;
int b;
int c;
int d;

a=5;
b=3;
c=a/b;
d=a%b;


write_int (c);
wait_clic();
write_int (d);


// Fin du code

wait_escape();
exit(0);
}
