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

void bubblesort(int size) {
  char aux[SIZE_S];
  int i = 0;
  int j = 0;
  for(i=size-1; i >= 1; i--) {   
    for(j=0; j < i; j++) {
      if(strcmp(data[j].s, data[j+1].s) > 0) {
      	strcpy(aux, data[j].s);
      	strcpy(data[j].s, data[j+1].s);
        strcpy(data[j+1].s, aux);        
      }
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

  bubblesort(size);

   gettimeofday(&end,NULL);
  double delta = ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6;
  printf("%lf\n",delta);
  
  /*for(i = 0; i < size; i++) {
    printf("%s", data[i].s);
    printf("\n");
  }*/
  return 0;  
}
