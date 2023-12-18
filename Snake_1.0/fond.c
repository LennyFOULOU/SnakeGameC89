#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include "fond.h"
#include "serpent.h"
#include "fruit.h"

#define LARGEUR_FENETRE 1600 /* Largeur de la fenêtre */
#define HAUTEUR_FENETRE 1000 /* Hauteur de la fenêtre */
#define NB_COLONNES 60       /* Nombre de colonnes du jeu */
#define NB_LIGNES 40         /* Nombre de lignes du jeu */


void dessinerMurs() {
    unsigned long tempsActuel, tempsEcoule, minutes, secondes; 
    char tempsString[10];
    static unsigned long tempsDebut = 0; /* stocker le temps de début */

    ChoisirCouleurDessin(CouleurParComposante(255, 255, 255)); /* Couleur du texte pour le temps */

    if (tempsDebut == 0) {
      tempsDebut = Microsecondes(); /* Enregistrer le temps de début si ce n'est pas déjà fait */
    }

    tempsActuel = Microsecondes();
    tempsEcoule = (tempsActuel - tempsDebut) / 1000000; /* Convertir en secondes */

    /* Calculer les minutes et les secondes */
    minutes = tempsEcoule / 60;
    secondes = tempsEcoule % 60;

    /* Afficher le temps écoulé en bas à gauche */
    snprintf(tempsString, sizeof(tempsString), "%02lu:%02lu", minutes, secondes);
    EcrireTexte(10, HAUTEUR_FENETRE - 30, tempsString, 2);
}

void dessinerScore() {
  char scoreString[4]; /* Pour stocker le score sous forme de chaîne de caractères */
  snprintf(scoreString, sizeof(scoreString), "%03d", ObtenirScore()); /* Formater le score à trois chiffres (exemple: 001, 010, 100) */

  /* Affichage du score en bas à droite */
  ChoisirCouleurDessin(CouleurParComposante(255, 255, 255)); /* Couleur du texte pour le score */
  EcrireTexte(LARGEUR_FENETRE - 60, HAUTEUR_FENETRE - 30, scoreString, 2);
}

void AfficherEcranDefaite() {
  int imageChargee;
  imageChargee = ChargerImage("image/defaite.xpm", (LARGEUR_FENETRE - 1300) / 2, (HAUTEUR_FENETRE - 900) / 2, 0, 0, 1000, 1000);
    AfficherFenetre();
}

