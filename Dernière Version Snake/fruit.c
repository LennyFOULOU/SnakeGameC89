#include <stdlib.h>
#include <graph.h>
#include <time.h>
#include "fruit.h"
#include "serpent.h"

#define TAILLE_POMME 20
#define NB_POMMES 5         
#define LARGEUR_FENETRE 1600
#define HAUTEUR_FENETRE 1000        
#define NB_COLONNES 60       
#define NB_LIGNES 40


/* Initialisation de la variable de jeu pour stocker le score */
Jeu jeu = {0}; /* Initialise le score à 0 */

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

void GererPommesMangees(Pomme pommes[], int nombrePommes, Serpent* serpent) {
    int i, j, pommeSurSerpent;

    for (i = 0; i < nombrePommes; i++) {
        if (pommes[i].estMangee) {
            do {
                pommeSurSerpent = 0;
                pommes[i].x = TAILLE_POMME * (1 + rand() % (NB_COLONNES - 2));
                pommes[i].y = TAILLE_POMME * (1 + rand() % ((NB_LIGNES - 2) - 2));
                
                for (j = 0; j < serpent->longueur; j++) {
                    if (pommes[i].x == serpent->corps[j].x && pommes[i].y == serpent->corps[j].y) {
                        pommeSurSerpent = 1;
                        break;
                    }
                }
            } while (pommeSurSerpent); 

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
	    AugmenterScore();
            return;
        }
    }
    *pommeMangee = 0;
}

void DessinerPomme(int x, int y, int sprite) {
    AfficherSprite(sprite, x, y);
}

void AugmenterScore() {
  jeu.score += 5; /* Augmenter le score de 5 points à chaque fois qu'une pomme est mangée */
}

int ObtenirScore() {
    return jeu.score;
}

void ResetScore() {
  jeu.score = 0; /* Réinitialiser le score */
}
