#include <stdio.h>

void main() {
	int arr[5];
	int rank[5];

	int* p, * q;
	int* r = rank;	//r�� rank�� �����ϴ� ������
	
	for (p = arr; p < arr + 5; p++)
		scanf("%d", p);
	//arr�Է¹ޱ�

	for (p = arr; p < arr + 5; p++) {
		int tmp = 1;
		//arr�� ���� ������� rank�� �����ϱ� ���� ��
		for (q = arr; q < arr + 5; q++) {
			if (*q > *p) ++tmp;
		}	//arr���Ҹ� �ݺ��ϸ� ���鼭 �� ������ rank�� ����
		*r = tmp;	
		++r;		//rank���� rank�迭�� ����
	}

	p = arr;
	q = rank;		//p�� arr�� q�� rank�� �����ϴ� ������
	while (p < arr + 5) {
		printf("%d=r%d ", *p, *q);
		++p;
		++q;
	}		//arr�迭�� rank�迭�� ���� ���� ���
}