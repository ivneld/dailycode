#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int N, K;					//N : 보석의 개수, K : 배낭의 무게
int W[1010];
int P[1010];

int DP[1010][10010];

int main() {
	scanf("%d %d", &N, &K);			
	for (int i = 1; i <= N; i++)
		scanf("%d  %d", &W[i], &P[i]);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (j < W[i])
				DP[i][j] = DP[i - 1][j];
			else
				DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - W[i]] + P[i]);
		}
	}
	printf("%d", DP[N][K]);
}