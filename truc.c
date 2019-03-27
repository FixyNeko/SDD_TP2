#include "truc.h"

void echanger(int i, int j, int * tab) {
	int t = tab[i];
	tab[i] = tab[j];
	tab[j] = t;
}

void TrucIte(int i, int n, int * tab) {
	pile_t * pile = InitPile(TAILLE);
	int fin = 0;
	int j = 0;

	while(!fin) {
		if(j < n) {
			echanger(i, j, tab);
			PILEempiler(pile, j);
			i++;
			j = i;
		} else {
			if(i == (n - 1)) {
				for(j = 0; j < n; j++) {
					printf("%d ", tab[j]);
				}
				printf("\n");
			}
			if(!PILEEstVide(pile)) {
				PILEdepiler(pile, &j);
				i--;
				echanger(i, j, tab);
				j++;
			} else {
				fin = 1;
			}
		}
	}
	PILEliberer(pile);
}

void TRUC(int i, int n, int *tab, int profondeur)
{
	int j;
	int temp;

	for(j = 0; j < profondeur; j++) {
		printf("\t");
	}
	printf("TRUC %d %d [ ", i, n);
	for( j=0; j < n; j++ )
	{
		printf("%d ",tab[j]);
	}
	printf("]\n");

	if( i == (n-1))
	{
		//printf("AFFICHAGE DU TABLEAU POUR I = N\n");
		for(j = 0; j < profondeur; j++) {
			printf("\t");
		}
		printf("sortie: ");
		for( j=0; j < n; j++ )
		{
			printf("%d ",tab[j]);
		}
		printf("\n");
	}
	else
	{
		for(j=i; j<n; j++)
		{
			//printf("AVANT CHANGEMENT N°1 :  %d , %d , %d\n",tab[0],tab[1],tab[2]);
			temp = tab[i];
			tab[i] = tab[j];
			tab[j] = temp;
			//printf("AVANT APPEL RECURSSIF :  %d , %d , %d\n",tab[0],tab[1],tab[2]);
			TRUC(i+1,n,tab, profondeur+1);
			//printf("AVANT CHANGEMENT N°2 :  %d , %d , %d\n",tab[0],tab[1],tab[2]);
			temp = tab[i];
			tab[i] = tab[j];
			tab[j] = temp;
			//printf("A LA FIN DES APPELS :  %d , %d , %d\n",tab[0],tab[1],tab[2]);
		}
	}
}
