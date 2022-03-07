#include <stdio.h>

void main() {
	int arr[5];
	int rank[5];

	int* p, * q;
	int* r = rank;	//r은 rank에 접근하는 포인터
	
	for (p = arr; p < arr + 5; p++)
		scanf("%d", p);
	//arr입력받기

	for (p = arr; p < arr + 5; p++) {
		int tmp = 1;
		//arr의 원소 순서대로 rank를 저장하기 위한 값
		for (q = arr; q < arr + 5; q++) {
			if (*q > *p) ++tmp;
		}	//arr원소를 반복하며 돌면서 각 원소의 rank를 구함
		*r = tmp;	
		++r;		//rank값을 rank배열에 저장
	}

	p = arr;
	q = rank;		//p는 arr에 q는 rank에 접근하는 포인터
	while (p < arr + 5) {
		printf("%d=r%d ", *p, *q);
		++p;
		++q;
	}		//arr배열과 rank배열의 값을 각각 출력
}