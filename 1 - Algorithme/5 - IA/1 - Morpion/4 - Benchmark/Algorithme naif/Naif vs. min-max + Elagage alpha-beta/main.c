#include "main.h"

int plateauMorpion[NB_LIGNE][NB_COLONNE];
int borneAlpha, borneBeta;

int Max(const int a, const int b)
{
	if(a > b)
		return a;
	else
		return b;
}

int Min(const int a, const int b)
{
	if(a < b)
		return a;
	else
		return b;
}

void initialiserMorpion(void)
{
	int indexLig, indexCol;

	for(indexLig = 0; indexLig < NB_LIGNE; ++indexLig)
		for(indexCol = 0; indexCol < NB_COLONNE; ++indexCol)
			plateauMorpion[indexLig][indexCol] = VIDE;
}

int hasard(const int min, const int max)
{
	return (rand() % (max - min + 1)) + min;
}

int peutGagnerMorpion(const int typeJoueur, int *lig, int *col)
{
	int indexLig, indexCol;

	for(indexLig = 0; indexLig < NB_LIGNE; ++indexLig)
	{
		for(indexCol = 0; indexCol < NB_COLONNE; ++indexCol)
		{
			if(plateauMorpion[indexLig][indexCol] == VIDE)
			{
				plateauMorpion[indexLig][indexCol] = typeJoueur;

				if(gagnerMorpion() == typeJoueur)
				{
					*lig = indexLig;
					*col = indexCol;

					plateauMorpion[indexLig][indexCol] = VIDE;

					return 1;
				}

				plateauMorpion[indexLig][indexCol] = VIDE;
			}
		}
	}

	return 0;
}

void IAMorpionNaif(const int typeJoueur)
{
	int lig, col;
	int adversaire;

	if(typeJoueur == IA)
		adversaire = JOUEUR;
	else if(typeJoueur == JOUEUR)
		adversaire = IA;
	
	if(peutGagnerMorpion(typeJoueur, &lig, &col))
		plateauMorpion[lig][col] = typeJoueur;
	else if(peutGagnerMorpion(adversaire, &lig, &col))
		plateauMorpion[lig][col] = typeJoueur;
	else
	{
		do
		{
			lig = hasard(0, NB_LIGNE - 1);
			col = hasard(0, NB_COLONNE - 1);
			
		} while(plateauMorpion[lig][col] != VIDE);
		
		plateauMorpion[lig][col] = typeJoueur;
	}
}

int compterNbSerieMorpion(const int typeJoueur, const int longueurSerie)
{
	int indexLig, indexCol;
	int compteur;
	int nbSerie;

	nbSerie = 0;
	
	for(indexLig = 0; indexLig < NB_LIGNE; ++indexLig)
	{	
		compteur = 0;
				
		for(indexCol = 0; indexCol < NB_COLONNE; ++indexCol)
		{
			if(plateauMorpion[indexLig][indexCol] == typeJoueur)
				++compteur;
			else
				compteur = 0;

			if(compteur == longueurSerie)
			{
				++nbSerie;
				compteur = 0;
			}
		}
	}

	for(indexLig = 0; indexLig < NB_LIGNE; ++indexLig)
	{	
		compteur = 0;
				
		for(indexCol = 0; indexCol < NB_COLONNE; ++indexCol)
		{
			if(plateauMorpion[indexCol][indexLig] == typeJoueur)
				++compteur;
			else
				compteur = 0;

			if(compteur == longueurSerie)
			{
				++nbSerie;
				compteur = 0;
			}
		}
	}

	for(indexLig = 0, indexCol = 0; indexLig < NB_LIGNE; ++indexLig, ++indexCol)
	{		
		if(plateauMorpion[indexLig][indexCol] == typeJoueur)
			++compteur;
		else
			compteur = 0;
	}	

	if(compteur == longueurSerie)
		++nbSerie;

	compteur = 0;

	for(indexLig = 0, indexCol = NB_COLONNE - 1; indexLig < NB_LIGNE; ++indexLig, --indexCol)
	{		
		if(plateauMorpion[indexLig][indexCol] == typeJoueur)
			++compteur;
		else
			compteur = 0;
	}

	if(compteur == longueurSerie)
		++nbSerie;

	return nbSerie;
}

