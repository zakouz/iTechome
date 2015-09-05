#ifndef MAIN_H
#define MAIN_H

typedef struct Liste Liste;
struct Liste
{
	int donnee;
	Liste *suivant;
};

void creerListe(Liste **liste);
void supprimerListe(Liste **liste);

void ajouterEnTeteListe(Liste **liste, const int donnee);
void ajouterEnFinListe(Liste **liste, const int donnee);
void ajouterIndexListe(Liste **liste, const int donnee, const int indexNouveauElement);

void supprimerEnTeteListe(Liste **liste);
void supprimerEnFinListe(Liste **liste);
void supprimerIndexListe(Liste **liste, const int indexNouveauElement);

void afficherListe(Liste **liste);

int estVideListe(Liste **liste);

int tailleListe(Liste **liste);

#endif
