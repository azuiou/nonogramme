#include <stdio.h>
#include <stdlib.h>
#include "grille.h"
#include "algo.h"
#include "affichage.h"
#include <MLV/MLV_all.h>


void usage(char*nom){
    printf("/!\\ Erreur d'usage de %s verifier le nombre d'argument/!\\ \n",nom);
}

int main(int argc, char**argv){
    int etape = 0, interrupteur;
    int cases_decouverte = 0;
    plateau plateau;
    /*test nombre d'arguments*/
    if (argc!=2){
        usage(argv[0]);
        exit (EXIT_FAILURE);
    }
    interrupteur = case_par_case();
    MLV_create_window("Solveur","Solveur", WINDOW_LENGHT, WINDOW_HEIGHT);
    init_plateau(plateau.grille);
    recuperation_donnees(argv[1], plateau.grille,&plateau.cases, &plateau.col, &plateau.ligne); 
    printf(" plateau.cases : %d \n",plateau.cases);
    printf(" plateau.ligne : %d \n",plateau.ligne);
    printf(" plateau.col : %d \n",plateau.col);
    printf("cases remplies : %d\n", cases_decouverte);
    remplie_depart(plateau.grille, plateau, interrupteur, &cases_decouverte);
    bord_fini(plateau.grille,plateau,interrupteur, &cases_decouverte);
    printf("sus : %d\n", plateau.grille[0][2][0]);
    printf("cases remplies : %d\n", cases_decouverte);
    while( cases_decouverte < plateau.cases && etape < 1){
        barre(plateau.grille, plateau, interrupteur);
        /*complete(plateau.grille, plateau, interrupteur, &cases_decouverte);*/
        bord_fini(plateau.grille,plateau,interrupteur, &cases_decouverte);
        etape++;
    }
    affiche_dessin(plateau.grille, plateau.col, plateau.ligne);
    printf("FINI\n");
    MLV_wait_seconds(100);
    MLV_free_window();
    exit (EXIT_SUCCESS);        
}