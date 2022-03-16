#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
int* prefixAverages1();
int* prefixAverages2();

void main() {
	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;

	int n;
	int* A;
	int* X;
	scanf("%d", &n);
	X = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		X[i] = rand() % 10000 + 1;

	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);
	A = prefixAverages1(X, n);
	QueryPerformanceCounter(&end);
	/*for (int i = 0; i < n; i++)
		printf("%d ", A[i]);*/
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("%.12fms", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
	printf("\n");

	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);
	A = prefixAverages2(X, n);
	QueryPerformanceCounter(&end);
	/*for (int i = 0; i < n; i++)
		printf("%d ", A[i]);*/
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("%.12fms", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
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
