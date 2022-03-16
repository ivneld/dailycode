#include <stdio.h>
#include <stdlib.h>

int mostOnes();

void main() {
	int n;
	scanf("%d", &n);
	int* p = (int*)malloc(sizeof(int) * n * n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			scanf("%d", p + i * n + j);
	}
	
	printf("%d", mostOnes(p, n));
}

int mostOnes(int *A,int n) {
	int maxRow=0;
	int idx = 0;

	for (int i = 0; i < n; i++) {
		for (int j = idx; j < n; j++) {
			if (*(A+i*n+j) == 1) {
				++idx;
				maxRow = i;
			}
			else
				break;
		}
	}

	return maxRow;
}