#include <stdio.h>

void addArray();

void main() {
	int N;
	scanf("%d", &N);
	int a[20]={0}, b[20]={0}, c[20]={0};
	
	for (int *p = a; p < a + N; p++)
		scanf("%d", p);
	for (int *p = b; p < b + N; p++)
		scanf("%d", p);

	addArray(a, b, c, N);

	for (int *p = c; p < c + N; p++)
		printf(" %d", *p);
}

void addArray(int *a,int *b, int *c,int N) {

	for (int i = 0; i < N; i++) {
		*(c + i) = *(a + i) + *(b + N - 1 - i);
	}
}