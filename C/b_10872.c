#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//팩토리얼 연산을 재귀로 구현

int factorial();

int main() {
	int x;
	scanf("%d", &x);
	printf("%d", factorial(x));
	return 0;
}

int factorial(int x) {
	if (x > 1)
		return x * factorial(x - 1);
	else return 1;
}