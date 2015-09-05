#ifndef MAIN_H
#define MAIN_H

#define NB_LIG	3
#define NB_COL	3

#define NB_ALIGNE 3

enum casePlateau { VIDE = 0, ADVERSAIRE = 1, IA = 2 };

void initialiserMorpion(int plateau[NB_LIG][NB_COL]);

void afficherMorpion(int plateau[NB_LIG][NB_COL]);
void afficherGagnantMorpion(const int gagnant);

int casePlateau(int plateau[NB_LIG][NB_COL], int lig, int col);
int gagnantMorpion(int plateau[NB_LIG][NB_COL]);

int plateauRempli(int plateau[NB_LIG][NB_COL]);
int aleatoire(int min, int max);

void faireJouerAdversaire(int plateau[NB_LIG][NB_COL]);

int peutGagner(int joueur, int plateau[NB_LIG][NB_COL], int *lig, int *col);
void faireJouerIA(int plateau[NB_LIG][NB_COL]);

void jeuMorpion(int plateau[NB_LIG][NB_COL]);

#endif
