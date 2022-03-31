#include <stdio.h>
#include <string.h>

int findStr(char* str,char ch,int N);

int main() {
	char str[101];
	char ch;
	scanf("%s", str);
	getchar();
	scanf("%c", &ch);
	int N = strlen(str);

	int cnt = findStr(str, ch, N);
	printf("%d", cnt);
	return 0;
}
// hello l
int findStr(char* str, char ch, int N) {
	if (N == 1) {
		if (str[0] == ch)
			return 1;
		else
			return 0;
	}
	else {
		if (str[N - 1] == ch)
			return 1 + findStr(str, ch, N - 1);
		else
			return findStr(str, ch, N - 1);
	}
}