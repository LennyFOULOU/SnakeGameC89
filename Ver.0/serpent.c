#include <stdlib.h>
#include <graph.h>
#include <X11/keysym.h>
#include <unistd.h>

/* Définition des constantes pour la fenêtre et le serpent */
#define LARGEUR_FENETRE 800
#define HAUTEUR_FENETRE 600
#define TAILLE_CASE 10
#define NB_COLONNES (LARGEUR_FENETRE / TAILLE_CASE)
#define NB_LIGNES (HAUTEUR_FENETRE / TAILLE_CASE)
#define DELAI 100000 /*Microsecondes*/

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
    Position* trainee; /* Utiliser un nom simple pour la variable */
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

/* Fonction pour afficher le serpent */
int afficherSerpent(Serpent* serpent) {
    couleur couleurSerpent = CouleurParNom("red");

    /* Afficher la tête du serpent */
    RemplirRectangle(serpent->position.x, serpent->position.y, TAILLE_CASE, TAILLE_CASE);

    /* Afficher la trainée du serpent */

    for (i = 0; i < serpent->longueur - 1; i++) {
        RemplirRectangle(serpent->trainee[i].x, serpent->trainee[i].y, TAILLE_CASE, TAILLE_CASE);
    }
    if (serpent->position.x < 0 || serpent->position.x >= LARGEUR_FENETRE ||
        serpent->position.y < 0 || serpent->position.y >= HAUTEUR_FENETRE) {
        return 0; /* Indiquer que le serpent est sorti de la fenêtre */
    }
}

/* Fonction principale du programme */
int main() {
    couleur couleurFond;
    int touchePressee;
        Serpent serpent;

    
    InitialiserGraphique();
    CreerFenetre(10, 10, LARGEUR_FENETRE, HAUTEUR_FENETRE);
    ChoisirTitreFenetre("Serpent");

    couleurFond = CouleurParNom("lightgreen");
    EffacerEcran(couleurFond);


    initialiserSerpent(&serpent);

    touchePressee = 0;
    while (!touchePressee) {
        if (ToucheEnAttente()) {
            KeySym touche = Touche();

            /* Utiliser des conditions pour détecter différentes touches */
            if (touche == XK_Return) {
                /* Code pour la touche "entrée" */
            } else if (touche == XK_Escape) {
                /* Code pour la touche "échappe" */
                touchePressee = 1;
            } else if (touche == XK_Shift_L || touche == XK_Shift_R) {
                /* Code pour les touches "Shift" */
            } else if (touche == XK_Control_L || touche == XK_Control_R) {
                /* Code pour les touches "Control" */
            } else if (touche == XK_KP_Enter) {
                /* Code pour la touche "entrée" du pavé numérique */
            } else if (touche == XK_space) {
                /* Code pour la touche "espace" */
            } else if (touche == XK_Left || touche == XK_Right || touche == XK_Up || touche == XK_Down) {
                serpent.direction = touche;
            }

        } else {
            /* Si aucune touche n'est en attente, continuer à déplacer le serpent dans la dernière direction */
            deplacerSerpent(&serpent);
            EffacerEcran(couleurFond);
            afficherSerpent(&serpent);
            usleep(DELAI); /* Ajout du délai */
        }
    }

    FermerGraphique();
    return EXIT_SUCCESS;
}
