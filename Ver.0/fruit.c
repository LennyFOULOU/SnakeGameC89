#include<stdlib.h>
#include<stdio.h>
#include<graph.h>

/* Définition des constantes pour la fenêtre et le serpent */
#define LARGEUR_FENETRE 1600
#define HAUTEUR_FENETRE 1800
#define TAILLE_CASE 10
#define NB_COLONNES 60
#define NB_LIGNES 40
#define DELAI 100000 /*Microseconde*/

int pomme,x[5], y[5];
int i;
void Pomme(){

    for(i = 0; i< 5; i++){
        AfficherSprite(pomme, x[i], y[i]);
    }
    
}
