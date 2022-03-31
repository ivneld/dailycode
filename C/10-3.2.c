#include <stdio.h>
#include <string.h>

int main() {	
	char str1[100] = { 0 };
	char str2[100] = { 0 };
	gets(str1);
	gets(str2);

	int len1 = strlen(str1);
	int len2 = strlen(str2);

	int cnt = 0;	
	for (int i = 0; i < len1; i++) {
		if (str1[i] == str2[0]) {	//첫 문자가 같은지 확인
			if (strncmp(&str1[i], str2, len2) == 0
				&& (i == 0 || str1[i - 1] == '.' || str1[i - 1] == ' ') &&
				(str1[i + len2] == 0 || str1[i + len2] == ' ' || str1[i + len2] == '.'))
				//세 가지 조건을 모두 만족하면 개수를 추가함
				//문자열이 같아야 하고, 독립된 단어인지 문자열의 앞, 뒤를 확인함
			{
				++cnt;
				i += len2;
			}	//확인한 문자열 뒤로 포인터 이동
		}
	}
	printf("%d", cnt);
	return 0;
}