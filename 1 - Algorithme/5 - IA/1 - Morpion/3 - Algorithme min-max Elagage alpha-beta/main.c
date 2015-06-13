#include <stdio.h>
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

int alpha, beta;

int nbSerieMorpion(int plateau[NB_LIG][NB_COL], int joueur)
{
	int nbSerie;

	nbSerie = 0;

	int indexLig, indexCol, indexDirection, indexLongueur;
	int direction[4][2] = {{0, 1}, {1, 0}, {1, 1}, {1, -1}};

	for(indexLig = 0; indexLig < NB_LIG; ++indexLig)
		for(indexCol = 0; indexCol < NB_COL; ++indexCol)
			for(indexDirection = 0; indexDirection < 4; ++indexDirection)
			{
				int lig, col;
				int compteur;

				lig = indexLig;
				col = indexCol;
				compteur = 0;

				for(indexLongueur = 0; indexLongueur < NB_ALIGNE - 1; ++indexLongueur)
				{
					if(casePlateau(plateau, lig, col) == joueur)
						++compteur;
					else
						compteur = 0;

					if(compteur == NB_ALIGNE - 1)
					{
						++nbSerie;
						compteur = 0;
					}

					lig += direction[indexDirection][0];
					col += direction[indexDirection][1];
				}
			}

	return nbSerie;
}

int evaluationIA(int plateau[NB_LIG][NB_COL])
{
	int gagnant;

	gagnant = gagnantMorpion(plateau);

	if(gagnant == IA)
		return SCORE_MAX;
	else if(gagnant == ADVERSAIRE)
		return SCORE_MIN;
	else
	{
		if(!plateauRempli(plateau))
		{
			int nbSerieIA, nbSerieAdversaire;

			nbSerieIA = nbSerieMorpion(plateau, IA);
			nbSerieAdversaire = nbSerieMorpion(plateau, ADVERSAIRE);

			return nbSerieIA - nbSerieAdversaire;
		}
		else
			return SCORE_NUL;
	}
}

int scoreMax(int plateau[NB_LIG][NB_COL], int profondeur)
{
	int indexLig, indexCol;
	int maxIA, scoreNoeud;

	maxIA = SCORE_MIN;

	if(gagnantMorpion(plateau) != 0 || profondeur == 0)
		return evaluationIA(plateau);

	for(indexLig = 0; indexLig < NB_LIG; ++indexLig)
		for(indexCol = 0; indexCol < NB_COL; ++indexCol)
			if(plateau[indexLig][indexCol] == VIDE)
			{
				plateau[indexLig][indexCol] = ADVERSAIRE;
		
				scoreNoeud = scoreMin(plateau, profondeur - 1);

				if(scoreNoeud > maxIA)
					maxIA = scoreNoeud;

				if(scoreNoeud >= beta)
				{
					plateau[indexLig][indexCol] = VIDE;
					return scoreNoeud;
				}

				if(scoreNoeud > alpha)
					alpha = scoreNoeud;

				plateau[indexLig][indexCol] = VIDE;
			}

	return maxIA;
}

int scoreMin(int plateau[NB_LIG][NB_COL], int profondeur)
{
	int indexLig, indexCol;
	int minIA, scoreNoeud;

	minIA = SCORE_MAX;

	if(gagnantMorpion(plateau) != 0 || profondeur == 0)
		return evaluationIA(plateau);

	for(indexLig = 0; indexLig < NB_LIG; ++indexLig)
		for(indexCol = 0; indexCol < NB_COL; ++indexCol)
			if(plateau[indexLig][indexCol] == VIDE)
			{
				plateau[indexLig][indexCol] = IA;
		
				scoreNoeud = scoreMax(plateau, profondeur - 1);

				if(scoreNoeud < minIA)
					minIA = scoreNoeud;

				if(scoreNoeud <= alpha)
				{
					plateau[indexLig][indexCol] = VIDE;
					return scoreNoeud;
				}

				if(scoreNoeud < beta)
					beta = scoreNoeud;

				plateau[indexLig][indexCol] = VIDE;
			}

	return minIA;
}

void faireJouerIA(int plateau[NB_LIG][NB_COL])
{
	int indexLig, indexCol;
	int lig, col;
	int maxIA, scoreNoeud;
	int profondeur;

	maxIA = SCORE_MIN;
	profondeur = PROFONDEUR_IA;
	alpha = SCORE_MIN;
	beta = SCORE_MAX;

	for(indexLig = 0; indexLig < NB_LIG; ++indexLig)
		for(indexCol = 0; indexCol < NB_COL; ++indexCol)
			if(plateau[indexLig][indexCol] == VIDE)
			{
				plateau[indexLig][indexCol] = IA;
		
				scoreNoeud = scoreMax(plateau, profondeur - 1);

				if(scoreNoeud > maxIA)
				{
					maxIA = scoreNoeud;
					lig = indexLig;
					col = indexCol;
				}

				plateau[indexLig][indexCol] = VIDE;
			}

	plateau[lig][col] = IA;
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

	jeuMorpion(plateau);

	return 0;
}
