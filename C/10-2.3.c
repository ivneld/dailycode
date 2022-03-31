#include <stdio.h>
#include <string.h>

int main() {
	char str[10][100] = { 0 };
	char tmp[1000] = { 0 };

	gets(tmp);

	char* p = tmp;	//분이할 문자열의 첫 인덱스	
	int len = 0;	//분리한 문자열의 길이
	int idx = 0;	//str의 행을 나타내는 변수
	for (int i = 0; i <= strlen(tmp); i++) {
		if (tmp[i] == ' ' || tmp[i] == 0) {
			strncpy(str[idx++], p, len);
			p = &tmp[i + 1];
			len = 0;	
		}	//tmp[i]가 공백문자 이거나 문자열의 끝을 나타낼때
			//str의 한 행에 분리한 문자열 저장
		else
			++len;
	}		//문자열의 길이 저장

	for (int i = 0; i < idx; i++)
		puts(str[i]);

	char front[100];	//사전에서 가장 앞의 단어 저장하는 배열
	strcpy(front, str);	//초기 값
	for (int i = 1; i < idx; i++) {
		if (strcmp(str[i], front) < 0)
			strcpy(front, str[i]);
	}	//사전에서 앞의 단어이면 front를 변경
	puts(front);
	return 0;
}
