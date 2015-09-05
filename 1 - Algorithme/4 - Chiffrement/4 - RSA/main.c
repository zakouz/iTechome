#include <stdio.h>
#include <string.h>

int p, q;
int n, m;
int e, d;

int PGCD(int a, int b)
{
	while(a != b)
	{
		if(a > b)
			a -= b;
		else
			b -= a;
	}

	return a;
}

void determinerClePublique(void)
{
	n = p * q;
	m = (p - 1) * (q - 1);

	for(e = 2; PGCD(e, m) != 1; ++e)
		;
}

void determinerClePrivee(void)
{
	int expression;

	d = 1;

	do
	{
		expression = (e * d) % m;
		++d;

	} while(expression != 1);

	--d;
}

void chiffrement(char message[], int messageChiffre[])
{
	int indexMessage, index;

	for(indexMessage = 0; message[indexMessage] != 0; ++indexMessage)
	{
		messageChiffre[indexMessage] = 1;

		for(index = 0; index < e; ++index)
			messageChiffre[indexMessage] = (messageChiffre[indexMessage] * message[indexMessage]) % n;
	}
}

void dechiffrement(char message[], int messageChiffre[])
{
	int indexMessage, index;

	for(indexMessage = 0; message[indexMessage] != 0; ++indexMessage)
	{
		int lettreDechiffree;

		lettreDechiffree = 1;

		for(index = 0; index < d; ++index)
			lettreDechiffree = (lettreDechiffree * messageChiffre[indexMessage]) % n;

		message[indexMessage] = lettreDechiffree;
	}
}

int main(void)
{
	char message[] = "Site";
	int longueurMessage;

	longueurMessage = strlen(message);
	int messageChiffre[longueurMessage];

	p = 59;
	q = 71;

	determinerClePublique();
	determinerClePrivee();

	printf("p = %d\n", p);
	printf("q = %d\n", q);
	printf("n = %d\n", n);
	printf("m = %d\n", m);
	printf("e = %d\n", e);
	printf("d = %d\n", d);

	putchar('\n');

	printf("%s\n", message);
	chiffrement(message, messageChiffre);

	int indexMessage;

	for(indexMessage = 0; indexMessage < longueurMessage; ++indexMessage)
		printf("%d ", messageChiffre[indexMessage]);

	putchar('\n');

	dechiffrement(message, messageChiffre);
	printf("%s\n", message);

	return 0;
}
