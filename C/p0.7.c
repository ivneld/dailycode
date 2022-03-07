#include <stdio.h>
#include <stdlib.h>

int main() {
	int N;
	scanf("%d", &N);

	int* arr1 = (int*)malloc(sizeof(int) * N);
	int* arr2 = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++)
		scanf("%d", arr1 + i);
	for (int i = 0; i < N; i++)
		scanf("%d", arr2 + i);

	for (int i = 0; i < N; i++) {
		int sum;
		sum = *(arr1 + i) + *(arr2 + N - 1 - i);
		printf(" %d", sum);
	}
	free(arr1);
	free(arr2);
	return 0;
}