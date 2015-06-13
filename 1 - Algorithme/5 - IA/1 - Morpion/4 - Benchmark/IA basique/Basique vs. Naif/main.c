#include "main.h"

int plateauMorpion[NB_LIGNE][NB_COLONNE];

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

void IAMorpionRandom(const int typeJoueur)
{
	int lig, col;
	
	do
	{
		lig = hasard(0, NB_LIGNE - 1);
		col = hasard(0, NB_COLONNE - 1);
		
	} while(plateauMorpion[lig][col] != VIDE);
	
	plateauMorpion[lig][col] = typeJoueur;
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
				IAMorpionRandom(JOUEUR);

			gagnantMorpion = gagnerMorpion();

			if(!plateauRempli() && !gagnantMorpion)
				IAMorpionNaif(IA);

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
