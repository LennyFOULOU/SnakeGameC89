#include<stdlib.h>
#include<stdio.h>
#include<graph.h>
#include"menu.h"
#define LARGEUR_FENETRE 1600 /* Largeur de la fenêtre */
#define HAUTEUR_FENETRE 1000 /* Hauteur de la fenêtre */


void AfficherMenu() {
  ChargerImage("image/demarrage.png", 0, 50, 0, 0, 1600, 900);
  AfficherFenetre();
  RemplirRectangle(0, HAUTEUR_FENETRE - 80, LARGEUR_FENETRE, 80);
  RemplirRectangle(0, 0, LARGEUR_FENETRE, 50);
}

int GererMenu(void) {
    int x, y;
    while(1) {
        SourisPosition();
        while(!SourisCliquee()) {
            AfficherMenu();
        }
        x = _X;
        y = _Y;

        /* Vérification du clic sur le premier bouton pour lancer le jeu */
        if (x >= 90 && x <= 505 && y >= 390 && y <= 520) {
	  return 1; /* Retourne 1 pour indiquer le démarrage du jeu */
        }

        /* Vérification du clic sur le second bouton pour quitter la fenêtre */
        if (x >= 90 && x <= 505 && y >= 620 && y <= 750) {
	  return 0; /* Retourne 0 pour quitter la fenêtre */
        }
    }
    return 0;
}
