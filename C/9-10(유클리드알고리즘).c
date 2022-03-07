#include <stdio.h>

void gcdlcm();

void main() {
	int x, y;
	scanf("%d %d", &x, &y);
	int gcd = 0, lcm = 0;	//최대공약수, 최소공배수 초기화

	gcdlcm(x, y, &gcd, &lcm);
	printf("%d %d", gcd, lcm);
}

void gcdlcm(int x, int y, int* gcd, int* lcm) {
	int a, b;
	if (x > y) {
		a = x;
		b = y;
	}
	else {
		a = y;
		b = x;
	}//x, y 중 큰 값을 a에 작은 값을 b에 세팅

	int G;	
	int L = a * b;
	//G : 최대공약수, L : 최소공배수
	while (a % b != 0) {
		int tmp = a % b;
		a = b;
		b = tmp;
	}//a 와 b의 최대공약수는 b와 a%b의 최대공약수와 같다.
	//a와 b의 값을 반복분으로 바꿔주다가 a%b==0이 되면 그때의 b 값이 최대공약수
	G = b;
	L /= G;
	//최소공배수는 처음 두 수의 곱에서 G를 나눠준 값임
	*gcd = G;
	*lcm = L;
	//포인터에 값 전달
}