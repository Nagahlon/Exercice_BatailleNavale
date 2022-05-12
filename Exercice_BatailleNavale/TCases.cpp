#include "Define.h"
#include "TCases.h"


cases createCase(int n_l, int n_c) {

	cases temp;

	temp.n_lignes = n_l;
	temp.n_colonnes = n_c;

	return temp;

}


int detectCase(cases* tableau[TAILLE * TAILLE], int n_l, int n_c) {

	for (int n_i = 0; n_i < TAILLE * TAILLE; n_i++) { //Vérifie toute la taille du tablo

		if (tableau[n_i] != nullptr) { //On analyse que les case du tableau remplie

			if (tableau[n_i]->n_lignes == n_l && tableau[n_i]->n_colonnes == n_c) {

				return 1;

			}

		}

	}

	return 0; //Return 0 si on a jamais return 1

}


cases entreAttack() {

	cases temp;
	int n_x;
	int n_y;

	printf_s("Coordonnes X : "); //Le X sont les colonnes
	scanf_s("%d", &n_x);

	printf_s("Coordonnes Y : "); //Le y sont les lignes
	scanf_s("%d", &n_y);

	temp.n_colonnes = n_x - 1;
	temp.n_lignes = n_y - 1;

	return temp;

}