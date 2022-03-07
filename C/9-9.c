#include <stdio.h>

int* mid();

void main() {
	int x[3];
	
	for (int* p = x; p < x + 3; p++)
		scanf("%d", p);

	printf("%d", *mid(x));
}

int* mid(int* arr) {
	int* min = arr;
	int* max = arr;
	int* idx=NULL;

	for (int* p = arr; p < arr + 3; p++) {
		if (*p < *min) min = p;
		if (*p > *max) max = p;
	}	//�迭�� �ִ밪�� �ּҰ��� �ε����� ����

	for (int* p = arr; p < arr + 3; p++) {
		if (p != min && p != max) idx = p;
	}	//�ִ밪�� �ּҰ��� �ּҰ� �ƴ� �߾Ӱ��� �ּ� ����

	return idx;
}