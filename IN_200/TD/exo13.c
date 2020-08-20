#include "uvsqgraphics.h"
#define taille 512

COULEUR T2[256][256];

void remplir_aleatoire(){
	int i, j;
	for(i = 0; i < 256; i++)
		for(j = 0; j < 256; j++)
			T2[i][j] = couleur_RGB(alea_int(256), alea_int(256), alea_int(256));
}

void afficher_tableau(){
	int i, j;
	POINT P1, P2;
	for(i = 0; i < 256; i++){
		P1.y = 2 * i;
		P2.y = P1.y + 1;
		for(j = 0; j < 256; j++){
			P1.x = 2 * j;
			P2.x = P1.x + 1;
			draw_rectangle(P1, P2, T2[i][j]);
		}
	}
}

int main(){
	init_graphics(taille,taille);
	affiche_auto_off();

	remplir_aleatoire();
	afficher_tableau();

	wait_escape();
	exit(0);
}
