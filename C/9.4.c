#include <stdio.h>

void combine();	//b배열의 값들을 a배열에 합쳐주는 함수
void desc();	//배열의 값들을 내림차순 시켜주는 함수

void main() {
	int a[20]={0}, b[11]={0};	
	int n = 0, m = 0;

	for (int* p = a; p <= a + 10; p++) {
		scanf("%d", p);
		if (*p == 0) break;
		++n;	//0이 입력되기 전까지 a배열의 값들을 입력받고 크기를 n에 저장
	}
	for (int* p = b; p <= b + 10; p++) {
		scanf("%d", p);
		if (*p == 0) break;
		++m;	//0이 입력되기 전까지 b배열의 값들을 입력받고 크기를 m에 저장
	}
	combine(a, b, n, m);
	//b의 원소값들을 a배열 원소값들 뒤에 합침
	desc(a, n + m);	//a배열을 내림차순

	for (int* p = a; p < a + n; p++) printf("%d ", *p);
	printf("\n");
	for (int* p = a + n + m - 1; p >= a + n; p--) printf("%d ", *p);
	//내림차순된 a배열의 앞에서부터 n개 출력
	//내림차순된 a배열을 뒤에서부터 출력하면 오름차순임. m개 출력
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