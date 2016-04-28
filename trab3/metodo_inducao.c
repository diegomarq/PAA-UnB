#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(int argc, char *argv[]){
		
	int a2 = 0,b2 = 0, fn2 = 0, p = 0, l=0, i = 0, j = 0, achou = 0, k = 0, a_antes2 = 0, b_antes2 = 0, fn2_antes = 0, p_antes = 0, l_antes = 0, c1, c2, n1, n2, h = 1, h_antes;
	long long int n = 1, c = 1;
// 	int uu = 0;
	
	float resultado = 0, elevado = 0;
	
	char aa2[5],bb2[5],ffn2[5],nn[5];
	char stringa[30];
	for (i=0;i<31;i++){
		stringa[30-i] = '\0';
	}
	
	srand (time(NULL));
	
	strcpy(aa2,argv[1]);
	a2 = atoi(aa2);
	a_antes2 = a2;
	strcpy(bb2,argv[2]);
	b2 = atoi(bb2);
	b_antes2 = b2;
	strcpy(ffn2,argv[3]);
	fn2 = atoi(ffn2);
	fn2_antes = fn2;
	strcpy(nn,argv[4]);
	p = atoi(nn);
	p_antes = p;	
	
	strcpy(stringa, argv[5]);
	
// 	for (uu=0;uu<10;uu++){
		printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
		
			if (strcmp(stringa, "grandeo") == 0){
 				printf("\nGRANDEO\n\n");
				if (p == 1){
					printf("Fato: T(n) = %dT(n/%d) + n\nSuposicao: T(n/%d) ≤ c(n/%d)n\nPrecisa provar: T(n) ≤ cn", a2,b2,b2,b2);
					printf("\nT(n) = %dT(n/%d) + n\n", a2,b2);
					
					printf("\t<= %dc(n/%d)n + n\n", a2,b2);

					/*p == 1 -> elevado = (b2/a2);*/
					elevado = (b2/a2);
					
					printf("\t= (c/%f)n + n\n", elevado);
					printf("\t= cn - ((c/%.2f)n - n)  <-- Desejado - residual\n", elevado);
					printf("\t<= cn <-- Desejado\n");
					printf("\nQuando (c/%f)n - n >= 0, por exemplo,\n", elevado);
					
					for (i=0;i<2000;i++){
						c = i;
						for (j=0;j<2000;j++){
							n = j;

							/*p == 1 -> resultado = (c/elevado)*n - pow(n, fn2);*/
							resultado = (c/elevado)*n - pow(n, fn2);
							if (resultado >= 0 && c > 0 && n > 0){
								achou = 1;
								break;
							}
						}
						if (achou == 1)
							break;
					}
					if (achou == 0)
						printf("Nao existe solucao!!\n");
					else
						printf("se c >= %d e n >= %d\n",i,j);
				} else if (fn2 == 1){
					printf("Fato: T(n) = %dT(n/%d) + n\nSuposicao: T(n/%d) ≤ c(n/%d)n^%d\nPrecisa provar: T(n) ≤ cn^%d", a2,b2,b2,b2, p, p);
					printf("\nT(n) = %dT(n/%d) + n\n", a2,b2);
					printf("\t<= %dc(n/%d)^%d + n\n", a2,b2, p);
					
					if(p != 0) {
						elevado = ((pow(b2,p))/a2);
					} else {
						elevado = (1/a2);
					}				
					
					printf("\t= (c/%f)n^%d + n\n", elevado, p);
					printf("\t= cn^%d - ((c/%f)n^%d - n)  <-- Desejado - residual\n", p, elevado, p);
					printf("\t<= cn^%d <-- Desejado\n", p);
					printf("\nQuando (c/%f)n^%d - n >= 0, por exemplo,\n", elevado, p);
					
					for (i=1;i<2000;i++){
						c = i;
						for (j=1;j<2000;j++){
							//funciona como o elevado, o expoente é o p ele roda, por exemplo, duas vezes em uma funcao quadrática
							n = j;					
							
							/*Tratamento de excessao para p == 0*/
							/*fn2 == 1 -> resultado = (c/elevado)*pow(n,p) - n;*/
							if(p != 0) {
								resultado = (c/elevado)*pow(n,p) - n;
							} else {
								resultado = (c/elevado) - n;
							}

							if (resultado >= 0){
								achou = 1;
								break;
							}					
						}
						if (achou == 1)
							break;
					}
					if (achou == 0)
						printf("Nao existe solucao!!\n");
					else
						printf("se c >= %d e n >= %d\n",j,i);
				} else {
					
					printf("Fato: T(n) = %dT(n/%d) + n^%d\nSuposicao: T(n/%d) ≤ c(n/%d)n^%d\nPrecisa provar: T(n) ≤ cn^%d", a2,b2, fn2,b2,b2, p, p);
					printf("\nT(n) = %dT(n/%d) + n^%d\n", a2,b2, fn2);
					printf("\t<= %dc(n/%d)^%d + n^%d\n", a2,b2, p, fn2);
					
					if(p != 0) {
						elevado = ((pow(b2,p))/a2);
					} else {
						elevado = (1/a2);
					}
					
					printf("\t= (c/%f)n^%d + n^%d\n", elevado, p, fn2);
					printf("\t= cn^%d - ((c/%f)n^%d - n^%d)  <-- Desejado - residual\n", p, elevado, p, fn2);
					printf("\t<= cn^%d <-- Desejado\n", p);
					printf("\nQuando (c/%f)n^%d - n^%d >= 0, por exemplo,\n", elevado, p, fn2);
					
					for (i=1;i<2000;i++){		
						c = i;			
						for (j=1;j<2000;j++){
							//funciona como o elevado, o expoente é o p ele roda, por exemplo, duas vezes em uma funcao quadrática
							n = j;
							
							/*Excessao para caso p == 1*/
							if(p != 0) {
								resultado = (c/elevado)*pow(n,p) - pow(n,fn2);
							} else {
								resultado = (c/elevado) - pow(n,fn2);
							}						
							
							if (resultado >= 0){
								achou = 1;
								break;
							}						
						}
						if (achou == 1)
							break;
					}
					if (achou == 0)
						printf("Nao existe solucao!!\n");
					else
						printf("se c >= %d e n >= %d\n",j,i);
				}
			} else if (strcmp(stringa, "grandeomega") == 0){
 				printf("\nGRANDEOMEGA\n\n");
				if (p == 1){
					printf("Fato: T(n) = %dT(n/%d) + n\nSuposicao: T(n/%d) ≤ c(n/%d)n\nPrecisa provar: T(n) ≤ cn", a2,b2,b2,b2);
					printf("\nT(n) = %dT(n/%d) + n\n", a2,b2);
						
					printf("\t>= %dc(n/%d)n + n\n", a2,b2);
					
					/*p == 1 -> elevado = (b2/a2)*/
					elevado = (b2/a2);
					
					printf("\t= (c/%f)n + n\n", elevado);
					printf("\t= cn - ((c/%f)n - n)  <-- Desejado - residual\n", elevado);
					printf("\t>= cn <-- Desejado\n");
					printf("\nQuando (c/%f)n - n <= 0, por exemplo,\n", elevado);
					
					for (i=1;i<2000;i++){
						c = i;
						for (j=1;j<2000;j++){
							n = j;

							/*p == 1 -> resultado = (c/elevado)*n - pow(n, fn2);*/
							resultado = (c/elevado)*n - pow(n, fn2);
							if (resultado <= 0){
								achou = 1;
								break;
							}
						}
						if (achou == 1)
							break;
					}
					if (achou == 0)
						printf("Nao existe solucao!!\n");
					else
						printf("se c <= %d e n <= %d\n",i,j);
				} else if (fn2 == 1){
					printf("Fato: T(n) = %dT(n/%d) + n\nSuposicao: T(n/%d) ≤ c(n/%d)n^%d\nPrecisa provar: T(n) ≤ cn^%d", a2,b2,b2,b2, p, p);
					printf("\nT(n) = %dT(n/%d) + n\n", a2,b2);
					printf("\t>= %dc(n/%d)^%d + n\n", a2,b2, p);
					
					if(p != 0) {
						elevado = ((pow(b2,p))/a2);
					} else {
						elevado = (1/a2);
					}				
					
					printf("\t= (c/%f)n^%d + n\n", elevado, p);
					printf("\t= cn^%d - ((c/%f)n^%d - n)  <-- Desejado - residual\n", p, elevado, p);
					printf("\t>= cn^%d <-- Desejado\n", p);
					printf("\nQuando (c/%f)n^%d - n <= 0, por exemplo,\n", elevado, p);
					
					for (i=1;i<2000;i++){				
						c = i;
						for (j=1;j<2000;j++){
							//funciona como o elevado, o expoente é o p ele roda, por exemplo, duas vezes em uma funcao quadrática
							n = j;					
							
							/*Tratamento de excessao*/
							if(p != 0) {
								resultado = (c/elevado)*pow(n,p) - n;
							} else {
								resultado = (c/elevado) - n;
							}					
							
							if (resultado <= 0){
								achou = 1;
								break;
							}
						}				
						if (achou == 1)
							break;
					}
					if (achou == 0)
						printf("Nao existe solucao!!\n");
					else
						printf("se c <= %d e n <= %d\n",j,i);
				} else {
					
					printf("Fato: T(n) = %dT(n/%d) + n^%d\nSuposicao: T(n/%d) ≤ c(n/%d)n^%d\nPrecisa provar: T(n) ≤ cn^%d", a2,b2, fn2,b2,b2, p, p);
					printf("\nT(n) = %dT(n/%d) + n^%d\n", a2,b2, fn2);
					printf("\t<= %dc(n/%d)^%d + n^%d\n", a2,b2, p, fn2);
					
					if(p != 0) {
						elevado = ((pow(b2,p))/a2);
					} else {
						elevado = (1/a2);
					}
					
					printf("\t= (c/%f)n^%d + n^%d\n", elevado, p, fn2);
					printf("\t= cn^%d - ((c/%f)n^%d - n^%d)  <-- Desejado - residual\n", p, elevado, p, fn2);
					printf("\t>= cn^%d <-- Desejado\n", p);
					printf("\nQuando (c/%f)n^%d - n^%d <= 0, por exemplo,\n", elevado, p, fn2);
					
					for (i=1;i<2000;i++){
						c = i;
						for (j=1;j<2000;j++){
							//funciona como o elevado, o expoente é o p ele roda, por exemplo, duas vezes em uma funcao quadrática
							n = j;
							
							//*Excessao para caso p == 1*/
							if(p != 0) {
								resultado = (c/elevado)*pow(n,p) - pow(n,fn2);
							} else {
								resultado = (c/elevado) - pow(n,fn2);
							}
							
							if (resultado <= 0){
								achou = 1;
								break;
							}
							n=1;
						}
						if (achou == 1)
							break;
					}
					if (achou == 0)
						printf("Nao existe solucao!!\n");
					else
						printf("se c <= %d e n <= %d\n",j,i);
				}
			} else if (strcmp(stringa, "teta") == 0){		
				printf("\n\nGRANDE O\n\n");
				if (p == 1){
					printf("Fato: T(n) = %dT(n/%d) + n\nSuposicao: T(n/%d) ≤ c(n/%d)n\nPrecisa provar: T(n) ≤ cn", a2,b2,b2,b2);
					printf("\nT(n) = %dT(n/%d) + n\n", a2,b2);
					
					printf("\t<= %dc(n/%d)n + n\n", a2,b2);
					
					elevado = ((pow(b2,p))/a2);
					
					printf("\t= (c/%f)n + n\n", elevado);
					printf("\t= cn - ((c/%f)n - n)  <-- Desejado - residual\n", elevado);
					printf("\t<= cn <-- Desejado\n");
					printf("\nQuando (c/%f)n - n >= 0, por exemplo,\n", elevado);
					
					for (i=0;i<2000;i++){
						c = i;
						for (j=0;j<2000;j++){
							n = j;
							resultado = (c/elevado)*pow(n,p) - p;
							if (resultado >= 0 && c > 0 && n > 0){
								achou = 1;
								break;
							}
						}
						if (achou == 1)
							break;
					}
					if (achou == 0)
						printf("Nao existe solucao!!\n");
					else
						printf("se c >= %d e n >= %d\n",i,j);
				} else if (fn2 == 1){
					printf("Fato: T(n) = %dT(n/%d) + n\nSuposicao: T(n/%d) ≤ c(n/%d)n^%d\nPrecisa provar: T(n) ≤ cn^%d", a2,b2,b2,b2, p, p);
					printf("\nT(n) = %dT(n/%d) + n\n", a2,b2);
					printf("\t<= %dc(n/%d)^%d + n\n", a2,b2, p);
					
					if(p != 0) {
						elevado = ((pow(b2,p))/a2);
					} else {
						elevado = (1/a2);
					}				
					
					printf("\t= (c/%f)n^%d + n\n", elevado, p);
					printf("\t= cn^%d - ((c/%f)n^%d - n)  <-- Desejado - residual\n", p, elevado, p);
					printf("\t<= cn^%d <-- Desejado\n", p);
					printf("\nQuando (c/%f)n^%d - n >= 0, por exemplo,\n", elevado, p);
					
					for (i=1;i<2000;i++){
						c = i;
						for (j=1;j<2000;j++){
							//funciona como o elevado, o expoente é o p ele roda, por exemplo, duas vezes em uma funcao quadrática
							n = j;
							
							/*Excessao para caso p == 0*/
								if(p != 0) {
									resultado = (c/elevado)*pow(n,p) - n;
								} else {
									resultado = (c/elevado) - n;
								}
							
							if (resultado >= 0){
								achou = 1;
								break;
							}					
						}
						if (achou == 1)
							break;
					}
					if (achou == 0)
						printf("Nao existe solucao!!\n");
					else
						printf("se c >= %d e n >= %d\n",j,i);
				} else {
					
					printf("Fato: T(n) = %dT(n/%d) + n^%d\nSuposicao: T(n/%d) ≤ c(n/%d)n^%d\nPrecisa provar: T(n) ≤ cn^%d", a2,b2, fn2,b2,b2, p, p);
					printf("\nT(n) = %dT(n/%d) + n^%d\n", a2,b2, fn2);
					printf("\t<= %dc(n/%d)^%d + n^%d\n", a2,b2, p, fn2);
					
					if(p != 0) {
						elevado = ((pow(b2,p))/a2);
					} else {
						elevado = (1/a2);
					}				
					
					printf("\t= (c/%f)n^%d + n^%d\n", elevado, p, fn2);
					printf("\t= cn^%d - ((c/%f)n^%d - n^%d)  <-- Desejado - residual\n", p, elevado, p, fn2);
					printf("\t<= cn^%d <-- Desejado\n", p);
					printf("\nQuando (c/%f)n^%d - n^%d >= 0, por exemplo,\n", elevado, p, fn2);
					
					for (i=1;i<2000;i++){
						c = i;
						for (j=1;j<2000;j++){
							//funciona como o elevado, o expoente é o p ele roda, por exemplo, duas vezes em uma funcao quadrática
							n = j;
							
							/*Excessao para caso p == 1*/
							if(p != 0) {
								resultado = (c/elevado)*pow(n,p) - pow(n,fn2);
							} else {
								resultado = (c/elevado) - pow(n,fn2);
							}
							
							if (resultado >= 0){
								achou = 1;
								break;
							}
							n=1;
						}
						if (achou == 1)
							break;
					}
					if (achou == 0)
						printf("Nao existe solucao!!\n");
					else
						printf("se c >= %d e n >= %d\n",j,i);
				}
				
				a2 = a_antes2;
				b2 = b_antes2;
				fn2 = fn2_antes;
				p = p_antes;
				c1 = j;
				n1 = i;
				
				printf("\n\nGRANDE OMEGA\n\n");
				if (p == 1){
					printf("Fato: T(n) = %dT(n/%d) + n\nSuposicao: T(n/%d) ≤ c(n/%d)n\nPrecisa provar: T(n) ≤ cn", a2,b2,b2,b2);
					printf("\nT(n) = %dT(n/%d) + n\n", a2,b2);
						
					printf("\t>= %dc(n/%d)n + n\n", a2,b2);
					
					elevado = (b2/a2);
					
					printf("\t= (c/%f)n + n\n", elevado);
					printf("\t= cn - ((c/%f)n - n)  <-- Desejado - residual\n", elevado);
					printf("\t>= cn <-- Desejado\n");
					printf("\nQuando (c/%f)n - n <= 0, por exemplo,\n", elevado);
					
					for (i=1;i<2000;i++){
						c = i;
						for (j=1;j<2000;j++){
							n = j;
							resultado = (c/elevado)*n - pow(n, fn2);
							if (resultado <= 0){
								achou = 1;
								break;
							}
						}
						if (achou == 1)
							break;
					}
					if (achou == 0)
						printf("Nao existe solucao!!\n");
					else
						printf("se c <= %d e n <= %d\n",i,j);
				} else if (fn2 == 1){
					printf("Fato: T(n) = %dT(n/%d) + n\nSuposicao: T(n/%d) ≤ c(n/%d)n^%d\nPrecisa provar: T(n) ≤ cn^%d", a2,b2,b2,b2, p, p);
					printf("\nT(n) = %dT(n/%d) + n\n", a2,b2);
					printf("\t>= %dc(n/%d)^%d + n\n", a2,b2, p);
					
					if(p != 0) {
						elevado = ((pow(b2,p))/a2);
					} else {
						elevado = (1/a2);
					}				
					
					printf("\t= (c/%f)n^%d + n\n", elevado, p);
					printf("\t= cn^%d - ((c/%f)n^%d - n)  <-- Desejado - residual\n", p, elevado, p);
					printf("\t>= cn^%d <-- Desejado\n", p);
					printf("\nQuando (c/%f)n^%d - n <= 0, por exemplo,\n", elevado, p);
					
					for (i=1;i<2000;i++){
						c = i;
						for (j=1;j<2000;j++){
							//funciona como o elevado, o expoente é o p ele roda, por exemplo, duas vezes em uma funcao quadrática
							n = j;
							
							/*Excessao para caso p == 1*/
							if(p != 0) {
								resultado = (c/elevado)*pow(n,p) - n;
							} else {
								resultado = (c/elevado) - n;
							}
							
							if (resultado <= 0){
								achou = 1;
								break;
							}
						}
						n=1;
						if (achou == 1)
							break;
					}
					if (achou == 0)
						printf("Nao existe solucao!!\n");
					else
						printf("se c <= %d e n <= %d\n",j,i);
				} else {
					
					printf("Fato: T(n) = %dT(n/%d) + n^%d\nSuposicao: T(n/%d) ≤ c(n/%d)n^%d\nPrecisa provar: T(n) ≤ cn^%d", a2,b2, fn2,b2,b2, p, p);
					printf("\nT(n) = %dT(n/%d) + n^%d\n", a2,b2, fn2);
					printf("\t<= %dc(n/%d)^%d + n^%d\n", a2,b2, p, fn2);
					
					if(p != 0) {
						elevado = ((pow(b2,p))/a2);
					} else {
						elevado = (1/a2);
					}				
					
					printf("\t= (c/%f)n^%d + n^%d\n", elevado, p, fn2);
					printf("\t= cn^%d - ((c/%f)n^%d - n^%d)  <-- Desejado - residual\n", p, elevado, p, fn2);
					printf("\t>= cn^%d <-- Desejado\n", p);
					printf("\nQuando (c/%f)n^%d - n^%d <= 0, por exemplo,\n", elevado, p, fn2);
					
					for (i=1;i<2000;i++){
						c = i;
						for (j=1;j<2000;j++){
							//funciona como o elevado, o expoente é o p ele roda, por exemplo, duas vezes em uma funcao quadrática
							n = j;
							
							/*Excessao para caso p == 1*/
							if(p != 0) {
								resultado = (c/elevado)*pow(n,p) - pow(n,fn2);
							} else {
								resultado = (c/elevado) - pow(n,fn2);
							}
							
							if (resultado <= 0){
								achou = 1;
								break;
							}
							n=1;
						}
						if (achou == 1)
							break;
					}
					if (achou == 0)
						printf("Nao existe solucao!!\n");
					else
						printf("se c <= %d e n <= %d\n",j,i);
				}
				
				c2 = j;
				n2 = i;
				a2 = a_antes2;
				b2 = b_antes2;
				fn2 = fn2_antes;
				p = p_antes;
				n = 1;
				c = 1;
				achou = 0;
				
				for (i=1;i<2000;i++){
					c = i;
					for (j=1;j<2000;j++){
						n = j;
						resultado = (c/elevado)*pow(n,p) - pow(n,fn2);
						if (c > 0 && n > 0 && resultado >= 0 && resultado <= 0){
							achou = 1;
							break;
						}
						n=1;
					}
					if (achou == 1)
						break;
				}
				
				if (achou == 1)
					printf("\nPODEMOS PROVAR O TETA PARA c = %d E n = %d\n", j,i);
				else 
					printf("\nNAO EXISTE PROVA PARA TETA\n");
			}
			
// 		a2 = rand() % 10;
// 		b2 = rand() % 10;
// 		fn2 = rand() % 10;
// 		p = rand() % 10;
// 	}

	printf("\n\n");
	
	return 0;
}