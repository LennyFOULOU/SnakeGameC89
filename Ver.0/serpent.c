#include "serpent.h"
#include "fruit.h"
#include "fond.h"
#include <stdlib.h>
#include <graph.h>

#define LARGEUR_FENETRE 1600 /* Largeur de la fenêtre (60 colonnes de jeu + murs de 2 cases de chaque côté) */
#define HAUTEUR_FENETRE 1000 /* Hauteur de la fenêtre (40 lignes de jeu + murs de 2 cases en haut et en bas) */
#define TAILLE_CASE 10       /* Taille d'une case pour le jeu de Snake */
#define NB_COLONNES 60       /* Nombre de colonnes du jeu */
#define NB_LIGNES 40



void initialiserSerpent(Serpent* serpent) {
  
    serpent->position.x = NB_COLONNES / 2 * TAILLE_CASE;
    serpent->position.y = NB_LIGNES / 2 * TAILLE_CASE;
    serpent->longueur = 10;
    serpent->trainee = (Position*)malloc(serpent->longueur * sizeof(Position));
    serpent->direction = XK_Right; /* Direction initiale */

}


int deplacerSerpent(Serpent* serpent) {

  int i;
  Position ancienneTete = serpent->position;

  if (serpent->direction == XK_Left) {
  serpent->position.x -= TAILLE_CASE;
  } else if (serpent->direction == XK_Right) {
  serpent->position.x += TAILLE_CASE;
  } else if (serpent->direction == XK_Up) {
  serpent->position.y -= TAILLE_CASE;
  } else if (serpent->direction == XK_Down) {
  serpent->position.y += TAILLE_CASE;
  }

  if (serpent->longueur > 1) {
    for (i = serpent->longueur - 1; i > 0; i--) {
      serpent->trainee[i] = serpent->trainee[i - 1];
    }
    serpent->trainee[0] = ancienneTete;
    }
  
}



int afficherSerpent(Serpent* serpent) { /* Fonction pour afficher le serpent */

  int i;
  couleur couleurSerpent = CouleurParComposante(34, 139, 34);

  ChoisirCouleurDessin(couleurSerpent);

  /* Afficher la tête du serpent */
  RemplirRectangle(serpent->position.x, serpent->position.y, TAILLE_CASE, TAILLE_CASE);

  /* Afficher la trainée du serpent */
  for (i = 0; i < serpent->longueur - 1; i++) {
    RemplirRectangle(serpent->trainee[i].x, serpent->trainee[i].y, TAILLE_CASE, TAILLE_CASE);
  }
  if (serpent->position.x < 0 || serpent->position.x >= LARGEUR_FENETRE ||
      serpent->position.y < 0 || serpent->position.y >= HAUTEUR_FENETRE) {
    return 0; /* Indiquer que le serpent est sorti de la fenêtre */
  }

}
