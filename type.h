#ifndef _TYPE_H_
#define _TYPE_H_
#define COL 101
#define LIGNE 101
#define X 50



typedef struct {  
  int cases;
  int col;
  int ligne;
  int grille[COL][LIGNE][X];      
}plateau;

#endif