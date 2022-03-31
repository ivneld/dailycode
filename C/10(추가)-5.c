#include <stdio.h>
#include <string.h>

int vowel(char ch) {
	if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
		return 1;
	if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
		return 1;
	return 0;
}

int main() {
	char str1[101] = { 0 };
	char str2[101] = { 0 };

	scanf("%s", str1);
	scanf("%s", str2);

	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int p = 0, q = 0;
	
	while (p != len1 || q != len2) {
		for (int i = p; i < len1; i++) {
			printf("%c", str1[i]);
			++p;
			
			if (vowel(str1[i])) {
				break;
			}	
		}
		//p = 7, q = 6, 
		for (int i = q; i < len2; i++) {
			printf("%c", str2[i]);
			++q;
			
			if (vowel(str2[i])) {
				break;
			}
		}
	}
	return 0;
}

