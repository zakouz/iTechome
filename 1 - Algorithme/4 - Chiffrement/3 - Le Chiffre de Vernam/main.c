#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define FIN 25
#define DEBUT 0

char message[] = "Ordinateur";
int tailleMessage;

void creerCle(char cle[])
{
	int indexCle;

	for(indexCle = 0; indexCle < tailleMessage; ++indexCle)
		cle[indexCle] = ((rand() % (FIN - DEBUT + 1)) + DEBUT) + 'a';

	cle[indexCle] = '\0';
}

void chiffrement(char cle[])
{
	int indexTab;
	
	for(indexTab = 0; message[indexTab] != '\0'; ++indexTab)
	{
		if(isupper(message[indexTab]))
		{
			int rangCle;

			rangCle = tolower(cle[indexTab]) - 'a';

			message[indexTab] -= 'A';
			message[indexTab] = ((message[indexTab] + rangCle) % 26 + 26) % 26;
			message[indexTab] += 'A';
		}
		else if(islower(message[indexTab]))
		{
			int rangCle;

			rangCle = tolower(cle[indexTab]) - 'a';
			
			message[indexTab] -= 'a';
			message[indexTab] = ((message[indexTab] + rangCle) % 26 + 26) % 26;
			message[indexTab] += 'a';
		}
	}
}

void dechiffrement(char cle[])
{
	int indexTab;
	
	for(indexTab = 0; message[indexTab] != '\0'; ++indexTab)
	{
		if(isupper(message[indexTab]))
		{
			int rangCle;

			rangCle = tolower(cle[indexTab]) - 'a';

			message[indexTab] -= 'A';
			message[indexTab] = ((message[indexTab] - rangCle) % 26 + 26) % 26;
			message[indexTab] += 'A';
		}
		else if(islower(message[indexTab]))
		{
			int rangCle;

			rangCle = tolower(cle[indexTab]) - 'a';
			
			message[indexTab] -= 'a';
			message[indexTab] = ((message[indexTab] - rangCle) % 26 + 26) % 26;
			message[indexTab] += 'a';
		}
	}
}

int main(void) 
{
	srand(time(NULL));
	tailleMessage = strlen(message);
	
	char cle[tailleMessage];
	creerCle(cle);

	printf("%s\n", message);

	chiffrement(cle);
	printf("%s\n", message);

	dechiffrement(cle);
	printf("%s\n", message);

	return 0;
}
