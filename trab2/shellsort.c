#include <stdio.h>
#include <string.h>

#define SIZE_S 100
#define SIZE_C 2

char data[SIZE_C][SIZE_S];
int size = 0;

void shellsort(int size) {
    char aux[SIZE_S];
    int i, j, gap;
    while(gap < size)
        gap = 3*gap+1;

    while(gap > 1) {
        gap /= 3;
        for(i=gap; i < size; i++) {
            strcpy(aux, data[i]);
            j = i-gap;
            while(j >= 0 && strcmp(aux, data[j]) < 0) {
                strcpy(data[j+gap], data[j]);
                j -= gap;
            }
            strcpy(data[j+gap], aux);
        }
	}
}

int main(void) {  
    int i;
    for(i =0; scanf("%[^\n]%*c", data[i]) != EOF; i++);  
    size = i;

    shellsort(size);

    for(i = 0; i < size; i++) {
        printf("%s", data[i]);
        printf("\n");
    }
    return 0;

  
}
