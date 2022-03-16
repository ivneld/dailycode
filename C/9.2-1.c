#include <stdio.h>

int passengerN();
void rebooking();
int changeseat();

void main() {
	int bus[21] = { 0 };	
	int N;
	scanf("%d", &N);

	for (int* p = bus; p < bus + N; p++)
		scanf("%d", p);//�Է¹��� �¼� ��ȣ ����

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
	else return 0;	//�°� ���� 5���� ������ -1 ��ȯ , �׷��� ������ 0��ȯ
}

void rebooking(int* ar) {
	
	for (int* p = ar; *p != 0; p++) {
		int flag = 0;
		//ar�� ���ҵ��� �տ������� �ߺ��� Ȯ��
		//�ߺ��� üũ�ϴ� ���� flag , �ߺ��̸� flag=1
		for (int* q = ar; q < p; q++) {
			if (*q == *p) {
				flag = 1;
				break;
			}
		}//q �� p ��ġ ���� ������ Ȯ�� �ϸ� p�� ����Ű�� ���Ұ� �ߺ������� Ȯ���Ѵ�.

		if (flag) {//�ߺ� ���̸�
			int tmp = *p;
			for (int* q = p; *q != 0; q++) {
				if (*q == tmp) *q = changeseat(ar);
			}//�ߺ��� ���� tmp�� ������ �ΰ� p �ε������� �迭�� ���������� tmp�� ���� ������ changeseat�Լ��� �̿��Ͽ� ���� �ٲ��ش�.
		}

	}
}

int changeseat(int* ar) {
	int seat = 1;		//������ �ּ� ���� ���Ҹ� ã�� ���� ����
	int flag = 1;		

	while (flag) {
		flag = 0;	//�迭�� ó������ Ž���ϰ� seat�� ���� ���� �ִٸ� seat�� ������Ű�鼭 �ּ� ���� ������
					//flag = 0 �̸� �迭�� ������ Ž�������� seat�� ���� ���� ���� �ּ� ���� ã�Ҵٴ� ���̹Ƿ� �ݺ����� ��������.
		for (int* p = ar; *p != 0; p++) {
			if (*p == seat) {
				flag = 1;
				++seat;
				break;	//seat�� ���� ���� ������ flag�� �ٽ� 1�� �ٲپ� �ݺ���
			}
		}
	}
	return seat;
}