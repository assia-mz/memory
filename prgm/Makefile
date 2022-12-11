run : fenetre.o cartes1.o cartes2.o cartes3.o 
	gcc -o run fenetre.o cartes1.o cartes2.o cartes3.o finjeu.o -lgraph

finjeu.o : finjeu.c
	gcc -o finjeu.o -c finjeu.c -lgraph
	
fenetre.o : fenetre.c
	gcc -o fenetre.o -c fenetre.c -lgraph

cartes3.o : affichecartes3.c
	gcc -o cartes3.o -c affichecartes3.c -lgraph

cartes2.o : affichecartes2.c
	gcc -o cartes2.o -c affichecartes2.c -lgraph

cartes1.o : affichecartes1.c affichecartes1.o
	gcc -o cartes1.o -c affichecartes1.c -lgraph

clean :
	rm -f *.o
