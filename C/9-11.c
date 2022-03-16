#include <stdio.h>

void strcopy();

void main() {
	char a[6]={""}, b[6]={""};
	
	for (char* p = a; p < a + 6; p++)
		scanf("%c", p);

	strcopy(a, b);

	for (char* p = b; p < b + 6; p++)
		printf("%c", *p);
}

void strcopy(char a[], char b[]) {
	for (int i = 0; i < 6; i++) {
		*(b + i) = *(a + i);
	}
}