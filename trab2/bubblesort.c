#include <stdio.h>
#include <string.h>

char data[2][100];
char n[100];
int size = 0;

void bubblesort(int size) {
  int i = 0;
  int j = 0;
  for(i=size-1; i >= 1; i--) {   
    for(j=0; j < i; j++) {
      if(strcmp(data[j], data[j+1]) > 0) {
	strcpy(n, data[j]);
	strcpy(data[j], data[j+1]);
        strcpy(data[j+1], n);        
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