#include <stdlib.h>
#include <graph.h>
#include <time.h>
#include "fruit.h"

#define TAILLE_POMME 20
#define NB_SPRITES 5         
#define LARGEUR_FENETRE 1600
#define HAUTEUR_FENETRE 1000        
#define NB_COLONNES 60       
#define NB_LIGNES 40       

void PlacerPomme(Pomme *pomme) {
    int i;
    for (i = 0; i < NB_SPRITES; i++) {
        do {
            pomme[i].position.x = rand() % (LARGEUR_FENETRE / TAILLE_CASE) * TAILLE_CASE;
            pomme[i].position.y = rand() % ((HAUTEUR_FENETRE - 80) / TAILLE_CASE) * TAILLE_CASE;
        } while (!EstPositionValide(pomme, i)); 

        pomme[i].disponible = 1;

        ChoisirEcran(1);
        AfficherSprite(pomme[i].sprite, pomme[i].position.x, pomme[i].position.y);
        ChoisirEcran(0);
        CopierZone(1, 0, 0, 0, LARGEUR_FENETRE, HAUTEUR_FENETRE, 0, 0);
    }
}


int EstPositionValide(Pomme *pomme, int index) {
    int i;
    for (i = 0; i < index; i++) {
        if ((pomme[index].position.x == pomme[i].position.x) && (pomme[index].position.y == pomme[i].position.y)) {
            return 0;
        }
    }

    if (pomme[index].position.y >= HAUTEUR_FENETRE - 80) {
        return 0; 
    }

    return 1;
}
