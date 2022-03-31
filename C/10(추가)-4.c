#include <stdio.h>
#include <string.h>

int main() {
	char tmp[101] = { 0 };
	char str[10][101] = { 0 };

	gets(tmp);

	int len = strlen(tmp);
	int idx = 0;
	int cnt = 0;
	char* p = tmp;
	for (int i = 0; i <= len; i++) {
		if (tmp[i] == ' ' || tmp[i] == '\0') {
			strncpy(str[idx++], p, cnt);
			cnt = 0;
			p = &tmp[i + 1];
		}
		else
			++cnt;
	}

	for (int i = 0; i < idx; i++) {
		for (int j = i + 1; j < idx; j++) {
			if (strlen(str[j]) == strlen(str[i])) {
				if (strcmp(str[i], str[j]) > 0) {
					char temp[101];
					strcpy(temp, str[i]);
					strcpy(str[i], str[j]);
					strcpy(str[j], temp);
				}
			}
			
			if (strlen(str[j]) > strlen(str[i])) {
				char temp[101];
				strcpy(temp, str[j]);
				strcpy(str[j], str[i]);
				strcpy(str[i], temp);
			}
		}
	}


	for (int i = 0; i < idx; i++)
		printf("%s\n", str[i]);
	return 0;
}