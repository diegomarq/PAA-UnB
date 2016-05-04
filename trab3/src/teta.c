#include "mode.h"

void _tprint_result(typefunction function) {	
	printf("\t\nO valor entao sera:\n");
	printf("\tc >= %.2f e n >= %d\n", function.res_cteta, function.res_nteta);

	printf("\n--------------------------------\n");
}

void _tprint_notexists() {	
	printf("Nao foi possivel completar a prova\n");

	printf("\n--------------------------------\n");
}

void teta(typefunction function) {

	if(comega == -1 && co == -1) {
		_tprint_notexists();
	}
	else if(comega >= 0 && co == -1) {
		_tprint_notexists();
	}	
	else if(comega == -1 && co >= 0) {
		_tprint_notexists();
	}
	else {

		if (comega > co) {
			function.res_cteta = comega;
			function.res_nteta = 1;
		}
		else if(comega < co) {
			function.res_cteta = co;
			function.res_nteta = 1;
		} else {
			function.res_cteta = co;
			function.res_nteta = 1;
		}
		_tprint_result(function);
	}
}