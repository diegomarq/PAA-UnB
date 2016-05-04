#include "mode.h"

float comega = -2, co = -2;
int nomega = -2, no = -2;

int valid_function(typefunction function) {
	int flag = 0;
	if(function.a <= 0) {
		printf("Invalid value of a\n");		
	}
	else if(function.b <= 0) {
		printf("Invalid value of b\n");
	}
	else if(function.fn < 0) {
		printf("Invalid value of fn\n");
	}
	else if(function.p < 0) {
		printf("Invalid value of p\n");
	} else {
		flag = 1;
	}
	return flag;
}

void cases(typefunction function) {
	if (strcmp(function.mode, "grandeo") == 0){
		grandeO(function);		
	}
	else if (strcmp(function.mode, "grandeomega") == 0){
		grandeOmega(function);		
	}
	else if (strcmp(function.mode, "teta") == 0){
		grandeO(function);	
		grandeOmega(function);
		teta(function);
	}
}

int main(int argc, char *argv[]){

	typefunction function;

	if(argc < 5) {
		perror("Usage: <program object> <a> <b> <fn> <p> <mode>");
		return 0;
	}
	
	// READ INPUT
	function.a = atoi(argv[1]);	
	function.b = atoi(argv[2]);	
	function.fn = atoi(argv[3]);		
	function.p = atoi(argv[4]);
	
	
	// MODE INDUCTION
	strcpy(function.mode, argv[5]);

	// Check if values are valid
	if(valid_function(function) == 0) {
		return 0;
	}
	cases(function);
	return 0;
}