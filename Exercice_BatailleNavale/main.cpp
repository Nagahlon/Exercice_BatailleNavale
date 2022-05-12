//Fichier main.cpp
//Version 1.0
//Branch release


#include <stdio.h>
#include <string>
#include <string.h>


#include "TCases.h"
#include "TBateau.h"
#include "TFlotte.h"
#include "Define.h"

void affich(cases* tableau[TAILLE * TAILLE], cases* visee[TAILLE * TAILLE]);


int main() {

	cases* tableau[TAILLE * TAILLE] = {};
	cases* visee[TAILLE * TAILLE] = {};

	flotte equip;

	equip = createFlotte(tableau);

	while (detectFlotte(tableau, visee) == 0) {

		affich(tableau, visee);
		*visee[emplacementVide(visee)] = entreAttack();

	}

	affich(tableau, visee);

	return 0;
}

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

/*affich(tableauVide, tableau); //ca permet de faire un affichage propre

	printf_s("Positionne le Porte Avoion (5 cases)\n"); //Créer un bateau pour le PA

	printf_s("Colonne (X) : ");
	scanf_s("%d", &n_x);

	printf_s("Ligne (Y) : ");
	scanf_s("%d", &n_y);

	printf_s("Vertical (0) ou Horizontal (1) : ");
	scanf_s("%d", &n_v);

	temp.t_porteavion = (bateau*)malloc(sizeof(bateau));
	*temp.t_porteavion = createBateau(tableau, n_y - 1, n_x - 1, n_v, 5);


	affich(tableauVide, tableau);

	printf_s("\nPositionne le Croiseur (4 cases)\n"); //Créer un bateau pour le Cr

	printf_s("Colonne (X) : ");
	scanf_s("%d", &n_x);

	printf_s("Ligne (Y) : ");
	scanf_s("%d", &n_y);

	printf_s("Vertical (0) ou Horizontal (1) : ");
	scanf_s("%d", &n_v);

	temp.t_croiseur = (bateau*)malloc(sizeof(bateau));
	*temp.t_croiseur = createBateau(tableau, n_y - 1, n_x - 1, n_v, 4);


	affich(tableauVide, tableau);

	printf_s("\nPositionne le 1er Sous Marin (3 cases)\n"); //Créer un bateau pour le SM1

	printf_s("Colonne (X) : ");
	scanf_s("%d", &n_x);

	printf_s("Ligne (Y) : ");
	scanf_s("%d", &n_y);

	printf_s("Vertical (0) ou Horizontal (1) : ");
	scanf_s("%d", &n_v);

	temp.t_ssmarin1 = (bateau*)malloc(sizeof(bateau));
	*temp.t_ssmarin1 = createBateau(tableau, n_y - 1, n_x - 1, n_v, 3);


	affich(tableauVide, tableau);

	printf_s("\nPositionne le 2eme Sous Marin (3 cases)\n"); //Créer un bateau pour le SM2

	printf_s("Colonne (X) : ");
	scanf_s("%d", &n_x);

	printf_s("Ligne (Y) : ");
	scanf_s("%d", &n_y);

	printf_s("Vertical (0) ou Horizontal (1) : ");
	scanf_s("%d", &n_v);

	temp.t_ssmarin2 = (bateau*)malloc(sizeof(bateau));
	*temp.t_ssmarin2 = createBateau(tableau, n_y - 1, n_x - 1, n_v, 3);


	affich(tableauVide, tableau);;

	printf_s("\nPositionne le Torpilleur (2 cases)\n"); //Créer un bateau pour le To

	printf_s("Colonne (X) : ");
	scanf_s("%d", &n_x);

	printf_s("Ligne (Y) : ");
	scanf_s("%d", &n_y);

	printf_s("Vertical (0) ou Horizontal (1) : ");
	scanf_s("%d", &n_v);

	temp.t_torpilleur = (bateau*)malloc(sizeof(bateau));
	*temp.t_torpilleur = createBateau(tableau, n_y - 1, n_x - 1, n_v, 2);


	affich(tableauVide, tableau);*/