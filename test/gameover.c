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
    ChoisirCouleurDessin(CouleurParNom("black"));
    RemplirRectangle(0, 0, LARGEUR_FENETRE, HAUTEUR_FENETRE);
    ChoisirCouleurDessin(CouleurParNom("red"));
    EcrireTexte(LARGEUR_FENETRE / 2 - 100, HAUTEUR_FENETRE / 2, "Game Over", 2);
    EcrireTexte(LARGEUR_FENETRE / 2 - 150, HAUTEUR_FENETRE / 2 + 50, "Cliquez pour rejouer", 2);
}

void ReinitialiserJeu() {
Serpent serpent;
    Pomme pommes[NB_POMMES];

    InitialiserSerpent(&serpent, LARGEUR_FENETRE / 2, LARGEUR_FENETRE / 2);
    dessinerMurs();
    dessinerScore();
    InitialiserPommes(pommes, NB_POMMES);


 
}
