#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include "fond.h"
#include "serpent.h"
#include "fruit.h"
#define LARGEUR_FENETRE 1600 /* Largeur de la fenêtre (60 colonnes de jeu + murs de 2 cases de chaque côté) */
#define HAUTEUR_FENETRE 1000 /* Hauteur de la fenêtre (40 lignes de jeu + murs de 2 cases en haut et en bas) */
#define TAILLE_CASE 10       /* Taille d'une case pour le jeu de Snake */
#define NB_COLONNES 60       /* Nombre de colonnes du jeu */
#define NB_LIGNES 40         /* Nombre de lignes du jeu */
<<<<<<< HEAD
#define DELAI 1           /* Contrôler la vitesse du serpent */
int main() {

=======
#define DELAI 20           /* Contrôler la vitesse du serpent */


int main() {
  
>>>>>>> df51c8bc83b53c2bd4f8abfe5c13d257e24e39e7
  couleur c = CouleurParComposante(200, 200, 200);
  int touchePressee = 0;
  Serpent serpent;

  InitialiserGraphique();
  CreerFenetre(10, 10, LARGEUR_FENETRE, HAUTEUR_FENETRE);
<<<<<<< HEAD
=======

  EffacerEcran(c);
>>>>>>> df51c8bc83b53c2bd4f8abfe5c13d257e24e39e7
  dessinerMurs();
  initialiserSerpent(&serpent);
  InitialiserSprites();

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
      EffacerEcran(c);
      afficherSerpent(&serpent);
       usleep(DELAI);
       dessinerMurs();
      AfficherPommeAleatoire();
      LibererSprites();
   
    }
  }
  FermerGraphique();
  LibererSprites();
  free(serpent.trainee);
  return EXIT_SUCCESS;
  
}

