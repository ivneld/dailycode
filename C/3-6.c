#include <stdio.h>

int gcd();

int main() {
	int x, y;
	scanf("%d %d", &x, &y);
	printf("%d", gcd(x, y));
	return 0;
}

int gcd(int x, int y) {
	if (x % y == 0)
		return y;
	else {
		int tmp = x % y;
		int x = y;
		int y = tmp;
		gcd(x, y);
	}
}