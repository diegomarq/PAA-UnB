#include<stdlib.h>
#include<stdio.h>

long long int a[200001],max,total;

/*Para que a busca seja mais rápida e não exceda o tempo é feito um mergesort, tendo como resultado a quantidade de
buscas que foram feitas*/
/*Isso feito com a modificação da variavel global qnt*/
void ordena(long long int s,long long int e)
{
	long long int i=s,qnt=0,meio=(s+e)/2,j=meio+1;
	long long int *arr;
	arr=malloc(sizeof(long long int)*(e-s+1));
	for(;i<=meio && j<=e;)
	{
		if(a[i]>a[j])
		{
			arr[qnt++]=a[j];
			j++;

			total+=meio-i+1;
		}
		else
		{
			arr[qnt++]=a[i++];
		}
	}
	while(i<=meio)
		arr[qnt++]=a[i++];
	while(j<=e)
		arr[qnt++]=a[j++];
	for(i=0;i<qnt;i++)
	{
		a[i+s]=arr[i];

	}

}

void mergesort(long long int comeco,long long int fin,long long int qnt)
{
	if(qnt==1)
		return;
	else
	{
		int temp=(comeco+fin)/2;
		mergesort(comeco,temp,(temp-comeco+1));
		mergesort(temp+1,fin,(fin-temp));
		ordena(comeco,fin);
	}
}
int main()
{
	int tc;

    /*De acordo com a quantidade de casos de teste o programa faz um loop para agregar todos os inputs, fazendo
    o output no final de cada um*/
	scanf("%d",&tc);
	while(tc--)
	{
		long long int i;
		scanf("%lld",&max);
		total=0;
		for(i=0;i<max;i++)
			scanf("%lld",&a[i]);
		mergesort(0,max-1,max);
		printf("%lld\n",total);

	printf("\n");
	}
	return 0;
}
