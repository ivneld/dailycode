#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int N;
	scanf("%d", &N);

	int five = N / 5;
	int three = 0;
	//five �ִ� �������� �����ؼ� 0���� �Ǿ��� �� three�� �Ϻ��� ���� ���ϸ� -1
	int min = 0;
	while (five > 0) {
		int tmp = N - (five * 5);
		if (tmp % 3 == 0) {
			three = tmp / 3;
			min = three + five;
			break;
		}
		--five;
	}

	if (five == 0) {
		if (N % 3 == 0) {
			min = N / 3;
		}
		else
			min = -1;
	}
	printf("%d", min);
	return 0;
}