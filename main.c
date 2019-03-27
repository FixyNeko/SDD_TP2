#include "main.h"

#define TAILLE_TEST 6

int main(int argc, char * argv[]) {


	int i;
	pile_t * pile = InitPile(TAILLE_TEST);
	file_t * file = InitFile(TAILLE_TEST);

	printf("entrée: \n");
	printf("Pile pleine (0): %d\n", PILEEstPleine(pile)); // test de pile pleine, doit retourner 0

	for(i = 0; i < TAILLE_TEST + 2; i++) {
		PILEempiler(pile, i); // test d'empilage avec depassement de capacité
	}
	
	printf("Pile pleine (1): %d\n", PILEEstPleine(pile)); // test de pile pleine, doit retourner 1
	
	for(i = 0; i < TAILLE_TEST + 2; i++) {
		element_pile res;
		if(PILEdepiler(pile, &res)) // test de depilage avec depassement de capacité
			printf("%d\n", res);
	}

	printf("\ninversion\n");
	
	for(i = 0; i < TAILLE_TEST; i++) {
		PILEempiler(pile, i); // test d'empilage avec taille normale
	}
	
	printf("File pleine (0): %d\n", FILEEstPleine(file)); // test de file pleine, doit retourner 0

	for(i = 0; i < TAILLE_TEST / 2; i++) { // decale la tête de la file au milieu de sa mémoire
		element_pile res; // teste le retour en debut de la memoire de la file
		FILEentree(file, 0);
		FILEsortie(file, &res);
	}
	printf("tete en position %d sur %d\n", file->RangPremier, file->TailleMax);

	while(!PILEEstVide(pile)) { // etape 1 pour inverser la pile
		element_pile res;
		PILEdepiler(pile, &res);
		FILEentree(file, res);
	}
	
	printf("File pleine (1): %d\n", FILEEstPleine(file)); // test de file pleine, doit retourner 1

	while(!FILEEstVide(file)) {
		element_file res; // etape 2 pour inverser la file
		FILEsortie(file, &res);
		PILEempiler(pile, res);
	}
	
	while(!PILEEstVide(pile)) {
		element_pile res;
		PILEdepiler(pile, &res);
		printf("%d\n", res);
	}


	int tab[] = {1, 2, 3};
	printf("recursif:\n");
	TRUC(0, 3, tab, 0);
	printf("\niteratif:\n");
	TrucIte(0, 3, tab);

	PILEliberer(pile);
	FILEliberer(file);
	return 0;
}