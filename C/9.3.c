#include <stdio.h>

int isChar();
//char �����͸� ���ڷ� �޾� �ҹ����̸� 1, �ƴϸ� 0 �� �����ϴ� �Լ�

void main() {
	char ar[100] = { "" };

	for (char* p = ar; ; p++) {
		scanf("%c", p);
		if (*p == '#') break;
	}
	//#�� �Է¹��� �� ���� ar�� �Է°� ����

	int max = 0;	//���� ������ �ִ밪
	char* end = ar-1;	
	char* start = ar;
	//end�����͸� ar�迭�� ù��° ���Һ��� #���� �̵���Ű�鼭
	//end�� ����Ű�� ���� �ҹ��ڰ� �ƴҰ�� start���� end�������� ���ڵ��� ���
	//�׸��� start�� end���� �ε����� �̵����� ���ڰ� �����ؼ� ���ð��� ������� �ʵ��� ��.
	//���� start�� �ҹ��ڰ� �ƴҰ��� �ҹ��ڰ� �ƴ� ���ڰ� �����ؼ� 
	//���� �� �̹Ƿ� �ٹٲ��� ���� ����.
	//end - start�� ���ڿ��� ���̸� ��Ÿ���Ƿ� max�� ���� �� ���
	while (*end != '#') {
		
		++end;

		if (!isChar(end)) {
			for (char* q = start; q < end; q++) printf("%c", *q);
			
			if (isChar(start))
				printf("\n");

			if (end - start > max) max = end - start;
			start = end + 1;
		}
	}
	printf("%d", max);
}

int isChar(char* p) {
	if (*p >= 'a' && *p <= 'z') return 1;

	else return 0;
}
