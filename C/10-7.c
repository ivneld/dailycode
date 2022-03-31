#include <stdio.h>

void numToEng();

int main() {
	int N;
	scanf("%d", &N);

	int i=1;
	while (i <= N) {
		i *= 10;
	}
	i /= 10;

	for (int j = i; j >= 1; j /= 10) {
		numToEng(N / j % 10, j);
	}
	return 0;
}

void numToEng(int num, int digit) {
	char* N;
	char* D;

	if (num == 1)
		N = "one ";
	if (num == 2)
		N = "two ";
	if (num == 3)
		N = "three ";
	if (num == 4)
		N = "four ";
	if (num == 5)
		N = "five ";
	if (num == 6)
		N = "six ";
	if (num == 7)
		N = "seven ";
	if (num == 8)
		N = "eight ";
	if (num == 9)
		N = "nine ";
	if (num == 0)
		N = "";

	
	if (digit == 1000)
		D = "THO ";
	if (digit == 100)
		D = "HUN ";
	if (digit == 10)
		D = "TEN ";
	if (digit == 1 || num == 0)
		D = "";
	printf("%s%s", N, D);
}