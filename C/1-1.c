#include <stdio.h>
#include <stdlib.h>
//1 1 1 1 1 1 1 1
//1 1 1 1 1 1 0 0
//1 1 1 1 1 1 0 0
//1 1 1 1 1 0 0 0
//1 1 1 1 1 0 0 0
//1 1 1 1 1 0 0 0
//1 1 0 0 0 0 0 0
//0 0 0 0 0 0 0 0
int countOnesButSlow(int** A, int n);
int countOnes(int** A, int n);

int main() {
	int N;
	scanf("%d", &N);
	int **A = (int**)malloc(sizeof(int*) * N);
	for (int i = 0; i < N; i++)
		A[i] = (int*)malloc(sizeof(int) * N);
	//2차원 배열 A 동적 할당

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			scanf("%d", &A[i][j]);
	}
	//동적할당 받은 배열A에 비트행렬을 입력받음

	int cnt1 = countOnesButSlow(A, N);
	int cnt2 = countOnes(A, N);

	printf("%d\n", cnt1);
	printf("%d", cnt2);

	for (int i = 0; i < N; i++)
		free(A[i]);
	free(A);
	return 0;
}

//A행렬을 행마다 값이 0 이 아닐때 까지 1의 개수를 계산해서 cnt에 저장
//행렬의 모든 값이 1일때 최악의 경우임.
//O(n^2)의 실행시간
int countOnesButSlow(int** A, int n) {
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		int j = 0;
		while (j < n && A[i][j] == 1) {
			++cnt;
			++j;
		}
	}
	return cnt;
}

//A행렬을 가장 뒷열부터 탐색하여 1이 가장 많은 행을 찾고 idx에
// 1이 들어있는 마지막 열 인덱스 저장
// 다음 행부터 idx에 저장된 길이 보다 작으면 idx를 줄여가며 길이 탐색
// 1이 발견되면 cnt에 1의 개수 저장
int countOnes(int** A, int n) {
	int cnt = 0;
	int idx=n-1;

	for (int i = 0; i < n; i++) {
		int j;
		for (j = idx; j>=0&&A[i][j] == 0; j--) {
			--idx;
		}
		
		cnt += j + 1;
	}
	return cnt;
}