#include <stdio.h>
#include <stdlib.h>
#include "type.h"
#include "affichage.h"
#include <MLV/MLV_all.h>
#include <assert.h>


void remplie_depart(int t[LIGNE][COL][X], plateau plateau, int interrupteur, int * cases){
  int i,j, acc, k, n;
  /*regarde si une colonne est completee directement avec aucun espace*/
  for(i=1; i<=plateau.col; i++){
    if(t[0][i][0]==plateau.ligne){
      for(j=0; j<plateau.ligne; j++){
	t[j+1][i][0]=1;
	*cases+=1;
	if(interrupteur == 1){
	  affiche_dessin(t, plateau.col, plateau.ligne);
	  MLV_wait_milliseconds(100);
	}
      }
    }
    /*regarde si colonne complete avec espaces*/
    else{
      k = 0; 
      acc = 0;
      while(t[0][i][k+1]!=0){
	acc+=t[0][i][k];
	acc++;
	k++;
      }
      acc+=t[0][i][k];
      k++;
      if(acc==plateau.col){
	j = 0;
	n = 0;
	acc = 0;
	while(k>0){
	  while(j < t[0][i][n]){
	    t[acc+1+n][i][0]=1;
	    *cases+=1;
	    j++;
	    if(interrupteur == 1){
	      affiche_dessin(t, plateau.col, plateau.ligne);
	      MLV_wait_milliseconds(100);
	    }
	    acc++;
	  }
	  t[acc+n+1][i][0]=-1;
	  if(interrupteur == 1 && t[j][i][0] == 1){
	    affiche_dessin(t, plateau.col, plateau.ligne);
	    MLV_wait_milliseconds(100);
	  }
	  n++;
	  k--;
	  j = 0;
	}
      }
    }
  }
  /*regarde si une ligne est completee directement avec aucun espace*/
  for(i=1; i<=plateau.ligne; i++){
    if(t[i][0][0]==plateau.col){
      for(j=0; j<plateau.col; j++){
	t[i][j+1][0]=1;
	*cases+=1;
	if(interrupteur == 1){
	  affiche_dessin(t, plateau.col, plateau.ligne);
	  MLV_wait_milliseconds(100);
	}
      }
    }
    /*regarde si ligne complete avec espaces*/
    else{
      k = 0; 
      acc = 0;
      while(t[i][0][k+1]!=0){
	acc+=t[i][0][k];
	acc++;
	k++;
      }
      acc+=t[i][0][k];
      k++;
      if(acc==plateau.col){
	j = 0;
	n = 0;
	acc = 0;
	while(k>0){
	  while(j < t[i][0][n]){
	    t[i][acc+1+n][0]=1;
	    *cases+=1;
	    j++;
	    if(interrupteur == 1){
	      affiche_dessin(t, plateau.col, plateau.ligne);
	      MLV_wait_milliseconds(100);
	    }
	    acc++;
	  }
	  t[i][acc+1+n][0]=-1;
	  if(interrupteur == 1 && t[j][i][0] == 1){
	    affiche_dessin(t, plateau.col, plateau.ligne);
	    MLV_wait_milliseconds(100);
	  }
	  n++;
	  k--;
	  j = 0;
	}
      }
    }
  }
}

