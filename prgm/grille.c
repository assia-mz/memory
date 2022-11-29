#include<stdlib.h>
#include<graph.h>

int grille(void)
{
	int x=100;
	int	y=50;
	int h=150;
	int l=150;
	int i,j;
	
    InitialiserGraphique();
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

int grille2(void){
	int x=100;
	int	y=50;
	int h=150;
	int l=150;
	int i,j;
	
    InitialiserGraphique();
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
int main (void){
	grille2();
	//grille();
}