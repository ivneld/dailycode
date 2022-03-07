#include <stdio.h>

void swap();

void main() {
	int N;
	int arr[50];
	int x, y;		
	scanf("%d", &N);

	for (int* p = arr; p < arr + N; p++)
		scanf("%d", p);
	//arr입력받기

	scanf("%d %d", &x, &y);
	//바꿀 인덱스

	swap(arr + x, arr + y);
	//arr[x], arr[y] 전달

	for (int* p = arr; p < arr + N; p++)
		printf(" %d", *p);//출력
}

void swap(int *x,int *y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}//x,y 가 가리키는 값 서로 변경