#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#define LARGEUR_FENETRE 1600 
#define HAUTEUR_FENETRE 1000 
#define TAILLE_CASE 20       
#define NB_COLONNES 60       
#define NB_LIGNES 40         
#define CYCLE 100000
#define VITESSE_SERPENT 100000
#define NB_POMMES 5
#define NB_POINTS_VICTOIRE 500

#include"serpent.h"
#include "boss.h"
#include <time.h>

void InitialiserBoss(Boss *boss) {
    boss->x = 0;
    boss->y = 0;
    boss->directionX = 1;
    boss->directionY = 0;
    boss->sprite = ChargerSprite("image/shrek.png");
}

void DeplacerBoss(Boss *boss) {

    int direction = rand() % 4;  
    int ancienX = boss->x;
    int ancienY = boss->y;

   if (direction == 0) {
        boss->directionX = -1;
        boss->directionY = 0;
    } else if (direction == 1) {
        boss->directionX = 1;
        boss->directionY = 0;
    } else if (direction == 2) {
        boss->directionX = 0;
        boss->directionY = -1;
    } else if (direction == 3) {
        boss->directionX = 0;
        boss->directionY = 1;
    }

    boss->x += boss->directionX;
    boss->y += boss->directionY;
    if (boss->x < 0 || boss->x >= LARGEUR_FENETRE || boss->y < 0 || boss->y >= HAUTEUR_FENETRE) {
        boss->x = ancienX;
        boss->y = ancienY;
        boss->directionX = (rand() % 3) - 1; 
        boss->directionY = (rand() % 3) - 1; 
    }


}
void DessinerBoss(int x, int y, int sprite) {
        AfficherSprite(sprite, x, y)
}

int CollisionAvecBoss(const Serpent *serpent, const Boss *boss) {
 
    int teteX = serpent->corps[0].x;
    int teteY = serpent->corps[0].y;


    if (teteX == boss->x && teteY == boss->y) {
        return 1;
    } else {
        return 0;
    }
}
