#include <stdio.h>

void combine();	//b�迭�� ������ a�迭�� �����ִ� �Լ�
void desc();	//�迭�� ������ �������� �����ִ� �Լ�

void main() {
	int a[20]={0}, b[11]={0};	
	int n = 0, m = 0;

	for (int* p = a; p <= a + 10; p++) {
		scanf("%d", p);
		if (*p == 0) break;
		++n;	//0�� �ԷµǱ� ������ a�迭�� ������ �Է¹ް� ũ�⸦ n�� ����
	}
	for (int* p = b; p <= b + 10; p++) {
		scanf("%d", p);
		if (*p == 0) break;
		++m;	//0�� �ԷµǱ� ������ b�迭�� ������ �Է¹ް� ũ�⸦ m�� ����
	}
	combine(a, b, n, m);
	//b�� ���Ұ����� a�迭 ���Ұ��� �ڿ� ��ħ
	desc(a, n + m);	//a�迭�� ��������

	for (int* p = a; p < a + n; p++) printf("%d ", *p);
	printf("\n");
	for (int* p = a + n + m - 1; p >= a + n; p--) printf("%d ", *p);
	//���������� a�迭�� �տ������� n�� ���
	//���������� a�迭�� �ڿ������� ����ϸ� ����������. m�� ���
}

void combine(int* a, int* b,int n,int m) {
	for (int* p = a + n; p < a + n + m; p++) {
		*p = *b;
		++b;
	}
}

void desc(int* a, int N) {
	int max = *a;

	for (int* p = a; p < a + N; p++) {
		for (int* q = p+1; q < a + N; q++) {
			if (*q > *p) {
				int tmp = *p;
				*p = *q;
				*q = tmp;
			}
		}
	}
}