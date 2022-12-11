#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include "fonctions.h"

int finjeu(int taille,int *visibles)
{
	// si chaque images est retournée, on renvoie 1
	int i,fin=0;
	for(i=0;i<taille;i++)
	{
		if (visibles[i]!=0)
		{
			fin++;
		}
	}
	if (fin==taille)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}