#include <stdio.h>
#include <stdlib.h>
#include <graph.h>

int main(void)
{
	InitialiserGraphique();
    CreerFenetre(250,100,1350,850);
    ChargerImageFond("../img/fond_violet.png");
    ChargerImage("../img/start_button.png",550,60,0,0,300,300);
    while(1)
    {
        SourisPosition();
        int x=_X;
        int y=_Y;
        if (SourisCliquee()&&(x>=570)&&(x<=770)&&(y>=155)&&(y<=225))
        {
            ChargerImageFond("../img/fond_orange.png");
            ChargerImage("../img/difficulty_levels.png",550,200,0,130,230,90);
            ChargerImage("../img/difficulty_levels.png",550,350,274,130,230,90);
            ChargerImage("../img/difficulty_levels.png",550,500,272,270,230,90);
            while(1)
            {
                SourisPosition();
                if (SourisCliquee()&&(_X>=545)&&(_X<=775)&&(_Y>=195)&&(_Y<=290))
                {
                    ChargerImageFond("../img/fond_vert.png");
                }
                SourisPosition();
                if (SourisCliquee()&&(_X>=545)&&(_X<=775)&&(_Y>=345)&&(_Y<=440))
                {
                    ChargerImageFond("../img/fond_orange2.png");
                }
                SourisPosition();
                if (SourisCliquee()&&(_X>=545)&&(_X<=775)&&(_Y>=495)&&(_Y<=590))
                {
                    ChargerImageFond("../img/fond_rouge.png");
                }
            }
        }
    }
	Touche();
    FermerGraphique();
    return EXIT_SUCCESS;
}