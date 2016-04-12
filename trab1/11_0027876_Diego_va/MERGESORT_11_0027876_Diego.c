#include<stdio.h>

//O programa tem como output um array de int por isso o erro no spoj
//Entretanto o compilador do spoj foi ultilizado como base, sendo o link para o caso de uso
//http://ideone.com/pnAau6

int arr[100000]; //array de input;
int mergesort(int arr[],int inicio,int ultimo)
{
  int meio;
  if(inicio<ultimo) {
    meio=(inicio+ultimo)/2;
    //Faz divisoes sucessivas do array, ordenando primeiro a primeira parte e em seguida a ultima
    mergesort(arr,inicio,meio);
    mergesort(arr,meio+1,ultimo);
    // Ordena o array tendo como area apenas os ponteiros que delimitam sua extensão como o meio e o ultimo
    ordena(arr,inicio,meio,ultimo);
  }

  return 0;
}

int ordena(int arr[],int inicio,int meio,int ultimo)
{
  int arr1[50000],arr2[50000];

  int n1,n2,i,j,k;
  n1=meio-inicio+1;
  n2=ultimo-meio;

  for(i=0; i<n1; i++)
    arr1[i]=arr[inicio+i];
  for(j=0; j<n2; j++)
    arr2[j]=arr[meio+j+1];

  arr1[i]=49999;
  arr2[j]=49999;

  i=0;
  j=0;
  for(k=inicio; k<=ultimo; k++) {
    if(arr1[i]<=arr2[j])
      arr[k]=arr1[i++];
    else
      arr[k]=arr2[j++];
  }

  return 0;
}
int main()
{
  int n,i,j;

  //Faz a leitura do input sendo o j o tamanho do array
  j = 0;
  while( scanf("%d",&n) != EOF ) { arr[j++] = n ; }


  mergesort(arr,0,j-1);


  for(i=0; i<j; i++)
    printf("%d",arr[i]);

  return 0;
}
