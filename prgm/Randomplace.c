#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(){
int grilleeasy[12];
int grillenormal[16];
int grillehard[20];
int i,a,place;	
int indice;
int option=3;

srand(time(NULL));

if(option==1){
    for(a=0;a<12;a++){
    grilleeasy[a]=0;
    }
    	
    for(a=0;a<2;a++){
     for (i=1;i<7;i++){
    	place = rand()%12;
        if(grilleeasy[place]!=0){
        i--;}
        else{grilleeasy[place]=i;}
            }
            }
    
    for(a=0;a<12;a++){
    printf("%d", grilleeasy[a]);
    	printf(" ");
    }
    printf("\n");
}

if(option==2){
    for(a=0;a<16;a++){
    grillenormal[a]=0;
    }
    	
    for(a=0;a<2;a++){
     for (i=1;i<9;i++){
    	place = rand()%16;
        if(grillenormal[place]!=0){
        i--;
        }
        else{grillenormal[place]=i;}
            }
            }
    
    for(a=0;a<16;a++){
    printf("%d", grillenormal[a]);
    	printf(" ");
    }
    printf("\n");
}

if(option==3){
    for(a=0;a<20;a++){
    grillehard[a]=0;
    }
    	
    for(a=0;a<2;a++){
     for (i=1;i<11;i++){
    	place = rand()%20;
        if(grillehard[place]!=0){
        i--;
        }
        else{grillehard[place]=i;}
            }
            }
    
    for(a=0;a<20;a++){
    printf("%d", grillehard[a]);
    	printf(" ");
    }
    printf("\n");
    }
    }