#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include <string.h>
#include <unistd.h>
#include "fonctions.h"
#define CYCLE 1000000L

void temps(int n)
{
    char buf[100];
    ChoisirEcran(1);
    CopierZone(2,1,0,0,100,50,0,0);
    snprintf(buf,100,"temps : %05d",n);
    EcrireTexte(10,20,buf,0);
    CopierZone(1,0,0,0,100,50,0,0);
}

int main(void)
{
    int pos=1;
    int retour=0;
    int i=0,k,clic,n1,n2,cases;
    int x=190,y=50;
    int grille[20];
    int visibles[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int taille=0;
    unsigned long suivant= Microsecondes()+CYCLE;
    int n=0;
    char txt1[80]="Vous avez purifie les zones de siccite et sauve la foret !";
    char txt2[80]="Les Aranaras remercient nara dore et l'oiseau argente.";
    char txt3[80]="Vous avez battu tous les monstres aux alentours de la ville!";
    char txt4[80]="Les marchands de Liyue vous sont tres reconnaissants.";
    char txt5[80]="Vous avez arrete les Fatui et insere la Dent Etrange.";
    char txt6[80]="Vous obtenez la Lance Dosdragon !";

    int modetricheur=1;
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
        			ChoisirEcran(2);
        			ChargerImageFond("../img/fond_vert.png");
        			ChargerImage("../img/return_button.png",20,20,0,0,50,50);
        			ChargerImage("../img/Arana.png",40,530,0,0,300,300);
        			ChargerImage("../img/Ararycan.png",1040,540,0,0,300,300);
        			for (i=0;i<20;i++)
					{
						visibles[i]=0;
					}
					ChoisirEcran(0);
        			ChargerImageFond("../img/fond_vert.png");
        			ChargerImage("../img/return_button.png",20,20,0,0,50,50);
        			ChargerImage("../img/Arana.png",40,530,0,0,300,300);
        			ChargerImage("../img/Ararycan.png",1040,540,0,0,300,300);
        			cartes1(1,visibles,grille);
					n=0;
        			pos=3;
        		}
        		if ((_X>=545)&&(_X<=775)&&(_Y>=345)&&(_Y<=440))
        		{
        			ChoisirEcran(2);
        			ChargerImageFond("../img/fond_orange2.png");
        			ChargerImage("../img/Zhongli.png",980,260,0,0,550,550);
        			ChargerImage("../img/return_button.png",20,20,0,0,50,50);
        			for (i=0;i<20;i++)
					{
						visibles[i]=0;
					}
					ChoisirEcran(0);
					ChargerImageFond("../img/fond_orange2.png");
					ChargerImage("../img/Zhongli.png",980,260,0,0,550,550);
        			ChargerImage("../img/return_button.png",20,20,0,0,50,50);
        			cartes2(1,visibles,grille);
					n=0;
        			pos=6;
        		}
        		if ((_X>=545)&&(_X<=775)&&(_Y>=495)&&(_Y<=590))
        		{
					ChoisirEcran(2);
					ChargerImageFond("../img/fond_rouge.png");
					ChargerImage("../img/Xiangling.png",1100,205,0,0,400,600);
        			ChargerImage("../img/return_button.png",20,20,0,0,50,50);
					for (i=0;i<20;i++)
					{
						visibles[i]=0;
					}
					ChoisirEcran(0);
					ChargerImageFond("../img/fond_rouge.png");
					ChargerImage("../img/Xiangling.png",1100,205,0,0,400,600);
        			ChargerImage("../img/return_button.png",20,20,0,0,50,50);
        			cartes3(1,visibles,grille);
        			n=0;
        			pos=9;
        		}
            }
			while(pos==3)
			{
				SourisPosition();
				if (SourisCliquee())
				{
					cases=CaseCliquee1(_X,_Y);
					if (cases>0&&cases<=12&&visibles[cases-1]==0)
					{
						n1=cases-1;
						visibles[n1]=grille[n1];
						ChoisirEcran(0);
						cartes1(0,visibles,grille);
						pos=4;
					}
					if ((_X>=20)&&(_X<=70)&&(_Y>=20)&&(_Y<=70))
					{
						ChoisirEcran(0);
						pos=1;
						retour=1;
					}
				}
				else 
				{
					if (Microsecondes()>suivant)
                	{
						cartes1(0,visibles,grille);
	                    n++;
	                    temps(n);
	                    suivant=Microsecondes()+CYCLE;
	                }
	            }
				if (ToucheEnAttente()==1) /* on regarde si il y a des touches dans la pile */
				{
					if ((Touche()==XK_t)&&(modetricheur=1)) /* si la touche est touché pour la première fois*/
					{
						printf("Touché 1\n");
						//Triche1(n1,n2,visibles,grille);
					}
					if ((Touche()==XK_t)&&(modetricheur=2)) /* si la touche est touché pour la deuxième fois*/
					{
						printf("Touché 2\n");
						modetricheur=1;
						pos=3;
						//FinTriche1();
					}
				}
				while(pos==4)
				{
					SourisPosition();
					if (SourisCliquee())
					{
						cases=CaseCliquee1(_X,_Y);
						if (cases>0&&cases<=12&&cases!=n1+1&&visibles[cases-1]==0)
						{
							n2=cases-1;
							visibles[n2]=grille[n2];
							ChoisirEcran(0);
							cartes1(0,visibles,grille);
							pos=5;
						}
						if ((_X>=20)&&(_X<=70)&&(_Y>=20)&&(_Y<=70))
						{
							ChoisirEcran(0);
							pos=1;
							retour=1;
						}
					}
					else 
					{
						if (Microsecondes()>suivant)
	                	{
							cartes1(0,visibles,grille);
		                    n++;
		                    temps(n);
		                    suivant=Microsecondes()+CYCLE;
		                }
		            }
					while (pos==5)
					{
						if (visibles[n1]!=visibles[n2])
						{
							ChoisirEcran(0);
							Decouvrir1(n1,n2,visibles,grille);
							pos=3;
						}
						else if (finjeu(12,visibles)==1)
						{
							ChoisirEcran(0);
							EcrireTexte(600,80,"Bien joue !",2);
							EcrireTexte(600,750,"Victoire !",2);
							sleep(5);
							ChargerImageFond("../img/fond_vert.png");
							EcrireTexte(280,70,txt1,2);
							EcrireTexte(290,120,txt2,2);
							ChargerImage("../img/Aravinay.png",330,500,0,0,300,300);
        					ChargerImage("../img/Arama.png",750,500,0,0,300,300);
        					ChargerImage("../img/return_button.png",20,20,0,0,50,50);
							pos=10;
						}
						else if (visibles[n1]==visibles[n2])
						{
							pos=3;
						}
						while (pos==10)
						{
							SourisPosition();
							if (SourisCliquee()&&(_X>=20)&&(_X<=70)&&(_Y>=20)&&(_Y<=70))
							{
								ChoisirEcran(0);
								pos=1;
								retour=1;
							}
						}
					}
				}
			}
			while(pos==6)
			{
				if (ToucheEnAttente()==1) /* on regarde si il y a des touches dans la pile */
				{
					if ((Touche()==XK_t)&&(modetricheur=1)) /* si la touche est touché pour la première fois*/
					{
						printf("Touché 1\n");
						//Triche2(n1,n2,visibles,grille);
					}
					if ((Touche()==XK_t)&&(modetricheur=2)) /* si la touche est touché pour la deuxième fois*/
					{
						printf("Touché 2\n");
						modetricheur=1;
						pos=6;
						//FinTriche2();
					}
				}

				SourisPosition();
				if (SourisCliquee())
				{
					cases=CaseCliquee2(_X,_Y);
					if (cases>0&&cases<=16&&visibles[cases-1]==0)
					{
						n1=cases-1;
						visibles[n1]=grille[n1];
						ChoisirEcran(0);
						cartes2(0,visibles,grille);
						pos=7;
					}
					if ((_X>=20)&&(_X<=70)&&(_Y>=20)&&(_Y<=70))
					{
						ChoisirEcran(0);
						pos=1;
						retour=1;
					}
				}
				else 
				{
					if (Microsecondes()>suivant)
                	{
						cartes2(0,visibles,grille);
	                    n++;
	                    temps(n);
	                    suivant=Microsecondes()+CYCLE;
	                }
	            }
				while(pos==7)
				{
					SourisPosition();
					if (SourisCliquee())
					{
						cases=CaseCliquee2(_X,_Y);
						if (cases>0&&cases<=16&&cases!=n1+1&&visibles[cases-1]==0)
						{
							n2=cases-1;
							visibles[n2]=grille[n2];
							ChoisirEcran(0);
							cartes2(0,visibles,grille);
							pos=8;
						}
						if ((_X>=20)&&(_X<=70)&&(_Y>=20)&&(_Y<=70))
						{
							ChoisirEcran(0);
							pos=1;
							retour=1;
						}
					}
					else 
					{
						if (Microsecondes()>suivant)
	                	{
							cartes2(0,visibles,grille);
		                    n++;
		                    temps(n);
		                    suivant=Microsecondes()+CYCLE;
		                }
		            }
					while (pos==8)
					{
						if (visibles[n1]!=visibles[n2])
						{
							ChoisirEcran(0);
							Decouvrir2(n1,n2,visibles,grille);
							pos=6;
						}
						else if (finjeu(16,visibles)==1)
						{
							ChoisirEcran(0);
							EcrireTexte(850,235,"Bien joue !",2);
							EcrireTexte(600,635,"Victoire !",2);
							sleep(5);
							ChargerImageFond("../img/fond_orange2.png");
							ChargerImage("../img/Ningguang.png",10,90,0,0,650,650);
							EcrireTexte(400,360,txt3,2);
							EcrireTexte(450,410,txt4,2);
        					ChargerImage("../img/return_button.png",20,20,0,0,50,50);
							pos=20;
						}
						else if (visibles[n1]==visibles[n2])
						{
							pos=6;
						}
						while (pos==20)
						{
							SourisPosition();
							if (SourisCliquee()&&(_X>=20)&&(_X<=70)&&(_Y>=20)&&(_Y<=70))
							{
								ChoisirEcran(0);
								pos=1;
								retour=1;
							}
						}
					}
				}
			}
			while(pos==9)
			{
				SourisPosition();
				if (SourisCliquee())
				{
					cases=CaseCliquee3(_X,_Y);
					if (cases>0&&cases<=20&&visibles[cases-1]==0)
					{
						n1=cases-1;
						visibles[n1]=grille[n1];
						ChoisirEcran(0);
						cartes3(0,visibles,grille);
						pos=10;
					}
					if ((_X>=20)&&(_X<=70)&&(_Y>=20)&&(_Y<=70))
					{
						ChoisirEcran(0);
						pos=1;
						retour=1;
					}
				}
				else 
				{
					if (Microsecondes()>suivant)
                	{
						cartes3(0,visibles,grille);
	                    n++;
	                    temps(n);
	                    suivant=Microsecondes()+CYCLE;
	                }
	            }
				if (ToucheEnAttente()==1) /* on regarde si il y a des touches dans la pile */
				{
					if ((Touche()==XK_t)&&(modetricheur=1)) /* si la touche est touché pour la première fois*/
					{
						printf("Touché 1\n");
						//Triche3(n1,n2,visibles,grille);
					}
					if ((Touche()==XK_t)&&(modetricheur=2)) /* si la touche est touché pour la première fois*/
					{
						printf("Touché 2\n");
						modetricheur=1;
						pos=9;
						//FinTriche3();
					}
				}
				while(pos==10)
				{
					SourisPosition();
					if (SourisCliquee())
					{
						cases=CaseCliquee3(_X,_Y);
						if (cases>0&&cases<=20&&cases!=n1+1&&visibles[cases-1]==0)
						{
							n2=cases-1;
							visibles[n2]=grille[n2];
							ChoisirEcran(0);
							cartes3(0,visibles,grille);
							pos=11;
						}
						if ((_X>=20)&&(_X<=70)&&(_Y>=20)&&(_Y<=70))
						{
							ChoisirEcran(0);
							pos=1;
							retour=1;
						}
					}
					else 
					{
						if (Microsecondes()>suivant)
	                    {
	                        n++;
	                        temps(n);
	                        suivant=Microsecondes()+CYCLE;
	                    }
	                }
					while (pos==11)
					{
						if (visibles[n1]!=visibles[n2])
						{
							ChoisirEcran(0);
							Decouvrir3(n1,n2,visibles,grille);
							pos=9;
						}
						else if (finjeu(20,visibles)==1)
						{
							ChoisirEcran(0);
							EcrireTexte(20,235,"Bien joue !",2);
							EcrireTexte(600,635,"Victoire !",2);
							sleep(5);
							ChargerImageFond("../img/fond_rouge.png");
							ChargerImage("../img/lance.png",570,30,0,0,200,700);
							EcrireTexte(200,760,txt5,2);
							EcrireTexte(280,810,txt6,2);
        					ChargerImage("../img/return_button.png",20,20,0,0,50,50);
							pos=30;
						}
						else if (visibles[n1]==visibles[n2])
						{
							pos=9;
						}
						while (pos==30)
						{
							SourisPosition();
							if (SourisCliquee()&&(_X>=20)&&(_X<=70)&&(_Y>=20)&&(_Y<=70))
							{
								ChoisirEcran(0);
								pos=1;
								retour=1;
							}
						}
					}
				}
			}
		}
    }
	Touche();
    FermerGraphique();
    return EXIT_SUCCESS;
}