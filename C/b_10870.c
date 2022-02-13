#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>>
//피보나치의 수 재귀로 구현
int fibonacci();

int main() {
	int n;
	scanf("%d", &n);
	printf("%d", fibonacci(n));
	
	return 0;
}

int fibonacci(int n) {
	if (n >= 2)
		return fibonacci(n - 1) + fibonacci(n - 2);
	else
		return n;
}