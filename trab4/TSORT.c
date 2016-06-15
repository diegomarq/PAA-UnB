/*Diego Marques de Azevedo*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int v[1000001];

void swap(int a, int b){
    int aux;
    aux = v[a];
    v[a] = v[b];
    v[b] = aux;
}

int hoare_partion(int l, int r) {
	int pivo = v[l + rand()%(r-l)];
	int i = l-1;
	int j = r+1;
	while(1) {
		do i++; while(v[i] < pivo);
		do j--; while(v[j] > pivo);
		if(i < j) swap(i, j);
		else return j;
	}
}

void quicksort(int l, int r) {
	int pivo;

	if(l < r) {
		pivo = hoare_partion(l, r);		
		quicksort(l, pivo);
		quicksort(pivo+1, r);
	}
}

int main() {
	int i, c;
	srand(time(NULL));
	scanf("%d", &c);
	for(i=0; i<c; i++)
		scanf("%d", &v[i]);
	quicksort(0, c-1);
	for(i=0; i<c; i++) printf("%d\n", v[i]);
	return 0;
}
