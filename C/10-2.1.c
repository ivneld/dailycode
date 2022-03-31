#include <stdio.h>
#include <string.h>

int main() {
	char str[100] = { 0 };
	scanf("%s", str);
	int len = strlen(str);

	for (int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++) {
			if (strcmp(&str[i], &str[j]) > 0) {
				char tmp = str[i];
				str[i] = str[j];
				str[j] = tmp;
			}
		}
	}
	puts(str);

	return 0;
}