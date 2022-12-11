/*Les cartes seront retournées par un clic de souris
	- charger les cartes 
	- afficher toutes les cartes
	- les afficher dans un écran virtuel
	- les mélanger et leurs attribuer une place d'après la grille de randomcartes
	- déterminer leur position dans l'écran
	- faire une boucle et vérifier la présence de clic
	- si clic, verifier si correspond à une des images
	- si oui, attendre 2e clic de carte
	- verifier si la première carte et la deuxième correspondent à une paire
	- si c'est le cas, garder les cartes tournée, sinon les retourner
*/	

#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include "fonctions.h"

int cartes3(int v,int *visibles,int *grille)
{	
	int acc=20;
	int ntest=0,ntest2=0;
	int x=-10;
	int	y=50;
	int h=150;
	int l=150;
	int go_on=1;
	int i,j,a,place;
	srand(time(NULL));

	char p1_1[]="../img/anemo.png";
	char p2_1[]="../img/cryo.png"; 
	char p3_1[]="../img/dendro.png"; 
	char p4_1[]="../img/electro.png";
	char p5_1[]="../img/geo.png"; 
	char p6_1[]="../img/hydro.png"; 
	char p7_1[]="../img/primo.png";
	char p8_1[]="../img/pyro.png"; 
	char p9_1[]="../img/voeu.png";  
	char p10_1[]="../img/baie.png"; 

	char* tabImages[10]={p1_1,p2_1,p3_1,p4_1,p5_1,p6_1,p7_1,p8_1,p9_1,p10_1};



	if (v==1)
	{
		for(a=0;a<20;a++)
		{
			grille[a]=0;
		}
		
		for(a=0;a<2;a++)
		{
			for (i=1;i<11;i++)
			{
				place = rand()%20;
				if(grille[place]!=0)
				{
					i--;
				}
				else
				{
					grille[place]=i;
				}
			}
		}
	}


	for (j=1;j<5;j++)
	{
		for(i=1;i<6;i++)
		{
			acc=acc-1;
			x+=200;
			ntest2++;
			if (visibles[ntest2-1]!=0)
			{
				ChargerImage("../img/fond_cartes_rouge.png",x,y,0,0,150,150);
				ChargerImage(tabImages[grille[ntest2-1]-1],x+25,y+25,0,0,100,100);
			}
			else
			{
				ChargerImage("../img/dos_cartes_rouge.png",x,y,0,0,150,150);
			}
		}
		y+=200;
		x-=200*5;
	}
    return EXIT_SUCCESS;
}	
	

int CaseCliquee3(int x,int y)
{
	int i,j,x_base=-10,y_base=50;
	for (j=1;j<5;j++)
	{
		for(i=1;i<6;i++)
		{
			x_base+=200;
			if ((x>=x_base)&&(x<=x_base+150)&&(y>=y_base)&&(y<=y_base+150))
			{
				return ((j-1)*5)+i;
			}
		}
		y_base+=200;
		x_base-=200*5;
	}
	return 0;
}

	
void Decouvrir3(int n1,int n2,int *visibles,int *grille)
{
    sleep(1);
    ChargerImageFond("../img/fond_rouge.png");
    ChargerImage("../img/Xiangling.png",1100,205,0,0,400,600);
    ChargerImage("../img/return_button.png",20,20,0,0,128,128);
    visibles[n1]=0;
    visibles[n2]=0;
    cartes3(0,visibles,grille);
}