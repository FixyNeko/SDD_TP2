#include "main.h"

int main(int argc, char * argv[]) {

	int i;
	file_t * pile = InitFile(9);

	printf("empiler: \n");

	for(i = 0; i < 5; i++) {
		FILEentree(pile, i);
		printf("%d\n", i);
	}

	while(!FILEEstVide(pile)) {
		int t;
		FILEsortie(pile, &t);
		printf("%d\n", t);
	}

	return 0;
}