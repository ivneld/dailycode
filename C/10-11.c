#include <stdio.h>
#include <string.h>

int check();

int main() {
	char str1[81];
	char str2[11];
	scanf("%s", str1);
	scanf("%s", str2);
	int chk = check(str1, str2);

	printf("%d %d", strlen(str1), chk);

	return 0;
}

int check(char* str1, char* str2) {
	int len1 = strlen(str1);
	int len2 = strlen(str2);

	for (int i = 0; i < len1; i++) {
		int j=0;
		if (str1[i] == str2[0]) {
			for (j = 0; j < len2; j++) {
				//i : 3
				if (str1[i + j] != str2[j]) break;

			}
		}

		if (j == len2) return 1;
	}
	return 0;
}

//str1�� ���ٰ� str2[0]�� ���� ���ڰ�
//�߰ߵǸ� str2�� ���̸�ŭ ��ĭ�� Ȯ���ϰ�
//Ʋ���� break; ���� ������ j = len2-1 �̸� 
//return 1;