#include <stdio.h>

int sum(int N) {
	if (N == 1) return 1;
	return N + sum(N - 1);
}

int main() {
	int N;
	scanf("%d", &N);
	int result = sum(N);

	printf("%d", result);
	return 0;
}
