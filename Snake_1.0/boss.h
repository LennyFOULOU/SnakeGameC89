
#ifndef BOSS_H
#define BOSS_H

#include <graph.h>
#include "serpent.h"

typedef struct {
    int x;
    int y;
    int directionX;
    int directionY;
    int sprite;
} Boss;

void InitialiserBoss(Boss *boss);
void DeplacerBoss(Boss *boss);
void DessinerBoss(int x, int y, int sprite);
int CollisionAvecBoss(const Serpent *serpent, const Boss *boss);


#endif
