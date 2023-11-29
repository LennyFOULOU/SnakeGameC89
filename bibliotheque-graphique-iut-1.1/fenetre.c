#include<stdlib.h>
#include<stdio.h>
#include<graph.h>
    int main () {
        InitialiserGraphique();
         CreerFenetre(10,20,600,400);
         couleur c;
         c = CouleurParNom("red");
         void ChoisirCouleurDessin(couleur c);
         Touche();
         

    
         
         return EXIT_SUCCESS;
    }