#include <stdio.h>
#include <string.h>

#define SIZE_S 100
#define SIZE_C 2

char data[SIZE_C][SIZE_S];
int size = 0;

void bubblesort(int size) {
  char aux[SIZE_S];
  int i = 0;
  int j = 0;
  for(i=size-1; i >= 1; i--) {   
    for(j=0; j < i; j++) {
      if(strcmp(data[j], data[j+1]) > 0) {
      	strcpy(aux, data[j]);
      	strcpy(data[j], data[j+1]);
        strcpy(data[j+1], aux);        
      }
    }
  }
}

int main(void) {  
  int i;
  for(i =0; scanf("%[^\n]%*c", data[i]) != EOF; i++);  
  size = i;
  
  bubblesort(size);
  
  for(i = 0; i < size; i++) {
    printf("%s", data[i]);
    printf("\n");
  }
  return 0;

  
}