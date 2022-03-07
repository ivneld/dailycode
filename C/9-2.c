#include <stdio.h>
#include <string.h>

void main() {

	char ch[20];
	scanf("%s", ch);

	int idx;
	for (int i = 0; i < strlen(ch); i++) {
		if (*(ch+i) == '#') {
			idx = i;
			break;
		}
	}

	for (int i = idx - 1; i >= 0; i--)
		printf("%c", *(ch+i));
}