#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"

int baseDirection[4][2] = 
{
	{-1, 0},
	{1, 0},
	{0, -1},
	{0, 1}
};

bateau baseBateau[NB_BATEAU] = 
{
	{"porte-avions", 5},
	{"croiseur", 4},
	{"contre-torpilleurs", 3},
	{"sous-marin", 3},
	{"torpilleur", 2}
};

void initialiserPlateau(int plateau[NB_LIG][NB_COL])
{
	int indexLig, indexCol;

	for(indexLig = 0; indexLig < NB_LIG; ++indexLig)
		for(indexCol = 0; indexCol < NB_COL; ++indexCol)
			plateau[indexLig][indexCol] = VIDE;
}

void afficherPlateau(int plateau[NB_LIG][NB_COL])
{
	int indexLig, indexCol;

	printf("     1  2  3  4  5  6  7  8  9  10\n\n");

	for(indexLig = 0; indexLig < NB_LIG; ++indexLig)
	{
		printf("%2d  ", indexLig + 1);

		for(indexCol = 0; indexCol < NB_COL; ++indexCol)
		{
			switch(plateau[indexLig][indexCol])
			{
				case ADVERSAIRE:
					printf(" | ");
					break;
				case RATE:
					printf(" X ");
					break;
				case TOUCHE:
					printf(" O ");
					break;
				default :
					printf(" ~ ");
					break;
			}
		}

		putchar('\n');
	}

	putchar('\n');
}

int estSurPlateau(int plateau[NB_LIG][NB_COL], int joueur)
{
	int indexLig, indexCol;

	for(indexLig = 0; indexLig < NB_LIG; ++indexLig)
		for(indexCol = 0; indexCol < NB_COL; ++indexCol)
			if(plateau[indexLig][indexCol] == joueur)
				return 1;

	return 0;
}

int gagnantBatailleNavale(int plateau[NB_LIG][NB_COL])
{
	if(estSurPlateau(plateau, IA) == 0)
		return ADVERSAIRE;
	else if(estSurPlateau(plateau, ADVERSAIRE) == 0)
		return IA;

	return VIDE;
}

void afficherGagnant(int gagnant)
{
	switch(gagnant)
	{
		case VIDE :
			puts("Match nul !");
			break;
		case ADVERSAIRE :
			puts("Vous avez gagne !");
			break;
		case IA :
			puts("Vous avez perdu !");
			break;
		default :
			break;
	}
}

void viderBuffer(void)
{
	int lettre;
		    
	lettre = 0;
	    
	while(lettre != '\n' && lettre != EOF)		
	        lettre = getchar();
}

int aleatoire(int min, int max)
{
	return (rand() % (max - min + 1)) + min;
}

int estPositionValide(int plateau[NB_LIG][NB_COL], 
	int ligne, int colonne, int direction, int longueur)
{
	int indexLongueur;
	int indexLig, indexCol;

	indexLig = ligne;
	indexCol = colonne;

	for(indexLongueur = 0; indexLongueur < longueur; ++indexLongueur)
	{
		if(	indexLig >= 0 && indexLig < NB_LIG && 
			indexCol >= 0 && indexCol < NB_COL &&
			plateau[indexLig][indexCol] == VIDE)
		{
			indexLig += baseDirection[direction][0];
			indexCol += baseDirection[direction][1];
		}
		else
			return 0;
	}

	return 1;
}

void placerBateau(int plateau[NB_LIG][NB_COL], int joueur, 
	int ligne, int colonne, int direction, int longueur)
{
	int indexLongueur;
	int indexLig, indexCol;

	indexLig = ligne;
	indexCol = colonne;

	for(indexLongueur = 0; indexLongueur < longueur; ++indexLongueur)
	{
		if(	indexLig >= 0 && indexLig < NB_LIG && 
			indexCol >= 0 && indexCol < NB_COL)
		{
			plateau[indexLig][indexCol] = joueur;

			indexLig += baseDirection[direction][0];
			indexCol += baseDirection[direction][1];
		}
		else
			return ;
	}
}

void emplacementBateauAdversaire(int plateau[NB_LIG][NB_COL])
{
	int indexBateau;

	for(indexBateau = 0; indexBateau < NB_BATEAU; ++indexBateau)
	{
		char positionBateau[TAILLE_MAX];
		int ligne, colonne, direction;
		char caractereDirection;

		afficherPlateau(plateau);
		printf("Ou voulez-vous placer votre %s (%d cases de long) ?\n", baseBateau[indexBateau].nom, baseBateau[indexBateau].longueur);
		printf("> ");

		scanf("%[^\n]s\n", positionBateau);
		viderBuffer();
		sscanf(positionBateau, "%d %d %c", &ligne, &colonne, &caractereDirection);

		switch(caractereDirection)
		{
			case 'h' : case 'H' :
				direction = HAUT;
				break;
			case 'b' : case 'B' :
				direction = BAS;
				break;
			case 'g' : case 'G' :
				direction = GAUCHE;
				break;
			case 'd' : case 'D' :
				direction = DROITE;
				break;
			default:
				break;
		}

		placerBateau(plateau, ADVERSAIRE, ligne - 1, colonne - 1, direction, baseBateau[indexBateau].longueur);
	}
}

