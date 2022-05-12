#include "Define.h"
#include "TFlotte.h"

flotte createFlotte(cases* tableau[TAILLE * TAILLE])
{
	flotte temp{};
	int n_x;
	int n_y;
	int n_v;

	cases* tableauVide[TAILLE * TAILLE]; //On creer un tableau de case remplie de vide
	for (int n_i = 0; n_i < TAILLE * TAILLE; n_i++) {

		if (tableauVide[n_i] != nullptr) {
			tableauVide[n_i] = (cases*)malloc(sizeof(cases));
			tableauVide[n_i]->n_lignes = 0;
			tableauVide[n_i]->n_colonnes = 0;

		}

	}
	return temp;
}

int detectFlotte(cases* tableau[TAILLE * TAILLE], cases* visee[TAILLE * TAILLE])
{
	int n_j = 0;

	for (int n_i = 0; n_i < TAILLE * TAILLE; n_i++) {

		if (tableau[n_i] != nullptr) {

			if (detectCase(visee, tableau[n_i]->n_lignes, tableau[n_i]->n_colonnes) == 0) {

				return 0;

			}
			else {

				n_j++;

			}
		}
	}

	if (n_j == 16) {

		return 1;

	}
}
