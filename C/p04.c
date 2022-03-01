#include <stdio.h>
#include <string.h>

int main() {
	char strArr[100]={""};
	scanf("%s", &strArr);
	int len = strlen(strArr);	

	for (int i = 0; i < len; i++) {
		printf("%s\n", strArr);
		char tmp = strArr[0];

		for (int i = 0; i < len; i++)
			strArr[i] = strArr[i + 1];
		strArr[len - 1] = tmp;
	}
	
	return 0;
}