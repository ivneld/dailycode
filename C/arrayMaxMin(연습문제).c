#include <stdio.h>

int max();
void arrayMaxMin();

int main() {
	int arr[5] = { 3,4,5,6,1 };
	int x, y;
	arrayMaxMin(arr, 5, &x, &y);
	printf("%d %d", x, y);
	return 0;
}

int max(int a, int b) {
	return a > b ? a : b;
}
int min(int a, int b) {
	return a > b ? b : a;
}

void arrayMaxMin(int* A, int n,int *x,int *y) {
	if (n == 1) {
		*x = A[0];
		*y = A[0];
	}
	else {
		*x = max(A[n - 1], *x);
		*y = min(A[n - 1], *y);
	}
}