void bord_fini(int t[LIGNE][COL][X], plateau plateau, int interrupteur, int*cases){
  int i,j,indice;
  /* regarde si dans une colonne on est au bord et on peut donc compléter */
  for(i=1; i<=plateau.col; i++){
    if(t[1][i][0] == 1){
      for(j=2; j<=t[0][i][0]; j++){
        if(t[j][i][0] != 1){
          t[j][i][0] = 1;
          *cases+=1;
          if(interrupteur == 1 && t[j][i][0] == 1){
            affiche_dessin(t, plateau.col, plateau.ligne);
            MLV_wait_milliseconds(100);
          }
        }
      }
      t[j][i][0] = -1;
      if(interrupteur == 1 && t[j][i][0] == 1){
        affiche_dessin(t, plateau.col, plateau.ligne);
        MLV_wait_milliseconds(100);
      }
    }
  }
  /*pareil mais a la fin de la colonne*/
  for(i=1; i<=plateau.col; i++){
    if(t[plateau.ligne][i][0] == 1){
      indice = 0;
      while(t[0][i][indice+1] != 0)
	indice++;
      for(j=plateau.ligne-1; j>plateau.ligne - t[0][i][indice] ; j--){
	if(t[j][i][0] != 1){
	  t[j][i][0] = 1;
	  *cases+=1;
	  if(interrupteur == 1 && t[j][i][0] == 1){
	    affiche_dessin(t, plateau.col, plateau.ligne);
	    MLV_wait_milliseconds(100);
	  }
	}
      }
      if(interrupteur == 1 && t[j][i][0] == 1){
	affiche_dessin(t, plateau.col, plateau.ligne);
	MLV_wait_milliseconds(100);
      }
    }
  }
  /* regarde si dans une ligne on esst au bord et on peut donc compléter */
  for(i=1; i<=plateau.ligne; i++){
    if(t[i][1][0] == 1){
      for(j=2; j<=t[i][0][0]; j++){
        if(t[i][j][0] != 1){
          t[i][j][0] = 1;
          *cases+=1;
          if(interrupteur == 1 && t[i][j][0] == 1){
            affiche_dessin(t, plateau.col, plateau.ligne);
            MLV_wait_milliseconds(100);
          }
        }
      }
      t[i][j][0] = -1;
      if(interrupteur == 1 && t[i][j][0] == 1){
        affiche_dessin(t, plateau.col, plateau.ligne);
        MLV_wait_milliseconds(100);
      }
    }
  }
  /*pareil mais a la fin de la ligne*/
  for(i=1; i<=plateau.ligne; i++){
    if(t[i][plateau.col][0] == 1){
      indice = 0;
      while(t[i][0][indice+1] != 0)
	indice++;
      for(j=plateau.col-1; j>plateau.col - t[i][0][indice] ; j--){
	if(t[i][j][0] != 1){
	  t[i][j][0] = 1;
	  *cases+=1;
	  if(interrupteur == 1 && t[i][j][0] == 1){
	    affiche_dessin(t, plateau.col, plateau.ligne);
	    MLV_wait_milliseconds(100);
	  }
	}
      }
      if(interrupteur == 1 && t[i][j][0] == 1){
	affiche_dessin(t, plateau.col, plateau.ligne);
	MLV_wait_milliseconds(100);
      }
    }
  }
}

static int ligne_terminee(int t[LIGNE][COL][X], int a, plateau plateau){
  int i, longueur = 0, acc = 0, acc2 = 0;
  while(t[a][0][longueur] != 0)
    longueur++;
  for(i = 0; i < longueur; i++){
    acc += t[a][0][i];
  }
  for(i = 1; i <= plateau.col; i++){
    if(t[a][i][0] == 1)
      acc2++;
  }
  printf("acc : %d\n", acc);
  printf("acc2 : %d\n", acc2);
  if(acc == acc2)
    return 1;
  return 0;
}

static int colonne_terminee(int t[LIGNE][COL][X], int a, plateau plateau){
  int i, longueur = 0, acc = 0, acc2 = 0;
  while(t[0][a][longueur] != 0)
    longueur++;
  for(i = 0; i < longueur; i++){
    acc += t[0][a][i];
  }
  for(i = 1; i <= plateau.ligne; i++){
    if(t[i][a][0] == 1)
      acc2++;
  }
  printf("acc col : %d\n", acc);
  printf("acc2 col : %d\n", acc2);
  if(acc == acc2)
    return 1;
  return 0;
}

