#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int grille(){

	int a=0, acc=0, place, i, j=1,x=0;
	int grille[20];
	srand(time(NULL));

	for(a=0;a<20;a++){
		grille[a]=0;
		}

	for (i=1;i<20;i++){
			place = rand()%20;
			if(grille[place]!=0){
			i--;}
			else{grille[place]=i;}
		}
	
	return grille;

		}

