#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int N, M;		//종류 : 100
int V[110];	//무게
int C[110];	//만족도
int K[100];	//개수

int DP[10010][10010];

int main() {
	int v, c,k,idx=0;

	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d %d", &v, &c, &k);
		for (int j = 0; j < k; j++) {
			++idx;
			V[idx] = v;
			C[idx] = c;
		}
	}
	
	for (int i = 1; i <= idx; i++) {
		for (int j = 1; j <= M; j++) {
			if (j < V[i])
				DP[i][j] = DP[i - 1][j];
			else
				DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - V[i]] + C[i]);
		}
	}
	
	printf("%d", DP[idx][M]);
	return 0;
}