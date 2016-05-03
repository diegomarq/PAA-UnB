#include "mode.h"

void grandeO(typefunction function) {

	float itm_calc, itm_view, rd_calc, rd_view, c;

	printf("--------------------------------\n");
	printf("\nGRANDEO\n\n");

	itm_calc = 	function.a/pow(function.b, function.p);
	itm_view = pow(itm_calc, -1);

	rd_calc = 1 - itm_calc;
	rd_view = pow(rd_calc, -1);

	if(function.p > function.fn) {
		function.res_c = rd_view;
		function.res_n = 1;		
	}
	else if(function.p == function.fn && rd_calc > 0) {

		function.res_c = 1;
		while(c < 1) {
			c = function.res_c++/rd_view;			
		}
		function.res_n = 1;
	}
	else {
		function.res_c = -1;
		function.res_n = -1;
	}
	
	if(function.fn == 0) {
		printf("Fato: T(n) = %dT(n/%d) + 1\n", function.a, function.b);

		if(function.p == 0)  {
			printf("Suposicao: T(n/%d) ≤ c\nPrecisa provar: T(n) ≤ c\n", function.b);

			printf("\nT(n)\t= %dT(n/%d) + 1\n", function.a, function.b);
			printf("\t<= %dc + 1\n", function.a);		

			printf("\t= (c/%f) + 1\n", itm_view);


			// MODE SOLUCTION
			if(itm_calc >= 1) {		
				printf("\t<= c <- Desejado\n");
				printf("Solucao nao existe\n");
			}
			else {
				printf("\t= c -((c/%.2f) - 1) <- desejado - residual\n", rd_view);
				printf("\t<= c <- Desejado\n");

				printf("\t\nQuando (c/%.2f) - 1 >= 0, por exemplo\n", rd_view);
				printf("\tc >= %d e n >= %d\n", function.res_c, function.res_n);
			}

		}
		else if(function.p == 1)  {
			printf("Suposicao: T(n/%d) ≤ c(n/%d)\nPrecisa provar: T(n) ≤ cn\n", function.b, function.b);	

			printf("\nT(n)\t= %dT(n/%d) + 1\n", function.a, function.b);
			printf("\t<= %dc(n/%d) + 1\n", function.a, function.b);

			printf("\t= (c/%f)n + 1\n", itm_view);

			// MODE SOLUCTION
			if(itm_calc >= 1) {				
				printf("\t<= cn <- Desejado\n");
				printf("Solucao nao existe\n");
			}
			else {
				printf("\t= cn -((c/%.2f)n - 1) <- desejado - residual\n", rd_view);
				printf("\t<= cn <- Desejado\n");

				printf("\t\nQuando (c/%.2f)n - 1 >= 0, por exemplo\n", rd_view);
				printf("\tc >= %d e n >= %d\n", function.res_c, function.res_n);
			}
		}
		else {
			printf("Suposicao: T(n/%d) ≤ c(n/%d)^%d\nPrecisa provar: T(n) ≤ cn^%d\n", function.b, function.b, function.p, function.p);

			printf("\nT(n)\t= %dT(n/%d) + 1\n", function.a, function.b);
			printf("\t<= %dc(n/%d)^%d + 1\n", function.a, function.b, function.p);

			printf("\t= (c/%f)n^%d + 1\n", itm_view, function.p);

			// MODE SOLUCTION
			if(itm_calc >= 1) {				
				printf("\t<= cn^%d <- Desejado\n", function.p);
				printf("Solucao nao existe\n");
			}
			else {
				printf("\t= cn^%d -((c/%.2f)n^%d - 1) <- desejado - residual\n", function.p, rd_view, function.p);
				printf("\t<= cn^%d <- Desejado\n", function.p);

				printf("\t\nQuando (c/%.2f)n^%d - 1 >= 0, por exemplo\n", rd_view, function.p);
				printf("\tc >= %d e n >= %d\n", function.res_c, function.res_n);
			}
		}
	}
	else if(function.fn == 1){
		printf("Fato: T(n) = %dT(n/%d) + n\n", function.a, function.b);

		if(function.p == 0)  {
			printf("Suposicao: T(n/%d) ≤ c\nPrecisa provar: T(n) ≤ c\n", function.b);

			printf("\nT(n)\t= %dT(n/%d) + n\n", function.a, function.b);
			printf("\t<= %dc + n\n", function.a);

			// MODE SOLUCTION
			if(itm_calc >= 1 || function.res_c == -1) {				
				printf("\t<= c <- Desejado\n");
				printf("Solucao nao existe\n");
			}
			else {
				printf("\t= c -((c/%.2f) - 1) <- desejado - residual\n", rd_view);
				printf("\t<= c <- Desejado\n");

				printf("\t\nQuando (c/%.2f) - 1 >= 0, por exemplo\n", rd_view);
				printf("\tc >= %d e n >= %d\n", function.res_c, function.res_n);
			}
		}
		else if(function.p == 1)  {
			printf("Suposicao: T(n/%d) ≤ c(n/%d)n\nPrecisa provar: T(n) ≤ cn\n", function.b, function.b);	

			printf("\nT(n)\t= %dT(n/%d) + n\n", function.a, function.b);
			printf("\t<= %dc(n/%d) + n\n", function.a, function.b);

			// MODE SOLUCTION
			if(itm_calc >= 1) {				
				printf("\t<= cn <- Desejado\n");
				printf("Solucao nao existe\n");
			}
			else {
				printf("\t= cn -((c/%.2f)n - n) <- desejado - residual\n", rd_view);
				printf("\t<= cn <- Desejado\n");

				printf("\t\nQuando (c/%.2f)n - n >= 0, por exemplo\n", rd_view);
				printf("\tc >= %d e n >= %d\n", function.res_c, function.res_n);
			}			
		}
		else {
			printf("Suposicao: T(n/%d) ≤ c(n/%d)^%d\nPrecisa provar: T(n) ≤ cn^%d\n", function.b, function.b, function.p, function.p);

			printf("\nT(n)\t= %dT(n/%d) + n\n", function.a, function.b);
			printf("\t<= %dc(n/%d)^%d + n\n", function.a, function.b, function.p);

			// MODE SOLUCTION
			if(itm_calc >= 1) {				
				printf("\t<= cn^%d <- Desejado\n", function.p);
				printf("Solucao nao existe\n");
			}
			else {
				printf("\t= cn^%d -((c/%.2f)n^%d - n) <- desejado - residual\n", function.p, rd_view, function.p);
				printf("\t<= cn^%d <- Desejado\n", function.p);

				printf("\t\nQuando (c/%.2f)n^%d - n >= 0, por exemplo\n", rd_view, function.p);
				printf("\tc >= %d e n >= %d\n", function.res_c, function.res_n);
			}
		}	
	} else {
		printf("Fato: T(n) = %dT(n/%d) + n^%d\n", function.a, function.b, function.fn);

		if(function.p == 0)  {
			printf("Suposicao: T(n/%d) ≤ c\nPrecisa provar: T(n) ≤ c\n", function.b);

			printf("\nT(n)\t= %dT(n/%d) + n^%d\n", function.a, function.b, function.fn);
			printf("\t<= %dc + n^%d\n", function.a, function.fn);

			// MODE SOLUCTION
			if(itm_calc >= 1) {				
				printf("\t<= c <- Desejado\n");
				printf("Solucao nao existe\n");
			}
			else {
				printf("\t= c -((c/%.2f) - n^%d) <- desejado - residual\n", rd_view, function.fn);
				printf("\t<= c <- Desejado\n");

				printf("\t\nQuando (c/%.2f) - n^%d >= 0, por exemplo\n", rd_view, function.fn);
				printf("\tc >= %d e n >= %d\n", function.res_c, function.res_n);
			}
		}
		else if(function.p == 1)  {
			printf("Suposicao: T(n/%d) ≤ c(n/%d)n\nPrecisa provar: T(n) ≤ cn\n", function.b, function.b);	

			printf("\nT(n)\t= %dT(n/%d) + n^%d\n", function.a, function.b, function.fn);
			printf("\t<= %dc(n/%d) + n^%d\n", function.a, function.b, function.fn);

			// MODE SOLUCTION
			if(itm_calc >= 1) {				
				printf("\t<= cn <- Desejado\n");
				printf("Solucao nao existe\n");
			}
			else {
				printf("\t= cn -((c/%.2f)n - n^%d) <- desejado - residual\n", rd_view, function.fn);
				printf("\t<= cn <- Desejado\n");

				printf("\t\nQuando (c/%.2f)n - n^%d >= 0, por exemplo\n", rd_view, function.fn);
				printf("\tc >= %d e n >= %d\n", function.res_c, function.res_n);
			}
		}
		else {
			printf("Suposicao: T(n/%d) ≤ c(n/%d)^%d\nPrecisa provar: T(n) ≤ cn^%d\n", function.b, function.b, function.p, function.p);

			printf("\nT(n)\t= %dT(n/%d) + n^%d\n", function.a, function.b, function.fn);
			printf("\t<= %dc(n/%d)^%d + n^%d\n", function.a, function.b, function.p, function.fn);

			// MODE SOLUCTION
			if(itm_calc >= 1 || function.res_c == -1) {				
				printf("\t<= cn^%d <- Desejado\n", function.p);
				printf("Solucao nao existe\n");
			}
			else {
				printf("\t= cn^%d -((c/%.2f)n^%d - n^%d) <- desejado - residual\n", function.p, rd_view, function.p, function.fn);
				printf("\t<= cn^%d <- Desejado\n", function.p);

				printf("\t\nQuando (c/%.2f)n^%d - n^%d >= 0, por exemplo\n", rd_view, function.p, function.fn);
				printf("\tc >= %d e n >= %d\n", function.res_c, function.res_n);
			}
		}
	}

	printf("\n--------------------------------\n");
}