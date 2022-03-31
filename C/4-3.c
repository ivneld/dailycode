#include <stdio.h>
#include <stdlib.h>

struct List {
	int data;
	struct List* next;
};
//열 인덱스가 0이면 ++하면서 끝까지 채우고
//열 인덱스가 N-1이면 --하면서 0 까지
int main() {
	int N;
	scanf("%d", &N);
	struct List** list = NULL;
	list = (struct List**)malloc(sizeof(struct List*) * (N+1));
	for (int i = 0; i < N+1; i++)
		list[i] = (struct List*)malloc(sizeof(struct List) * (N+1));
	//List형 2차원배열 할당

	
	int j=0;
	list[0][0].data = 1;	//첫 data값 초기화
	for (int i = 0; i < N; i++) {
		if (j == 0) {		//오른쪽으로 이동하는 경우
			for (; j < N-1; j++) {	
				list[i][j].next = &list[i][j + 1];
				list[i][j].next->data = list[i][j].data + 1;
			}
			list[i][j].next = &list[i+1][j];
			list[i][j].next->data = list[i][j].data + 1;
		}

		else if (j == N - 1) {	//왼쪽으로 이동하는 경우
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

	// 동적할당 해제
	for (int i = 0; i < N; i++)
		free(list[i]);
	free(list);
	return 0;
}