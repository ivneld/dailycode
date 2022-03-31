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
	//2���� �迭 A ���� �Ҵ�

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			scanf("%d", &A[i][j]);
	}
	//�����Ҵ� ���� �迭A�� ��Ʈ����� �Է¹���

	int cnt1 = countOnesButSlow(A, N);
	int cnt2 = countOnes(A, N);

	printf("%d\n", cnt1);
	printf("%d", cnt2);

	for (int i = 0; i < N; i++)
		free(A[i]);
	free(A);
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