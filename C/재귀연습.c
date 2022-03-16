#include <stdio.h>

void rPrintDigits(int n) {
	if (n < 10)
		printf("%d\n",n);
	else {
		rPrintDigits(n / 10);
		printf("%d\n", n % 10);
	}
}

void printDigits() {
	int n;
	printf("Enter a number\n");
	scanf("%d", &n);
	if (n < 0)
		printf("Negative number!\n");
	else
		rPrintDigits(n);
}

int product(int a, int b) {
	if (b == 1)
		return a;
	else
		return a + product(a, b - 1);
}

int module(int a, int b) {
	if (a < b)
		return a;
	else
		return module(a - b, b);
}

int quotient(int a, int b) {
	if (a < b)
		return 0;
	else
		return 1 + quotient(a - b, b);
}

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d %d %d", product(a, b), module(a, b), quotient(a, b));

	return 0;
}