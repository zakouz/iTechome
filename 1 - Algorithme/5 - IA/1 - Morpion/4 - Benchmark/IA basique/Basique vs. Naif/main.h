#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NB_LIGNE 3
#define NB_COLONNE 3

enum Case {VIDE = 0, JOUEUR = 1, IA = 2};

void initialiserMorpion(void);
int hasard(const int min, const int max);
int peutGagnerMorpion(const int typeJoueur, int *lig, int *col);
void IAMorpionRandom(const int typeJoueur);
void IAMorpionNaif(const int typeJoueur);
int plateauRempli(void);
int verifierLigneGagnerMorpion(const int typeJoueur);
int verifierColonneGagnerMorpion(const int typeJoueur);
int verifierDiagonaleGagnerMorpion(const int typeJoueur);
int gagnerMorpion(void);
void jeuMorpion(void);

#endif
