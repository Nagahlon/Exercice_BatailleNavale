#include "Define.h"
#include "TFlotte.h"
#include "Render.h"

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

	affich(tableauVide, tableau); //ca permet de faire un affichage propre

	printf_s("Positionne le Porte-Avions (5 cases)\n"); //Créer un bateau pour le PA

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

	printf_s("\nPositionne le 1er Sous-Marin (3 cases)\n"); //Créer un bateau pour le SM1

	printf_s("Colonne (X) : ");
	scanf_s("%d", &n_x);

	printf_s("Ligne (Y) : ");
	scanf_s("%d", &n_y);

	printf_s("Vertical (0) ou Horizontal (1) : ");
	scanf_s("%d", &n_v);

	temp.t_ssmarin1 = (bateau*)malloc(sizeof(bateau));
	*temp.t_ssmarin1 = createBateau(tableau, n_y - 1, n_x - 1, n_v, 3);


	affich(tableauVide, tableau);

	printf_s("\nPositionne le 2eme Sous-Marin (3 cases)\n"); //Créer un bateau pour le SM2

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


	affich(tableauVide, tableau);

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
