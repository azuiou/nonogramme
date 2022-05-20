CC = gcc
OPTIONS = -Wall -W -O3 -pedantic   
CFLAGS = -g -O2 -Wall -W -O3 -pedantic `pkg-config --cflags MLV`                                                                     
LDFLAGS = `pkg-config --libs-only-other --libs-only-L MLV`                                                                                    
LDLIBS = `pkg-config --libs-only-l MLV`

main : main.o grille.o algo.o affichage.o sauvegarde.o
	$(CC) $(CFLAGS) $(LDFLAGS) main.o grille.o algo.o sauvegarde.o affichage.o $(LDLIBS) -o main

main.o : main.c type.h grille.h
	$(CC) $(CFLAGS) $(LDFLAGS) -c $(LDLIBS) main.c 

grille.o : grille.c type.h 
	$(CC) $(OPTIONS) -c grille.c

sauvegarde.o : sauvegarde.c sauvegarde.h
	$(CC) $(OPTIONS) -c sauvegarde.c

algo.o : algo.c type.h
	$(CC) $(CFLAGS) $(LDFLAGS) algo.c $(LDLIBS) -c

affichage.o : affichage.c 
		$(CC) $(CFLAGS) $(LDFLAGS) affichage.c $(LDLIBS) -c

clean :
	rm -rf *.o *~ main