/*A ADAPATE !!!!*/
void barre(int t[LIGNE][COL][X], plateau plateau, int interrupteur){
  int acc1, acc2, i, k, j, longueur, a, tmp, stop;
  /*barre ligne*/
  for(i = 1; i<= plateau.col; i++){
    j = 1;
    k = 1;
    acc1 = 0, acc2 = 0;
    longueur = 0;
    while(t[i][0][longueur] != 0)
      longueur++;
    //printf("ligne terminee : %d\n", ligne_terminee(t, i, plateau));
    if(ligne_terminee(t, i, plateau)){
      stop = 0;
      while( stop == 0){/*tant que pas fin de la ligne*/
        k = j;
        while(t[i][j][0] != 1 && j <= plateau.col){/*trouve ou premiere case pleine*/
          j++;
        }
        if(j > 1){
          for(tmp = k; tmp < j; tmp++){
            t[i][tmp][0] = -1;
          }
        }
        while(t[i][j][0]==1 && j <= plateau.col){/*compte longueur de cases pleines*/
          acc1++;
          j++;
        }
        if(j >= plateau.col)
          stop = 1;
        /*while(t[i][j][0] != 1 && j <= plateau.col){
          j++;
        }*/
        /*while(t[i][j][0]==1 && j <= plateau.col){
          acc2++;
          j++;
        }*/
        /*if(acc1 == t[i][0][0] && acc2 == t[i][0][1]){
          while(t[i][k][0] != 1){
            t[i][k][0] = -1;
            k++;
          }
        }*/
      }
    }
    /*for(k; k < plateau.col; k++){
      t[i][k][0] = -1;
    }*/
  }
  /*barre colonne*/
    for(i = 1; i<= plateau.ligne; i++){
    j = 1, stop;
    k = 1;
    acc1 = 0, acc2 = 0;
    longueur = 0;
    while(t[0][i][longueur] != 0)
      longueur++;
    //printf("colonne terminee : %d\n", colonne_terminee(t, i, plateau));
    if(colonne_terminee(t, i, plateau)){
      stop = 0;
      while( stop == 0){/*tant que pas fin de la ligne*/
        k = j;
        while(t[j][i][0] != 1 && j <= plateau.ligne){/*trouve ou premiere case pleine*/
          j++;
        }
        if(j > 1){
          for(tmp = k; tmp < j; tmp++){
            t[tmp][i][0] = -1;
          }
        }
        while(t[j][i][0]==1 && j <= plateau.ligne){/*compte longueur de cases pleines*/
          acc1++;
          j++;
        }
        if(j >= plateau.ligne)
          stop = 1;
      }
    }
    /*for(k; k < plateau.ligne; k++){
      t[k][i][0] = -1;
    }*/
  }  
    printf("ICI BIEN\n");
}

/*A ADAPTE !!!!*/
void complete(int t[LIGNE][COL][X], plateau plateau, int interrupteur, int * cases){
  int i, j, k, longueur;
  /*lignes*/
  for(i = 1; i<= plateau.col; i++){
    j = 1;
    k = 1;
    longueur = 0;
    while(t[i][j][0] == 1 ){
      j++;
      k++;
    }
    while(t[i][j][0] == -1 ){
      j++;
      k++;
    }
    while(t[i][j][0] == 0 ){
      longueur++;
      j++;
    }
    if(longueur == t[i][0][1]){
      while(t[i][k][0] == 0){
	t[i][k][0] = 1;
	*cases+=1;
	k++;
      }
    }
    printf("%d %d\n",longueur,t[i][0][1]);
  }
  /*colonnes*/
  for(i = 1; i<= plateau.col; i++){
    j = 1;
    k = 1;
    longueur = 0;
    while(t[j][i][0] == 1 ){
      j++;
      k++;
    }
    while(t[j][i][0] == -1 ){
      j++;
      k++;
    }
    while(t[j][i][0] == 0 ){
      longueur++;
      j++;
    }
    if(longueur == t[0][i][1]){
      while(t[k][i][0] == 0){
	t[k][i][0] = 1;
	*cases +=1;
	k++;
      }
    }
    printf("%d %d\n",longueur,t[i][0][1]);
  }
}