int evaluationIA(void)
{
	int gagnant;

	gagnant = gagnerMorpion();

	if(gagnant == IA)
		return SCORE_MAX;
	else if(gagnant == JOUEUR)
		return SCORE_MIN;
	else
	{
		if(!plateauRempli())
		{
			int nbSerieJoueur, nbSerieIA;

			nbSerieJoueur = compterNbSerieMorpion(JOUEUR, NB_LIGNE - 1);
			nbSerieIA = compterNbSerieMorpion(IA, NB_LIGNE - 1);

			return nbSerieIA - nbSerieJoueur;
		}
		else
			return SCORE_NUL;
	}
}

int valeurMax(const int typeJoueur, const int profondeur)
{
	int indexLig, indexCol;
	int maxIA, valeurNoeud;
	int adversaire;

	if(typeJoueur == IA)
		adversaire = JOUEUR;
	else if(typeJoueur == JOUEUR)
		adversaire = IA;

	maxIA = SCORE_MIN;

	if(gagnerMorpion() != 0 || profondeur == 0)
		return evaluationIA();

	for(indexLig = 0; indexLig < NB_LIGNE; ++indexLig)
	{
		for(indexCol = 0; indexCol < NB_COLONNE; ++indexCol)
		{
			if(plateauMorpion[indexLig][indexCol] == VIDE)
			{
				plateauMorpion[indexLig][indexCol] = adversaire;
		
				valeurNoeud = valeurMin(typeJoueur, profondeur - 1);

				if(valeurNoeud > maxIA)
					maxIA = valeurNoeud;

				if(valeurNoeud >= borneBeta)
				{
					plateauMorpion[indexLig][indexCol] = VIDE;
					return valeurNoeud;
				}

				borneAlpha = Max(borneAlpha, valeurNoeud);

				plateauMorpion[indexLig][indexCol] = VIDE;
			}
		}
	}

	return maxIA;
}

int valeurMin(const int typeJoueur, const int profondeur)
{
	int indexLig, indexCol;
	int minIA, valeurNoeud;

	minIA = SCORE_MAX;

	if(gagnerMorpion() != 0 || profondeur == 0)
		return evaluationIA();

	for(indexLig = 0; indexLig < NB_LIGNE; ++indexLig)
	{
		for(indexCol = 0; indexCol < NB_COLONNE; ++indexCol)
		{
			if(plateauMorpion[indexLig][indexCol] == VIDE)
			{
				plateauMorpion[indexLig][indexCol] = typeJoueur;
		
				valeurNoeud = valeurMax(typeJoueur, profondeur - 1);

				if(valeurNoeud < minIA)
					minIA = valeurNoeud;

				if(valeurNoeud <= borneAlpha)
				{
					plateauMorpion[indexLig][indexCol] = VIDE;
					return valeurNoeud;
				}
				
				borneBeta = Min(borneBeta, valeurNoeud);
				
				plateauMorpion[indexLig][indexCol] = VIDE;
			}
		}
	}

	return minIA;
}

void IAMorpionMinMaxElagage(const int typeJoueur, const int profondeur)
{
	int indexLig, indexCol;
	int coupLig, coupCol;
	int maxIA, valeurNoeud;

	maxIA = SCORE_MIN;

	borneAlpha = SCORE_MIN;
	borneBeta = SCORE_MAX;

	for(indexLig = 0; indexLig < NB_LIGNE; ++indexLig)
	{
		for(indexCol = 0; indexCol < NB_COLONNE; ++indexCol)
		{
			if(plateauMorpion[indexLig][indexCol] == VIDE)
			{
				plateauMorpion[indexLig][indexCol] = typeJoueur;
		
				valeurNoeud = valeurMax(typeJoueur, profondeur - 1);

				if(valeurNoeud > maxIA)
				{
					maxIA = valeurNoeud;
					coupLig = indexLig;
					coupCol = indexCol;
				}

				plateauMorpion[indexLig][indexCol] = VIDE;
			}
		}
	}

	plateauMorpion[coupLig][coupCol] = typeJoueur;
}

