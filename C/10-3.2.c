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
		if (str1[i] == str2[0]) {	//ù ���ڰ� ������ Ȯ��
			if (strncmp(&str1[i], str2, len2) == 0
				&& (i == 0 || str1[i - 1] == '.' || str1[i - 1] == ' ') &&
				(str1[i + len2] == 0 || str1[i + len2] == ' ' || str1[i + len2] == '.'))
				//�� ���� ������ ��� �����ϸ� ������ �߰���
				//���ڿ��� ���ƾ� �ϰ�, ������ �ܾ����� ���ڿ��� ��, �ڸ� Ȯ����
			{
				++cnt;
				i += len2;
			}	//Ȯ���� ���ڿ� �ڷ� ������ �̵�
		}
	}
	printf("%d", cnt);
	return 0;
}