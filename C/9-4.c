#include <stdio.h>

void main() {
	int arr[3] = { 0 };
	int* p,*q;
	
	for (p = arr; p < arr + 3; p++)
		scanf("%d", p);

	for (p = arr; p < arr + 3; p++) {
		for (q = p + 1; q < arr + 3; q++) {
			if (*p < *q) {
				int tmp = *p;
				*p = *q;
				*q = tmp;
			}
		}
	}		//p, q �����Ͱ��� �̿��� ��������

	printf("%d", *(arr+1));	//arr �߾Ӱ� ���
}