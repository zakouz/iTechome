#ifndef MAIN_H
#define MAIN_H

typedef struct Pile Pile;
struct Pile
{
	int donnee;
	Pile *suivant;
};

void creerPile(Pile **pile);
void supprimerPile(Pile **pile);

void empiler(Pile **pile, const int donnee);
int depiler(Pile **pile);

void afficherPile(Pile **pile);

int estVidePile(Pile **pile);

int taillePile(Pile **pile);

#endif
