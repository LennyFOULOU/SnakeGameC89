#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include "serpent.h"
#include "fruit.h"
#include "fond.h"

#define LARGEUR_FENETRE 1600 /* Largeur de la fenêtre (60 colonnes de jeu + murs de 2 cases de chaque côté) */
#define HAUTEUR_FENETRE 1000 /* Hauteur de la fenêtre (40 lignes de jeu + murs de 2 cases en haut et en bas) */
#define TAILLE_CASE 20       /* Taille d'une case pour le jeu de Snake */
#define NB_COLONNES 60       /* Nombre de colonnes du jeu */
#define NB_LIGNES 40         /* Nombre de lignes du jeu */
#define CYCLE 100000
#define VITESSE_SERPENT 100000
#define NB_POMMES 5
#define NB_POINTS_VICTOIRE 500


int main() {

  couleur couleurFond = CouleurParComposante(200, 200, 200);
  int touchePressee, i;
  int pommeMangee;
  Serpent serpent;
  unsigned long tempsPrecedent = Microsecondes();
  unsigned long tempsActuel;
  couleur couleurMurs = CouleurParComposante(0, 0, 0);
  int Pause;
  Pomme pommes[NB_POMMES];
  int defaite = 0;

  unsigned long tempsDebut = Microsecondes(); /* Enregistrer le temps de début du jeu */
  unsigned long tempsEcoule = 0; 
  
  srand(time(NULL));
  
  InitialiserGraphique();
  CreerFenetre(10, 10, LARGEUR_FENETRE, HAUTEUR_FENETRE);
  EffacerEcran(couleurFond);
  AfficherFenetre();
  InitialiserPommes(pommes, NB_POMMES); 
  GenererPommes(pommes, NB_POMMES);
  InitialiserSerpent(&serpent, LARGEUR_FENETRE / 2, HAUTEUR_FENETRE / 2);

    while (1) {

        if (ToucheEnAttente()) {
            int touche = Touche();
            if (touche == ' ') {
                Pause = !Pause;
            }
            if (touche == XK_Left && serpent.directionX != 1) {
                serpent.directionX = -1;
                serpent.directionY = 0;
            } else if (touche == XK_Right && serpent.directionX != -1) {
                serpent.directionX = 1;
                serpent.directionY = 0;
            } else if (touche == XK_Up && serpent.directionY != 1) {
                serpent.directionX = 0;
                serpent.directionY = -1;
            } else if (touche == XK_Down && serpent.directionY != -1) {
                serpent.directionX = 0;
                serpent.directionY = 1;
            } else if (touche == XK_Escape) { 
	        break;
            }
        }

        if(!Pause) {
        
        if (ObtenirScore() >= 50 && ObtenirScore() <100) {
            AfficherBarreProgression(10);
        } else if (ObtenirScore() >= 100 && ObtenirScore() <150) {
            AfficherBarreProgression(20);
        } else if (ObtenirScore() >= 150 && ObtenirScore() <200) {
            AfficherBarreProgression(30);
        } else if (ObtenirScore() >= 200 && ObtenirScore() <250) {
            AfficherBarreProgression(40);
        } else if (ObtenirScore() >= 250 && ObtenirScore() <300) {
            AfficherBarreProgression(50);
        } else if (ObtenirScore() >= 300 && ObtenirScore() <350) {
            AfficherBarreProgression(60);
        } else if (ObtenirScore() >= 350 && ObtenirScore() <400) {
            AfficherBarreProgression(70);
        } else if (ObtenirScore() >= 400 && ObtenirScore() <450) {
            AfficherBarreProgression(80);
        } else if (ObtenirScore() >= 450 && ObtenirScore() <500) {
            AfficherBarreProgression(90);
        } else if (ObtenirScore() >= 500) {
            AfficherBarreProgression(100);
        } 

        tempsActuel = Microsecondes();
        tempsEcoule = (tempsActuel - tempsDebut) / 1000000;
        if (tempsActuel - tempsPrecedent >= VITESSE_SERPENT) {
        MangerPomme(pommes, NB_POMMES, serpent.corps[0].x, serpent.corps[0].y, &pommeMangee);
        if (pommeMangee) {
        serpent.longueur+=2;  
        GererPommesMangees(pommes, NB_POMMES);
        pommeMangee = 0;
        }
        DeplacerSerpent(&serpent);
        if (VerifierCollision(&serpent)) {
	      defaite = 1;
	      Pause = 1;	      
        }
        EffacerEcran(couleurFond);
        DessinerSerpent(&serpent);
        AfficherPommes(pommes, NB_POMMES);
        ChoisirCouleurDessin(couleurMurs);
        RemplirRectangle(0, HAUTEUR_FENETRE - 80, LARGEUR_FENETRE, 80); 
        dessinerMurs();
	    dessinerScore();
        AfficherFenetre();
        tempsPrecedent = tempsActuel;  
        }
	    if (defaite && Pause) {    
        if (ObtenirScore() >= NB_POINTS_VICTOIRE) {
        AfficherEcranVictoire(); 
        } else {
        AfficherEcranDefaite();
        }
        AfficherFenetre();
        dessinerScoreFin();
        dessinerTempsFinal(tempsEcoule);
	    while (1) {        
        verifierClicQuitter();
        if (ToucheEnAttente()) {
        int touche = Touche();
        if (touche == XK_Escape) {
        break;
            }
        }
        }
        }
   }
   }
   for (i = 0; i < NB_POMMES; i++) {
    LibererSprite(pommes[i].sprite);
  }
    
   FermerGraphique();
   return EXIT_SUCCESS;
 }
    
   
    



