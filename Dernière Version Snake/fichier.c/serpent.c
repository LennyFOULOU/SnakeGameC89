#include <stdlib.h>
#include <graph.h>
#include "../fichier.h/serpent.h"


#define LARGEUR_FENETRE 1600
#define HAUTEUR_FENETRE 1000
#define TAILLE_CASE 20
#define NB_COLONNES 60
#define NB_LIGNES 40
#define CYCLE 100000



void InitialiserSerpent(Serpent *serpent, int x, int y) {
    serpent->longueur = 10;
    serpent->directionX = 1;
    serpent->directionY = 0;
    serpent->corps[0].x = x;
    serpent->corps[0].y = y;
}

void DeplacerSerpent(Serpent *serpent) {
    int i;

    for ( i = serpent->longueur - 1; i > 0; i--) {
        serpent->corps[i] = serpent->corps[i - 1];
    }

    serpent->corps[0].x += serpent->directionX * TAILLE_CASE;
    serpent->corps[0].y += serpent->directionY * TAILLE_CASE;
}
  


int VerifierCollision(const Serpent *serpent) {
    int teteX = serpent->corps[0].x;
    int teteY = serpent->corps[0].y;
    int i;

    if (teteX < 0 || teteX >= LARGEUR_FENETRE || teteY < 0 || teteY >= HAUTEUR_FENETRE-80) {
        return 1;
    }

    for (i = 1; i < serpent->longueur; i++) {
  if (teteX == serpent->corps[i].x && teteY == serpent->corps[i].y) {
    return 1;
  }
    }

    return 0;
}

void DessinerSerpent(const Serpent *serpent) {
     int i;
         couleur couleurSerpent = CouleurParComposante(34, 139, 34);

     ChoisirEcran(1);

     EffacerEcran(CouleurParComposante(230, 230, 250));
    

        ChoisirCouleurDessin(couleurSerpent);
    /* Afficher la tête du serpent */
    RemplirRectangle(serpent->corps[0].x, serpent->corps[0].y, TAILLE_CASE, TAILLE_CASE);


    for (i = 0; i < serpent->longueur; i++) {
       RemplirRectangle(serpent->corps[i].x, serpent->corps[i].y, TAILLE_CASE, TAILLE_CASE);
    }
ChoisirEcran(0);
AfficherFenetre();
CopierZone(1, 0, 0, 0, LARGEUR_FENETRE, HAUTEUR_FENETRE, 0, 0);
   
}
