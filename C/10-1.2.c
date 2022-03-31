#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//ch가 어떤 문자인지 판별하는 함수
int isalnum(char ch) {
	if (ch >= 'a' && ch <= 'z') return 2;
	else if (ch >= 'A' && ch <= 'Z') return 1;
	else if (ch >= '0' && ch <= '9') return 0;
	else return -1;
}	

void changeStr();
int canChange();

int main() {
	char str1[40] = { 0 };
	char str2[40] = { 0 };

	gets(str1);
	gets(str2);	//str2는 공백문자가 있을 수 있기 때문에 gets

	int chk = canChange(str1, str2);
	printf("%d", chk);
	return 0;
}
//문자열을 N의 값에따라 변경시켜주는 함수
void changeStr(char* str,int N) {
	char changeStr[40] = { 0 };

	int idx = 0;
	for (char* p = str; *p != 0; p++) {
		if (isalnum(*p) == 2) {
			changeStr[idx++] = *p - N;
		}//*p의 값이 소문자면 N만큼 앞으로 이동
		else if (isalnum(*p) == 1) {
			changeStr[idx++] = *p + N;
		}//*p의 값이 대문자면 N만큼 뒤로 이동
		else if (isalnum(*p) == 0) {
			for (int i = 0; i < N; i++)
				changeStr[idx++] = 'A' + atoi(p) - 1;
			if (atoi(p) > 9)
				p++;	//*p의 값이 숫자이면 해당 숫자가 가리키는 대문자 저장
		}				//또한 *p의 값이 10 이상이면 포인터 한칸 이동
		else if(isalnum(*p)==-1)
			changeStr[idx++] = ' ';
	}	//그 이외의 문자일 경우 공백 저장
	strcpy(str, changeStr);	//임시 문자열을 원래 배열로 이동
}
//문자열끼리 변경가능한지 확인하는 함수
int canChange(char* str1, char* str2) {
	int chk = 0;

	char str1Original[40],str2Original[40];
	strcpy(str1Original, str1);
	strcpy(str2Original, str2);		//changeStr함수를 호출하기 전의 문자열

	for (int N = 1; N < 11; N++) {	//A -> B
		changeStr(str1, N);
		if (strcmp(str1, str2) == 0)
			chk = 1;
		strcpy(str1, str1Original);
	}
	for (int N = 1; N < 11; N++) {	//B -> A
		changeStr(str2, N);
		if (strcmp(str1, str2) == 0)
			chk = 2;
		strcpy(str2, str2Original);
	}
	return chk;
}