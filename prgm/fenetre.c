#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include <string.h>
#include <unistd.h>
#include "fonctions.h"


int main(void)
{
    int pos=1;
    int retour=0;
    int i=0,k,clic,n1,n2,cases;
    int x=190,y=50;
    int grille[20];
    int visibles[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int taille=0;

	InitialiserGraphique();
    CreerFenetre(250,100,1350,850);
    ChargerImageFond("../img/fond_violet.png");
    ChargerImage("../img/start_button.png",550,60,0,0,300,300);
	while(pos==1)
    {
        SourisPosition();
        if (SourisCliquee()&&(_X>=570)&&(_X<=770)&&(_Y>=155)&&(_Y<=225)||retour==1)
        {
            ChargerImageFond("../img/fond_orange.png");
            ChargerImage("../img/difficulty_levels.png",550,200,0,130,230,90);
            ChargerImage("../img/difficulty_levels.png",550,350,274,130,230,90);
            ChargerImage("../img/difficulty_levels.png",550,500,272,270,230,90);
            pos=2;
        }
    	while(pos==2)
    	{
    		SourisPosition();
            if (SourisCliquee())
            {
        		if ((_X>=545)&&(_X<=775)&&(_Y>=195)&&(_Y<=290))
        		{
        			ChargerImageFond("../img/fond_vert.png");
        			ChargerImage("../img/return_button.png",20,20,0,0,128,128);
        			pos=3;
        		}
        		if ((_X>=545)&&(_X<=775)&&(_Y>=345)&&(_Y<=440))
        		{
        			ChargerImageFond("../img/fond_orange2.png");
        			ChargerImage("../img/return_button.png",20,20,0,0,128,128);
        			pos=3;
        		}
        		if ((_X>=545)&&(_X<=775)&&(_Y>=495)&&(_Y<=590))
        		{
        			ChargerImageFond("../img/fond_rouge.png");
        			ChargerImage("../img/return_button.png",20,20,0,0,128,128);
        			cartes3(1,visibles,grille);
        			pos=3;
        		}
            }
        }
        while(pos==3)
        {
            SourisPosition();
            if (SourisCliquee())
            {
                cases=CaseCliquee3(_X,_Y);
                if (cases>0&&cases<=20)
                {
                    n1=cases-1;
                    visibles[n1]=grille[n1];
                    cartes3(0,visibles,grille);
                    pos=4;
                }
                if ((_X>=20)&&(_X<=60)&&(_Y>=20)&&(_Y<=60))
                {
                    pos=1;
                    retour=1;
                }
            }
            while(pos==4)
            {
                SourisPosition();
                if (SourisCliquee())
                {
                    cases=CaseCliquee3(_X,_Y);
                    if (cases>0&&cases<=20&&cases!=n1+1)
                    {
                        n2=cases-1;
                        visibles[n2]=grille[n2];
                        cartes3(0,visibles,grille);
                        pos=5;
                    }
                    if ((_X>=20)&&(_X<=60)&&(_Y>=20)&&(_Y<=60))
                    {
                         pos=1;
                         retour=1;
                    }
                }
                while (pos==5)
                {
                    if (visibles[n1]!=visibles[n2])
                    {
                         Decouvrir3(n1,n2,visibles,grille);
                         pos=3;
                    }
                    else if (visibles[n1]==visibles[n2])
                    {
                         pos=3;
                    }
                    SourisPosition();
                    if (SourisCliquee()&&(_X>=20)&&(_X<=60)&&(_Y>=20)&&(_Y<=60))
                    {
                         pos=1;
                         retour=1;
                    }
                }
            }
        }
    }
	Touche();
    FermerGraphique();
    return EXIT_SUCCESS;
}