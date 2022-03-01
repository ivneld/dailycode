#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void get_min_max();

int main() {
	int arr[10] = { 12,1003,1,5,66,77,0,1002,99,4 };
	int max = arr[0], min = arr[0];

	get_min_max(arr, &min, &max);
	printf("최대값 : %d\n", max);
	printf("최소값 : %d", min);
	return 0;
}

void get_min_max(int *arr,int* min, int* max) {
	for (int i = 1; i < 10; i++) {
		if (*(arr + i) > *max)
			*max = *(arr + i);
		if (*(arr + i) < *min)
			*min = *(arr + i);
	}
}