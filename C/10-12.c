#include <stdio.h>
#include <string.h>

int count();

int main() {
	char str1[101];
	char str2[101];

	gets(str1);
	scanf("%s", str2);
	int cnt = count(str1, str2);
	printf("%d", cnt);
	return 0;
}
//i 
//0 1 2 4
int count(char* str1, char* str2) {
	int cnt = 0;
	int i=0;
	int len1 = strlen(str1);
	int len2 = strlen(str2);

	for (; i < len1; i++) {
		int j = 0;
		if (str1[i] == str2[0]) {
			for (j = 0; j < len2; j++) {
				if (str1[i + j] != str2[j]) break;
			}
		}
		if (j == len2) {
			++cnt;
			i += len2;
			i--;
		}
		
	}
	return cnt;
}