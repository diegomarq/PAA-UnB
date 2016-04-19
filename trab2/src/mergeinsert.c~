#include <stdio.h>
#include <string.h>

#define SIZE_S 100 // string size
#define SIZE_C 10 // number of elements

char data[SIZE_C][SIZE_S];
int size = 0;

void insertionsort(int begin, int end) {
    char now[SIZE_S];
    int i, j;

    for (i = begin+1; i < end; i++) {
        strcpy(now, data[i]);
        j = i-1;
        while(j >= begin && strcmp(now, data[j]) < 0) {
            strcpy(data[j+1], data[j]);
            j--;
        }
        strcpy(data[j+1], now);
    }
}

void merge(int begin, int middle, int end) {
    char aux[SIZE_C][SIZE_S];
    int i, j, k;
  
    for (i = begin; i < middle+1; i++)
        strcpy(aux[i], data[i]);
  
    for (j = middle+1; j < end+1; j++)
        strcpy(aux[end+middle+1-j], data[j]);

    i = begin;
    j = end;

    for (k = begin; k < end+1; k++) {
        if (strcmp(aux[i], aux[j]) < 0) {
            strcpy(data[k], aux[i]);
            i++;
        } else {
            strcpy(data[k], aux[j]);
            j--;
        }
    }
}

void mergesort(int begin, int end, int k) {
    int middle;
  
    if(begin != end) {
        middle = (begin+end)/2;
        mergesort(begin, middle, k);
        mergesort(middle+1, end, k);

        if(end-begin+1 <= k)
            insertionsort(begin, end);
        else
            merge(begin, middle, end);

    }
}

int main(int argc, char *argv[]) {  
    int i, k;

    if(argc == 1){
        printf("Usage : <program_name> <delimiter>\n");
        return 1;
    }
    k = atoi(argv[1]);

    for(i =0; scanf("%[^\n]%*c", data[i]) != EOF; i++);  
    size = i;

    mergesort(0, size-1, k);

    for(i = 0; i < size; i++) {
        printf("%s", data[i]);
        printf("\n");
    }
    return 0;  
}
