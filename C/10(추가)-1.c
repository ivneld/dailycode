#include <stdio.h>
#include <string.h>

void printStr();

int main() {
	int N;
	scanf("%d", &N);
	char str[1010] = { " " };
	char* strP[10];
	//white black and
	char* p = str;
	for (int i = 0; i < N; i++) {
		scanf("%s", p);
		strP[i] = p;
		p += strlen(str);
		++p;
	}
	
	for (int i = 0; i < N; i++) {
		int tmp;
		scanf("%d", &tmp);
		printStr(strP[tmp-1]);
	}
	return 0;
}

void printStr(char* ptr) {
	for (char* p = ptr; *p != '\0'; p++)
		printf("%c", *p);
	printf(" ");
}