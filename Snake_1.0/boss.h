#ifndef BOSS_H
#define BOSS_H
#include <graph.h>
#include "serpent.h"
typedef struct {
    int x;
    int y;
    int sprite;
} Boss;
typedef struct {
    int x;
    int y;
    int sprite;
} EffetBoss;
void InitialiserBoss1(Boss* boss);
void InitialiserBoss2(Boss* boss);
void InitialiserBoss3(Boss* boss);
void DeplacerBoss1(Boss* boss);
void DeplacerBoss2(Boss* boss);
void DeplacerBoss3(Boss* boss);
void DessinerBoss(int x, int y, int sprite);
int CollisionAvecBoss1(const Serpent* serpent, const Boss* boss);
int CollisionAvecBoss2(const Serpent* serpent, const Boss* boss);
int CollisionAvecBoss3(const Serpent* serpent, const Boss* boss);
void InitialiserEffetBoss1(EffetBoss* effet);
void InitialiserEffetBoss2(EffetBoss* effet);
void InitialiserEffetBoss3(EffetBoss* effet);
void AfficherEffetBoss(EffetBoss* effet);
#endif