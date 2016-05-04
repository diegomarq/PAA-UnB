SRC = ./src/

all:  metodo_inducao clean

metodo_inducao: grandeOmega.o grandeO.o teta.o
	gcc -Wall $(SRC)metodo_inducao.c $(SRC)mode.h grandeOmega.o grandeO.o teta.o -o metodo_inducao.out -lm

teta.o:
	gcc -Wall $(SRC)teta.c $(SRC)mode.h -c -lm

grandeOmega.o:
	gcc -Wall $(SRC)grandeOmega.c $(SRC)mode.h -c -lm

grandeO.o:
	gcc -Wall $(SRC)grandeO.c $(SRC)mode.h -c -lm

clean:
	rm -rf *.o

fclean:
	rm -rf *.out
	
