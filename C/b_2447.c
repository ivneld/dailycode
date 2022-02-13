#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

char arr[2500][2500];

//RemoveStar -> cnt는 1부터 시작 
//arr[cnt][cnt]를 시작점으로 cnt*cnt만큼 제거
// j의 간격은 cnt*3을 더함
//cnt에 3을 곱하여 재귀로 넘김

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
//cnt는 1부터 시작
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
