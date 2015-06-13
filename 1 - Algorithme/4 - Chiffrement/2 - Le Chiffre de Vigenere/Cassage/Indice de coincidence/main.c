#include <stdio.h>
#include <string.h>
#include <ctype.h>

char message[] = "BCNCGPLBHZQIVNGLQNCJPTRURWIYOJTMEYIPABFBTTYYPXIGCKDLRNBWMFJLCBFFXOWHWBFZQOPZQEXXYAYYPNWYFFYMFYQFVRZLFTRXBOMGUFWAFUKDTRGLTVQLBTVGYOPBPIJXMPYQZTVPFPZGLBDZBHAOWANGPURMLFDVYKDMAWLCMQUKDTNVXTMQYCPBUCVPWHOKPAPUITMEVIPCRNYWIAWCWIAKRPLRXBFFSIKEIVHBDLNHPFVICIWITYAPACIRTTYYPOWANGLQBOYWQRFBYWZDBYMEYDCMGNBYQQYQCMIYKFVVXBOMIIFCZRJXCBVLSPZFKRPTDOBNPBMBOQAWLYVHXLYBCYODWAHBRZNWBLLVYRYIWUJLQFJRCQRHPLDBCOUIVNOZCIYILDVYQCMFVBWTRYQLAFYWWWAARPIZIKRWHNGLQROAPTNWELVPYJPZPCGLQPIJXQFXBDNNOQPARNAPARLOPCEMMLZQIKAMAMBKIZIFOMGYJAARHQPUCMPLTHYWWMZIKOMCIRCUBCNFIAXGPVRMBCIVJIFAYUZPAGOKPLEIIPLRGXNPVHBLNNCOPDRLPPZQYPWIEGBDLRMXYORNXCMAXOPNBOAPJBHEPCEDBXMEYQZCEHBPVPIOPCAYCZQFMRCKRNBXXFJBCLHYQRITHBPBWYJPLVMGPURNOZUCYMPCGYQCMDOFWUNXLYVRWLXURWXAWHLOTMAUSPKOYXFKBOMOMTLXNMRNAPJBHKPDBFLYBRWBBCVFVLMHXBXMVFIPCEXBEWHNBPBRLKTBRFXGQRXRYPBGJPXNLJTTRMXFBEYP";
int tailleMessage;

double calculerIndice(void)
{
	double indice;

	int frequence[26] = {0};
	int indexMessage;

	indice = 0.0;

	for(indexMessage = 0; message[indexMessage] != '\0'; ++indexMessage)
		if(isalpha(message[indexMessage]))
			++frequence[tolower(message[indexMessage]) - 'a'];

	int indexLettre;

	for(indexLettre = 0; indexLettre < 26; ++indexLettre)
		indice += (double) (frequence[indexLettre] * (frequence[indexLettre] - 1)) / (tailleMessage * (tailleMessage - 1));

	return indice;
}

void indiceCoincidence(void)
{
	double indice;
	
	tailleMessage = strlen(message);

	printf("Indice de coincidence : %f\n", calculerIndice());

	indice = (tailleMessage * (0.074 - 0.038)) / (calculerIndice() * (tailleMessage - 1) - tailleMessage * 0.038 + 0.078);

	printf("Longueur cle : %f\n", indice);
}

int main(void)
{
	indiceCoincidence();

	return 0;
}
