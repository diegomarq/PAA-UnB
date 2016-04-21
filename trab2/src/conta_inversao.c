#include <stdio.h>
#include <stdlib.h>
#include <string.h>
<<<<<<< HEAD

long long int inversions = 0;
=======
>>>>>>> 3c17ac8c3188a7aec3cf8943ff34336be27b5a5f

typedef struct _string_array {
  char s[6];
}string_array;

<<<<<<< HEAD
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
=======

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
>>>>>>> 3c17ac8c3188a7aec3cf8943ff34336be27b5a5f
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

<<<<<<< HEAD
    string_array *data;
    
    data = (string_array*)malloc(3300000*sizeof(string_array));
    for(i =0; scanf("%[^\n]%*c", data[i].s) != EOF; i++);
    size = i;
    
    mergesort(data, size);
    printf("%lld\n", inversions);
    return 0;
=======
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
>>>>>>> 3c17ac8c3188a7aec3cf8943ff34336be27b5a5f
}
