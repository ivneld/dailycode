#include <stdio.h>

int* MAX();
int* MIN();

void main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int ar[100] = { 0 };	
		int* p = ar;
		//배열 초기화, ar배열을 참조하는 포인터 p 생성
		while (1) {
			scanf("%d", p);
			if (*p == 0) break;
			else ++p;
		}
		//p를 이용하여 ar배열에 값을 입력받음
		//방금 입력받은 값이 0일 경우 배열의 마지막이므로 반복문을 나옴
		//그렇지 않을경우, ar의 다음 인덱스 원소를 입력받음

		int max = *MAX(ar);
		int min = *MIN(ar);
		printf("%d %d\n", max, min);
		//최대값과 최소값 각각 출력
		}
	}


int* MAX(int* ar) {
	int* idx = ar;
	//ar배열의 첫번째 원소를 최대값 인덱스로 저장
	for (int* p = ar; *p != 0; p++) {
		if (*p > *idx) idx = p;
	}//배열ar을 가리키는 포인터p를 이용하여 마지막 원소인 0 이 나오기
	//전까지 최대값을 탐색 후 최대값의 인덱스를 저장
	return idx;
}

int* MIN(int* ar) {
	int* idx = ar;
	//ar배열의 첫번째 원소를 최소값 인덱스로 저장
	for (int* p = ar; *p != 0; p++) {
		if (*idx > *p) idx = p;
	}//0이 나오기 전까지 최소값을 탐색 후 인덱스 저장
	return idx;
}
