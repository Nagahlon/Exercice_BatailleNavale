#pragma once
#include "Define.h"


typedef struct cases {

	int n_lignes;
	int n_colonnes;

}cases;

cases createCase(int, int);
int detectCase(cases* tableau[TAILLE * TAILLE], int n_l, int n_c);
cases entreAttack();