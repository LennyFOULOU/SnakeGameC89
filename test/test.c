
#include <graph.h>
#include <time.h>

#include <stdlib.h>
#include<stdio.h>

#define LARGEUR_FENETRE 1600
#define HAUTEUR_FENETRE 1000
#define TAILLE_CASE 10


void TesterChargementSprite() {
    int sprite;
    InitialiserGraphique();
    CreerFenetre(10, 10, LARGEUR_FENETRE, HAUTEUR_FENETRE);


     sprite = ChargerSprite("/test/image/pomme.bmp");
    if (sprite == -1) {
        fprintf(stderr, "Erreur lors du chargement du sprite de la pomme.\n");
        FermerGraphique();
        exit(EXIT_FAILURE);
    }

    ChoisirEcran(1);
    EffacerEcran(CouleurParNom("white"));
    AfficherSprite(sprite, 100, 100); 
    AfficherFenetre();
    ChoisirEcran(0);

   

    FermerGraphique();
    LibererSprites(1);
}

int main() {
    TesterChargementSprite();
    return EXIT_SUCCESS;
}
