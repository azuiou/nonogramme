#ifndef _ALGO_H_
#define _ALGO_H_

void remplie_depart(int t[LIGNE][COL][X], plateau plateau, int interrupteur, int * cases);

void bord_fini(int t[LIGNE][COL][X], plateau plateau, int interrupteur, int*cases);

void barre(int t[LIGNE][COL][X], plateau plateau, int interrupteur);

void complete(int t[LIGNE][COL][X], plateau plateau, int interrupteur, int * cases);

#endif