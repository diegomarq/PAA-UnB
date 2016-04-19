// Diego Marques de Azevedo 11/0027876

#include <stdio.h>

int vector[100000];
int aux[100000];
int m;

void merge(int begin, int middle, int end) {
  int i, j, k;
  
  for (i = begin; i < middle+1; i++) {
    aux[i] = vector[i];
  }

  for (j = middle+1; j < end+1; j++) {
    aux[end+middle+1-j] = vector[j];
  }

  i = begin;
  j = end;

  for (k = begin; k < end+1; k++) {
    if (aux[i] <= aux[j]) {
      vector[k] = aux[i];
      i++;       
    } else {
      vector[k] = aux[j];
      j--; 
      m+=middle-i+1;     
    }    
  }  
}

void mergesort(int begin, int end) {
  int middle;
  
  if(begin < end) {
    middle = (begin+end)/2;
    mergesort(begin, middle);
    mergesort(middle+1, end);
    merge(begin, middle, end);
  }
}

int main() {
  int n, i, c;

  scanf("%d",&c);
  while(c--) {
    int i;
    scanf("%d",&n);
    m=0;
    for(i=0;i<n;i++)
      scanf("%d",&vector[i]);
    mergesort(0,n-1);
   
    printf("%d\n",m);  
    printf("\n");
  }
  return 0;
}
