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
        pommes[i].x = TAILLE_POMME * (1 + rand() % (NB_COLONNES - 2));
        pommes[i].y = TAILLE_POMME * (1 + rand() % ((NB_LIGNES - 2) - 2));
        pommes[i].estMangee = 0;

    }
}
void GererPommesMangees(Pomme pommes[], int nombrePommes) {
    int i;
    for (i = 0; i < nombrePommes; i++) {
        if (pommes[i].estMangee) {
         
            pommes[i].x = TAILLE_POMME * (1 + rand() % (NB_COLONNES - 2));
            pommes[i].y = TAILLE_POMME * (1 + rand() % ((NB_LIGNES - 2) - 2));
            pommes[i].estMangee = 0; 
        }
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

void MangerPomme(Pomme pommes[], int nombrePommes, int x, int y, int *pommeMangee) {
  int i;
    for (i = 0; i < nombrePommes; i++) {
        if (!pommes[i].estMangee && x == pommes[i].x && y == pommes[i].y) {
            pommes[i].estMangee = 1;
            *pommeMangee = 1;
            return;
        }
    }
    *pommeMangee = 0;
}

void DessinerPomme(int x, int y, int sprite) {
    AfficherSprite(sprite, x, y);
}
