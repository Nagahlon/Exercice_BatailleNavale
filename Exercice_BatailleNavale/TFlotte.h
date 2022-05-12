#pragma once
#include "TBateau.h"


typedef struct flotte {

	bateau* t_porteavion;
	bateau* t_croiseur;
	bateau* t_ssmarin1;
	bateau* t_ssmarin2;
	bateau* t_torpilleur;

}flotte;

flotte createFlotte(cases* tableau[TAILLE * TAILLE]);
int detectFlotte(cases* tableau[TAILLE * TAILLE], cases* visee[TAILLE * TAILLE]);