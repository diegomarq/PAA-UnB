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

	int res_c;
	int res_n;
}typefunction;

void grandeO(typefunction function);
void grandeOmega(typefunction function);

#endif
