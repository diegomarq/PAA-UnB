#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _string_array {
  char s[6];
}string_array;


int size;
long long int count;

void merge (string_array *vector, int s, int middle) { 
  int i,j,k;

  string_array *aux = malloc(s*sizeof(string_array));
  
  for(i=0,j=middle,k=0;k<s;k++) {
    if(j==s) {
      strcpy(aux[k].s, vector[i].s);
      i++;
    }
    else if(i==middle) {
      strcpy(aux[k].s, vector[j].s);
      j++;
    }
    else if(strcmp(vector[j].s, vector[i].s)<0) {
      strcpy(aux[k].s, vector[j].s);
      j++;
      count+=middle-i;
    }
    else {
      strcpy(aux[k].s, vector[i].s);
      i++;
    }
  }
  for(i=0;i<s;i++) {
    strcpy(vector[i].s, aux[i].s);
  }
  free(aux);
}

void mergesort (string_array *vector, int s) {
    if (s < 2)
        return;
    int middle = s / 2;
    mergesort(vector, middle);
    mergesort(vector + middle, s - middle);
    merge(vector, s, middle);
}

int main() {
  int i;

  string_array* vector;  

  vector = (string_array*)malloc(3300000*sizeof(string_array));  

  size = 0;
  for(i =0; scanf("%[^\n]%*c", vector[i].s) != EOF; i++);  
  size = i;
  count = 0;
  mergesort(vector, size-1);
   
  printf("%lld\n",count);  
  printf("\n");
  
  return 0;
}
