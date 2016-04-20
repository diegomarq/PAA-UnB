#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#define SIZE_S 6

int size = 0;
long long int inversions = 0;

typedef struct _string_array {
  char s[6];
}string_array;
string_array* data;

void insertionsort(int size) {
    char now[SIZE_S];
    int i, j;

    for (i = 1; i < size; i++) {
        strcpy(now, data[i].s);
        j = i-1;
        while(j >= 0 && strcmp(now, data[j].s) < 0) {
            inversions++;
            strcpy(data[j+1].s, data[j].s);
            j--;
        }
        strcpy(data[j+1].s, now);
    }
}

int main(void) {  
    int i;
    // struct timeval start,end;
    data = (string_array*)malloc(3300000*sizeof(string_array));
    for(i =0; scanf("%[^\n]%*c", data[i].s) != EOF; i++);
    size = i;

    // gettimeofday(&start,NULL);
    insertionsort(size);
    printf("%lld\n", inversions);
    // gettimeofday(&end,NULL);
    // double delta = ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6;
    // printf("%lf\n",delta);

   // for(i = 0; i < size; i++) {
   //     printf("%s", data[i].s);
   //     printf("\n");
   // }
    return 0;

  
}
