#include <stdio.h>
#include <stdlib.h>
#include "grille.h"
#include "algo.h"
#include "affichage.h"
#include <MLV/MLV_all.h>
#include "sauvegarde.h"
#include <assert.h>


void usage(char*nom){
    printf("/!\\ Erreur d'usage de %s verifier le nombre d'argument/!\\ \n",nom);
}

int main(int argc, char**argv){
    int etape = 0, interrupteur;
    int cases_decouverte = 0;
    plateau plateau;
    char * save;
    int choix;
    /*test nombre d'arguments*/
    if (argc!=2){
        usage(argv[0]);
        exit (EXIT_FAILURE);
    }
    save = malloc(128 * sizeof(char));
    interrupteur = case_par_case();
    MLV_create_window("Solveur","Solveur", WINDOW_LENGHT, WINDOW_HEIGHT);
    init_plateau(plateau.grille);
    recuperation_donnees(argv[1], plateau.grille,&plateau.cases, &plateau.col, &plateau.ligne); 
    printf(" plateau.cases : %d \n",plateau.cases);
    printf(" plateau.ligne : %d \n",plateau.ligne);
    printf(" plateau.col : %d \n",plateau.col);
    printf("cases remplies : %d\n", cases_decouverte);
    remplie_depart(plateau.grille, plateau, interrupteur, &cases_decouverte);
    remplie_partiel(plateau.grille, plateau, interrupteur, &cases_decouverte);
    bord_fini(plateau.grille,plateau,interrupteur, &cases_decouverte);
    printf("sus : %d\n", plateau.grille[0][2][0]);
    printf("cases remplies : %d\n", cases_decouverte);
    while( cases_decouverte < plateau.cases && etape < 8){
        printf("decouvert1 : %d\n", cases_decouverte);
        printf("a decouvrir : %d \n", plateau.cases);
        barre(plateau.grille, plateau);
        //complete(plateau.grille, plateau, interrupteur, &cases_decouverte);
        printf("decouvert2 : %d\n", cases_decouverte);
        bord_fini(plateau.grille,plateau,interrupteur, &cases_decouverte);
        printf("decouvert3 : %d\n", cases_decouverte);
        etape++;
    }
    printf("decouvert4 : %d\n", cases_decouverte);
    printf("a decouvrir : %d \n", plateau.cases);
    printf("%d etapes pour trouver la solution\n", etape);
    affiche_dessin(plateau.grille, plateau.col, plateau.ligne);
    printf("FINI\n");
    if (verif( plateau.grille, plateau) == 1){
        printf("LA RESOLUTION EST BONNE\n");
        printf("Voulez-vous sauvegarder ?\n0 : non\nautre : oui\n");
        if(scanf("%d",&choix) != 1){
            printf("erreur recuperation de données\n");
            exit(EXIT_FAILURE);
        }
        if(choix != 0){
            printf("Entrez nom de sauvegarde (128 caracteres max)\n");
            if(scanf("%s",save) != 1){
                printf("%s\n", save);
                printf("erreur recuperation du fichier de sauvegarde\n");
                exit(EXIT_FAILURE);
            }
            sauvegarde(plateau, save);
        }
    }
    else{
        printf("LA RESOLUTION EST MAUVAISE\n");
    }
    MLV_wait_seconds(100);
    MLV_free_window();
    exit (EXIT_SUCCESS);        
}