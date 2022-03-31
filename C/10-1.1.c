#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ch가 소문자면 2 반환, 대문자면 1 반환, 숫자면 0을 반환, 그 이외의 값일 땐 -1을 반환하는 함수
int isalnum(char ch) {
	if (ch >= 'a' && ch <= 'z') return 2;
	else if (ch >= 'A' && ch <= 'Z') return 1;
	else if (ch >= '0' && ch <= '9') return 0;
	else return -1;	
}

int main() {
	char A[21] = { 0 };
	char changeA[50]={0};	//배열A에 옮길 임시 배열
	int N;

	scanf("%s %d", A, &N);
	int len = strlen(A);

	int idx = 0;
	for (int i = 0; i < len; i++) {
		if (isalnum(A[i])==1) {
			changeA[idx++] = A[i] + N;	//현재 인덱스의 값이 대문자면 N만큼 아스키 코드값 이동
		}
		else if (isalnum(A[i]) == 2) {
			changeA[idx++] = A[i] - N;	//소문자일 경우
		}
		else if (isalnum(A[i])==0) {
			for (int j = 0; j < N; j++)
				changeA[idx++] = 'A' + atoi(&A[i]) -1;	//일의 자리 숫자일 경우

			if (atoi(&A[i]) > 9)		//10 이상의 수일 경우
				i++;
		}
		if (isalnum(A[i]) ==-1) {
			
			changeA[idx++] = ' ';	//영문자, 숫자가 아닐 경우 공백을 저장
		}
	}
	strcpy(A, changeA);		//임시 배열의 값을 A로 이동
	puts(A);	//A출력
	return 0;
}
