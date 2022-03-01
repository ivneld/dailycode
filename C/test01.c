#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void arith_seq();

int main() {
	int N, num1;
	int arr[10] = { 0};
	scanf("%d %d", &N, &num1);

	arith_seq(arr, N, num1);
	return 0;
}

void arith_seq(int* p, int N, int num1) {
	*p = num1;
	for (int i = 1; i < 10; i++) {
		*(p + i) = *p + (N * i);
	}
	for (int i = 0; i < 10; i++)
		printf("%d ", *(p + i));
}