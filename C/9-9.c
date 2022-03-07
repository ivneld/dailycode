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
	}	//배열의 최대값과 최소값의 인덱스를 저장

	for (int* p = arr; p < arr + 3; p++) {
		if (p != min && p != max) idx = p;
	}	//최대값과 최소값의 주소가 아닌 중앙값의 주소 저장

	return idx;
}