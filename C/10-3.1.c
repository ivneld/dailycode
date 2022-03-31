#include <stdio.h>
#include <string.h>

int main() {
	char str1[100] = { 0 };
	char str2[100] = { 0 };
	gets(str1);
	gets(str2);

	int strlen1 = strlen(str1);
	int strlen2 = strlen(str2);

	int cnt = 0;
	for (int i = 0; i < strlen1; i++) {
		if (str1[i]==str2[0]) {
			if (strncmp(&str1[i], str2, strlen2) == 0) {
				++cnt;
				i += strlen2 - 1;
			}
		}
	}
	printf("%d", cnt);
	return 0;
}