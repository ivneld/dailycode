#include <stdio.h>

int modulo();

void main() {
	int a, b;
	scanf("%d %d", &a, &b);

	printf("%d", modulo(a, b));
}

int modulo(int a,int b) {
	int tmp=b;

	while (tmp<=a) {
		tmp += b;
	}
	tmp -= b;
	//b의 배수 중 a보다 작은 최대 배수를 구함

	if (a - tmp >= 0) {
		return a - tmp;
	}//a - 최대 배수 한 값 반환
	else {
		return a;
	}//만약 b의 값이 더 크다면 a를 그대로 반환
}