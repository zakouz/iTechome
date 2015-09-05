#include <stdio.h>
#include <string.h>
#include <ctype.h>

char message[] = "BCNCGPLBHZQIVNGLQNCJPTRURWIYOJTMEYIPABFBTTYYPXIGCKDLRNBWMFJLCBFFXOWHWBFZQOPZQEXXYAYYPNWYFFYMFYQFVRZLFTRXBOMGUFWAFUKDTRGLTVQLBTVGYOPBPIJXMPYQZTVPFPZGLBDZBHAOWANGPURMLFDVYKDMAWLCMQUKDTNVXTMQYCPBUCVPWHOKPAPUITMEVIPCRNYWIAWCWIAKRPLRXBFFSIKEIVHBDLNHPFVICIWITYAPACIRTTYYPOWANGLQBOYWQRFBYWZDBYMEYDCMGNBYQQYQCMIYKFVVXBOMIIFCZRJXCBVLSPZFKRPTDOBNPBMBOQAWLYVHXLYBCYODWAHBRZNWBLLVYRYIWUJLQFJRCQRHPLDBCOUIVNOZCIYILDVYQCMFVBWTRYQLAFYWWWAARPIZIKRWHNGLQROAPTNWELVPYJPZPCGLQPIJXQFXBDNNOQPARNAPARLOPCEMMLZQIKAMAMBKIZIFOMGYJAARHQPUCMPLTHYWWMZIKOMCIRCUBCNFIAXGPVRMBCIVJIFAYUZPAGOKPLEIIPLRGXNPVHBLNNCOPDRLPPZQYPWIEGBDLRMXYORNXCMAXOPNBOAPJBHEPCEDBXMEYQZCEHBPVPIOPCAYCZQFMRCKRNBXXFJBCLHYQRITHBPBWYJPLVMGPURNOZUCYMPCGYQCMDOFWUNXLYVRWLXURWXAWHLOTMAUSPKOYXFKBOMOMTLXNMRNAPJBHKPDBFLYBRWBBCVFVLMHXBXMVFIPCEXBEWHNBPBRLKTBRFXGQRXRYPBGJPXNLJTTRMXFBEYP";
int longueurMessage;
int longueurCle = 5;

void afficherCle(char ligne[], int rangCle, char cle[])
{
	int frequence[26] = {0};
	int indexLigne;

	for(indexLigne = 0; ligne[indexLigne] != '\0'; ++indexLigne)
		++frequence[tolower(ligne[indexLigne]) - 'a'];

	printf("Frequences : ");

	for(indexLigne = 0; indexLigne < 26; ++indexLigne)
		printf("%d ", frequence[indexLigne]);

	putchar('\n');

	int indexMax, max;

	indexMax = 0;
	max = 0;

	for(indexLigne = 0; indexLigne < 26; ++indexLigne)
	{
		if(frequence[indexLigne] > max)
		{
			max = frequence[indexLigne];
			indexMax = indexLigne;
		}
	}

	printf("Max : %c -> %d\n", indexMax + 'A', max);

	char lettreCle;

	lettreCle = (indexMax + 'A') -  ('E' - 'A');
	while(lettreCle < 'A')
		lettreCle += 26;

	cle[rangCle] = lettreCle;
	printf("Lettre %d de la cle : %c\n", rangCle + 1, lettreCle);
}

void analyseFrequentielle(void)
{
	char cle[longueurCle];
	int indexCle, indexMessage;

	longueurMessage = strlen(message);

	for(indexCle = 0; indexCle < longueurCle; ++indexCle)
	{
		char ligne[longueurMessage];
		int indexLigne;

		printf("Ligne %d : ", indexCle + 1);

		for(indexMessage = indexCle, indexLigne = 0; indexMessage < longueurMessage; ++indexLigne)
		{
			ligne[indexLigne] = message[indexMessage];
			indexMessage += longueurCle;
		}

		ligne[indexLigne] = '\0';

		puts(ligne);
		afficherCle(ligne, indexCle, cle);

		putchar('\n');
	}

	putchar('\n');

	cle[longueurCle] = '\0';
	printf("Cle : %s\n", cle);
}

int main(void)
{
	analyseFrequentielle();

	return 0;
}
