#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include "fond.h"
#include "serpent.h"
#include "fruit.h"

#define LARGEUR_FENETRE 1600 /* Largeur de la fenêtre (60 colonnes de jeu + murs de 2 cases de chaque côté) */
#define HAUTEUR_FENETRE 1000 /* Hauteur de la fenêtre (40 lignes de jeu + murs de 2 cases en haut et en bas) */
#define NB_COLONNES 60       /* Nombre de colonnes du jeu */
#define NB_LIGNES 40         /* Nombre de lignes du jeu */

    unsigned long tempsDebut = 0; /* Variable globale pour stocker le temps de début */


void dessinerMurs() { /* Dessiner les murs en remplissant des rectangles */
    couleur couleurMurs = CouleurParComposante(0, 0, 0);
    unsigned long tempsActuel, tempsEcoule, minutes, secondes; 
    char tempsString[10];

    RemplirRectangle(0, HAUTEUR_FENETRE - 80, LARGEUR_FENETRE, 80);                            /* Rectangle supplémentaire en bas */

    ChoisirCouleurDessin(CouleurParComposante(255, 255, 255)); /*Couleur du texte pour le temps */
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
