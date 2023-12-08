#include <stdlib.h>
#include <graph.h>
#include <X11/keysym.h>

#define LARGEUR_FENETRE 800
#define HAUTEUR_FENETRE 600
#define TAILLE_CASE 20
#define NB_COLONNES (LARGEUR_FENETRE / TAILLE_CASE)
#define NB_LIGNES (HAUTEUR_FENETRE / TAILLE_CASE)

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position position;
    int longueur;
    Position* traînée;
} Serpent;

void initialiserSerpent(Serpent* serpent) {
    serpent->position.x = NB_COLONNES / 2 * TAILLE_CASE;
    serpent->position.y = NB_LIGNES / 2 * TAILLE_CASE;
    serpent->longueur = 1;
    serpent->traînée = (Position*)malloc(serpent->longueur * sizeof(Position));
}

void deplacerSerpent(Serpent* serpent, int direction) {
    // Sauvegarder la position actuelle de la tête du serpent
    Position ancienneTete = serpent->position;

    // Mettre à jour la position de la tête en fonction de la direction
    switch (direction) {
        case XK_Left:
            serpent->position.x -= TAILLE_CASE;
            break;
        case XK_Right:
            serpent->position.x += TAILLE_CASE;
            break;
        case XK_Up:
            serpent->position.y -= TAILLE_CASE;
            break;
        cas