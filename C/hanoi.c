#include <stdio.h>

void hanoi();
void rHanoi();

int main() {
	int N;
	scanf("%d", &N);
	hanoi(N);

	return 0;
}

void hanoi(int n) {
	rHanoi(n, 'A', 'B', 'C');
	return;
}

void rHanoi(int n, char from, char aux, char to) {
	if (n == 1) {
		printf("move from %c to %c\n", from, to);
		return;
	}
	else {
		rHanoi(n - 1, from, to, aux);
		printf("move from %c to %c\n", from, to);
		rHanoi(n - 1, aux, from, to);
		return;
	}
}