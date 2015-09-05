#include <stdio.h>
#include <ctype.h>

char message[] = "Programmation";
char cle[] = "linux";
int tailleCle = 5;

void chiffrement(void)
{
	int indexTab;
	int indexCle;
	
	for(indexTab = 0, indexCle = 0; message[indexTab] != '\0'; ++indexTab)
	{
		if(indexCle == tailleCle)
			indexCle = 0;

		if(isupper(message[indexTab]))
		{
			int rangCle;

			rangCle = tolower(cle[indexCle]) - 'a';

			message[indexTab] -= 'A';
			message[indexTab] = ((message[indexTab] + rangCle) % 26 + 26) % 26;
			message[indexTab] += 'A';

			++indexCle;
		}
		else if(islower(message[indexTab]))
		{
			int rangCle;

			rangCle = tolower(cle[indexCle]) - 'a';
			
			message[indexTab] -= 'a';
			message[indexTab] = ((message[indexTab] + rangCle) % 26 + 26) % 26;
			message[indexTab] += 'a';

			++indexCle;
		}
	}
}

void dechiffrement(void)
{
	int indexTab;
	int indexCle;
	
	for(indexTab = 0, indexCle = 0; message[indexTab] != '\0'; ++indexTab)
	{
		if(indexCle == tailleCle)
			indexCle = 0;

		if(isupper(message[indexTab]))
		{
			int rangCle;

			rangCle = tolower(cle[indexCle]) - 'a';

			message[indexTab] -= 'A';
			message[indexTab] = ((message[indexTab] - rangCle) % 26 + 26) % 26;
			message[indexTab] += 'A';

			++indexCle;
		}
		else if(islower(message[indexTab]))
		{
			int rangCle;

			rangCle = tolower(cle[indexCle]) - 'a';
			
			message[indexTab] -= 'a';
			message[indexTab] = ((message[indexTab] - rangCle) % 26 + 26) % 26;
			message[indexTab] += 'a';

			++indexCle;
		}
	}
}

int main(void) 
{
	printf("%s\n", message);

	chiffrement();
	printf("%s\n", message);

	dechiffrement();
	printf("%s\n", message);

	return 0;
}
