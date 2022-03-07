#include <stdio.h>

void gcdlcm();

void main() {
	int x, y;
	scanf("%d %d", &x, &y);
	int gcd = 0, lcm = 0;	//�ִ�����, �ּҰ���� �ʱ�ȭ

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
	}//x, y �� ū ���� a�� ���� ���� b�� ����

	int G;	
	int L = a * b;
	//G : �ִ�����, L : �ּҰ����
	while (a % b != 0) {
		int tmp = a % b;
		a = b;
		b = tmp;
	}//a �� b�� �ִ������� b�� a%b�� �ִ������� ����.
	//a�� b�� ���� �ݺ������� �ٲ��ִٰ� a%b==0�� �Ǹ� �׶��� b ���� �ִ�����
	G = b;
	L /= G;
	//�ּҰ������ ó�� �� ���� ������ G�� ������ ����
	*gcd = G;
	*lcm = L;
	//�����Ϳ� �� ����
}