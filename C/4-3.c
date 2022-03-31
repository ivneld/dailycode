#include <stdio.h>
#include <stdlib.h>

struct List {
	int data;
	struct List* next;
};
//�� �ε����� 0�̸� ++�ϸ鼭 ������ ä���
//�� �ε����� N-1�̸� --�ϸ鼭 0 ����
int main() {
	int N;
	scanf("%d", &N);
	struct List** list = NULL;
	list = (struct List**)malloc(sizeof(struct List*) * (N+1));
	for (int i = 0; i < N+1; i++)
		list[i] = (struct List*)malloc(sizeof(struct List) * (N+1));
	//List�� 2�����迭 �Ҵ�

	
	int j=0;
	list[0][0].data = 1;	//ù data�� �ʱ�ȭ
	for (int i = 0; i < N; i++) {
		if (j == 0) {		//���������� �̵��ϴ� ���
			for (; j < N-1; j++) {	
				list[i][j].next = &list[i][j + 1];
				list[i][j].next->data = list[i][j].data + 1;
			}
			list[i][j].next = &list[i+1][j];
			list[i][j].next->data = list[i][j].data + 1;
		}

		else if (j == N - 1) {	//�������� �̵��ϴ� ���
			for (; j > 0; j--) {
				list[i][j].next = &list[i][j-1];
				list[i][j].next->data = list[i][j].data + 1;
			}
			list[i][j].next = &list[i+1][j];
			list[i][j].next->data = list[i][j].data + 1;
		}
	}
	

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf(" %d", list[i][j].data);
		puts("");
	}

	// �����Ҵ� ����
	for (int i = 0; i < N; i++)
		free(list[i]);
	free(list);
	return 0;
}