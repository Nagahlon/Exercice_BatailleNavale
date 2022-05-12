#include "Define.h"
#include "TBateau.h"


bateau createBateau(cases* tableau[TAILLE * TAILLE], int n_l, int n_c, int n_r, int n_n) { //n_r est la rotation (Vertical ou Horizontal) //n_n est la longeur de case du bateau

	bateau temp{};

	if (detectBateau(tableau, n_l, n_c, n_r, n_n) == 1) { //Si la position est compromise, on annule
		return temp;
	}

	temp.t_pos = (cases*)malloc(sizeof(cases));
	*temp.t_pos = createCase(n_l, n_c); //Enregistre directement la premiere case de la position du bateau
	tableau[emplacementVide(tableau)] = temp.t_pos; //Puis l'enregiste dans le tablo

	temp.n_rota = n_r; //Enregiste la rotation et la longeur
	temp.n_case = n_n;

	for (int n_i = 1; n_i < n_n; n_i++) { //Repete le nombre de fois la taille du bateau

		if (n_r == 0) { //En fonction de la rotation

			*tableau[emplacementVide(tableau)] = createCase(n_l + n_i, n_c); //Vertical

		}
		else {

			*tableau[emplacementVide(tableau)] = createCase(n_l, n_c + n_i); //Horizontal

		}

	}

	return temp;

}


int detectBateau(cases* tableau[TAILLE * TAILLE], int n_l, int n_c, int n_r, int n_n) {

	for (int n_i = 0; n_i < n_n; n_i++) { //Boucle la longeur du bateau voulu

		if (n_r == 0) { //Dans quel sens on verifie (Vertical / Horizontal)

			if (detectCase(tableau, n_l + n_i, n_c) == 1) {
				return 1; //Return 1 si c'est detecte
			}

		}
		else {

			if (detectCase(tableau, n_l, n_c + n_i) == 1) {
				return 1;
			}

		}

	}

	return 0; //Si toutes les verification sont bonnes, ont renvoie 0

}


int emplacementVide(cases* tableau[TAILLE * TAILLE]) {

	int n_i = 0;

	while (tableau[n_i] != nullptr) { //Incremente tant que les places dans le tablo sont prises

		n_i++;

	}

	tableau[n_i] = (cases*)malloc(sizeof(cases)); //On en profite pour faire un malloc

	return n_i;

}