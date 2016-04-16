#include <stdio.h>
#include <string.h>

#define SIZE_S 100 // string size
#define SIZE_C 20 // number of elements

char data[SIZE_C][SIZE_S];
int size = 0;

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

void mergesort(int begin, int end) {
  int middle;
  
  if(begin != end) {
    middle = (begin+end)/2;
    mergesort(begin, middle);
    mergesort(middle+1, end);
    merge(begin, middle, end);
  }
}

int main(void) {  
    int i;
    for(i =0; scanf("%[^\n]%*c", data[i]) != EOF; i++);  
    size = i;

    mergesort(0, size-1);

    for(i = 0; i < size; i++) {
        printf("%s", data[i]);
        printf("\n");
    }
    return 0;

  
}
