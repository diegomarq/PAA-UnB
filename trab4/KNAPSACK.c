/*Diego Marques de Azevedo*/
#include <stdio.h>

int v[2001], s[2001];
long long int DP[2001][2001];

long long int max(long long int a, long long int b) {
	if(a > b) return a;
	else return b;
}

long long int knapsack(int mv, int n) {
	int i, j;
	for(i=0; i<n; i++) {
		for(j=0; j<=mv; j++) {
			if(i == 0){
				if(j >= s[0]) DP[i][j] = v[0];
				else DP[i][j] = 0;
			}
			else if(s[i] <= j)
				DP[i][j] = max(v[i] + DP[i-1][j-s[i]], DP[i-1][j]);
			else
				DP[i][j] = DP[i-1][j];
		}
	}
	return DP[n-1][mv];
}

int main() {
	int i, mv, n;
	scanf("%d%d", &mv, &n);
	for (i=0; i<n; i++)
		scanf("%d%d", &s[i], &v[i]);
	printf("%lld\n", knapsack(mv, n));
	return 0;
}
