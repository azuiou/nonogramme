#include <stdio.h>
#include <stdlib.h>
#include "type.h"

void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

/* initialise le plateau */
void init_plateau(int t[LIGNE][COL][X]){
    int i,j,k;
    for(i = 0; i<LIGNE; i++){
        for(j = 0; j<COL; j++){
            t[i][j][0] = 0;
            for(k=0;k<X;k++){
                t[i][j][k]=0;
            }
        }
    }
}

/* affiche grille plus donnes pour reesoudre */
void affiche_grille(int t[LIGNE][COL][X],plateau plateau){
    int i,j,k;
    printf("grille à resoudre \n");
    for(i = 1; i<plateau.ligne+1; i++){
        for(j = 1; j<plateau.col+1; j++){
            printf("%d ",t[i][j][0]);
        }
        printf("\n");
    }
    /*affichage donnees de colonnes */
    for(j = 1; j<=plateau.col; j++){
        printf("colonne %d \n",j);
        for(k = 0; k<X; k++){
                printf("%d ",t[0][j][k]);
        }
        printf("\n");
    }
    /*affichage donnees de lignes*/
    for(j = 1; j<=plateau.ligne; j++){
        printf("ligne %d \n",j);
        for(k = 0; k<X; k++){
                printf("%d ",t[j][0][k]);
        }
        printf("\n");
    }
}

/* fais entrez les donnees necessaires à l'utilisateur */
void recuperation_donnees(char fic[50], int t[LIGNE][COL][X], int*cases, int *col, int*ligne){
    int tmp;
    int i = 0,j=0;
    FILE *fichier = fopen(fic, "r");
    if(fichier==NULL){
        printf("fichier non existant \n");
        exit(EXIT_FAILURE);
    }
    if(fscanf(fichier,"%d %d",ligne, col)!=2){/*recuperation de ligne et col (premiere ligne du fichier)*/
        printf("erreur fichier premiere ligne doit etre deux entier séparés par un espace (ligne colonnes) \n");
        exit(EXIT_FAILURE);
    };/* premiere ligne nombre ligne colonnes */
    while((fscanf(fichier,"%d",&tmp))==1){/*recuperation des valeurs necessaires pour resoudre*/
        if(tmp == -1)/*retour a la ligne*/{
            j=0;
            i++;
        }
        else{
            if(i<*col){
                t[0][i+1][j] = tmp;/*stock les valeurs des colonnes*/
                *cases +=tmp;/*compte le nombre de cases à remplir dans la grille*/
            }
            else
                t[i+1-*col][0][j] = tmp;/*stock les valeurs des lignes*/
            j++;
        }
    }
    fclose(fichier);
}


int verif(int t[LIGNE][COL][X], plateau plateau){
    int i = 1, acc, acc2 ,j, longueur, continuer = 1;
    /*lignes*/
    while( i <= plateau.ligne && continuer == 1){
        j = 0;
        acc = 0;
        acc2 = 0;
        longueur = 0;
        while(t[i][0][longueur] != 0)
            longueur++;
        while( j < longueur ){
            acc += t[i][0][j];
            j++;
        }
        j = 1;
        while(j <= plateau.col){
            if(t[i][j][0] == 1)
                acc2 ++;
            j++;
        }
        if( acc != acc2){
            continuer = 0;
            return 0;
        }
        i++;
    }
    /*colonnes*/
    while( i <= plateau.col && continuer == 1){
        j = 0;
        acc = 0;
        acc2 = 0;
        longueur = 0;
        while(t[0][i][longueur] != 0)
            longueur++;
        while( j < longueur ){
            acc += t[0][i][j];
            j++;
        }
        j = 1;
        while(j <= plateau.ligne){
            if(t[j][i][0] == 1)
                acc2 ++;
            j++;
        }
        if( acc != acc2){
            continuer = 0;
            return 0;
        }
        i++;
    }
    return 1;
}
