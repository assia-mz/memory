/*Les cartes seront retournées par un clic de souris
	- charger les cartes 
	- afficher toutes les cartes
	- les afficher dans un écran virtuel
	- les mélanger et leurs attribuer une place d'après la grille de randomcartes
	- déterminer leur position dans l'écran
	- faire une boucle et vérifier la présence de clic
	- si clic, verifier si correspond à un des sprites
	- si oui, attendre 2e clic de carte
	- verifier si la première carte et la deuxième correspondent à une paire
	- si c'est le cas, garder les cartes tournée, sinon les retourner
*/	

#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include <time.h>
#include "fonctions.h"

int cartes()
{	
	int acc=20;
	int x=-10;
	int	y=50;
	int h=150;
	int l=150;
	int go_on=1;
	int i,j;
	int a=1;
	int place;
	int grille[20];
	srand(time(NULL));


	long int p1_1=ChargerSprite("../img/anemo.png"); //1
	long int p2_1=ChargerSprite("../img/cryo.png"); // 3
	long int p3_1=ChargerSprite("../img/dendro.png"); // 5
	long int p4_1=ChargerSprite("../img/electro.png"); // 7
	long int p5_1=ChargerSprite("../img/geo.png"); // 9
	long int p6_1=ChargerSprite("../img/hydro.png"); // 11
	long int p7_1=ChargerSprite("../img/primo.png"); // 13
	long int p8_1=ChargerSprite("../img/pyro.png"); // 15
	long int p9_1=ChargerSprite("../img/voeu.png"); // 17
	long int p10_1=ChargerSprite("../img/baie.png"); // 18
	long int p1_2=ChargerSprite("../img/anemo.png"); // 2
	long int p2_2=ChargerSprite("../img/cryo.png"); // 4
	long int p3_2=ChargerSprite("../img/dendro.png"); // 6
	long int p4_2=ChargerSprite("../img/electro.png"); // 8
	long int p5_2=ChargerSprite("../img/geo.png"); // 10
	long int p6_2=ChargerSprite("../img/hydro.png"); // 12
	long int p7_2=ChargerSprite("../img/primo.png"); // 14
	long int p8_2=ChargerSprite("../img/pyro.png"); // 16
	long int p9_2=ChargerSprite("../img/voeu.png"); // 19
	long int p10_2=ChargerSprite("../img/baie.png"); //20
	long int dos1_1=ChargerSprite("../img/dos_cartes_rouge.png"); 
	long int dos2_1=ChargerSprite("../img/dos_cartes_rouge.png"); 
	long int dos3_1=ChargerSprite("../img/dos_cartes_rouge.png"); 
	long int dos4_1=ChargerSprite("../img/dos_cartes_rouge.png"); 
	long int dos5_1=ChargerSprite("../img/dos_cartes_rouge.png"); 
	long int dos6_1=ChargerSprite("../img/dos_cartes_rouge.png"); 
	long int dos7_1=ChargerSprite("../img/dos_cartes_rouge.png"); 
	long int dos8_1=ChargerSprite("../img/dos_cartes_rouge.png"); 
	long int dos9_1=ChargerSprite("../img/dos_cartes_rouge.png"); 
	long int dos10_1=ChargerSprite("../img/dos_cartes_rouge.png"); 
	long int dos1_2=ChargerSprite("../img/dos_cartes_rouge.png"); 
	long int dos2_2=ChargerSprite("../img/dos_cartes_rouge.png"); 
	long int dos3_2=ChargerSprite("../img/dos_cartes_rouge.png"); 
	long int dos4_2=ChargerSprite("../img/dos_cartes_rouge.png"); 
	long int dos5_2=ChargerSprite("../img/dos_cartes_rouge.png"); 
	long int dos6_2=ChargerSprite("../img/dos_cartes_rouge.png"); 
	long int dos7_2=ChargerSprite("../img/dos_cartes_rouge.png"); 
	long int dos8_2=ChargerSprite("../img/dos_cartes_rouge.png"); 
	long int dos9_2=ChargerSprite("../img/dos_cartes_rouge.png"); 
	long int dos10_2=ChargerSprite("../img/dos_cartes_rouge.png"); 


	int tabSprite[20]={p1_1,p1_2,p2_1,p2_2,p3_1,p3_2,p4_1,p4_2,p5_1,p5_2,p6_1,p6_2,p7_1,p7_2,p8_1,p8_2,p9_1,p9_2,p10_1,p10_2};
	int tabSpriteDos[20]={dos1_1,dos1_2,dos2_1,dos2_2,dos3_1,dos3_2,dos4_1,dos4_2,dos5_1,dos5_2,dos6_1,dos6_2,dos7_1,dos7_2,dos8_1,dos8_2,dos9_1,dos9_2,dos10_1,dos10_2};

	for(a=0;a<20;a++){
		grille[a]=0;
		}

	for (i=1;i<20;i++){
			place = rand()%20;
			if(grille[place]!=0){
			i--;}
			else{grille[place]=i;}
		}

	for (j=1;j<5;j++){
		for(i=1;i<6;i++){
			acc=acc-1;
			RemplirRectangle(x+=200, y, l, h );
			AfficherSprite(tabSprite[grille[acc]],x+25,y+25);
			AfficherSprite(tabSpriteDos[grille[acc]],x,y);
		}
		y+=200;
		x-=200*5;
	}
    return EXIT_SUCCESS;

}	
	
	

	
