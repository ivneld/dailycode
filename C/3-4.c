#include <stdio.h>

int max();
int findMax();

int main() {
	int N;
	scanf("%d", &N);
	int* arr = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
		scanf("%d", arr + i);
	printf("%d", findMax(arr, N));
	return 0;
}

int max(int x, int y) {
	return x > y ? x : y;
}

int findMax(int* x,int N) {
	if (N == 1)
		return x[0];
	else
	return max(x[N - 1], findMax(x, N - 1));
}
//5
//4 1 8 3 7  
//7과 4 2 8 3 중에서 최대값 비교
