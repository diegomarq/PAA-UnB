SRC = ./src/

all:  metodo_inducao clean

metodo_inducao: grandeOmega.o grandeO.o teta.o
	gcc -Wall $(SRC)metodo_inducao_11_0027876_Diego.c $(SRC)mode_11_0027876_Diego.h grandeOmega_11_0027876_Diego.o grandeO_11_0027876_Diego.o teta_11_0027876_Diego.o -o inducao.out -lm

teta.o:
	gcc -Wall $(SRC)teta_11_0027876_Diego.c $(SRC)mode_11_0027876_Diego.h -c -lm

grandeOmega.o:
	gcc -Wall $(SRC)grandeOmega_11_0027876_Diego.c $(SRC)mode_11_0027876_Diego.h -c -lm

grandeO.o:
	gcc -Wall $(SRC)grandeO_11_0027876_Diego.c $(SRC)mode_11_0027876_Diego.h -c -lm

clean:
	rm -rf *.o

fclean:
	rm -rf *.out
	
