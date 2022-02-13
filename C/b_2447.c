#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

char arr[2500][2500];

//RemoveStar -> cnt�� 1���� ���� 
//arr[cnt][cnt]�� ���������� cnt*cnt��ŭ ����
// j�� ������ cnt*3�� ����
//cnt�� 3�� ���Ͽ� ��ͷ� �ѱ�

void AllStar(int n);
void removeStar(int x, int y, int cnt);
void Pivot(int n, int cnt);

int main() {
	int n;
	scanf("%d", &n);
	AllStar(n);
	Pivot(n, 1);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%c", arr[i][j]);
		printf("\n");
	}
	return 0;
}
void AllStar(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			arr[i][j] = '*';
	}
}
//cnt�� 1���� ����
void removeStar(int x, int y, int cnt) {
	for (int i = x; i < x + cnt; i++) {
		for (int j = y; j < y + cnt; j++)
			arr[i][j] = ' ';
	}
}

void Pivot(int n, int cnt) {
	if (cnt < n) {
		int size = cnt * 3;
		for (int i = cnt; i < n; i += size) {
			for (int j = cnt; j < n; j += size) {
				removeStar(i, j, cnt);
			}
		}

		Pivot(n, cnt * 3);
	}
}
