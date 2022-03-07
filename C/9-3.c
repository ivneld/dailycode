#include <stdio.h>

void main() {

	int ar[50] = { 0 }, N;
	int* p;

	scanf("%d", &N);

	for (p = ar; p < ar + N; p++) {
		scanf("%d", p);
	}

	int sum = 0;
	for (p = ar; p < ar + N; p++) {
		if (*p == 0) break;
		++sum;
	}
	printf("%d", sum);
}