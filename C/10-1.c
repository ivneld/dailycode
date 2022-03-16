#include <stdio.h>

int main() {
	char ch[20] = { " " };
	
	gets(ch);

	for (int i = 0; i < 20; i++) {
		if (ch[i] >= 'a' && ch[i] <= 'z')
			printf("%c", ch[i]);
	}

	return 0;
}