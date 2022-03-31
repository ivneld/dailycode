#include <stdio.h>

void swap();

int main() {
	int N;
	int X[101] = { 0 };
	int cnt;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &X[i]);
	scanf("%d", &cnt);

	for (int i = 0; i < cnt; i++) {
		int start, end;
		scanf("%d %d", &start, &end);
		swap(X, start, end);
	}
	for (int i = 0; i < N; i++)
		printf(" %d", X[i]);
	return 0;
}

void swap(int* X,int start, int end) {
	int n = (end - start + 1) / 2;

	for (int i = 0; i < n; i++) {
		int tmp = X[start + i];
		X[start + i] = X[end - i];
		X[end - i] = tmp;
	}
}