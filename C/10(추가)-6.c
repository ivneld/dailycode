#include <stdio.h>
#include <string.h>
#include <ctype.h>
//�빮�� �ҹ��� ��ȯ ���̺귯��
int front();
int back();

int main() {
	char str[101] = { 0 };
	scanf("%s", str);
	int len = strlen(str);

	for (int i = 0; i < len-1; i++) {
		if (front(str, i) && back(str, i))
			str[i]=toupper(str[i]);
	}

	puts(str);
	return 0;
}
//abcdabdacd
int front(char* str, int idx) {
	char now = *(str + idx);
	for (char* p = str; p < str + idx; p++) {
		if (*p == now)
			return 1;
	}
	return 0;
}

int back(char* str, int idx) {
	char now = *(str + idx);
	for (char* p = str + idx + 1; *p != 0; p++) {
		if (*p == now)
			return 1;
	}
	return 0;
}