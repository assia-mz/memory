#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include "fonctions.h"

int cartes1(int v,int triche,int *visibles,int *grille)
{	
	int acc=12;
	int ntest=0,ntest2=0;
	int x=90;
	int	y=125;
	int h=150;
	int l=150;
	int go_on=1;
	int i,j,a,place;
	srand(time(NULL));

	// initialisation des cartes depuis leur chemin
	char p1_1[]="../img/anemo.png";
	char p2_1[]="../img/cryo.png"; 
	char p3_1[]="../img/dendro.png"; 
	char p4_1[]="../img/electro.png";
	char p5_1[]="../img/geo.png"; 
	char p6_1[]="../img/hydro.png";

	//tableau contenant les chemins des images
	char* tabImages[6]={p1_1,p2_1,p3_1,p4_1,p5_1,p6_1};


	// si on veut créer la grille aléatoirement
	if (v==1)
	{
		for(a=0;a<12;a++)
		{
			grille[a]=0;
		}
		
		for(a=0;a<2;a++)
		{
			for (i=1;i<7;i++)
			{
				place = rand()%12;
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

	// affichage des images ou des dos
	for (j=1;j<4;j++)
	{
		for(i=1;i<5;i++)
		{
			acc=acc-1;
			x+=200;
			ntest2++;
			if (visibles[ntest2-1]!=0||triche==1)
			{
				ChargerImage("../img/fond_cartes_vert.png",x,y,0,0,150,150);
				ChargerImage(tabImages[grille[ntest2-1]-1],x+25,y+25,0,0,100,100);
			}
			else
			{
				ChargerImage("../img/dos_cartes_vert.png",x,y,0,0,150,150);
			}
		}
		y+=200;
		x-=200*4;
	}
    return EXIT_SUCCESS;
}	
	

int CaseCliquee1(int x,int y)
{
	// si une case est cliquée, on renvoie sa position unique dans la grille 
	int i,j,x_base=90,y_base=125;
	for (j=1;j<4;j++)
	{
		for(i=1;i<5;i++)
		{
			x_base+=200;
			if ((x>=x_base)&&(x<=x_base+150)&&(y>=y_base)&&(y<=y_base+150))
			{
				//indice de la case appuyée
				return ((j-1)*4)+i;
			}
		}
		y_base+=200;
		x_base-=200*4;
	}
	return 0;
}

	
void Decouvrir1(int n1,int n2,int *visibles,int *grille)
{
	// on attend une seconde avant d'afficher l'ecran de jeu sans les cartes données en argument
    sleep(1);
    ChargerImageFond("../img/fond_vert.png");
    ChargerImage("../img/Arana.png",40,530,0,0,300,300);
    ChargerImage("../img/Ararycan.png",1040,540,0,0,300,300);
    ChargerImage("../img/voir.png",1270,20,0,0,61,53);
    ChargerImage("../img/return_button.png",20,20,0,0,128,128);
    visibles[n1]=0;
    visibles[n2]=0;
    cartes1(0,0,visibles,grille);
}

