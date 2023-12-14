#ifndef FRUIT_H
#define FRUIT_H
#include"serpent.h"

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    int disponible;
    Point position;
    int sprite; 
} Pomme;


void InitialiserPomme(Pomme *pomme);

int MangerPomme(Serpent *serpent, Pomme *pomme);

void PlacerPomme(Pomme *pomme);

#endif
