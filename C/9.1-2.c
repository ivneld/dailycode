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
		int* maxIdx = MAX(ar);
		int* minIdx = MIN(ar);
		//최대값, 최소값의 인덱스 
		
		if (maxIdx >= minIdx) {//최대값 인덱스가 최소값 인덱스보다 크거나 같을 때
			if (maxIdx - minIdx <= 1) printf("none\n");
			//두 인덱스 사이에 값이 없거나 두 인덱스가 같은 값을 가리킬 때
			
			else {
				for (p = minIdx + 1; p < maxIdx; p++) printf("%d ", *p);
					
				printf("\n");
			}//두 인덱스 사이의 값들을 출력
		}

		else {//최소값의 인덱스가 최대값의 인덱스 보다 클 때
			if (minIdx - maxIdx == 1) printf("none\n");
			//두 인덱스 사이에 값이 없을때
			else {
				for (p = maxIdx + 1; p < minIdx; p++) printf("%d ", *p);

				printf("\n");
			}//두 인덱스 사이의 값들을 출력
		}
		
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
