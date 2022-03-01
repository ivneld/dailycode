#include <stdio.h>
#include <algorithm>
#define X 5000

int min(int x,int y) {
	return x > y ? y : x;
}

int main() {
	int dp[19] = { 0,X,X,1,X,1 };

	for (int i = 6; i <= 18; i++) {
		dp[i] = min(dp[i - 3] + 1, dp[i - 5] + 1);
	}

	if (dp[18] >= X) {
		printf("-1");
		return 0;
	}

	printf("%d",dp[18]);
	return 0;
}