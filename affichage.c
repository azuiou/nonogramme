#include <MLV/MLV_all.h>
#include <stdio.h>
#include <stdlib.h>
#include "type.h"
#include "affichage.h"
#include "grille.h"


void affiche_dessin(int t[LIGNE][COL][X], int col, int ligne){
  int i ,j;
  int x = 10, y =WINDOW_HEIGHT/20;
  int p = 3;
  for(i=1;i<=ligne;i++){
    for(j=1;j<=col;j++){
        if(t[i][j][0]==1){
	       MLV_draw_filled_rectangle(x+=WINDOW_HEIGHT/20,y,WINDOW_HEIGHT/20-p,WINDOW_HEIGHT/20-p,MLV_COLOR_CORNSILK4);
         MLV_actualise_window();
        }
        else if(t[i][j][0]==-1){
	       MLV_draw_filled_rectangle(x+=WINDOW_HEIGHT/20,y,WINDOW_HEIGHT/20-p,WINDOW_HEIGHT/20-p,MLV_COLOR_RED);
         MLV_actualise_window();
        }
        else{
         MLV_draw_filled_rectangle(x+=WINDOW_HEIGHT/20,y,WINDOW_HEIGHT/20-p,WINDOW_HEIGHT/20-p,MLV_COLOR_BLACK);
         MLV_actualise_window();
        }
    }
    x=10;
    y+=WINDOW_HEIGHT/20;
  }
}

int case_par_case(){
  int interrupteur;
  printf("Entrez 1 pour afficher la résolution case par case ou sinon entrez n'importe quelle entier \nChoix : ");
  if(scanf("%d",&interrupteur)!=1){
    printf("erreur de saisie le choix de base sera donc 1\n");
    viderBuffer();
    return 1;
  }
  return interrupteur;
}