#include <stdio.h>

void print(int N) {
	if (N < 10) {
		printf("%d\n", N);
		return;
	}

	print(N / 10);
	printf("%d\n", N % 10);
}
int main() {
	int N;
	scanf("%d", &N);
	print(N);
	return 0;
}