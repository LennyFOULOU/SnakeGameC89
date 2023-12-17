#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include"serpent.h"
#include"fond.h"
#include"fruit.h"
#include"gameover.h"
#define LARGEUR_FENETRE 1600
#define HAUTEUR_FENETRE 1000
#define TAILLE_BOUTON 100
#define NB_POMMES 5



void AfficherGameOver() {


ChargerImageFond("image/defaite.png");
}
void ReinitialiserJeu() {
Serpent serpent;
    Pomme pommes[NB_POMMES];

    InitialiserSerpent(&serpent, LARGEUR_FENETRE / 2, LARGEUR_FENETRE / 2);
    dessinerMurs();
    dessinerScore();
    InitialiserPommes(pommes, NB_POMMES);


 
}
