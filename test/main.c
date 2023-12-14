#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include "serpent.h"
#include "fruit.h"

#define LARGEUR_FENETRE 1600 /* Largeur de la fenêtre (60 colonnes de jeu + murs de 2 cases de chaque côté) */
#define HAUTEUR_FENETRE 1000 /* Hauteur de la fenêtre (40 lignes de jeu + murs de 2 cases en haut et en bas) */
#define TAILLE_CASE 20       /* Taille d'une case pour le jeu de Snake */
#define NB_COLONNES 60       /* Nombre de colonnes du jeu */
#define NB_LIGNES 40         /* Nombre de lignes du jeu */
#define CYCLE 100000
#define VITESSE_SERPENT 100000



int main() {


  couleur couleurFond = CouleurParComposante(200, 200, 200);
  int touchePressee, i;
  Serpent serpent;
        unsigned long tempsPrecedent = Microsecondes();
    unsigned long tempsActuel;
      couleur couleurMurs = CouleurParComposante(0, 0, 0);



  InitialiserGraphique();
  CreerFenetre(10, 10, LARGEUR_FENETRE, HAUTEUR_FENETRE);
 
  EffacerEcran(couleurFond);

  AfficherFenetre();


    InitialiserSerpent(&serpent, LARGEUR_FENETRE / 2, HAUTEUR_FENETRE / 2);
    
    while (1) {
        if (ToucheEnAttente()) {
            int touche = Touche();
            if (touche == XK_Left && serpent.directionX != 1) {
                serpent.directionX = -1;
                serpent.directionY = 0;
            } else if (touche == XK_Right && serpent.directionX != -1) {
                serpent.directionX = 1;
                serpent.directionY = 0;
            } else if (touche == XK_Up && serpent.directionY != 1) {
                serpent.directionX = 0;
                serpent.directionY = -1;
            } else if (touche == XK_Down && serpent.directionY != -1) {
                serpent.directionX = 0;
                serpent.directionY = 1;
            }
        }

        tempsActuel = Microsecondes();
        if (tempsActuel - tempsPrecedent >= VITESSE_SERPENT) {
            DeplacerSerpent(&serpent);
            if (VerifierCollision(&serpent)) {
                FermerGraphique();
                return EXIT_SUCCESS;
            }

            EffacerEcran(couleurFond);
            DessinerSerpent(&serpent);
            AfficherFenetre();
            tempsPrecedent = tempsActuel;
	    ChoisirCouleurDessin(couleurMurs);
	    RemplirRectangle(0, HAUTEUR_FENETRE - 80, LARGEUR_FENETRE, 80);                       
        }
    }

    FermerGraphique();
    return EXIT_SUCCESS;
}