void emplacementBateauIA(int plateau[NB_LIG][NB_COL], int plateauIA[NB_LIG][NB_COL])
{
	int indexBateau;

	initialiserPlateau(plateauIA);

	for(indexBateau = 0; indexBateau < NB_BATEAU; ++indexBateau)
	{
		int ligne, colonne, direction;

		do
		{
			ligne = aleatoire(0, NB_LIG - 1);
			colonne = aleatoire(0, NB_COL - 1);
			direction = aleatoire(0, 3);

		} while(!estPositionValide(plateau, ligne, colonne, direction, baseBateau[indexBateau].longueur));

		placerBateau(plateau, IA, ligne, colonne, direction, baseBateau[indexBateau].longueur);
		placerBateau(plateauIA, IA, ligne, colonne, direction, baseBateau[indexBateau].longueur);
	}
}

void faireJouerAdversaire(int plateau[NB_LIG][NB_COL])
{
	int ligne, colonne;

	printf("C'est a vous de jouer !\n");
	printf("> ");
	scanf("%d %d", &ligne, &colonne);
	--ligne;
	--colonne;

	putchar('\n');

	if(plateau[ligne][colonne] == IA)
	{
		plateau[ligne][colonne] = TOUCHE;
		printf("Vous avez touche un navire ennemi !");
	}
	else
	{
		plateau[ligne][colonne] = RATE;
		printf("Vous n'avez pas touche de navire ennemi.");
	}

	putchar('\n');
}

/* ------------------------------------------ Code de l'IA ------------------------------------------ */

void alentourCase(int plateauIA[NB_LIG][NB_COL], int ligne, int colonne)
{
	if(	(ligne - 1) >= 0 && 
		plateauIA[ligne - 1][colonne] != IA &&
		plateauIA[ligne - 1][colonne] != RATE &&
		plateauIA[ligne - 1][colonne] != TOUCHE)
			plateauIA[ligne - 1][colonne] = EXPLORE;
	if((ligne + 1) < NB_LIG &&
		plateauIA[ligne + 1][colonne] != IA &&
		plateauIA[ligne + 1][colonne] != RATE &&
		plateauIA[ligne + 1][colonne] != TOUCHE)
			plateauIA[ligne + 1][colonne] = EXPLORE;
	if((colonne - 1) >= 0 &&
	 	plateauIA[ligne][colonne - 1] != IA &&
	 	plateauIA[ligne][colonne - 1] != RATE &&
	 	plateauIA[ligne][colonne - 1] != TOUCHE)
			plateauIA[ligne][colonne - 1] = EXPLORE;
	if((colonne + 1) < NB_COL &&
		plateauIA[ligne][colonne + 1] != IA &&
		plateauIA[ligne][colonne + 1] != RATE &&
		plateauIA[ligne][colonne + 1] != TOUCHE)
			plateauIA[ligne][colonne + 1] = EXPLORE;
}

void caseAexplorer(int plateauIA[NB_LIG][NB_COL], int *ligne, int *colonne)
{
	int indexLig, indexCol;

	for(indexLig = 0; indexLig < NB_LIG; ++indexLig)
	{
		for(indexCol = 0; indexCol < NB_COL; ++indexCol)
		{
			if(plateauIA[indexLig][indexCol] == EXPLORE)
			{
				*ligne = indexLig;
				*colonne = indexCol;

				return ;
			}
		}
	}

	*ligne = -1;
	*colonne = -1;
}

void faireJouerIA(int plateau[NB_LIG][NB_COL], int plateauIA[NB_LIG][NB_COL])
{
	static int modeJeu = CHASSE;

	if(modeJeu == CHASSE)
	{
		int ligne, colonne;

		do
		{
			ligne = aleatoire(0, NB_LIG - 1);
			colonne = aleatoire(0, NB_COL - 1);

		} while(plateauIA[ligne][colonne] != VIDE);

		if(plateau[ligne][colonne] == ADVERSAIRE)
		{
			plateau[ligne][colonne] = VIDE;
			plateauIA[ligne][colonne] = TOUCHE;

			printf("L'ordinateur a touche un navire en position : %d %d\n", ligne + 1, colonne + 1);

			modeJeu = CIBLE;

			alentourCase(plateauIA, ligne, colonne);
		}
		else
			plateauIA[ligne][colonne] = RATE;
	}
	else if(modeJeu == CIBLE)
	{
		int ligne, colonne;

		caseAexplorer(plateauIA, &ligne, &colonne);

		if(ligne == -1 && colonne == -1)
		{
			modeJeu = CHASSE;
			faireJouerIA(plateau, plateauIA);
		}
		else if(plateau[ligne][colonne] == ADVERSAIRE)
		{
			plateau[ligne][colonne] = VIDE;
			plateauIA[ligne][colonne] = TOUCHE;

			printf("L'ordinateur a touche un navire en position : %d %d\n", ligne + 1, colonne + 1);

			alentourCase(plateauIA, ligne, colonne);
		}
		else
			plateauIA[ligne][colonne] = RATE;
	}
}

/* -------------------------------------------------------------------------------------------------- */

void jeuBatailleNavale(void)
{
	int plateau[NB_LIG][NB_COL];
	int plateauIA[NB_LIG][NB_COL];
	int gagnant;

	gagnant = 0;

	initialiserPlateau(plateau);

	emplacementBateauAdversaire(plateau);
	emplacementBateauIA(plateau, plateauIA);

	do
	{
		afficherPlateau(plateau);

		if(!gagnant)
			faireJouerAdversaire(plateau);

		gagnant = gagnantBatailleNavale(plateau);

		if(!gagnant)
			faireJouerIA(plateau, plateauIA);

		gagnant = gagnantBatailleNavale(plateau);

	} while(!gagnant);

	afficherPlateau(plateau);
	afficherGagnant(gagnant);
}

int main(void)
{
	srand(time(NULL));

	jeuBatailleNavale();

	return 0;
}
