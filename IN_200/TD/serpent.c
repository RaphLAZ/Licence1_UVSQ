#include <uvsqgraphics.h>

// Définition des différentes formes

#define VIDE 0
#define CERCLE 100
#define CARRE 101
#define CROIX 102

// Définition des types

struct elem {
  int i,j; // position sur le quadrillage de l'élément
  int forme; // vaut VIDE, CERCLE, CARRE ou CROIX
  COULEUR couleur; // vaut bleu, rouge, jaune ou vert
};

typedef struct elem ELEMENT;

struct serpent {
  int longueur; // nombre d'éléments dans le corps du serpent
  ELEMENT corps[200]; // les éléments constitutifs du serpent
  POINT direction; // vaut (0,1) pour haut, (0,-1) pour BAS, (-1,0) pour GAUCHE ou (1,0) pour DROITE
};

typedef struct serpent SERPENT;

// Variables globales
int score;

/************************************************************************************************/
/************************************  FONCTIONS UTILITAIRES ************************************/
/************************************************************************************************/
POINT normaliser_direction(POINT p) {
	POINT d;
	d.x = 0;
	d.y = 0;
	if(p.x > 0) {
		d.x++;
	} else if(p.x < 0) {
		d.x--;
	} else if(p.y > 0) {
		d.y++;
	} else if(p.y < 0) {
		d.y--;
	}
	return d;
}

COULEUR couleur_aleatoire() {
	int aleatoire = alea_int(4);
	if(aleatoire == 0) {
		return bleu;
	} else if(aleatoire == 1) {
		return rouge;
	} else if(aleatoire == 2) {
		return jaune;
	}
	return vert;
}

int forme_aleatoire(int inclureVide) {
	if(!inclureVide) {
		return 100+alea_int(3);
	}
	int nouvelleForme = alea_int(40); // Nous choisissons volontairement de mettre plus de vides que d'éléments.
	if(nouvelleForme == 0) {
		return CERCLE;
	} else if(nouvelleForme == 1) {
		return CARRE;
	} else if(nouvelleForme == 2) {
		return CROIX;
	}
	return VIDE;
}

/************************************************************************************************/
/********************************** FONCTIONS D'INITIALISATION **********************************/
/************************************************************************************************/
void init_jeu(ELEMENT jeu[40][60]) {
	score = 0;
	for(int i = 0 ; i < 40 ; i++) {
		for(int j = 0 ; j < 60 ; j++) {
			jeu[i][j].i = i;
			jeu[i][j].j = j;
			jeu[i][j].forme = forme_aleatoire(TRUE);
			if(jeu[i][j].forme == VIDE) {
				jeu[i][j].couleur = black;
			} else {
				jeu[i][j].couleur = couleur_aleatoire();
			}
		}
	}
}

SERPENT init_serpent(ELEMENT jeu[40][60]) { // Nous avons besoin du jeu en paramètre pour éviter de placer le serpent sur un élément autre que VIDE.
	SERPENT s;
	s.longueur = 1;
	
	ELEMENT tete;
	do { // Tirer une position aléatoire tant que celle-ci n'est pas VIDE.
		tete.i = alea_int(40);
		tete.j = alea_int(60);
	} while(jeu[tete.i][tete.j].forme != VIDE);
	tete.forme = CERCLE;
	tete.couleur = blanc;
	s.corps[0] = tete;
	
	// Direction initiale : Droite
	s.direction.x = 1;
	s.direction.y = 0;
	
	return s;
}

/************************************************************************************************/
/************************************  FONCTIONS D'AFFICHAGE ************************************/
/************************************************************************************************/
void affiche_element(ELEMENT e) {
	if(e.forme == CERCLE) {
		POINT centre;
		centre.x = e.i * 10 + 5;
		centre.y = e.j * 10 + 5;
		draw_fill_circle(centre, 5, e.couleur);
	} else if(e.forme == CARRE || e.forme == VIDE) {
		POINT bg, hd;
		bg.x = e.i * 10;
		bg.y = e.j * 10;
		hd.x = bg.x + 10;
		hd.y = bg.y + 10;
		draw_fill_rectangle(bg, hd, e.couleur);
	} else if(e.forme == CROIX) {
		POINT bg, hg, bd, hd;
		bg.x = e.i * 10;
		bg.y = e.j * 10;
		hg.x = bg.x;
		hg.y = bg.y + 10;
		bd.x = bg.x + 10;
		bd.y = bg.y;
		hd.x = bd.x;
		hd.y = hg.y;
		draw_line(bg, hd, e.couleur);
		draw_line(bd, hg, e.couleur);
	}	
}

void affiche_jeu(ELEMENT jeu[40][60]) {
	for(int i = 0 ; i < 40 ; i++) {
		for(int j = 0 ; j < 60 ; j++) {
			affiche_element(jeu[i][j]);
		}
	}
}

void affiche_serpent(SERPENT s) {
	for(int a = 0 ; a < s.longueur ; a++) {
		affiche_element(s.corps[a]);
	}
}

