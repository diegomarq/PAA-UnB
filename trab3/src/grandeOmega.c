#include "mode.h"

void print_header(typefunction function) {
	printf("--------------------------------\n");
	printf("\nGRANDEOMEGA\n\n");

	printf("Fato: T(n) = %dT(n/%d) + n^%d\n", function.a, function.b, function.fn);
	printf("Suposicao: T(n/%d) >= c(n/%d)^%d\nPrecisa provar: T(n) >= cn^%d\n", function.b, function.b, function.p, function.p);
}

void print_initprove(typefunction function) {
	printf("\nT(n)\t= %dT(n/%d) + n^%d\n", function.a, function.b, function.fn);
	printf("\t>= %dc(n/%d)^%d + n^%d\n", function.a, function.b, function.p, function.fn);
}

void print_bodyprove(typefunction function, float rd_calc) {
	printf("\t= cn^%d + (%.2fcn^%d + n^%d) <- desejado - residual\n", function.p, rd_calc, function.p, function.fn);
	printf("\t>= cn^%d <- Desejado\n", function.p);
}

void print_result(typefunction function, float rd_calc) {
	printf("\t\nQuando %.2fcn^%d + n^%d >= 0, por exemplo\n", rd_calc, function.p, function.fn);
	printf("\tc >= %.2f e n >= %d\n", function.res_comega, function.res_nomega);

	printf("\n--------------------------------\n");
}

void print_anyresult(typefunction function) {
	printf("\t\nQuando n^%d >= 0, por exemplo\n", function.fn);
	printf("\tn >= %d\n", function.res_nomega);

	printf("\n--------------------------------\n");
}

void print_notexists(typefunction function) {
	printf("\t\n>= cn^%d para qualquer escolha de c > 0\n", function.p);
	printf("\tNao foi possivel completar a prova\n");

	printf("\n--------------------------------\n");
}

void grandeOmega(typefunction function) {

	float itm_calc, rd_calc;

	itm_calc = 	function.a/pow(function.b, function.p);	
	rd_calc = itm_calc - 1;

	print_header(function);
	print_initprove(function);
	print_bodyprove(function, rd_calc);

	if(itm_calc < 1) {

		if(function.p > function.fn) {
			print_notexists(function);

			function.res_comega = -1;
			function.res_nomega = -1;
		}
		else if(function.p == 0 && function.fn == 0) {
			function.res_comega = 1;
			function.res_nomega = 1;
			print_result(function, rd_calc);
		}
		else if(function.p == function.fn) {
			print_notexists(function);	

			function.res_comega = -1;
			function.res_nomega = -1;
		}
		else {			
			function.res_comega = 1/rd_calc;
			function.res_nomega = 1;
			print_result(function, rd_calc);			
		}
	}
	else if (itm_calc == 1) {
		function.res_comega = 0; // any value
		function.res_nomega = 1;
		print_anyresult(function);
	}
	else {
		function.res_comega = 1;
		function.res_nomega = 1;
		print_result(function, rd_calc);
	}

	comega = function.res_comega;
	nomega = function.res_nomega;
}