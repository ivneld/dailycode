#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ch�� �ҹ��ڸ� 2 ��ȯ, �빮�ڸ� 1 ��ȯ, ���ڸ� 0�� ��ȯ, �� �̿��� ���� �� -1�� ��ȯ�ϴ� �Լ�
int isalnum(char ch) {
	if (ch >= 'a' && ch <= 'z') return 2;
	else if (ch >= 'A' && ch <= 'Z') return 1;
	else if (ch >= '0' && ch <= '9') return 0;
	else return -1;	
}

int main() {
	char A[21] = { 0 };
	char changeA[50]={0};	//�迭A�� �ű� �ӽ� �迭
	int N;

	scanf("%s %d", A, &N);
	int len = strlen(A);

	int idx = 0;
	for (int i = 0; i < len; i++) {
		if (isalnum(A[i])==1) {
			changeA[idx++] = A[i] + N;	//���� �ε����� ���� �빮�ڸ� N��ŭ �ƽ�Ű �ڵ尪 �̵�
		}
		else if (isalnum(A[i]) == 2) {
			changeA[idx++] = A[i] - N;	//�ҹ����� ���
		}
		else if (isalnum(A[i])==0) {
			for (int j = 0; j < N; j++)
				changeA[idx++] = 'A' + atoi(&A[i]) -1;	//���� �ڸ� ������ ���

			if (atoi(&A[i]) > 9)		//10 �̻��� ���� ���
				i++;
		}
		if (isalnum(A[i]) ==-1) {
			
			changeA[idx++] = ' ';	//������, ���ڰ� �ƴ� ��� ������ ����
		}
	}
	strcpy(A, changeA);		//�ӽ� �迭�� ���� A�� �̵�
	puts(A);	//A���
	return 0;
}
