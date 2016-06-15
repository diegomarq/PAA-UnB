/*Diego Marques de Azevedo*/
#include <stdio.h>
#include <string.h>

char w1[2001], w2[2001];
int DP[2001][2001];

int min(int a, int b);

int min(int a, int b) {
	if(a > b) return b;
	else return a;
}

int edist(int n1, int n2) {
	int i, j;
	for(i=0; i<=n1; i++) {
		for(j=0; j<=n2; j++) {
			if(i==0) {
				//insere
				DP[i][j] = j;
			}
			if(j==0) {
				//insere
				DP[i][j] = i;
			}
			if(i == 0 || j == 0) continue;
			if(w1[i-1] == w2[j-1]) {
				//sem custo
				DP[i][j] = DP[i-1][j-1];
			}
			else{
				DP[i][j] = DP[i-1][j-1] + 1;
			}			
			//insere, remove, troca
			DP[i][j] = min(min(DP[i][j-1]+1, DP[i-1][j]+1), DP[i][j]);
		}
	}	
	return DP[n1][n2];
}

int main() {
	int c;

	scanf("%d", &c);
	while(c--) {
		scanf(" %s %s", w1, w2);		
		printf("%d\n", edist(strlen(w1), strlen(w2)));
	}
	return 0;
}
