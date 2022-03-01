#include <stdio.h>

void ABC();

int main() {
	int arr[10];
	for (int i = 0; i < 10; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < 9; i++)
		ABC(arr, i);

	for (int i = 0; i < 10; i++)
		printf(" %d", arr[i]);
	return 0;
}

void ABC(int arr[], int k) {
	int max = arr[k];
	int idx = k;

	for (int i = k + 1; i < 10; i++) {
		if (arr[i] > max) {
			max = arr[i];
			idx = i;
		}
	}
	int tmp = arr[k];
	arr[k] = max;
	arr[idx] = tmp;
}