#include <stdio.h>
#include <string.h>

#define SIZE_S 100
#define SIZE_C 2

char data[SIZE_C][SIZE_S];
int size = 0;

void selectionsort(int size) {
    char aux[SIZE_S];
    int i, j, min; 
    for(i=0; i < size-1; i++) {    
        min = i;
        for(j=min+1; j < size; j++) {
            if(strcmp(data[j], data[min]) < 0) {
            	min = j;
            }
        }
        if(min != i) {    
            strcpy(aux, data[i]);
            strcpy(data[i], data[min]);
            strcpy(data[min], aux);
        }
    }
}

int main(void) {  
    int i;
    for(i =0; scanf("%[^\n]%*c", data[i]) != EOF; i++);  
    size = i;

    selectionsort(size);

    for(i = 0; i < size; i++) {
        printf("%s", data[i]);
        printf("\n");
    }
    return 0;

  
}