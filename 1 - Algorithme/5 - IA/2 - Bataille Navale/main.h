#ifndef MAIN_H
#define MAIN_H

#define NB_LIG		10
#define NB_COL		10

#define NB_BATEAU 	5

#define TAILLE_MAX	256

enum casePlateau { VIDE = 0, ADVERSAIRE = 1, IA = 2, RATE = 3, TOUCHE = 4, EXPLORE = 5 };
enum direction { HAUT = 0, BAS = 1, GAUCHE = 2, DROITE = 3 };
enum jeu { CHASSE = 0, CIBLE = 1 };

typedef struct bateau bateau;
struct bateau
{
	const char *nom;
	const int longueur;
};

void initialiserPlateau(int plateau[NB_LIG][NB_COL]);

void afficherPlateau(int plateau[NB_LIG][NB_COL]);

int estSurPlateau(int plateau[NB_LIG][NB_COL], int joueur);
int gagnantBatailleNavale(int plateau[NB_LIG][NB_COL]);
void afficherGagnant(int gagnant);

void viderBuffer(void);
int aleatoire(int min, int max);

int estPositionValide(int plateau[NB_LIG][NB_COL], 
	int ligne, int colonne, int direction, int longueur);
void placerBateau(int plateau[NB_LIG][NB_COL], int joueur, 
	int ligne, int colonne, int direction, int longueur);
void emplacementBateauAdversaire(int plateau[NB_LIG][NB_COL]);
void emplacementBateauIA(int plateau[NB_LIG][NB_COL], int plateauIA[NB_LIG][NB_COL]);

void faireJouerAdversaire(int plateau[NB_LIG][NB_COL]);

void alentourCase(int plateauIA[NB_LIG][NB_COL], int ligne, int colonne);
void caseAexplorer(int plateauIA[NB_LIG][NB_COL], int *ligne, int *colonne);
void faireJouerIA(int plateau[NB_LIG][NB_COL], int plateauIA[NB_LIG][NB_COL]);

void jeuBatailleNavale(void);

#endif
