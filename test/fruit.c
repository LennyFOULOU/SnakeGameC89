#include <stdlib.h>
#include <graph.h>
#include <time.h>
#include "fruit.h"

#define TAILLE_POMME 20
#define NB_SPRITES 5         
#define LARGEUR_FENETRE 1600
#define HAUTEUR_FENETRE 1000 
#define TAILLE_CASE 10       
#define NB_COLONNES 60       
#define NB_LIGNES 40       

void InitialiserPomme(Pomme *pomme) {
    pomme->disponible = 0;
    pomme->sprite = ChargerSprite("/test/image/pomme.bmp"); 
}

int MangerPomme(Serpent *serpent, Pomme *pomme) {
    int teteX = serpent->corps[0].x;
    int teteY = serpent->corps[0].y;

    if (teteX == pomme->position.x && teteY == pomme->position.y && pomme->disponible) {
        pomme->disponible = 0;
        LibererSprite(pomme->sprite); 
        return 1;
    }

    return 0;
}

void PlacerPomme(Pomme *pomme) {
    pomme->position.x = rand() % (LARGEUR_FENETRE / TAILLE_CASE) * TAILLE_CASE;
    pomme->position.y = rand() % (HAUTEUR_FENETRE / TAILLE_CASE) * TAILLE_CASE;
    pomme->disponible = 1;

    ChoisirEcran(1);
    AfficherSprite(pomme->sprite, pomme->position.x, pomme->position.y);
    ChoisirEcran(0);
    CopierZone(1, 0, 0, 0, LARGEUR_FENETRE, HAUTEUR_FENETRE, 0, 0);
}
