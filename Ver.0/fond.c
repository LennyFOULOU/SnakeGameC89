#include <stdlib.h>
#include <graph.h>
#include <X11/keysym.h>

#define LARGEUR_FENETRE 640 // Largeur de la fenêtre (60 colonnes de jeu + murs de 2 cases de chaque côté)
#define HAUTEUR_FENETRE 440 // Hauteur de la fenêtre (40 lignes de jeu + murs de 2 cases en haut et en bas)

#define TAILLE_CASE 10       // Taille d'une case pour le jeu de Snake

#define NB_COLONNES 60 // Nombre de colonnes du jeu
#define NB_LIGNES 40   // Nombre de lignes du jeu

void dessinerMurs() {
    // Dessiner le mur du haut
    DessinerRectangle(0, 0, LARGEUR_FENETRE, TAILLE_CASE * 2);
    // Dessiner le mur du bas
    DessinerRectangle(0, HAUTEUR_FENETRE - TAILLE_CASE * 2, LARGEUR_FENETRE, TAILLE_CASE * 2);
    // Dessiner le mur de gauche
    DessinerRectangle(0, 0, TAILLE_CASE * 2, HAUTEUR_FENETRE);
    // Dessiner le mur de droite
    DessinerRectangle(LARGEUR_FENETRE - TAILLE_CASE * 2, 0, TAILLE_CASE * 2, HAUTEUR_FENETRE);
}

int main() {
    InitialiserGraphique();
    CreerFenetre(10, 10, LARGEUR_FENETRE, HAUTEUR_FENETRE);
    ChoisirTitreFenetre("Snake");
    
    couleur couleurFond = CouleurParNom("grey"); // Couleur de fond pour la zone de jeu
    EffacerEcran(couleurFond);
    
    couleur couleurMurs = CouleurParNom("black"); // Couleur des murs
    ChoisirCouleurDessin(couleurMurs); // Sélectionner la couleur pour dessiner les murs
    dessinerMurs(); // Dessiner les murs autour de la zone de jeu
    
    int touchePressee = 0; // Variable pour détecter si une touche a été pressée

    while (!touchePressee) {
        if (ToucheEnAttente()) {
            KeySym touche = Touche();
            if (touche == XK_Escape) { // Si la touche appuyée est Échap
                touchePressee = 1; // Sortir de la boucle
            }
        }
    }

    FermerGraphique();
    return EXIT_SUCCESS;
}
