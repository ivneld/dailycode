#include <stdio.h>
//3048을 1으로 나눈 몫 %10 출력
//3048을 10으로 나눈 몫 %10 출력
//3048을 100으로 나눈 몫 %10 출력
//3048을 1000으로 나눈 목 %10 출력
//10000은 3048보다 크므로 종료
void print(int N,int digit) {
	if (digit == 1) {
		printf("%d\n", N / digit % 10);
		return;
	}
	print(N, digit / 10);
	printf("%d\n", N / digit % 10);
}
//digit은 1000부터 시작
int main() {
	int N;
	scanf("%d", &N);
	int i;

	for (i = 1; i <= N; i *= 10);
	i /= 10;

	print(N, i);

	return 0;
}