#ifndef FONCTIONS
#define FONCTIONS

int cartes1(int v,int triche,int *visibles,int *grille);
int cartes2(int v,int triche,int *visibles,int *grille);
int cartes3(int v,int triche,int *visibles,int *grille);
int CaseCliquee1(int x,int y);
int CaseCliquee2(int x,int y);
int CaseCliquee3(int x,int y);
void Decouvrir1(int n1,int n2,int *visibles,int *grille);
void Decouvrir2(int n1,int n2,int *visibles,int *grille);
void Decouvrir3(int n1,int n2,int *visibles,int *grille);
int finjeu(int taille,int *visibles);

#endif
