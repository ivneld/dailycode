#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>>
//�Ǻ���ġ�� �� ��ͷ� ����
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