#include "uvsqgraphics.h"

int main()
{
init_graphics(1280,720);

// Debut du code
int a;
int b;
int c;
int d;
int e;
int f;

/*a=10;
b=20;
c=5;*/
a=lire_entier_clavier();
b=lire_entier_clavier();
c=lire_entier_clavier();

d=a-b-c;
e=(a-b)-c;
f=a-(b-c);

write_int (d);
write_ln();
wait_clic();
write_int(e);
writeln();
wait_clic();
write_int (f);


// Fin du code

wait_escape();
exit(0);
}
