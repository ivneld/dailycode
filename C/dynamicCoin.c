#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int N;
	scanf("%d", &N);

	int five = N / 5;
	int three = 0;
	//five 최대 개수부터 시작해서 0개가 되었을 때 three로 완벽히 지불 못하면 -1
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