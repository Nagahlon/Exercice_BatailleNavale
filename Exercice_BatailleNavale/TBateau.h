#pragma once
#include "TCases.h"
#include "Define.h"


typedef struct bateau {

	int n_case;
	int n_rota;
	cases* t_pos;

}bateau;

bateau createBateau(cases* tableau[TAILLE * TAILLE], int n_l, int n_c, int n_r, int n_n);
int detectBateau(cases* tableau[TAILLE * TAILLE], int n_l, int n_c, int n_r, int n_n);
int emplacementVide(cases* tableau[TAILLE * TAILLE]);