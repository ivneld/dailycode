#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int countOnesButSlow(int** A, int n);
int countOnes(int** A, int n);
//배열을 0 으로 초기화하는 함수
void resetArr(int** A, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			A[i][j] = 0;
	}
}
//배열을 문제의 조건에 따라 1로 채우는 함수
//또한, kTotal값을 변경해주는 함수
void makeArr(int** A, int n,int* kTotal) {
	int* k = (int*)malloc(sizeof(int) * n);
	resetArr(A, n);

	k[0] = rand() % ((int)(0.1 * n) + 1) + (0.9 * n);
	for (int i = 0; i < k[0]; i++)
		A[0][i] = 1;

	for (int i = 1; i < n; i++) {
		k[i] = rand() % ((int)(0.1 * k[i - 1]) + 1) + (0.9 * k[i - 1]);
		for (int j = 0; j < k[i]; j++)
			A[i][j] = 1;
	}
	
	for (int i = 0; i < n; i++) *kTotal += k[i];
}

int main() {
	int kTotal = 0;		
	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;

	for (int N = 3000; N >= 1000; N -= 1000) {
		int** A = (int**)malloc(sizeof(int*) * N);

		for (int i = 0; i < N; i++)
			A[i] = (int*)malloc(sizeof(int) * N);
		//N의 값에 따라 배열A 동적 할당
		makeArr(A, N, &kTotal);
		//배열에 값을 채움
		QueryPerformanceFrequency(&ticksPerSec);
		QueryPerformanceCounter(&start);
		int ones = countOnes(A, N);
		QueryPerformanceCounter(&end);
		//빠른버전일 경우의 속도
		diff.QuadPart = end.QuadPart - start.QuadPart;
		double cputime = (double)diff.QuadPart / (double)ticksPerSec.QuadPart;
		printf("%d, %d ,%lf\n", kTotal, ones, cputime);

		for (int i = 0; i < N; i++)
			free(A[i]);
		free(A);
		//할당한 메모리 반환
		kTotal = 0;
		//kTotal 초기화
	}

	for (int N = 3000; N >= 1000; N -= 1000) {
		int** A = (int**)malloc(sizeof(int*) * N);

		for (int i = 0; i < N; i++)
			A[i] = (int*)malloc(sizeof(int) * N);

		makeArr(A, N, &kTotal);

		QueryPerformanceFrequency(&ticksPerSec);
		QueryPerformanceCounter(&start);
		int ones = countOnesButSlow(A, N);
		QueryPerformanceCounter(&end);
		//느린버전일 경우의 속도
		diff.QuadPart = end.QuadPart - start.QuadPart;
		double cputime = (double)diff.QuadPart / (double)ticksPerSec.QuadPart;
		printf("%d, %d ,%lf\n", kTotal, ones, cputime);

		for (int i = 0; i < N; i++)
			free(A[i]);
		free(A);
		kTotal = 0;
	}


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
	int idx = n - 1;

	for (int i = 0; i < n; i++) {
		int j;
		for (j = idx; j >= 0 && A[i][j] == 0; j--) {
			--idx;
		}

		cnt += j + 1;
	}
	return cnt;
}

