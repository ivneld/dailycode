#include <stdio.h>

void swap();

void main() {
	int N;
	int arr[50];
	int x, y;		
	scanf("%d", &N);

	for (int* p = arr; p < arr + N; p++)
		scanf("%d", p);
	//arr�Է¹ޱ�

	scanf("%d %d", &x, &y);
	//�ٲ� �ε���

	swap(arr + x, arr + y);
	//arr[x], arr[y] ����

	for (int* p = arr; p < arr + N; p++)
		printf(" %d", *p);//���
}

void swap(int *x,int *y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}//x,y �� ����Ű�� �� ���� ����