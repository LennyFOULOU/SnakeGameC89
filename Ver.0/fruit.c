#include <stdlib.h>
#include <graph.h>
#include <time.h>
#include "fruit.h"

#define TAILLE_POMME 20      /* Taille de la pomme*/
#define NB_SPRITES 5         /* Nombre total de sprites pour les pommes*/
#define LARGEUR_FENETRE 1600 /* Largeur de la fenêtre (60 colonnes de jeu + murs de 2 cases de chaque côté) */
#define HAUTEUR_FENETRE 1000 /* Hauteur de la fenêtre (40 lignes de jeu + murs de 2 cases en haut et en bas) */
#define TAILLE_CASE 10       /* Taille d'une case pour le jeu de Snake */
#define NB_COLONNES 60       /* Nombre de colonnes du jeu */
#define NB_LIGNES 40         /* Nombre de lignes du jeu */
#define NB_SPRITE 5


void InitialiserSprites() { /* Fonction pour initialiser les sprites des pommes */

  /* Charger les sprites des pommes*/
  int SpritePomme =  ChargerSprite("/Ver.0/image/pomme.png");
  int PommeSprite[NB_SPRITE];
  int i;
    for ( i = 0; i < NB_SPRITES; i++) {
      PommeSprite[i] = SpritePomme;
    }

}


void AfficherPommeAleatoire() { /* Fonction pour afficher une pomme à une position aléatoire avec un sprite aléatoire */
 
    int x = (rand() % (LARGEUR_FENETRE / TAILLE_CASE)) * TAILLE_CASE;
    int y = (rand() % (HAUTEUR_FENETRE / TAILLE_CASE)) * TAILLE_CASE;

    /* Afficher la pomme à ces coordonnées en utilisant un sprite aléatoire*/
    int numSprite = rand() % NB_SPRITES;
    AfficherSprite(numSprite, x, y);
    
    usleep(500000); /* Attente de 500.000 microsecondes (0.5 seconde)*/
    
}


void LibererSprites() { /* Fonction pour libérer les sprites des pommes */

  int i;
  /* Libérer les sprites des pommes*/
  for ( i = 0; i < NB_SPRITES; i++) {
    LibererSprite(i);
  }

}

