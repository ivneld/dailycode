#include <stdio.h>

int main() {
	char ch[9] = { "" };
	int number;
	char* p = ch;
	scanf("%d", &number);

	for (int i = 1; i <= number; i *= 10) {
		*p = number / i % 10 + '0';
		p++;
	}

	printf("%s", ch);
	return 0;
}