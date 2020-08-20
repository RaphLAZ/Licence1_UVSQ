#include "uvsqgraphics.h"

#define lar 1000
#define lng 1000
#define radius 20
#define Nb_balle 100
#define hauteur_raquette 10
#define largeur_raquette 200
#define vie 3;
#define option_de_jeu 0;

int plafond = lng;

struct balle
{
	POINT centre;
	int rayon;
	COULEUR coul;
	int dx, dy;
};

typedef struct balle BALLE;

struct raquette
{
	POINT centre; // centre de la raquette
	int largeur; // largeur de la raquette
	int hauteur; // hauteur de la raquette
	COULEUR coul; // couleur de la raquette
};

typedef struct raquette RAQUETTE;

BALLE init_balle(){
	
	BALLE b;
	POINT p;
	
	p.x = lar/2;
	p.y = radius + 50;
	
	b.centre = p;
	b.rayon = radius;
	b.coul = white;
	b.dx = b.dy = 1;
	
	return b;
}

void affiche_balle(BALLE b){
	
	draw_fill_circle(b.centre, b.rayon, b.coul);
}

void efface_balle(BALLE b){
	
	draw_fill_circle(b.centre, b.rayon, black);
}

BALLE deplace_balle(BALLE b){

	b.centre.x += b.dx;
	b.centre.y += b.dy;
	
	return b;
}

BALLE rebond_balle(BALLE b){
	
	if(b.centre.x + radius > lar || b.centre.x - radius < 0){
		b.dx = - b.dx;
	}
	
	if(b.centre.y + radius >= plafond){
		b.dy = - b.dy;
	}
	
	return b;
}

RAQUETTE init_raquette(){
	
	RAQUETTE r;
	
	r.centre.x = lar/2;
	r.centre.y = 5 + hauteur_raquette;
	
	r.largeur = largeur_raquette;
	r.hauteur = hauteur_raquette;
	
	r.coul = white;
	
	return r;
}

void affiche_raquette(RAQUETTE r){
	
	POINT bg, hd;
	
	bg.x = r.centre.x - r.largeur/2; hd.x = r.centre.x + r.largeur/2;
	bg.y = r.centre.y - r.hauteur/2; hd.y = r.centre.y + r.hauteur/2;
	
	draw_fill_rectangle(bg, hd, r.coul);
}

void efface_raquette(RAQUETTE r){
	
	POINT bg, hd;
	
	bg.x = r.centre.x - r.largeur/2; hd.x = r.centre.x + r.largeur/2;
	bg.y = r.centre.y - r.hauteur/2; hd.y = r.centre.y + r.hauteur/2;
	
	draw_fill_rectangle(bg, hd, black);
}

RAQUETTE deplace_raquette(RAQUETTE r, int dx){
	
	
	
	
	if(r.centre.x + 3*dx - r.largeur/2 > 0 && r.centre.x + 3*dx + r.largeur/2 < lar)
		r.centre.x += 3*dx;
	
	return r;
}

int choc_balle_raquette(BALLE b, RAQUETTE r){
	
	if(b.centre.y - b.rayon == r.centre.y + r.hauteur/2){
		if (b.centre.x >= r.centre.x - r.largeur/2 && b.centre.x <= r.centre.x + r.largeur/2){
			return 1;
		}	
	}
	
	return 0;
}

int test_en_jeu(BALLE b){
	
	if(b.centre.y + b.rayon <= 0)
		return 0;
	else
		return 1;
}

