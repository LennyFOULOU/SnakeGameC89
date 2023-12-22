#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include "boss.h"
#include "serpent.h"
#define VITESSE_BOSS1 8
#define VITESSE_BOSS2 7
#define VITESSE_BOSS3 9
#define HAUTEUR_BOSS1 200
#define LARGEUR_BOSS1 570
#define HAUTEUR_BOSS2 100
#define LARGEUR_BOSS2 600
#define HAUTEUR_BOSS3 450
#define LARGEUR_BOSS3 100
void InitialiserBoss1(Boss* boss) {
    boss->x = 550; 
    boss->y = 10; 
    boss->sprite = ChargerSprite("image/shrek.png"); 
}
void InitialiserBoss2(Boss* boss) {
    boss->x = 300; 
    boss->y = 10; 
    boss->sprite = ChargerSprite("image/chatpotte.png"); 
}
void InitialiserBoss3(Boss* boss) {
    boss->x = 20; 
    boss->y = 550; 
    boss->sprite = ChargerSprite("image/jo.png"); 
}
void DeplacerBoss1(Boss* boss) {
 static int direction = 1;
 if (direction == 1) { /* Si le boss se déplace vers le bas */
     boss->y += VITESSE_BOSS1; /* Modifier ici la vitesse de déplacement vers le bas */
      if (boss->y >= HAUTEUR_FENETRE - HAUTEUR_BOSS1) {
      direction = 2; /* Changer la direction vers la droite */
      }
     } else if (direction == 2) { /* Si le boss se déplace vers la droite */
       boss->x += VITESSE_BOSS1; /* Modifier ici la vitesse de déplacement vers la droite */
        if (boss->x >= LARGEUR_FENETRE - LARGEUR_BOSS1) {
	direction = 3; /* Changer la direction vers le haut */
        }
     } else if (direction == 3) { /* Si le boss se déplace vers le haut */
       boss->y -= VITESSE_BOSS1; /* Modifier ici la vitesse de déplacement vers le haut */
        if (boss->y <= 10) {
	direction = 4; /* Changer la direction vers la gauche */
        }
     } else if (direction == 4) { /* Si le boss se déplace vers la gauche */
       boss->x -= VITESSE_BOSS1; /* Modifier ici la vitesse de déplacement vers la gauche */
        if (boss->x <= 550) {
	direction = 1; /* Changer la direction vers le bas */
       }
     }
}
void DeplacerBoss2(Boss* boss) {
 static int direction = 1;
 if (direction == 1) { /* Déplacement en diagonale en bas à droite */
     boss->x += VITESSE_BOSS2;
     boss->y += VITESSE_BOSS2;
     if (boss->x >= LARGEUR_FENETRE - LARGEUR_BOSS2 || boss->y >= HAUTEUR_FENETRE - HAUTEUR_BOSS2) {
     direction = 2; /* Changer la direction vers le haut à gauche */
     }
     } else if (direction == 2) { /* Déplacement en diagonale en haut à gauche */
       boss->x -= VITESSE_BOSS2;
       boss->y -= VITESSE_BOSS2;
       if (boss->x <= 10 || boss->y <= 10) {
        direction = 1; /* Changer la direction vers le bas à droite */
       }
    }
}
void DeplacerBoss3(Boss* boss) {
    static int direction = 1;
    if (direction == 1) { /* Vers le bas */
        boss->y += VITESSE_BOSS3;
        if (boss->y >= HAUTEUR_FENETRE - HAUTEUR_BOSS3) {
            direction = 2; /* Vers la droite */
        }
    } else if (direction == 2) { /* Vers la droite */
        boss->x += VITESSE_BOSS3;
        if (boss->x >= LARGEUR_FENETRE - LARGEUR_BOSS3) {
            direction = 3; /* Vers le haut */
        }
    } else if (direction == 3) { /* Vers le haut */
        boss->y -= VITESSE_BOSS3;
        if (boss->y <= 250) {
            direction = 4; /* Vers la gauche */
        }
    } else if (direction == 4) { /* Vers la gauche */
        boss->x -= VITESSE_BOSS3;
        if (boss->x <= 10) {
            direction = 1; /* Vers le bas */
        }
    }
}
void DessinerBoss(int x, int y, int sprite) {
    AfficherSprite(sprite, x, y);
}
int CollisionAvecBoss1(const Serpent* serpent, const Boss* boss) {
    int teteX = serpent->corps[0].x;
    int teteY = serpent->corps[0].y;
    int bossX = boss->x;
    int bossY = boss->y;
    int largeurBoss = 100; 
    int hauteurBoss = 88; 
    if (teteX >= bossX && teteX <= bossX + largeurBoss &&
    teteY >= bossY && teteY <= bossY + hauteurBoss) {
    return 1; 
    } else {
    return 0; 
    }
}
int CollisionAvecBoss2(const Serpent* serpent, const Boss* boss) {
    int teteX = serpent->corps[0].x;
    int teteY = serpent->corps[0].y;
    int bossX = boss->x;
    int bossY = boss->y;
    int largeurBoss = 69; 
    int hauteurBoss = 120; 
    if (teteX >= bossX && teteX <= bossX + largeurBoss &&
    teteY >= bossY && teteY <= bossY + hauteurBoss) {
    return 1; 
    } else {
    return 0; 
    }
}
int CollisionAvecBoss3(const Serpent* serpent, const Boss* boss) {
    int teteX = serpent->corps[0].x;
    int teteY = serpent->corps[0].y;
    int bossX = boss->x;
    int bossY = boss->y;
    int largeurBoss = 58; 
    int hauteurBoss = 140; 
    if (teteX >= bossX && teteX <= bossX + largeurBoss &&
    teteY >= bossY && teteY <= bossY + hauteurBoss) {
    return 1; 
    } else {
    return 0; 
    }
}
void InitialiserEffetBoss1(EffetBoss* effet) {
    effet->x = 550;
    effet->y = 10;
    effet->sprite = ChargerSprite("image/effet1.png");
}
void InitialiserEffetBoss2(EffetBoss* effet) {
    effet->x = 300;
    effet->y = 10;
    effet->sprite = ChargerSprite("image/effet2.png");
}
void InitialiserEffetBoss3(EffetBoss* effet) {
    effet->x = 20;
    effet->y = 550;
    effet->sprite = ChargerSprite("image/effet3.png");
}
void AfficherEffetBoss(EffetBoss* effet) {
    AfficherSprite(effet->sprite, effet->x, effet->y);
}
