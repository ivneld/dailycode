#include <stdio.h>

int arrsum();

void main() {
	int N,S,E;
	scanf("%d %d %d", &N,&S,&E);
	int arr[100]={0};
	for (int* p = arr; p < arr + N; p++)
		scanf("%d", p);

	printf("%d", arrsum(arr + S, arr + E));
}

int arrsum(int* s, int* e) {
	int sum = 0;

	for (int* p = s; p <= e; p++)
		sum += *p;

	return sum;
}