#include <stdio.h>
#include <string.h>

typedef struct _Student {
	char name[9];
	int score;
}Student;

int main() {
	Student arr[5];
	int sum=0;

	for (int i = 0; i < 5; i++) {
		scanf("%s %d", &arr[i].name, &arr[i].score);
		sum += arr[i].score;
	}
	
	int avg = sum / 5;
	
	for (int i = 0; i < 5; i++) {
		if (arr[i].score <= avg) {
			printf("%s\n", arr[i].name);
		}
	}

	return 0;
}
