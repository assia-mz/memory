#include<stdlib.h>
#include<graph.h>

int grille()
{
	int x=50;
	int	y=150;
	int h=150;
	int l=150;
	int i,j;
	
    InitialiserGraphique();
	
    CreerFenetre(10,10,1350,850);
	for (j=1;j<5;j++){
		
		for(i=1;i<5;i++){
			DessinerRectangle ( x+=200, y, l, h );
				
		}
		y+=200;
		x-=200*4;
		
	}
    Touche();
	FermerGraphique();
	return EXIT_SUCCESS;
}

int grille2(){
	int x=50;
	int	y=50;
	int h=150;
	int l=150;
	int i,j;
	
    InitialiserGraphique();
	
    CreerFenetre(10,10,1350,850);
	for (j=1;j<5;j++){
		for(i=1;i<5;i++){
			DessinerRectangle ( x+=150, y, l, h );
		}
		y+=150;
		x-=150*4;
	}
    Touche();
	FermerGraphique();
	return EXIT_SUCCESS;
}
int main (void){
	grille2();
	//grille();
}