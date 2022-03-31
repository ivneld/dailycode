#include <stdio.h>
#include <string.h>

int check();

int main() {
	char ch[31];
	scanf("%s", ch);
	int chk = check(ch);

	printf("%d %d", strlen(ch), chk);
	return 0;
}

int check(char* ch) {
	int len = strlen(ch);
	
	for (int i = 0; i < (len - 1) / 2; i++) {
		if (ch[i] != ch[len - 1 - i]) {
			return 0;
		}
	}
	return 1;
}


