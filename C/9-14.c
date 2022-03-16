#include <stdio.h>

int add_to_k();

void main() {
	int N;
	scanf("%d", &N);
	int sum = 0;
	int d[100];
	
	for (int* p = d; p < d + N; p++)
		scanf("%d", p);

	for (int i = 0; i < N; i++) {
		sum += add_to_k(d, d + i);
	}
	printf("%d", sum);
}

int add_to_k(int* S, int* E) {
	int sum = 0;

	for (int* p = S; p <= E; p++)
		sum += *p;

	return sum;
}