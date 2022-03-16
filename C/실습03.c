#include <stdio.h>
#include <stdlib.h>

int* prefixAverages1();
int* prefixAverages2();

void main() {
	int n;
	int* A;
	int* X;
	scanf("%d", &n);
	X = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", &X[i]);

	A = prefixAverages1(X, n);
	for (int i = 0; i < n; i++)
		printf("%d ", A[i]);
	
	printf("\n");

	A = prefixAverages2(X, n);
	for (int i = 0; i < n; i++)
		printf("%d ", A[i]);
}

int* prefixAverages1(int* X, int n) {
	float sum;
	int* A;
	A = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = 0; j <= i; j++) {
			sum += X[j];
		}
		A[i] = (int)(sum / (i + 1) + 0.5);
	}
	return A;
}

int* prefixAverages2(int* X, int n) {
	float sum = 0;
	int* A;
	A = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		sum += X[i];
		A[i] = (int)(sum / (i + 1) + 0.5);
	}
	return A;
}
