#include <stdio.h>
#include <stdlib.h>
#include <graph.h>

int main(void){
	InitialiserGraphique();
    CreerFenetre(250,100,1350,850);
    ChargerImageFond("../img/fond.png");
    ChargerImage("../img/start_button.png",550,60,0,0,300,300);
	ChargerImageFond("../img/fond2.png");
	ChargerImage("../img/difficulty_levels.png",550,200,0,130,230,90);
	ChargerImage("../img/difficulty_levels.png",550,350,274,130,230,90);
	ChargerImage("../img/difficulty_levels.png",550,500,272,270,230,90);
	Touche();
    FermerGraphique();
    return EXIT_SUCCESS;
}