#include <stdio.h>
#include <string.h>

int main() {
	char str1[101] = { " "};
	char str2[10][11] = { 0 };
	gets(str1);

	/*strncpy(str2[1], &str1[3],3);
	printf("%s", str2[1]);*/

	int len = strlen(str1);
	char* p = str1;
	int idx = 0;
	int cnt = 0;
	for (int i = 0; i <= len; i++) {
		if (str1[i] == ' ' || str1[i] == 0) {
			strncpy(str2[idx++], p, cnt);
			cnt = 0;
			p = &str1[i + 1];
		}
		else {
			++cnt;	//aa bbb cccc ddddd
		}		//idx 
	}			//cnt

	for (int i = 0; i < idx; i++)
		printf("%s\n", str2[i]);

	return 0;
}


