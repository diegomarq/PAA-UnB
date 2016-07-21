#include "mode_11_0027876_Diego.h"

void _print_header(typefunction function) {
	printf("--------------------------------\n");
	printf("\nGRANDEO\n\n");

	printf("Fato: T(n) = %dT(n/%d) + n^%d\n", function.a, function.b, function.fn);
	printf("Suposicao: T(n/%d) <= c(n/%d)^%d\nPrecisa provar: T(n) <= cn^%d\n", function.b, function.b, function.p, function.p);
}

void _print_initprove(typefunction function) {
	printf("\nT(n)\t= %dT(n/%d) + n^%d\n", function.a, function.b, function.fn);
	printf("\t<= %dc(n/%d)^%d + n^%d\n", function.a, function.b, function.p, function.fn);
}

void _print_bodyprove(typefunction function, float rd_calc) {
	printf("\t= cn^%d - (%.2fcn^%d - n^%d) <- desejado - residual\n", function.p, rd_calc, function.p, function.fn);
	printf("\t<= cn^%d <- Desejado\n", function.p);
}

void _print_result(typefunction function, float rd_calc) {
	printf("\t\nQuando %.2fcn^%d - n^%d >= 0, por exemplo\n", rd_calc, function.p, function.fn);
	printf("\tc >= %.2f e n >= %d\n", function.res_co, function.res_no);

	printf("\n--------------------------------\n");
}

void _print_notexists(typefunction function) {
	printf("\t\n<= cn^%d para qualquer escolha de c > 0\n", function.p);
	printf("\tNao foi possivel completar a prova\n");

	printf("\n--------------------------------\n");
}

void grandeO(typefunction function) {

	float itm_calc, rd_calc;

	itm_calc = 	function.a/pow(function.b, function.p);	
	rd_calc = 1 - itm_calc;

	_print_header(function);
	_print_initprove(function);
	_print_bodyprove(function, rd_calc);

	if(itm_calc >= 1) {
		_print_notexists(function);

		function.res_co = -1;
		function.res_no = -1;
	}
	else {
		if (function.p > function.fn) {
			function.res_co = 1/rd_calc;
			function.res_no = 1;
			_print_result(function, rd_calc);
		}
		else if (function.p == function.fn) {
			function.res_co = 1/rd_calc;
			function.res_no = 1;
			_print_result(function, rd_calc);	
		} else {
			_print_notexists(function);

			function.res_co = -1;
			function.res_no = -1;
		}
	}

	co = function.res_co;
	no = function.res_no;
}