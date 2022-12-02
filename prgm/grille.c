#include<stdlib.h>
#include<graph.h>
#include "fonctions.h"

int grille1(void)
{
	int x=100;
	int	y=150;
	int h=150;
	int l=150;
	int i,j;
	for (j=1;j<4;j++){
		for(i=1;i<5;i++){
			DessinerRectangle ( x+=200, y, l, h );
			ChargerImage("../img/dos_cartes_vert.png",x,y,0,0,150,150);
		}
		y+=200;
		x-=200*4;
	}
	return EXIT_SUCCESS;
}

int grille2(void)
{
	int x=100;
	int	y=50;
	int h=150;
	int l=150;
	int i,j;
	for (j=1;j<5;j++){
		for(i=1;i<5;i++){
			DessinerRectangle ( x+=200, y, l, h );
			ChargerImage("../img/dos_cartes_orange.png",x,y,0,0,150,150);
		}
		y+=200;
		x-=200*4;
	}
	return EXIT_SUCCESS;
}

int grille3(void)
{
	int x=-10;
	int	y=50;
	int h=150;
	int l=150;
	int i,j;
	for (j=1;j<5;j++){
		for(i=1;i<6;i++){
			DessinerRectangle ( x+=200, y, l, h );
			ChargerImage("../img/dos_cartes_rouge.png",x,y,0,0,150,150);
		}
		y+=200;
		x-=200*5;
	}
	return EXIT_SUCCESS;
}