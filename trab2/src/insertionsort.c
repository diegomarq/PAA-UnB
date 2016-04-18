#include <stdio.h>
#include <string.h>

#define SIZE_S 100
#define SIZE_C 2

char data[SIZE_C][SIZE_S];
int size = 0;

void insertionsort(int size) {
    char now[SIZE_S];    
    int i, j;

    for (i = 1; i < size; i++) {
        strcpy(now, data[i]);
        j = i-1;
        while(j >= 0 && strcmp(now, data[j]) < 0) {
            strcpy(data[j+1], data[j]);
            j--;
        }
        strcpy(data[j+1], now);
    }
}

int main(void) {  
    int i;
    for(i =0; scanf("%[^\n]%*c", data[i]) != EOF; i++);  
    size = i;

    insertionsort(size);

    for(i = 0; i < size; i++) {
        printf("%s", data[i]);
        printf("\n");
    }
    return 0;

  
}
