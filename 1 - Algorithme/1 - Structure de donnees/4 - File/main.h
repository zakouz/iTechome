#ifndef MAIN_H
#define MAIN_H

typedef struct File File;
struct File
{
	int donnee;
	File *suivant;
};

void creerFile(File **file);
void supprimerFile(File **file);

void enfiler(File **file, const int donnee);
int defiler(File **file);

void afficherFile(File **file);

int estVideFile(File **file);

int tailleFile(File **file);

#endif
