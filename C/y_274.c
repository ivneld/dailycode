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
	/*char team[5][10] = { "�Ｚ","�λ�","�ؼ�","���","��ȭ" };

	int i, n=sizeof(team)/sizeof(char[10]);

	printf("\n  %d���� �߱��� \n\n", n);
	for (i = 0; i < n; i++) {
		printf("team[%d] ==> %s \n", i, team[i]);
	}*/

	char team[5][10] = { "�Ｚ","�λ�","�ؼ�","���","��ȭ" };
	int i, n = sizeof(team) / sizeof(char[10]);
	
	puts(" \n �迭�����Ͱ� �ʿ��� ��� \n");
	printf(" \n  %d���� �߱��� \n\n", n);
	Display(team, n, " \n * �Լ����� ��� * \n");
	return 0;
}