#include "pile.h"

pile_t * InitPile(int TailleMax) {
	pile_t * pile = (pile_t *) malloc(sizeof(pile_t));
	if(pile != NULL) {
		pile->TailleMax = TailleMax;
		pile->RangSommet = 0;
		pile->donnees = (element_pile *) malloc(TailleMax * sizeof(element_pile));
		if(pile->donnees == NULL) {
			free(pile);
			pile = NULL;
		}
	}
	return pile;
}

int PILEEstVide(pile_t * pile) {
	return pile->RangSommet == 0;
}

int PILEEstPleine(pile_t * pile) {
	return pile->RangSommet == pile->TailleMax;
}

int PILEempiler(pile_t * pile, element_pile val) {
	int ok = !PILEEstPleine(pile);
	if(ok) {
		pile->donnees[pile->RangSommet] = val;
		pile->RangSommet++;
	}
	return ok;
}

int PILEdepiler(pile_t * pile, element_pile * res) {
	int ok = !PILEEstVide(pile);
	if(ok) {
		pile->RangSommet--;
		*res = pile->donnees[pile->RangSommet];
	}
	return ok;
}

int PILEsommet(pile_t * pile, element_pile * res) {
	int ok = !PILEEstVide(pile);
	if(ok) {
		*res = pile->donnees[pile->RangSommet - 1];
	}
	return ok;
}

void PILEliberer(pile_t * pile) {
	free(pile->donnees);
	free(pile);
}
