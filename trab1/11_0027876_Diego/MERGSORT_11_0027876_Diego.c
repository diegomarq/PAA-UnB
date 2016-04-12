#include <stdio.h>

int vector[100000];
int aux[100000];

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
    int i = 0;
    int n = 0;
    while( scanf("%d",&n) != EOF ) { vector[i] = n ; i++; }    
    mergesort(0, i-1);    
    n = i;
    i = 0;
    while(i < n) {
      if(i == n-1) printf("%d\n", vector[i++]);
      else printf("%d ", vector[i++]);
    }

    return 0;
}
