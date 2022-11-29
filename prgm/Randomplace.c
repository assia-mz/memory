#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(){
int grilleeasy[3][4];
int grillenormal[4][4];
int grillehard[4][5];
int grille1[12];
int grille2[16];
int grille3[20];
int i,j,a,place;
int ajt=0;
int indice;
int option=3;

srand(time(NULL));

if(option==1){
    for(a=0;a<12;a++){
    grille1[a]=0;
    }
    	
    for(a=0;a<2;a++){
     for (i=1;i<7;i++){
    	place = rand()%12;
        if(grille1[place]!=0){
        i--;}
        else{grille1[place]=i;}
            }
            }
            
    for (i=0;i<4;i++){
        for(j=0;j<3;j++){
            grilleeasy[i][j]=grille1[ajt];
            ajt++;
        }
    }
    
    for (i=0;i<4;i++){
        for(j=0;j<3;j++){
            printf("%4d",grilleeasy[i][j]);
                }
        printf("\n");
        }
    printf("\n");
}

if(option==2){
    for(a=0;a<16;a++){
    grille2[a]=0;
    }
    	
    for(a=0;a<2;a++){
     for (i=1;i<9;i++){
    	place = rand()%16;
        if(grille2[place]!=0){
        i--;
        }
        else{grille2[place]=i;}
            }
            }
    
    for(a=0;a<16;a++){
    printf("%d", grille2[a]);
    	printf(" ");
    }
    printf("\n");
    
    for (i=0;i<4;i++){
        for(j=0;j<4;j++){
            grillenormal[i][j]=grille2[ajt];
            ajt++;
        }
    }
    
    for (i=0;i<4;i++){
        for(j=0;j<4;j++){
            printf("%4d",grillenormal[i][j]);
                }
        printf("\n");
        }
    printf("\n");
}


if(option==3){
    for(a=0;a<20;a++){
    grille3[a]=0;
    }
    	
    for(a=0;a<2;a++){
     for (i=1;i<11;i++){
    	place = rand()%20;
        if(grille3[place]!=0){
        i--;
        }
        else{grille3[place]=i;}
            }
            }
    
    for(a=0;a<20;a++){
    printf("%d", grille3[a]);
    	printf(" ");
    }
    printf("\n");
    
    for (i=0;i<4;i++){
        for(j=0;j<5;j++){
            grillehard[i][j]=grille3[ajt];
            ajt++;
        }
    }
    
    for (i=0;i<4;i++){
        for(j=0;j<5;j++){
            printf("%4d",grillehard[i][j]);
                }
        printf("\n");
        }
    printf("\n");
    }

}

    