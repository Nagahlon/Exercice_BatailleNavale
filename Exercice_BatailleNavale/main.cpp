//Fichier main.cpp
//Version 1.0
//Branch release


#include <stdio.h>
#include <string>
#include <string.h>


#include "Define.h"
#include "Render.h"
#include "TCases.h"
#include "TBateau.h"
#include "TFlotte.h"


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