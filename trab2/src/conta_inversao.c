#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int inversions = 0;

typedef struct _string_array {
  char s[6];
}string_array;


void merge_conta_inversao (string_array *data, int size, int middle) {    
  int i,j,k;

  string_array *aux = malloc(size*sizeof(string_array));    

  for(i=0,j=middle,k=0;k<size;k++) {
    if(j==size) {
      strcpy(aux[k].s, data[i].s);
      i++;
    }
    else if(i==middle) {
      strcpy(aux[k].s, data[j].s);
      j++;
    }
    else if(strcmp(data[j].s, data[i].s)<0) {
      strcpy(aux[k].s, data[j].s);
      j++;
      inversions+=middle - i;
    }
    else {
      strcpy(aux[k].s, data[i].s);
      i++;
    }
  }
  for(i=0;i<size;i++) {
    strcpy(data[i].s, aux[i].s);
  } 
  free(aux);
}

void mergesort (string_array *data, int size) {
  if (size < 2)
      return;
  int middle = size / 2;
  mergesort(data, middle);
  mergesort(data + middle, size - middle);
  merge_conta_inversao(data, size, middle);
}

int main(void) {
  int i, size;
  string_array *data;
  
  data = (string_array*)malloc(3300000*sizeof(string_array));
  for(i =0; scanf("%[^\n]%*c", data[i].s) != EOF; i++);
  size = i;
  
  mergesort(data, size);
  printf("%lld\n", inversions);
  return 0;  
}
