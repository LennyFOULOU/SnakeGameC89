#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include "../fichier.h/serpent.h"
#include "../fichier.h/fruit.h"
#include "../fichier.h/fond.h"
#include "../fichier.h/boss.h"
#include "../fichier.h/menu.h"
#define LARGEUR_FENETRE 1600 /* Largeur de la fenêtre */
#define HAUTEUR_FENETRE 1000 /* Hauteur de la fenêtre */
#define TAILLE_CASE 20       /* Taille d'une case pour le jeu de Snake */
#define NB_COLONNES 60       /* Nombre de colonnes du jeu */
#define NB_LIGNES 40         /* Nombre de lignes du jeu */
#define CYCLE 100000
#define VITESSE_SERPENT 100000
#define NB_POMMES 5
#define NB_POINTS_VICTOIRE 500
#define SEUIL_BOSS_1 30
#define SEUIL_BOSS_2 200
#define SEUIL_BOSS_3 350
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
  unsigned long tempsDebut = Microsecondes(); 
  unsigned long tempsEcoule = 0; 
  int scoreActuel, scorePrecedent = 0;  
  int boss1Initialise = 0, boss2Initialise = 0, boss3Initialise = 0;
  Boss boss1, boss2, boss3;
  EffetBoss effetBoss1, effetBoss2, effetBoss3;
  int effetBoss1Initialise = 0, effetBoss2Initialise = 0, effetBoss3Initialise = 0;
  int debutJeu = 0;
  srand(time(NULL));
  InitialiserGraphique();
  CreerFenetre(10, 10, LARGEUR_FENETRE, HAUTEUR_FENETRE);
  EffacerEcran(couleurFond);
          AfficherMenu();

  AfficherFenetre();
debutJeu = GererMenu();
  if (debutJeu) {
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
        
        tempsActuel = Microsecondes();
        tempsEcoule = (tempsActuel - tempsDebut) / 1000000;
        if (tempsActuel - tempsPrecedent >= VITESSE_SERPENT) {
        MangerPomme(pommes, NB_POMMES, serpent.corps[0].x, serpent.corps[0].y, &pommeMangee);
        if (pommeMangee) {
        serpent.longueur+=2;  
        GererPommesMangees(pommes, NB_POMMES, &serpent);
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
        if (ObtenirScore() >= (SEUIL_BOSS_1 - 10) && !effetBoss1Initialise) {
            InitialiserEffetBoss1(&effetBoss1);
            effetBoss1Initialise = 1;
        }
        if (ObtenirScore() >= (SEUIL_BOSS_2 - 10) && !effetBoss2Initialise) {
            InitialiserEffetBoss2(&effetBoss2);
            effetBoss2Initialise = 1;
        }
        if (ObtenirScore() >= (SEUIL_BOSS_3 - 10) && !effetBoss3Initialise) {
            InitialiserEffetBoss3(&effetBoss3);
            effetBoss3Initialise = 1;
        }
        if (effetBoss1Initialise && ObtenirScore() < SEUIL_BOSS_1 ) {
            AfficherEffetBoss(&effetBoss1);
        }
        if (effetBoss2Initialise && ObtenirScore() < SEUIL_BOSS_2 ) {
            AfficherEffetBoss(&effetBoss2);
        }
        if (effetBoss3Initialise && ObtenirScore() < SEUIL_BOSS_3 ) {
            AfficherEffetBoss(&effetBoss3);
        }
	
        if (ObtenirScore() >= SEUIL_BOSS_1 && !boss1Initialise) {
        InitialiserBoss1(&boss1);
        boss1Initialise = 1;
        }
	if (ObtenirScore() >= SEUIL_BOSS_2 && !boss2Initialise) {
        InitialiserBoss2(&boss2);
        boss2Initialise = 1;
        }
        if (ObtenirScore() >= SEUIL_BOSS_3 && !boss3Initialise) {
        InitialiserBoss3(&boss3);
        boss3Initialise = 1;
        }
	if (boss1Initialise) {
        DeplacerBoss1(&boss1);
        DessinerBoss(boss1.x, boss1.y, boss1.sprite);
        if (CollisionAvecBoss1(&serpent, &boss1)) {
	defaite = 1;
        Pause = 1;
        }
        }
        if (boss2Initialise) {
        DeplacerBoss2(&boss2);
        DessinerBoss(boss2.x, boss2.y, boss2.sprite);
        if (CollisionAvecBoss2(&serpent, &boss2)) {
	defaite = 1;
        Pause = 1;
        }
	}
        if (boss3Initialise) {
        DeplacerBoss3(&boss3);
        DessinerBoss(boss3.x, boss3.y, boss3.sprite);
        if (CollisionAvecBoss3(&serpent, &boss3)) {
	defaite = 1;
        Pause = 1;
        }
        }
        scoreActuel = ObtenirScore();
        if (scoreActuel != scorePrecedent) {
        if (scoreActuel>= 50 && scoreActuel <100) {
            AfficherBarreProgression(10);
        } else if (scoreActuel >= 100 && scoreActuel <150) {
            AfficherBarreProgression(20);
        } else if (scoreActuel >= 150 && scoreActuel <200) {
            AfficherBarreProgression(30);
        } else if (scoreActuel >= 200 && scoreActuel <250) {
            AfficherBarreProgression(40);
        } else if (scoreActuel >= 250 && scoreActuel <300) {
            AfficherBarreProgression(50);
        } else if (scoreActuel >= 300 && scoreActuel <350) {
            AfficherBarreProgression(60);
        } else if (scoreActuel >= 350 && scoreActuel <400) {
            AfficherBarreProgression(70);
        } else if (scoreActuel >= 400 && scoreActuel <450) {
            AfficherBarreProgression(80);
        } else if (scoreActuel >= 450 && scoreActuel <500) {
            AfficherBarreProgression(90);
        } else if (scoreActuel >= 500) {
            AfficherBarreProgression(100);
        } 
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
    }
    
    for (i = 0; i < NB_POMMES; i++) {
    LibererSprite(pommes[i].sprite);
    }
    if (boss1Initialise) {
    LibererSprite(boss1.sprite);
    }
    if (boss2Initialise) {
    LibererSprite(boss2.sprite);
    }
    if (boss3Initialise) {
    LibererSprite(boss3.sprite);
    }
    if (effetBoss1Initialise) {
    LibererSprite(effetBoss1.sprite);
    }
    if (effetBoss2Initialise) {
    LibererSprite(effetBoss2.sprite);
    }
    if (effetBoss3Initialise) {
    LibererSprite(effetBoss3.sprite);
    }
    
  }
   FermerGraphique();
   return EXIT_SUCCESS;
}
