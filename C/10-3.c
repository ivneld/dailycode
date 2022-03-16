#include <stdio.h>

void pushStr();

int main() {
	int size = 0;
	char ch[100] = { " " };
	scanf("%s", ch);

	for (char* p = ch; *p != '\0'; p++)
		++size;
	
	puts(ch);
	for (int i = 0; i < size - 1; i++) {
		pushStr(ch, size);
		printf("%s\n", ch);
	}
	return 0;
}

void pushStr(char* ch,int size) {
	char tmp = *ch;

	for (int i = 1; i < size; i++) {
		ch[i - 1] = ch[i];
	}
	ch[size - 1] = tmp;
}