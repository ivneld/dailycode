#include <stdio.h>

void main() {

	char ch[10];

	int max = 0;	//���� �󵵼� ����
	char idx;		//���� �󵵼��� ���� ����
	char* p,*q;		//�迭 ���� ������

	for (p = ch; p < ch + 10; p++)
		scanf("%c", p);
	//ch�Է¹���

	for (p = ch; p < ch + 10; p++) {
		int frequency = 0;
		
		for (q = ch; q < ch + 10; q++) {
			if (*p == *q) ++frequency;
		}//�󵵼� ����

		if (frequency > max) {
			max = frequency;
			idx = *p;
		}//�� ���� �󵵼��� �󵵼��� �׋��� ���Ұ� ����
	}

	printf("%c %d", idx, max);
}