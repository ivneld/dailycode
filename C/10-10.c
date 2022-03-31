#include <stdio.h>
#include <string.h>

int main() {
	int N;
	char ch[101];
	char result[101];

	scanf("%d", &N);
	getchar();

	gets(ch);
	int min = strlen(ch);
	strcpy(result, ch);

	for (int i = 1; i < N; i++) {
		gets(ch);
		if (strlen(ch) < min) {
			strcpy(result, ch);
			min = strlen(ch);
		}
	}
	printf("%s\n", result);
	return 0;
}