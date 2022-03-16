#include <stdio.h>

int strLen();
void pushStr();
void strCat();

int main() {
	char ch1[40] = { " " }, ch2[20] = { " " };
	int idx;
	scanf("%s", ch1);
	scanf("%s", ch2);
	scanf("%d", &idx);
	int len1 = strLen(ch1);
	int len2 = strLen(ch2);

	for (int i = 0; i < len2; i++) {
		pushStr(ch1, idx + i, len1 + i);
	}
	strCat(ch1, ch2, idx, len2);
	printf("%s", ch1);
	return 0;
}

int strLen(int* ch) {
	int len = 0;

	for (char* p = ch; *p != '\0'; p++)
		++len;

	return len;
}

void pushStr(char* ch,int idx, int len) {
	for (int i = len - 1; i >= idx; i--) {
		ch[i + 1] = ch[i];
	}
	//배열 ch를 idx위치부터 마지막 인덱스까지 한칸 뒤로 민다.
}

void strCat(char* ch1, char* ch2,int idx,int len2) {
	char* p = ch2;
	for (int i = 0; i < len2; i++) {
		*(ch1 + idx) = *p;
		++p;
		++idx;
	}
}