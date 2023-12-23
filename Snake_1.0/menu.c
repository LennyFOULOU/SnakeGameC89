#include<stdlib.h>
#include<stdio.h>
#include<graph.h>
#include"menu.h"
#define LARGEUR_FENETRE 1600 /* Largeur de la fenêtre */
#define HAUTEUR_FENETRE 1000 /* Hauteur de la fenêtre */


void AfficherMenu() {
ChargerImage("image/demarrage.png", (LARGEUR_FENETRE - 1300) / 2, (HAUTEUR_FENETRE - 900) / 2, 0, 0, 1000, 1000);
  AfficherFenetre();
}

    int GererMenu(void) {
    int x, y;
   while(1) {
    SourisPosition();
    while(!SourisCliquee()) {
      AfficherMenu();
    }
    return 1;
   }
return 0;
}

