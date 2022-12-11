#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include "fonctions.h"

int cartes2(int v,int triche,int *visibles,int *grille)
{	
	int acc=16;
	int ntest=0,ntest2=0;
	int x=90;
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
	char p7_1[]="../img/pyro.png";  
	char p8_1[]="../img/baie.png"; 

	char* tabImages[8]={p1_1,p2_1,p3_1,p4_1,p5_1,p6_1,p7_1,p8_1};



	if (v==1)
	{
		for(a=0;a<16;a++)
		{
			grille[a]=0;
		}
		
		for(a=0;a<2;a++)
		{
			for (i=1;i<9;i++)
			{
				place = rand()%16;
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
		for(i=1;i<5;i++)
		{
			acc=acc-1;
			x+=200;
			ntest2++;
			if (visibles[ntest2-1]!=0||triche==1)
			{
				ChargerImage("../img/fond_cartes_orange.png",x,y,0,0,150,150);
				ChargerImage(tabImages[grille[ntest2-1]-1],x+25,y+25,0,0,100,100);
			}
			else
			{
				ChargerImage("../img/dos_cartes_orange.png",x,y,0,0,150,150);
			}
		}
		y+=200;
		x-=200*4;
	}
    return EXIT_SUCCESS;
}	
	

int CaseCliquee2(int x,int y)
{
	int i,j,x_base=90,y_base=50;
	for (j=1;j<5;j++)
	{
		for(i=1;i<5;i++)
		{
			x_base+=200;
			if ((x>=x_base)&&(x<=x_base+150)&&(y>=y_base)&&(y<=y_base+150))
			{
				return ((j-1)*4)+i;
			}
		}
		y_base+=200;
		x_base-=200*4;
	}
	return 0;
}

	
void Decouvrir2(int n1,int n2,int *visibles,int *grille)
{
    sleep(1);
    ChargerImageFond("../img/fond_orange2.png");
    ChargerImage("../img/Zhongli.png",980,260,0,0,550,550);
    ChargerImage("../img/return_button.png",20,20,0,0,128,128);
    ChargerImage("../img/voir.png",1270,20,0,0,61,53);
    visibles[n1]=0;
    visibles[n2]=0;
    cartes2(0,0,visibles,grille);
}
