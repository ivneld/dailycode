#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int countOnesButSlow(int** A, int n);
int countOnes(int** A, int n);
//�迭�� 0 ���� �ʱ�ȭ�ϴ� �Լ�
void resetArr(int** A, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			A[i][j] = 0;
	}
}
//�迭�� ������ ���ǿ� ���� 1�� ä��� �Լ�
//����, kTotal���� �������ִ� �Լ�
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
		//N�� ���� ���� �迭A ���� �Ҵ�
		makeArr(A, N, &kTotal);
		//�迭�� ���� ä��
		QueryPerformanceFrequency(&ticksPerSec);
		QueryPerformanceCounter(&start);
		int ones = countOnes(A, N);
		QueryPerformanceCounter(&end);
		//���������� ����� �ӵ�
		diff.QuadPart = end.QuadPart - start.QuadPart;
		double cputime = (double)diff.QuadPart / (double)ticksPerSec.QuadPart;
		printf("%d, %d ,%lf\n", kTotal, ones, cputime);

		for (int i = 0; i < N; i++)
			free(A[i]);
		free(A);
		//�Ҵ��� �޸� ��ȯ
		kTotal = 0;
		//kTotal �ʱ�ȭ
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
		//���������� ����� �ӵ�
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

//A����� �ึ�� ���� 0 �� �ƴҶ� ���� 1�� ������ ����ؼ� cnt�� ����
//����� ��� ���� 1�϶� �־��� �����.
//O(n^2)�� ����ð�
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

//A����� ���� �޿����� Ž���Ͽ� 1�� ���� ���� ���� ã�� idx��
// 1�� ����ִ� ������ �� �ε��� ����
// ���� ����� idx�� ����� ���� ���� ������ idx�� �ٿ����� ���� Ž��
// 1�� �߰ߵǸ� cnt�� 1�� ���� ����
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

