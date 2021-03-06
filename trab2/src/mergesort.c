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
    struct timeval start,end;  
    data = (string_array*)malloc(3300000*sizeof(string_array));
    aux = (string_array*)malloc(3300000*sizeof(string_array));
    for(i =0; scanf("%[^\n]%*c", data[i].s) != EOF; i++);  
    size = i;
	
	gettimeofday(&start,NULL);
    mergesort(0, size-1);
    gettimeofday(&end,NULL);
  	double delta = ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6;
  	printf("%lf\n",delta);

    /*for(i = 0; i < size; i++) {
        printf("%s", data[i].s);
        printf("\n");
    }*/
    return 0;

  
}
