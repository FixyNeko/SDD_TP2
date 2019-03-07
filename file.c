#include "file.h"

file_t * InitFile(int TailleMax) {
	file_t * file = (file_t *) malloc(sizeof(file_t));
	if(file != NULL) {
		file->donnees = (element_file *) malloc(sizeof(element_file));
		if(file->donnees == NULL) {
			free(file);
			file = NULL;
		}
		else {
			file->TailleMax = TailleMax;
			file->compteur = 0;
			file->RangPremier = 0;
			file->RangDernier = TailleMax - 1;
		}
	}
	return file;
}

int FILEEstVide(file_t * file) {
	return file->compteur == 0;
}

int FILEEstPleine(file_t * file) {
	return file->compteur == file->TailleMax;
}

int FILEentree(file_t * file, element_file val) {
	int ok = !FILEEstPleine(file);
	if(ok) {
		file->donnees[file->RangDernier] = val;
		file->RangDernier++;
	}
	return ok;
}

int FILEsortie(file_t * file, element_file * res) {
	int ok = !FILEEstVide(file);
	if(ok) {
		file->RangDernier--;
		*res = file->donnees[file->RangDernier];
	}
	return ok;
}

void FILEliberer(file_t * file) {
	free(file->donnees);
	free(file);
}
