#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NB_LIGNE 3
#define NB_COLONNE 3

#define SCORE_MIN -42
#define SCORE_MAX 42
#define SCORE_NUL 0

#define PROFONDEUR_IA 9

enum Case {VIDE = 0, JOUEUR = 1, IA = 2};

int Max(const int a, const int b);
int Min(const int a, const int b);void initialiserMorpion(void);
int hasard(const int min, const int max);
int compterNbSerieMorpion(const int typeJoueur, const int longueurSerie);
int evaluationIA(void);
void IAMorpionRandom(const int typeJoueur);
int valeurMax(const int profondeur);
int valeurMin(const int profondeur);
void IAMorpion(const int profondeur);
int plateauRempli(void);
int verifierLigneGagnerMorpion(const int typeJoueur);
int verifierColonneGagnerMorpion(const int typeJoueur);
int verifierDiagonaleGagnerMorpion(const int typeJoueur);
int gagnerMorpion(void);
void jeuMorpion(void);

#endif
