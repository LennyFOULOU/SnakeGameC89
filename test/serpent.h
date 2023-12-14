#ifndef SERPENT_H
#define SERPENT_H
#define LARGEUR_FENETRE 1600
#define HAUTEUR_FENETRE 1000
#define TAILLE_CASE 20
#define NB_COLONNES 60
#define NB_LIGNES 40
#define CYCLE 100000


typedef struct {
    int x , y;
} Corps;

typedef struct {
    int longueur;
    int directionX;
    int directionY;
    Corps corps[NB_COLONNES * NB_LIGNES];
} Serpent;

void InitialiserSerpent(Serpent *serpent, int x, int y);

void DeplacerSerpent(Serpent *serpent);

int VerifierCollision(const Serpent *serpent);

void DessinerSerpent(const Serpent *serpent);

#endif