#include <stdio.h>
#include <string.h>

int main() {
	char str[10][100] = { 0 };
	char tmp[1000] = { 0 };

	gets(tmp);

	char* p = tmp;	//������ ���ڿ��� ù �ε���	
	int len = 0;	//�и��� ���ڿ��� ����
	int idx = 0;	//str�� ���� ��Ÿ���� ����
	for (int i = 0; i <= strlen(tmp); i++) {
		if (tmp[i] == ' ' || tmp[i] == 0) {
			strncpy(str[idx++], p, len);
			p = &tmp[i + 1];
			len = 0;	
		}	//tmp[i]�� ���鹮�� �̰ų� ���ڿ��� ���� ��Ÿ����
			//str�� �� �࿡ �и��� ���ڿ� ����
		else
			++len;
	}		//���ڿ��� ���� ����

	for (int i = 0; i < idx; i++)
		puts(str[i]);

	char front[100];	//�������� ���� ���� �ܾ� �����ϴ� �迭
	strcpy(front, str);	//�ʱ� ��
	for (int i = 1; i < idx; i++) {
		if (strcmp(str[i], front) < 0)
			strcpy(front, str[i]);
	}	//�������� ���� �ܾ��̸� front�� ����
	puts(front);
	return 0;
}
