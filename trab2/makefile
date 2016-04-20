SRC = "./src/"
EXE = "./bin/"

all: bubblesort combsort insertion merge selection shell maker conta_inversao mergeinsert clean

insertion:
	gcc -Wall $(SRC)insertionsort.c -o $(EXE)insertion.out

combsort:
	gcc -Wall $(SRC)combsort.c -o $(EXE)comb.out	

bubblesort:
	gcc -Wall $(SRC)bubblesort.c -o $(EXE)bubble.out

merge:
	gcc -Wall $(SRC)mergesort.c -o $(EXE)merge.out
	
selection:
	gcc -Wall $(SRC)selectionsort.c -o $(EXE)selection.out
	
shell:
	gcc -Wall $(SRC)shellsort.c -o $(EXE)shell.out

conta_inversao:
	gcc -Wall $(SRC)conta_inversao.c -o $(EXE)conta_inversao.out	

mergeinsert:
	gcc -Wall $(SRC)mergeinsert.c -o $(EXE)mergeinsert.out

# sorts.o:
# 	gcc -Wall sorts.h sorts.c -c

maker:
	gcc -Wall string_maker.c -o $(EXE)maker.out
	
clean:
	rm -rf *.o
