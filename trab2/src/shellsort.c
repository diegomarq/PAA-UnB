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

void shellsort(int size) {
    char aux[SIZE_S];
    int i, j, gap;
    while(gap < size)
        gap = 3*gap+1;

    while(gap > 1) {
        gap /= 3;
        for(i=gap; i < size; i++) {
            strcpy(aux, data[i].s);
            j = i-gap;
            while(j >= 0 && strcmp(aux, data[j].s) < 0) {
                strcpy(data[j+gap].s, data[j].s);
                j -= gap;
            }
            strcpy(data[j+gap].s, aux);
        }
	}
}

int main(void) {  
    int i;
    struct timeval start,end;  
    data = (string_array*)malloc(3300000*sizeof(string_array));
    for(i =0; scanf("%[^\n]%*c", data[i].s) != EOF; i++);  
    size = i;

	gettimeofday(&start,NULL);
    shellsort(size);
    gettimeofday(&end,NULL);
  	double delta = ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6;
	printf("%lf\n",delta);

    /*for(i = 0; i < size; i++) {
        printf("%s", data[i].s);
        printf("\n");
    }*/
    return 0;

  
}
