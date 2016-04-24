SRC = "./src/"
EXE = "./bin/"
UTIL = "./util/"

all: bubblesort combsort insertion merge selection shell conta_inversao mergeinsert maker_s clean

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

maker_s:
	gcc -Wall $(UTIL)maker_s.c -o $(EXE)maker.out
	
clean:
	rm -rf *.o
