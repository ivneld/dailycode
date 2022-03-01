#include <stdio.h>

void swap();

int main() {
	int N;
	int arr[50];
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	int a, b;
	scanf("%d %d", &a, &b);

	swap(arr + a, arr + b);

	for (int i = 0; i < N; i++)
		printf(" %d", arr[i]);
	return 0;
}

void swap(int* x, int* y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}