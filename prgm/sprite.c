#include <stdio.h>  
#include <stdlib.h>
#include <graph.h>

int main(void){

	int p1,i,j;
	int x=10;
	int y=10;
	int acc=0;
	/*
	InitialiserGraphique();
    CreerFenetre(250,100,1350,850);
   	p1=ChargerSprite("../img/anemo.png");

   	for(i=0;i<10;i++){
    AfficherSprite(p1,x,y);
	x=x+10;
	y=y+10;
	}*/

	for (j=1;j<5;j++){
		for(i=1;i<6;i++){
			acc=acc+1;
			printf("%d",acc);
			printf(" - ");
			printf("%d", acc-1);
		}
		y+=200;
		x-=200*5;
	}
/*
	Touche();
	FermerGraphique(); */
	return EXIT_SUCCESS;
	}