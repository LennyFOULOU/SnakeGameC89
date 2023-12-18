#ifndef FRUIT_H
#define FRUIT_H
#include"serpent.h"

typedef struct {
    int x;
    int y;
    int estMangee;
  int sprite; /* Ajout d'un identifiant pour le sprite de la pomme */
} Pomme;

typedef struct {
  int score; /* Nouveau champ pour stocker le score */
} Jeu;

void AugmenterScore(); 
void InitialiserPommes(Pomme pommes[], int nombrePommes);
void GenererPommes(Pomme pommes[], int nombrePommes);
void GererPommesMangees(Pomme pommes[], int nombrePommes);
void AfficherPommes(Pomme pommes[], int nombrePommes);
void MangerPomme(Pomme pommes[], int nombrePommes, int x, int y, int *pommeMangee);
void DessinerPomme(int x, int y, int sprite); 
int ChargerSprite(char *file);
void AfficherSprite(int n, int x, int y);
void LibererSprite(int n);

#endif
