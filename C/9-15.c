#include <stdio.h>

void ABC();

void main() {
	int arr[10] = { 0 };
	int size = 10;
	for (int* p = arr; p < arr + 10; p++)
		scanf("%d", p);

	for (int i = 0; i < 9; i++) {
		ABC(arr + i, size);
		--size;
	}

	for (int* p = arr; p < arr + 10; p++) printf(" %d", *p);
}

void ABC(int *S, int K) {
	int max = *S;
	int* idx = S;

	for (int* p = S; p < S + K; p++) {
		if (*p > max) {
			max = *p;
			idx = p;
		}
	}
	int tmp = *S;
	*S = max;
	*idx = tmp;
}