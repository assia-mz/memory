#include <stdio.h>
#include <stdlib.h>
#include <graph.h>

int main(void){
	InitialiserGraphique();
    CreerFenetre(250,100,1350,850);
    ChargerImageFond("../img/fond.png");
	Touche();
    FermerGraphique();
    return EXIT_SUCCESS;
}