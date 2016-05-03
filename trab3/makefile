SRC = ./src/

all:  metodo_inducao clean

metodo_inducao: grandeO.o grandeOmega.o
	gcc -Wall $(SRC)metodo_inducao.c $(SRC)mode.h grandeO.o grandeOmega.o -o metodo_inducao.out -lm

grandeOmega.o:
	gcc -Wall $(SRC)grandeOmega.c $(SRC)mode.h -c -lm

grandeO.o:
	gcc -Wall $(SRC)grandeO.c $(SRC)mode.h -c -lm

clean:
	rm -rf *.o

fclean:
	rm -rf *.out
	
