#include <stdio.h>

int sum();

int main() {
	int X;
	scanf("%d", &X);
	int output = 0;

	for (int i = 1; i <= X; i++) {
		output += sum(i);
	}
	printf("%d", output);
	return 0;
}

int sum(int n) {
	int result = 0;
	for (int i = 1; i <= n; i++)
		result += i;
	return result;
}