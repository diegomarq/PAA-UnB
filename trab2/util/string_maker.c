#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct _string_array
{
  char dado[6];
}string_array;

void string_swap(string_array *strings, int i, int j)
{
    char aux[6] = "";
    strcpy(aux,strings[i].dado);
    strcpy(strings[i].dado,strings[j].dado);
    strcpy(strings[j].dado,aux);
}
void shuffle(string_array *array, int n)
{
	srand(time(NULL));
    if (n > 1) 
    {
        int i;
		for (i = 0; i < n - 1; i++) 
		{
		  int j = i + rand() / (RAND_MAX / (n - i) + 1);
		  string_swap(array,i,j);
		}
	}
}
void crescente(string_array *strings, int tam)
{
	char start[6];
	int i,j;
	strcpy(start,"aaaaa");
	for(i=0;i<tam;i++)
	{
		for(j=4;j>0;j--)
		{
			if(start[j] > 'z')
			{
				start[j] = 'a';
				start[j-1]++;
			}
		}
		strcpy(strings[i].dado,start);
		start[4]++;
	}
}
void decrescente(string_array *strings,int tam)
{
	char start[6];
	int i,j;
	strcpy(start,"zzzzz");
	for(i=0;i<tam;i++)
	{
		for(j=0;j<4;j++)
		{
			if(start[j] < 'a')
			{
				start[j] = 'z';
				start[j+1]--;
			}
		}
		strcpy(strings[i].dado,start);
		start[0]--;
	}

}
int main(int argc, char *argv[])
{
	if(argc < 3)
	{
		printf("Usage : ./maker.out <qtd> <modo>\n");
		return -1;
	}
	string_array *strings;
	strings = (string_array*)malloc(3300000*sizeof(string_array));
	int tam = atoi(argv[1]);
	int modo = atoi(argv[2]);
	int i;
	if(modo == 1)
	{
		crescente(strings,tam);
	}
	else if(modo == 2)
	{
		decrescente(strings,tam);
	}
	else
	{
		crescente(strings,tam/2);
		decrescente(strings + tam/2,tam/2);
 		shuffle(strings,tam);
	}
	for(i=0;i<tam;i++)
	{
		printf("%s\n",strings[i].dado);
	}
	return 0;
}