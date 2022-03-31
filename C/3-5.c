#include <stdio.h>

void rHanoi(int n, char from, char aux, char to) {

	if (n == 1) {
		printf("%c %c\n", from, to);
		return;
	}
	else {
		rHanoi(n - 1, from, to, aux);
		printf("%c %c\n", from, to);
		rHanoi(n - 1, aux, from, to);
		return;
	}
}

void Hanoi(int N) {
	rHanoi(N, 'A', 'B', 'C');
	return;
}

int main() {
	int N;
	scanf("%d", &N);
	Hanoi(N);
	return 0;
}



// A B C
// 
//   1
//   2 3