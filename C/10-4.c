#include <stdio.h>

int strLen();
int strCmp();

int main() {
	char ch1[100]={" "}, ch2[100] = {" "};
	gets(ch1);
	gets(ch2);

	int len1 = strLen(ch1);
	int len2 = strLen(ch2);
	int com = strCmp(ch1, ch2, len1);
	printf("%d %d", len1, com);
	return 0;
}

int strLen(int* ch) {
	int len = 0;

	for (char* p = ch; *p != '\0'; p++)
		++len;

	return len;
}

int strCmp(char* ch1,char* ch2,int len) {
	for (int i = 0; i < len; i++) {
		if (ch1[i] != ch2[i])
			return 0;
	}
	return 1;
}