int plateauRempli(void)
{
	int indexLig, indexCol;

	for(indexLig = 0; indexLig < NB_LIGNE; ++indexLig)
		for(indexCol = 0; indexCol < NB_COLONNE; ++indexCol)
			if(plateauMorpion[indexLig][indexCol] == VIDE)
				return 0;

	return 1;
}

int verifierLigneGagnerMorpion(const int typeJoueur)
{
	int indexLig, indexCol;
	int compteur;
	
	for(indexLig = 0; indexLig < NB_LIGNE; ++indexLig)
	{	
		compteur = 0;
				
		for(indexCol = 0; indexCol < NB_COLONNE; ++indexCol)
		{
			if(plateauMorpion[indexLig][indexCol] == typeJoueur)
				++compteur;

			if(compteur == NB_LIGNE)
				return 1;
		}
	}	
		
	return 0;
}

int verifierColonneGagnerMorpion(const int typeJoueur)
{
	int indexLig, indexCol;
	int compteur;
	
	for(indexLig = 0; indexLig < NB_LIGNE; ++indexLig)
	{	
		compteur = 0;
				
		for(indexCol = 0; indexCol < NB_COLONNE; ++indexCol)
		{
			if(plateauMorpion[indexCol][indexLig] == typeJoueur)
				++compteur;

			if(compteur == NB_COLONNE)
				return 1;
		}
	}	
		
	return 0;
}

int verifierDiagonaleGagnerMorpion(const int typeJoueur)
{
	int indexLig, indexCol;
	int compteur;
	
	compteur = 0;

	for(indexLig = 0, indexCol = 0; indexLig < NB_LIGNE; ++indexLig, ++indexCol)
	{	
			
		if(plateauMorpion[indexLig][indexCol] == typeJoueur)
			++compteur;
	}	

	if(compteur == NB_LIGNE)
		return 1;

	compteur = 0;

	for(indexLig = 0, indexCol = NB_COLONNE - 1; indexLig < NB_LIGNE; ++indexLig, --indexCol)
	{	
			
		if(plateauMorpion[indexLig][indexCol] == typeJoueur)
			++compteur;
	}

	if(compteur == NB_LIGNE)
		return 1;
		
	return 0;
}

int gagnerMorpion(void)
{
	if(verifierLigneGagnerMorpion(JOUEUR))
		return JOUEUR;
	else if(verifierColonneGagnerMorpion(JOUEUR))
		return JOUEUR;
	else if(verifierDiagonaleGagnerMorpion(JOUEUR))
		return JOUEUR;

	if(verifierLigneGagnerMorpion(IA))
		return IA;
	else if(verifierColonneGagnerMorpion(IA))
		return IA;
	else if(verifierDiagonaleGagnerMorpion(IA))
		return IA;

	return VIDE;
}

void jeuMorpion(void)
{
	int indexPartie;
	int nbGagne, nbPerdu, nbNul;

	 nbGagne = nbPerdu = nbNul = 0;

	for(indexPartie = 0; indexPartie < 10000; ++indexPartie)
	{
		int gagnantMorpion;

		gagnantMorpion = VIDE;
		initialiserMorpion();

		do
		{
			if(!plateauRempli() && !gagnantMorpion)
				IAMorpionNaif(JOUEUR);

			gagnantMorpion = gagnerMorpion();

			if(!plateauRempli() && !gagnantMorpion)
				IAMorpionMinMaxElagage(IA, PROFONDEUR_IA);

			gagnantMorpion = gagnerMorpion();

		} while(!plateauRempli() && !gagnantMorpion);

		if(gagnantMorpion == IA)
			++nbGagne;
		else if(gagnantMorpion == JOUEUR)
			++nbPerdu;
		else
			++nbNul;
	}

	printf("Gagne : %d\n", nbGagne);
	printf("Perdu : %d\n", nbPerdu);
	printf("Nul : %d\n", nbNul);
}

int main(void)
{
	srand(time(NULL));

	jeuMorpion();

	return 0;
}
