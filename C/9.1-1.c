#include <stdio.h>

int* MAX();
int* MIN();

void main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int ar[100] = { 0 };	
		int* p = ar;
		//�迭 �ʱ�ȭ, ar�迭�� �����ϴ� ������ p ����
		while (1) {
			scanf("%d", p);
			if (*p == 0) break;
			else ++p;
		}
		//p�� �̿��Ͽ� ar�迭�� ���� �Է¹���
		//��� �Է¹��� ���� 0�� ��� �迭�� �������̹Ƿ� �ݺ����� ����
		//�׷��� �������, ar�� ���� �ε��� ���Ҹ� �Է¹���

		int max = *MAX(ar);
		int min = *MIN(ar);
		printf("%d %d\n", max, min);
		//�ִ밪�� �ּҰ� ���� ���
		}
	}


int* MAX(int* ar) {
	int* idx = ar;
	//ar�迭�� ù��° ���Ҹ� �ִ밪 �ε����� ����
	for (int* p = ar; *p != 0; p++) {
		if (*p > *idx) idx = p;
	}//�迭ar�� ����Ű�� ������p�� �̿��Ͽ� ������ ������ 0 �� ������
	//������ �ִ밪�� Ž�� �� �ִ밪�� �ε����� ����
	return idx;
}

int* MIN(int* ar) {
	int* idx = ar;
	//ar�迭�� ù��° ���Ҹ� �ּҰ� �ε����� ����
	for (int* p = ar; *p != 0; p++) {
		if (*idx > *p) idx = p;
	}//0�� ������ ������ �ּҰ��� Ž�� �� �ε��� ����
	return idx;
}
