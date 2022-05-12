#include "Define.h"
#include "Render.h"
#include "TCases.h"
#include "TBateau.h"
#include "TFlotte.h"


void affich(cases* tableau[TAILLE * TAILLE], cases* visee[TAILLE * TAILLE]) {
	system("cls"); //Pour clear l'ecran

	for (int n_i = 0; n_i < TAILLE; n_i++) { //Pour les lignes

		for (int n_j = 0; n_j < TAILLE; n_j++) { //Pour les colonnes

			if (detectCase(visee, n_i, n_j) == 1) { //Si on a deja visee a ces coordonnes

				if (detectCase(tableau, n_i, n_j) == 1) { //Si il y a aussi un bateau ici

					printf_s("X ");

				}
				else { //Si il y a pas de bateau

					printf_s("0 ");

				}

			}
			else { //Si on a pas visee ici, c'est forcement ~

				printf_s("~ ");

			}

		}

		printf_s("  %d", n_i + 1); //Pour ecrire les numeros de lignes sur le cote
		if (n_i == 0) {

			printf(" ligne (Y)");

		}

		printf_s("\n");

	}

	printf_s("\n"); //Pour ecrire les numeros de colonnes sur le cote
	for (int n_i = 1; n_i <= TAILLE; n_i++) {

		printf_s("%d ", n_i);

	}
	printf_s("\ncolonne (X) \n\n");
}