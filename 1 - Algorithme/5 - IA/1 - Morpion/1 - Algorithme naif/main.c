#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"

void initialiserMorpion(int plateau[NB_LIG][NB_COL])
{
	int indexLig, indexCol;

	for(indexLig = 0; indexLig < NB_LIG; ++indexLig)
		for(indexCol = 0; indexCol < NB_COL; ++indexCol)
			plateau[indexLig][indexCol] = VIDE;
}

void afficherMorpion(int plateau[NB_LIG][NB_COL])
{
	int indexLig, indexCol;

	for(indexLig = 0; indexLig < NB_LIG; ++indexLig)
	{
		for(indexCol = 0; indexCol < NB_COL; ++indexCol)
		{
			switch(plateau[indexLig][indexCol])
			{
				case VIDE :
					putchar('.');
					break;
				case ADVERSAIRE :
					putchar('X');
					break;
				case IA :
					putchar('O');
					break;
				default :
					break;
			}

			putchar(' ');
		}

		putchar('\n');
	}

	putchar('\n');
}

void afficherGagnantMorpion(const int gagnant)
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

int casePlateau(int plateau[NB_LIG][NB_COL], int lig, int col)
{
	if((lig < 0) || (lig >= NB_LIG) ||
	   (col < 0) || (col >= NB_COL))
		return VIDE;

	return plateau[lig][col];
}

int gagnantMorpion(int plateau[NB_LIG][NB_COL])
{
	int indexJoueur, indexLig, indexCol, indexDirection, indexLongueur;
	int direction[4][2] = {{0, 1}, {1, 0}, {1, 1}, {1, -1}};

	for(indexJoueur = 1; indexJoueur <= 2; ++indexJoueur)
		for(indexLig = 0; indexLig < NB_LIG; ++indexLig)
			for(indexCol = 0; indexCol < NB_COL; ++indexCol)
				for(indexDirection = 0; indexDirection < 4; ++indexDirection)
				{
					int lig, col;
					int compteur;

					lig = indexLig;
					col = indexCol;
					compteur = 0;

					for(indexLongueur = 0; indexLongueur < NB_ALIGNE; ++indexLongueur)
					{
						if(casePlateau(plateau, lig, col) == indexJoueur)
							++compteur;

						lig += direction[indexDirection][0];
						col += direction[indexDirection][1];
					}

					if(compteur == NB_ALIGNE)
						return indexJoueur;
				}

	return VIDE;
}

int plateauRempli(int plateau[NB_LIG][NB_COL])
{
	int indexLig, indexCol;

	for(indexLig = 0; indexLig < NB_LIG; ++indexLig)
		for(indexCol = 0; indexCol < NB_COL; ++indexCol)
			if(plateau[indexLig][indexCol] == VIDE)
				return 0;

	return 1;
}

int aleatoire(int min, int max)
{
	return (rand() % (max - min + 1)) + min;
}

void faireJouerAdversaire(int plateau[NB_LIG][NB_COL])
{
	int ligne, colonne;
	
	puts("A votre tour !");
	putchar('>');
	scanf("%d %d", &ligne, &colonne);
	putchar('\n');

	plateau[ligne - 1][colonne - 1] = ADVERSAIRE;
}

/* ------------------------------------------ Code de l'IA ------------------------------------------ */

int peutGagner(int joueur, int plateau[NB_LIG][NB_COL], int *lig, int *col)
{
	int indexLig, indexCol;

	for(indexLig = 0; indexLig < NB_LIG; ++indexLig)
		for(indexCol = 0; indexCol < NB_COL; ++indexCol)
			if(plateau[indexLig][indexCol] == VIDE)
			{
				plateau[indexLig][indexCol] = joueur;

				if(gagnantMorpion(plateau) == joueur)
				{
					*lig = indexLig;
					*col = indexCol;

					plateau[indexLig][indexCol] = VIDE;

					return 1;
				}

				plateau[indexLig][indexCol] = VIDE;
			}

	return 0;
}

void faireJouerIA(int plateau[NB_LIG][NB_COL])
{
	int ligne, colonne;

	if(peutGagner(IA, plateau, &ligne, &colonne))
		plateau[ligne][colonne] = IA;
	else if(peutGagner(ADVERSAIRE, plateau, &ligne, &colonne))
		plateau[ligne][colonne] = IA;
	else
	{
		do
		{
			ligne = aleatoire(0, NB_LIG - 1);
			colonne = aleatoire(0, NB_COL - 1);
			
		} while(plateau[ligne][colonne] != VIDE);
		
		plateau[ligne][colonne] = IA;
	}
}

/* -------------------------------------------------------------------------------------------------- */

void jeuMorpion(int plateau[NB_LIG][NB_COL])
{
	int gagnant;

	gagnant = 0;

	initialiserMorpion(plateau);

	do
	{
		afficherMorpion(plateau);

		if(!gagnant)
			faireJouerAdversaire(plateau);

		gagnant = gagnantMorpion(plateau);

		if(!plateauRempli(plateau) && !gagnant)
			faireJouerIA(plateau);

		gagnant = gagnantMorpion(plateau);

	} while(!plateauRempli(plateau) && !gagnant);

	afficherMorpion(plateau);
	afficherGagnantMorpion(gagnant);
}

int main(void)
{
	int plateau[NB_LIG][NB_COL];

	srand(time(NULL));

	jeuMorpion(plateau);

	return 0;
}
