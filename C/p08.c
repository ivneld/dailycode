#include <stdio.h>
#include <stdlib.h>

typedef struct _Student {
	char name[7];
	int kor;
	int eng;
	int math;
}Student;

int main() {
	int N;
	scanf("%d", &N);

	Student* arr = (Student*)malloc(sizeof(Student) * N);

	for (int i = 0; i < N; i++) {
		scanf("%s", &arr[i].name);
		scanf("%d %d %d", &arr[i].kor, &arr[i].eng,&arr[i].math);
	}

	for (int i = 0; i < N; i++) {
		double avg;
		avg = (double)(arr[i].kor + arr[i].eng + arr[i].math) / 3;
		printf("%s %0.1lf ", arr[i].name, avg);

		if (arr[i].kor >= 90 || arr[i].eng >= 90 || arr[i].math >= 90)
			printf("GREAT ");

		if (arr[i].kor < 70 || arr[i].eng < 70 || arr[i].math < 70)
			printf("BAD");

		printf("\n");
	}
	return 0;
}