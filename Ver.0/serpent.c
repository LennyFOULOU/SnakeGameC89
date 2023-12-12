#include <stdlib.h>
#include <graph.h>
#include <X11/keysym.h>
#include <unistd.h>

#define LARGEUR_FENETRE 800
#define HAUTEUR_FENETRE 600
#define TAILLE_CASE 10
#define NB_COLONNES (LARGEUR_FENETRE / TAILLE_CASE)
#define NB_LIGNES (HAUTEUR_FENETRE / TAILLE_CASE)
#define DELAI 1 /*Microsecondes*/

int i;

/* Définition de la structure pour la position */
typedef struct {
    int x;
    int y;
} Position;

/* Définition de la structure pour le serpent */
typedef struct {
    Position position;
    int longueur;
    Position* trainee;
    int direction;
} Serpent;

/* Fonction pour initialiser le serpent */
void initialiserSerpent(Serpent* serpent) {
    serpent->position.x = NB_COLONNES / 2 * TAILLE_CASE;
    serpent->position.y = NB_LIGNES / 2 * TAILLE_CASE;
    serpent->longueur = 10;
    serpent->trainee = (Position*)malloc(serpent->longueur * sizeof(Position));
    serpent->direction = XK_Right; /* Direction initiale */
}

/* Fonction pour déplacer le serpent */
int deplacerSerpent(Serpent* serpent) {
    /* Sauvegarder la position actuelle de la tête du serpent */
    Position ancienneTete = serpent->position;

    /* Mettre à jour la position de la tête en fonction de la direction */
    if (serpent->direction == XK_Left) {
        serpent->position.x -= TAILLE_CASE;
    } else if (serpent->direction == XK_Right) {
        serpent->position.x += TAILLE_CASE;
    } else if (serpent->direction == XK_Up) {
        serpent->position.y -= TAILLE_CASE;
    } else if (serpent->direction == XK_Down) {
        serpent->position.y += TAILLE_CASE;
    }

    /* Mettre à jour la trainée du serpent */
    if (serpent->longueur > 1) {
        /* Déplacer chaque segment de la trainée */
        int i;
        for (i = serpent->longueur - 1; i > 0; i--) {
            serpent->trainee[i] = serpent->trainee[i - 1];
        }
        /* Mettre la vieille position de la tête comme le premier segment de la trainée */
        serpent->trainee[0] = ancienneTete;
    }



}

int afficherSerpent(Serpent* serpent) { /* Fonction pour afficher le serpent */
    int i;
    couleur couleurMurs = CouleurParComposante(0, 0, 0);
    couleur couleurSerpent = CouleurParComposante(34, 139, 34);
        ChoisirCouleurDessin(couleurSerpent);

    /* Afficher la tête du serpent */
    RemplirRectangle(serpent->position.x, serpent->position.y, TAILLE_CASE, TAILLE_CASE);

    /* Afficher la trainée du serpent */

    for (i = 0; i < serpent->longueur - 1; i++) {
        RemplirRectangle(serpent->trainee[i].x, serpent->trainee[i].y, TAILLE_CASE, TAILLE_CASE);
    }
     /* Réinitialiser la couleur des murs (noir) */
    ChoisirCouleurDessin(couleurMurs);
    
    if (serpent->position.x < 0 || serpent->position.x >= LARGEUR_FENETRE ||
        serpent->position.y < 0 || serpent->position.y >= HAUTEUR_FENETRE) {
        return 0; /* Indiquer que le serpent est sorti de la fenêtre */
    }
}

