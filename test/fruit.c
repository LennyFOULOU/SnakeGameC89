#include <stdlib.h>
#include <graph.h>
#include <time.h>
#include "fruit.h"

#define TAILLE_POMME 20
#define NB_POMMES 5         
#define LARGEUR_FENETRE 1600
#define HAUTEUR_FENETRE 1000        
#define NB_COLONNES 60       
#define NB_LIGNES 40       

void InitialiserPommes(Pomme pommes[], int nombrePommes) {
  int i;
    for (i = 0; i < nombrePommes; i++) {
        pommes[i].estMangee = 0;
        pommes[i].sprite = ChargerSprite("image/pomme.png"); 
    }
}

void GenererPommes(Pomme pommes[], int nombrePommes) {
  int i;
  /* Génération des positions aléatoires pour les pommes */
    for (i = 0; i < nombrePommes; i++) {
        pommes[i].x = TAILLE_POMME + rand() % (LARGEUR_FENETRE - 2 * TAILLE_POMME);
        pommes[i].y = TAILLE_POMME + rand() % ((HAUTEUR_FENETRE - 80) - 2 * TAILLE_POMME);
        pommes[i].estMangee = 0;
    }
}

void AfficherPommes(Pomme pommes[], int nombrePommes) {
  int i;
    for (i = 0; i < nombrePommes; i++) {
        if (!pommes[i].estMangee) {
            AfficherSprite(pommes[i].sprite, pommes[i].x, pommes[i].y);
        }
    }
}

void MangerPomme(Pomme pommes[], int nombrePommes, int x, int y) {
  int i;
    for (i = 0; i < nombrePommes; i++) {
        if (!pommes[i].estMangee && x == pommes[i].x && y == pommes[i].y) {
            pommes[i].estMangee = 1;
        }
    }
}

void DessinerPomme(int x, int y, int sprite) {
    AfficherSprite(sprite, x, y);
}
