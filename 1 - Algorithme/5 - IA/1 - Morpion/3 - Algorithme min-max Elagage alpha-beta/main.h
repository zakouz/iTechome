#ifndef MAIN_H
#define MAIN_H

#define NB_LIG	3
#define NB_COL	3

#define NB_ALIGNE 3

#define PROFONDEUR_IA 9

#define SCORE_MIN	-42
#define SCORE_MAX	42
#define SCORE_NUL	0

enum casePlateau { VIDE = 0, ADVERSAIRE = 1, IA = 2 };

void initialiserMorpion(int plateau[NB_LIG][NB_COL]);

void afficherMorpion(int plateau[NB_LIG][NB_COL]);
void afficherGagnantMorpion(const int gagnant);

int casePlateau(int plateau[NB_LIG][NB_COL], int lig, int col);
int gagnantMorpion(int plateau[NB_LIG][NB_COL]);

int plateauRempli(int plateau[NB_LIG][NB_COL]);

void faireJouerAdversaire(int plateau[NB_LIG][NB_COL]);

int nbSerieMorpion(int plateau[NB_LIG][NB_COL], int joueur);
int evaluationIA(int plateau[NB_LIG][NB_COL]);
int scoreMax(int plateau[NB_LIG][NB_COL], int profondeur);
int scoreMin(int plateau[NB_LIG][NB_COL], int profondeur);
void faireJouerIA(int plateau[NB_LIG][NB_COL]);

void jeuMorpion(int plateau[NB_LIG][NB_COL]);

#endif
