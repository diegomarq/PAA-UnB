/*Diego Marques de Azevedo*/
#include <stdio.h>
#include <string.h>

long long int DP[10001];
int monster[10001];

int max(int a, int b) {
	if(a > b) return a;
	else return b;
}

long long int farida(int n) {
	int i;
	if(n == 0) return 0;
	else if(n ==1) return monster[n-1];

	DP[0] = monster[0];
	DP[1] = max(monster[0], monster[1]);

	for(i = 2; i < n; i++) {
		DP[i] = max(monster[i]+DP[i-2], DP[i-1]);		
	}

	return DP[n-1];
}

int main() {
	int c, n, i, f;
	f = 1;
	scanf("%d", &c);	
	while(c--) {		
		scanf("%d", &n);		
		for (i = 0; i < n; i++)
			scanf("%d", &monster[i]);
		
		printf("Case %d: %lld\n", f++, farida(n));
	}

	return 0;
}
