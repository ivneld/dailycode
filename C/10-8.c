#include <stdio.h>
#include <string.h>

int main() {
	char str1[101], str2[101];
	scanf("%s", str1);
	scanf("%s", str2);

	if (strcmp(str1, str2) == -1)
		puts(strcat(str2, str1));
	else
		puts(strcat(str1,str2));
	return 0;
}