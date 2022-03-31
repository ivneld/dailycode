#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//ch�� � �������� �Ǻ��ϴ� �Լ�
int isalnum(char ch) {
	if (ch >= 'a' && ch <= 'z') return 2;
	else if (ch >= 'A' && ch <= 'Z') return 1;
	else if (ch >= '0' && ch <= '9') return 0;
	else return -1;
}	

void changeStr();
int canChange();

int main() {
	char str1[40] = { 0 };
	char str2[40] = { 0 };

	gets(str1);
	gets(str2);	//str2�� ���鹮�ڰ� ���� �� �ֱ� ������ gets

	int chk = canChange(str1, str2);
	printf("%d", chk);
	return 0;
}
//���ڿ��� N�� �������� ��������ִ� �Լ�
void changeStr(char* str,int N) {
	char changeStr[40] = { 0 };

	int idx = 0;
	for (char* p = str; *p != 0; p++) {
		if (isalnum(*p) == 2) {
			changeStr[idx++] = *p - N;
		}//*p�� ���� �ҹ��ڸ� N��ŭ ������ �̵�
		else if (isalnum(*p) == 1) {
			changeStr[idx++] = *p + N;
		}//*p�� ���� �빮�ڸ� N��ŭ �ڷ� �̵�
		else if (isalnum(*p) == 0) {
			for (int i = 0; i < N; i++)
				changeStr[idx++] = 'A' + atoi(p) - 1;
			if (atoi(p) > 9)
				p++;	//*p�� ���� �����̸� �ش� ���ڰ� ����Ű�� �빮�� ����
		}				//���� *p�� ���� 10 �̻��̸� ������ ��ĭ �̵�
		else if(isalnum(*p)==-1)
			changeStr[idx++] = ' ';
	}	//�� �̿��� ������ ��� ���� ����
	strcpy(str, changeStr);	//�ӽ� ���ڿ��� ���� �迭�� �̵�
}
//���ڿ����� ���氡������ Ȯ���ϴ� �Լ�
int canChange(char* str1, char* str2) {
	int chk = 0;

	char str1Original[40],str2Original[40];
	strcpy(str1Original, str1);
	strcpy(str2Original, str2);		//changeStr�Լ��� ȣ���ϱ� ���� ���ڿ�

	for (int N = 1; N < 11; N++) {	//A -> B
		changeStr(str1, N);
		if (strcmp(str1, str2) == 0)
			chk = 1;
		strcpy(str1, str1Original);
	}
	for (int N = 1; N < 11; N++) {	//B -> A
		changeStr(str2, N);
		if (strcmp(str1, str2) == 0)
			chk = 2;
		strcpy(str2, str2Original);
	}
	return chk;
}