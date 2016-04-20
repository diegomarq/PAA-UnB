#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#define SIZE_S 6

int size = 0;

typedef struct _string_array {
  char s[6];
}string_array;
string_array* data;
string_array* aux;

void insertionsort(int begin, int end) {
    char now[SIZE_S];
    int i, j;

    for (i = begin+1; i < end; i++) {
        strcpy(now, data[i].s);
        j = i-1;
        while(j >= begin && strcmp(now, data[j].s) < 0) {
            strcpy(data[j+1].s, data[j].s);
            j--;
        }
        strcpy(data[j+1].s, now);
    }
}

void merge(int begin, int middle, int end) {    
    int i, j, k;
  
    for (i = begin; i < middle+1; i++)
        strcpy(aux[i].s, data[i].s);
  
    for (j = middle+1; j < end+1; j++)
        strcpy(aux[end+middle+1-j].s, data[j].s);

    i = begin;
    j = end;

    for (k = begin; k < end+1; k++) {
        if (strcmp(aux[i].s, aux[j].s) < 0) {
            strcpy(data[k].s, aux[i].s);
            i++;
        } else {
            strcpy(data[k].s, aux[j].s);
            j--;
        }
    }
}

void mergesort(int begin, int end, int k) {
    int middle;
  
    if(end+begin <= k) {
        insertionsort(begin, end);
    } else {
        if(begin != end) {
            middle = (begin+end)/2;
            mergesort(begin, middle, k);
            mergesort(middle+1, end, k);
            merge(begin, middle, end);
        }
    }    
}

int main(int argc, char *argv[]) {  
    int i, k;
    struct timeval start,end;  
    data = (string_array*)malloc(3300000*sizeof(string_array));
    aux = (string_array*)malloc(3300000*sizeof(string_array));
    if(argc == 1){
        printf("Usage : <program_name> <delimiter>\n");
        return 1;
    }
    k = atoi(argv[1]);

    for(i =0; scanf("%[^\n]%*c", data[i].s) != EOF; i++);  
    size = i;
    
    gettimeofday(&start,NULL);
    mergesort(0, size-1, k);
    gettimeofday(&end,NULL);
    double delta = ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6;
    printf("%lf\n",delta);

    for(i = 0; i < size; i++) {
        printf("%s", data[i].s);
        printf("\n");
    }
    return 0;  
}
