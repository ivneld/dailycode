#include <stdio.h>

void Display(char(*x)[10], int y, char* msg)
{
	int i;
	puts(msg);
	for (i = 0; i < y; i++)
	{
		printf("team[%d] ==> %s \n", i, *(x + i));
	}
}
int main() {
	/*char team[5][10] = { "삼성","두산","넥센","기아","한화" };

	int i, n=sizeof(team)/sizeof(char[10]);

	printf("\n  %d개의 야구팀 \n\n", n);
	for (i = 0; i < n; i++) {
		printf("team[%d] ==> %s \n", i, team[i]);
	}*/

	char team[5][10] = { "삼성","두산","넥센","기아","한화" };
	int i, n = sizeof(team) / sizeof(char[10]);
	
	puts(" \n 배열포인터가 필요한 경우 \n");
	printf(" \n  %d개의 야구팀 \n\n", n);
	Display(team, n, " \n * 함수에서 출력 * \n");
	return 0;
}