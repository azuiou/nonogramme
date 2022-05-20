#include <stdio.h>
#include <stdlib.h>
#include "sauvegarde.h"

void sauvegarde(plateau plateau, char * fichier){
    FILE * fic = NULL;
    int i, j, k;
    fic = fopen(fichier, "w");
    if(fic == NULL){
        printf("erreur ouverture du fichier de sauvegarde\n");
        exit(EXIT_FAILURE);
    }
    /*sauvegarde données de colonnes*/
    for( i = 1; i <= plateau.col; i++){
        k = 0;
        while(plateau.grille[0][i][k] != 0){
            fprintf(fic,"%d ",plateau.grille[0][i][k]);
            k++;    
        }
        fprintf(fic,"%d ",-1);
        fprintf(fic,"%c",'\n');
    }
    /*sauvegarde données de lignes*/
    for( i = 1; i <= plateau.ligne; i++){
        k = 0;
        while(plateau.grille[i][0][k] != 0){
            fprintf(fic,"%d ",plateau.grille[i][0][k]);
            k++;    
        }
        fprintf(fic,"%d ",-1);
        fprintf(fic,"%c",'\n');
    }
    /* sauvegarde résolution */
    for( i = 1; i <= plateau.ligne; i++){
        for( j = 1; j <= plateau.col; j++){
            fprintf(fic, "%d ", plateau.grille[i][j][0]);
        }
        fprintf(fic, "\n");
    }
    fclose(fic);
}