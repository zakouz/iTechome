#include <stdio.h>

int tableau[] = {5, 1, 3, 8, 9, 6};
int taille = 6;

void fusion(int debut, int milieu, int fin)
{
	int compteurPartie1;
	int compteurPartie2;
	int A[milieu - debut + 1];
	int indexTab;

	for(indexTab = 0; indexTab <= milieu; ++indexTab)
		A[indexTab] = tableau[indexTab + debut];

	compteurPartie1 = debut;
	compteurPartie2 = milieu + 1;

	for(indexTab = debut; indexTab <= fin; ++indexTab)
	{ 
		if(compteurPartie1 == milieu + 1) 
		{
			tableau[indexTab] = tableau[compteurPartie2];
			compteurPartie2++;
		}
		else if(compteurPartie2 == fin + 1) 
		{ 
			tableau[indexTab] = A[compteurPartie1 - debut];
			compteurPartie1++;
		} 
		else if(A[compteurPartie1 - debut] < tableau[compteurPartie2])
		{ 
			tableau[indexTab] = A[compteurPartie1 - debut];
			compteurPartie1++; 
		}
		else
		{ 
			tableau[indexTab] = tableau[compteurPartie2];
			compteurPartie2++; 
		}
	}
}

void triFusionRecursif(int debut, int fin)
{
	if(debut != fin)
	{
		int milieu = (debut + fin) / 2;

		triFusionRecursif(debut, milieu);
		triFusionRecursif(milieu + 1, fin);

		fusion(debut, milieu, fin); 
	}
}

void triFusion(void)
{
	triFusionRecursif(0, taille - 1);
}

int main(void)
{
	int index;
	
	for(index = 0; index < taille; ++index)
		printf("%d ", tableau[index]);
		
	printf("\n\n");
	
	triFusion();
	
	for(index = 0; index < taille; ++index)
		printf("%d ", tableau[index]);
		
	return 0;
}
