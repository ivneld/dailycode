#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define X 5000

int dp[5001] = { 0,X,X,1,X,1 };

int min(int x,int y) {
	return x > y ? y : x;
}

int main() {
	int N;
	scanf("%d", &N);

	if (N > 5) {
		for (int i = 6; i <= N; i++) {
			dp[i] = min(dp[i - 3] + 1, dp[i - 5] + 1);
		}
		
		if (dp[N] >= X) {
			printf("-1");
			return 0;
		}
		printf("%d", dp[N]);
		return 0;
	}

	if (dp[N] == X)
		printf("-1");
	else
		printf("1");
	return 0;
}