#ifndef MODE_H
#define MODE_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct _typefunction {
	int a;
	int b;
	int fn;
	int p;
	char mode[6];

	float res_comega;
	float res_co;
	float res_cteta;
	int res_nomega;
	int res_no;
	int res_nteta;
}typefunction;

extern float comega, co;
extern int nomega, no;

void grandeO(typefunction function);
void grandeOmega(typefunction function);
void teta(typefunction function);

#endif
