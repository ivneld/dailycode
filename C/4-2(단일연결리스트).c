#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct List {
	int data;
	int pre_data;
	struct List* next;
};

int main() {
	int N, cnt;
	int arr[101] = { 0 };
	scanf("%d",&N);

	struct List* list = NULL;
	list = (struct List*)(malloc(sizeof(struct List) * N));

	for (int i = 0; i < N; i++) {
		scanf("%d", &list[i].data);
		list[i].pre_data = list[i].data;
	}

	scanf("%d", &cnt);
	for (int i = 0; i < cnt; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < cnt-1; i++) {
		list[arr[i]].next = &list[arr[i + 1]];
		list[arr[i]].next->data = list[arr[i]].pre_data;
	}

	for (int i = 0; i < N; i++)
		printf(" %d", list[i].data);

	return 0;
}