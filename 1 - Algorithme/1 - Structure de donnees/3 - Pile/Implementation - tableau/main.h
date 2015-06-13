#ifndef MAIN_H
#define MAIN_H

#define TAILLE_PILE 256

void initialiserPile(void);

void empiler(const int donnee);
int depiler(void);

void afficherPile(void);

int estVidePile(void);

int taillePile(void);

#endif
