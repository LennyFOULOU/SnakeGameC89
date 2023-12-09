
 #include <stdlib.h>
#include <graph.h>
#include <X11/keysym.h>
#define LARGEUR_FENETRE 1600 /* Largeur de la fenêtre (60 colonnes de jeu + murs de 2 cases de chaque côté) */
#define HAUTEUR_FENETRE 1000 /* Hauteur de la fenêtre (40 lignes de jeu + murs de 2 cases en haut et en bas) */
#define TAILLE_CASE 10       /* Taille d'une case pour le jeu de Snake */
#define NB_COLONNES 60       /* Nombre de colonnes du jeu */
#define NB_LIGNES 40         /* Nombre de lignes du jeu */
void dessinerMurs() {
    /* Dessiner les murs en remplissant des rectangles */
    couleur couleurMurs = CouleurParNom("black");
    /* Mur du haut */
    RemplirRectangle(0, 0, LARGEUR_FENETRE, TAILLE_CASE * 2);
    /* Mur du bas */
    RemplirRectangle(0, HAUTEUR_FENETRE - TAILLE_CASE * 2, LARGEUR_FENETRE, TAILLE_CASE * 2);
    /* Mur de gauche */
    RemplirRectangle(0, 0, TAILLE_CASE * 2, HAUTEUR_FENETRE);
    /* Mur de droite */
    RemplirRectangle(LARGEUR_FENETRE - TAILLE_CASE * 2, 0, TAILLE_CASE * 2, HAUTEUR_FENETRE);
    /* Rectangle supplémentaire en bas */
    RemplirRectangle(0, HAUTEUR_FENETRE - 80, LARGEUR_FENETRE, 80);
}
int main() {
    couleur couleurFond;
    int touchePressee;
    InitialiserGraphique();
    CreerFenetre(10, 10, LARGEUR_FENETRE, HAUTEUR_FENETRE);
    ChoisirTitreFenetre("Snake");
    
    couleurFond = CouleurParNom("grey"); /* Couleur de fond pour la zone de jeu */
    EffacerEcran(couleurFond);
    dessinerMurs(); /* Dessiner les murs autour de la zone de jeu */
    
    touchePressee = 0; /* Variable pour détecter si une touche a été pressée */
    while (!touchePressee) {
        if (ToucheEnAttente()) {
            KeySym touche = Touche();
            if (touche == XK_Escape) { /* Si la touche appuyée est Échap */
                touchePressee = 1; /* Sortir de la boucle */
            }
        }
    }
    
    FermerGraphique();
    return EXIT_SUCCESS;
}
