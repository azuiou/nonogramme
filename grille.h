#ifndef _GRILLE_H_
#define _GRILLE_H_
#include "type.h"

void viderBuffer();

/*initialise à 0 toutes les cases du plateau*/
void init_plateau(int t[LIGNE][COL][X]);

/*affiche le plateau de jeu (resolution plus donnees)*/
void affiche_grille(int t[LIGNE][COL][X], plateau plateau);

/*Rempli les donnees necessaires à la resolution pat l'utilisateur*/
void recuperation_donnees(char fic[50], int t[LIGNE][COL][X], int*cases, int *col, int*ligne);



#endif