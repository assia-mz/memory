#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include <time.h>

CreerGrille(int tab, int nbrligne, int nbrcolonne){
	srand(time(NULL));
	int grille = calloc(nbrligne, sizeof(int*));
	for (int c=0;c<nbrcolonne;c++){
		grille[c]=calloc(nbrcolonne, sizeof(int));
		}
	int i;
	int image,ligne, colonne;
	int taille=(nbrcolonne*nbrligne)-1;
	for (ligne=0;ligne<nbrligne;ligne++){
		for (colonne=0;colonne<nbrcolonne;colonne++){
			if (taille>=1){
				image=rand() % taille;
			}
		else {
			image=0;
		}
		grille[ligne][colonne]=tab[image];
		for (i=image;i<taille;i++) {
			tab[i]=tab[i+1];
			}
		taille--;
		}
	}
	return grille;
}