int main()
{
	init_graphics(lar,lng);
	
	BALLE b, b2, b3;
	RAQUETTE r;
	POINT direction;
	
	b = init_balle();
	b2 = init_balle();
	b3 = init_balle();
	r = init_raquette();
	
	b2.coul = blue;
	b3.coul = red;
	b2.dy = 2;
	b2.centre.x = lar/3;
	b3.centre.x = 2 * lar/3;
	
	affiche_auto_off();
	
	int score, life, combo, option, deuxieme_balle, troisieme_balle;
	
	deuxieme_balle = 0;
	troisieme_balle = 0;
	score = 0;
	life = vie;
	combo = 0;
	score = 0;
	option = option_de_jeu;
	
	POINT g, d, hg, hd;
	
	hg.x = 0;
	hd.x = lar;
	hg.y = hd.y = plafond;

		
	d.x = lar - 45;
	d.y = lng;
	
	aff_int(life, 50, d, white);
	
	g.x = 0;
	g.y = lng;
	
	aff_int(score, 50, g, white);

	switch (option){
		case 1:
			while(life){
				affiche_balle(b);
				affiche_raquette(r);
				
				affiche_all();
				
				efface_balle(b);
				efface_raquette(r);
				
				direction = get_arrow();
				
				b = deplace_balle(b);
				r = deplace_raquette(r, direction.x);
				
				b = rebond_balle(b);
				
				if (choc_balle_raquette(b, r)){
					b.dy = - b.dy;
					score += 1;
					combo += 1;
					
					if (combo == 10){
						combo = 0;
						life += 1;
						fill_screen(black);
						affiche_balle(b);
						affiche_raquette(r);
						aff_int(life, 50, d, white);
						affiche_all();
					}
					
					fill_screen(black);
				}
				
				if(!test_en_jeu(b)){
					life -= 1;
					fill_screen(black);
					b = init_balle();
				}
					aff_int(life, 50, d, white);
					aff_int(score, 50, g, white);
			}
			break;
		case 2:
			while(life){
				affiche_balle(b);
				
				if(deuxieme_balle == 1){
					affiche_balle(b2);
				}
				
				if(troisieme_balle == 1){
					affiche_balle(b3);
				}
				
				affiche_raquette(r);
				
				affiche_all();
				
				efface_balle(b);
				
				if (deuxieme_balle == 1){
					efface_balle(b2);
				}

				if (troisieme_balle == 1){
					efface_balle(b3);
				}
				

				efface_raquette(r);
				
				b = deplace_balle(b);
				
				if (deuxieme_balle == 1){
					b2 = deplace_balle(b2);
				}
				
				if (troisieme_balle == 1){
					b3 = deplace_balle(b3);
				}
				direction = get_arrow();
				r = deplace_raquette(r, direction.x);
				
				b = rebond_balle(b);
				
				if (deuxieme_balle == 1){
					b2 = rebond_balle(b2);
				}
				
				if (troisieme_balle == 1){
					b3 = rebond_balle(b3);
				}
				
				if (choc_balle_raquette(b, r)){
					b.dy = - b.dy;
					score += 1;
					combo += 1;
					
					if (combo == 3){
						
						if(deuxieme_balle == 0){
							deuxieme_balle = 1;
							b2 = init_balle();
							b2.dy = 2;
							b2.centre.x = lar/3;
							b2.coul = blue;
						}
						if(troisieme_balle == 0){
							troisieme_balle = 1;
							b3 = init_balle();
							b3.coul = red;
							b3.dx = 2;
							b3.centre.x = 2 * lar/3;
						}
						combo = 0;
						
						
	
					}
					
					fill_screen(black);
				}
				
				if (choc_balle_raquette(b2, r)){
					b2.dy = - b2.dy;
					score += 1;
					
					fill_screen(black);
				}
				
				if (choc_balle_raquette(b3, r)){
					b3.dy = - b3.dy;
					score += 1;
					
					fill_screen(black);
				}
				
				if(!test_en_jeu(b2)){
					deuxieme_balle = 0;
				}
				
				if(!test_en_jeu(b3)){
					troisieme_balle = 0;
				}
				
				if(!test_en_jeu(b)){
					if (deuxieme_balle == 0 && troisieme_balle == 0){
						life -= 1;
						combo = 0;
						fill_screen(black);
						b = init_balle();
						printf("COMBO BREAKER\n");
					}
				}
				
				
					aff_int(life, 50, d, white);
					aff_int(score, 50, g, white);
			}
			break;
		case 3:
			while(life){
				affiche_balle(b);
				affiche_raquette(r);
				
				affiche_all();
				
				efface_balle(b);
				efface_raquette(r);
				
				b = deplace_balle(b);
				direction = get_arrow();
				r = deplace_raquette(r, direction.x);
				
				b = rebond_balle(b);
				
				if (choc_balle_raquette(b, r)){
					b.dy = - b.dy;
					score += 1;
					combo += 1;
					b.dx++;
					b.dy++;
					fill_screen(black);
				}
				
				if(!test_en_jeu(b)){
					life -= 1;
					fill_screen(black);
					b = init_balle();
				}
					aff_int(life, 50, d, white);
					aff_int(score, 50, g, white);
			}
			break;
		case 4:
			while(life){
				affiche_balle(b);
				affiche_raquette(r);
				
				affiche_all();
				
				efface_balle(b);
				efface_raquette(r);
				
				b = deplace_balle(b);
				direction = get_arrow();
				r = deplace_raquette(r, direction.x);
				
				b = rebond_balle(b);
				
				if (choc_balle_raquette(b, r)){
					b.dy = - b.dy;
					score += 1;
					combo += 1;
					if(r.largeur >= 2 * radius)
						r.largeur -= 20;
					fill_screen(black);
				}
				
				if(!test_en_jeu(b)){
					life -= 1;
					fill_screen(black);
					b = init_balle();
					r = init_raquette();
				}
					aff_int(life, 50, d, white);
					aff_int(score, 50, g, white);
			}
			break;
		case 5:
			while(life){
				affiche_balle(b);
				affiche_raquette(r);
				affiche_all();
				
				efface_balle(b);
				efface_raquette(r);
				
				b = deplace_balle(b);
				direction = get_arrow();
				r = deplace_raquette(r, direction.x);
				
				b = rebond_balle(b);
				
				if (choc_balle_raquette(b, r)){
					b.dy = - b.dy;
					score += 1;
					combo += 1;
					plafond -= 50;
					hg.y = hd.y = plafond;
					
					fill_screen(black);
					draw_line(hg,hd,white);
					affiche_all();
				}
				
				if(!test_en_jeu(b)){
					life -= 1;
					draw_line(hg,hd,black);
					plafond = lng;
					b = init_balle();
					affiche_all();
				}
					aff_int(life, 50, d, white);
					aff_int(score, 50, g, white);
			}
			break;
		case 6:
			while(life){
				affiche_balle(b);
				affiche_raquette(r);
				
				affiche_all();
				
				efface_balle(b);
				efface_raquette(r);
				
				b = deplace_balle(b);
				direction = get_arrow();
				r = deplace_raquette(r, direction.x);
				
				b = rebond_balle(b);
				
				if (choc_balle_raquette(b, r)){
					b.dy = - b.dy;
					if(b.rayon > 5)
						b.rayon -= 5;
					score += 1;
					combo += 1;
					fill_screen(black);
				}
				
				if(!test_en_jeu(b)){
					life -= 1;
					fill_screen(black);
					b = init_balle();
				}
					aff_int(life, 50, d, white);
					aff_int(score, 50, g, white);
			}
			break;
		default:
			while(life){
				affiche_balle(b);
				affiche_raquette(r);
				
				affiche_all();
				
				efface_balle(b);
				efface_raquette(r);
				
				b = deplace_balle(b);
				direction = get_arrow();
				r = deplace_raquette(r, direction.x);
				
				b = rebond_balle(b);
				
				if (choc_balle_raquette(b, r)){
					b.dy = - b.dy;
					score += 1;
					combo += 1;
					fill_screen(black);
				}
				
				if(!test_en_jeu(b)){
					life -= 1;
					fill_screen(black);
					b = init_balle();
				}
					aff_int(life, 50, d, white);
					aff_int(score, 50, g, white);
			}
	}
	
	
	
	wait_escape();
	exit(0);
}


