#include <stdio.h>
/*Codigo simples para busca binaria, onde se a resposta for achada, mas existir o mesmo numero ele continua a busca
ate achar a posicao menor. Caso ele não ache o numero desejado, o retorno será -1*/
int buscaBinaria(int num[], int tamanho, int chave)
{
    int achou = 0;
    int comeco = 0;
    int fin = tamanho - 1;
    int meio, resp;

    while(comeco <= fin)
    {
        meio = comeco + (fin - comeco)/2;

        if(chave < num[meio])
            fin = meio - 1;
        else if(chave > num[meio])
            comeco = meio + 1;
        else {
        	resp = meio;
        	achou = 1;
            fin = meio - 1;
        }
    }
    if(achou == 1) {
    	return resp;
    } else {
    	return -1;
    }

}
int main()
{
    int *num;
    int n_num, n_queries, chave, i, achou;

    //Por meio de ponteiro, o programa armazena o input
    scanf("%d %d", &n_num, &n_queries);
    num = (int*)malloc(n_num * sizeof(int));

    //verifica quantas variaveis tem o array
    for(i = 0; i<n_num; i++)
        scanf("%d", &num[i]);
    /*para fazer o output sobre qual posicao o numero desejado esta, o programa faz uma busca binaria, tendo como limite
    a quantidade de caracteres passado anteriormente.*/
    for(i = 0; i<n_queries; i++)
    {
        scanf("%d", &chave);
        achou = buscaBinaria(num, n_num, chave);
        printf("%d\n", achou);
    }

    return 0;
}
