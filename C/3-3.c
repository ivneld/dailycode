#include <stdio.h>
//3048�� 1���� ���� �� %10 ���
//3048�� 10���� ���� �� %10 ���
//3048�� 100���� ���� �� %10 ���
//3048�� 1000���� ���� �� %10 ���
//10000�� 3048���� ũ�Ƿ� ����
void print(int N,int digit) {
	if (digit == 1) {
		printf("%d\n", N / digit % 10);
		return;
	}
	print(N, digit / 10);
	printf("%d\n", N / digit % 10);
}
//digit�� 1000���� ����
int main() {
	int N;
	scanf("%d", &N);
	int i;

	for (i = 1; i <= N; i *= 10);
	i /= 10;

	print(N, i);

	return 0;
}