void affiche_score() {
	// Affichage d'une ligne de séparation entre le plateau de jeu et le score.
	POINT g, d;
	g.x = 0;
	g.y = 601;
	d.x = 400;
	d.y = 601;
	draw_line(g, d, white);
	
	// Affichage du score
	POINT hg, bd;
	hg.x = 10;
	hg.y = 695;
	aff_pol("Score", 30, hg, white);
	hg.y = 655;
	bd.x = 400;
	bd.y = 602;
	draw_fill_rectangle(hg, bd, black);
	aff_int(score, 30, hg, white);
}

/************************************************************************************************/
/**************************************** GESTION DU JEU ****************************************/
/************************************************************************************************/
void fin() {
	wait_escape();
	exit(0);
}

SERPENT change_direction(SERPENT s, POINT p) {
	// p contient-il un déplacement ? Si oui, mettre à jour la direction du serpent.
	p = normaliser_direction(p);
	if(p.x != 0 || p.y != 0) {
		s.direction = p;
	}
	return s;
}


SERPENT deplace_serpent(SERPENT s, ELEMENT jeu[40][60]) {
	s = change_direction(s, get_arrow());
	
	// Chercher l'élément présent sur la prochaine case
	int iNext = s.corps[0].i + s.direction.x,
		jNext = s.corps[0].j + s.direction.y;
	ELEMENT next = jeu[iNext][jNext];
	
	int mange = 0; // Vaudra 1 si le serpent mange la prochaine case.
	if(next.forme != VIDE) {
		mange = 1;
		s.longueur++;
	}
	
	// Déplacer le corps du serpent en commencant par sa queue.
	for(int a = s.longueur - 1 ; a > 0 ; a--) {
		if(mange) {
			// Si le serpent mange, il ne se "déplace" pas mais il faut recopier chaque bout de son corps une case plus loin dans le tableau pour faire de la place pour sa nouvelle tête.
			s.corps[a] = s.corps[a-1];
		} else {
			s.corps[a].i = s.corps[a-1].i;
			s.corps[a].j = s.corps[a-1].j;
		}
	}
	
	// Manger le prochain élément ou déplacer la tête
	if(mange) {
		s.corps[0] = next;
		jeu[iNext][jNext].forme = VIDE;
		jeu[iNext][jNext].couleur = noir;
		score++;
	} else {
		s.corps[0].i += s.direction.x;
		s.corps[0].j += s.direction.y;
	}
	
	return s;
}


SERPENT gerer_serpent(SERPENT s) {
	ELEMENT tete = s.corps[0];
	
	// Quand le serpent heurte les bords de la fenêtre la partie se termine.
	if(tete.i < 0 || tete.i > 39 || tete.j < 0 || tete.j > 59) {
		fin();
	}
	
	// Quand la tête du serpent passe sur un cercle rouge, un carré bleu ou une croix jaune, le serpent meurt et le jeu s'arrête
	if((tete.forme == CERCLE && tete.couleur == rouge)
		|| (tete.forme == CARRE && tete.couleur == bleu)
		|| (tete.forme == CROIX && tete.couleur == jaune)) {
		fin();
	}
	
	// Quand trois éléments de la même forme et de la même couleur se suivent dans le corps du serpent, ils disparaissent et la taille du serpent diminue donc de trois.
	// Remarquons que cela ne peut arriver qu'au niveau de la tête du serpent. Nous n'avons donc pas à parcourir tout le serpent.
	if(s.longueur > 3 && s.corps[2].forme == s.corps[1].forme && s.corps[1].forme == s.corps[0].forme
			&& s.corps[2].couleur == s.corps[1].couleur && s.corps[1].couleur == s.corps[0].couleur) {
			for(int a = 3 ; a < s.longueur ; a++) { // On recopie le corps du serpent trois cases en arrière.
				s.corps[a-3] = s.corps[a];
			}
			s.longueur = s.longueur - 3;
			score += 100;
	}
	
	return s;
}

void repop_aleatoire(ELEMENT jeu[40][60]) {
	if(chrono_lap() > 10.0) {
		int i, j;
		do { // Tirer une position aléatoire tant que celle-ci n'est pas VIDE.
			i = alea_int(40);
			j = alea_int(60);
		} while(jeu[i][j].forme != VIDE);
		jeu[i][j].forme = forme_aleatoire(FALSE);
		jeu[i][j].couleur = couleur_aleatoire();
		chrono_start();
	}
}

int main() {
	ELEMENT jeu[40][60];
	SERPENT s;

	init_graphics(400,700);
	affiche_auto_off();
	
	init_jeu(jeu);
	s = init_serpent(jeu);
	chrono_start();
	while(1)
	{
		affiche_jeu(jeu);
		affiche_serpent(s);
		affiche_score();
		affiche_all();
		attendre(130);
		s = deplace_serpent(s, jeu);
		s = gerer_serpent(s);
		repop_aleatoire(jeu);
	}

	wait_escape();
	exit(0);
}
