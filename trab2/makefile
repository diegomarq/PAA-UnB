SRC = "./src/"

all: merge maker clean

merge:
	gcc -Wall $(SRC)mergesort.c -o $(SRC)merge.out

# sorts.o:
# 	gcc -Wall sorts.h sorts.c -c

maker:
	gcc -Wall string_maker.c -o maker.out
	
clean:
	rm -rf *.o
