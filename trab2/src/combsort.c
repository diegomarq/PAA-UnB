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

void combsort(int size) {
    char swap[SIZE_S];
    float shrink_factor = 1.247330950103979;
    int gap = size, swapped = 1, i;

    while (gap > 1 || swapped) {
        if (gap > 1)
            gap = gap / shrink_factor;

        swapped = 0;
        i = 0;

        while (gap+i < size) {
            if (strcmp(data[i].s, data[i+gap].s) > 0) {
                strcpy(swap, data[i].s);
                strcpy(data[i].s, data[i+gap].s);
                strcpy(data[i+gap].s, swap);
                swapped = 1;
            }
            ++i;
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
    combsort(size);
    gettimeofday(&end,NULL);
  	double delta = ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6;
  	printf("%lf\n",delta);

    /*for(i = 0; i < size; i++) {
        printf("%s", data[i].s);
        printf("\n");
    }*/
    return 0;

  
}
