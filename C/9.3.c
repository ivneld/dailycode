#include <stdio.h>

int isChar();
//char 포인터를 인자로 받아 소문자이면 1, 아니면 0 을 리턴하는 함수

void main() {
	char ar[100] = { "" };

	for (char* p = ar; ; p++) {
		scanf("%c", p);
		if (*p == '#') break;
	}
	//#을 입력받을 때 까지 ar에 입력값 저장

	int max = 0;	//문자 길이의 최대값
	char* end = ar-1;	
	char* start = ar;
	//end포인터를 ar배열의 첫번째 원소부터 #까지 이동시키면서
	//end가 가리키는 값이 소문자가 아닐경우 start부터 end전까지의 문자들을 출력
	//그리고 start를 end다음 인덱스로 이동시켜 숫자가 연속해서 나올경우는 출려되지 않도록 함.
	//현재 start가 소문자가 아닐경우는 소문자가 아닌 문자가 연속해서 
	//나온 것 이므로 줄바꿈을 하지 않음.
	//end - start는 문자열의 길이를 나타내므로 max에 저장 후 출력
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
