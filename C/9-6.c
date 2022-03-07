#include <stdio.h>

void main() {

	char ch[10];

	int max = 0;	//높은 빈도수 저장
	char idx;		//높은 빈도수를 가진 원소
	char* p,*q;		//배열 접근 포인터

	for (p = ch; p < ch + 10; p++)
		scanf("%c", p);
	//ch입력받음

	for (p = ch; p < ch + 10; p++) {
		int frequency = 0;
		
		for (q = ch; q < ch + 10; q++) {
			if (*p == *q) ++frequency;
		}//빈도수 세기

		if (frequency > max) {
			max = frequency;
			idx = *p;
		}//더 높은 빈도수의 빈도수와 그떄의 원소값 저장
	}

	printf("%c %d", idx, max);
}