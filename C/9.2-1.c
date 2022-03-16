#include <stdio.h>

int passengerN();
void rebooking();
int changeseat();

void main() {
	int bus[21] = { 0 };	
	int N;
	scanf("%d", &N);

	for (int* p = bus; p < bus + N; p++)
		scanf("%d", p);//입력받은 좌석 번호 저장

	if (!passengerN(N)) {

		rebooking(bus);

		printf("%d\n", passengerN(N));
		for (int* p = bus; p < bus + N; p++) printf("%d ", *p);
	}
	else
		printf("-1");
}

int passengerN(int n) {
	if (n < 5) return -1;
	else return 0;	//승객 수가 5보다 작으면 -1 반환 , 그렇지 않으면 0반환
}

void rebooking(int* ar) {
	
	for (int* p = ar; *p != 0; p++) {
		int flag = 0;
		//ar의 원소들을 앞에서부터 중복을 확인
		//중복을 체크하는 변수 flag , 중복이면 flag=1
		for (int* q = ar; q < p; q++) {
			if (*q == *p) {
				flag = 1;
				break;
			}
		}//q 는 p 위치 전의 값들을 확인 하며 p가 가리키는 원소가 중복값인지 확인한다.

		if (flag) {//중복 값이면
			int tmp = *p;
			for (int* q = p; *q != 0; q++) {
				if (*q == tmp) *q = changeseat(ar);
			}//중복된 값을 tmp에 저장해 두고 p 인덱스부터 배열의 마지막까지 tmp와 같은 값들을 changeseat함수를 이용하여 값을 바꿔준다.
		}

	}
}

int changeseat(int* ar) {
	int seat = 1;		//누락된 최소 양의 원소를 찾기 위한 변수
	int flag = 1;		

	while (flag) {
		flag = 0;	//배열을 처음부터 탐색하고 seat와 같은 값이 있다면 seat를 증가시키면서 최소 값을 저장함
					//flag = 0 이면 배열의 끝까지 탐색했지만 seat와 같은 값이 없어 최소 값을 찾았다는 것이므로 반복문을 빠져나옴.
		for (int* p = ar; *p != 0; p++) {
			if (*p == seat) {
				flag = 1;
				++seat;
				break;	//seat와 같은 값이 있으면 flag를 다시 1로 바꾸어 반복함
			}
		}
	}
	return seat;
}