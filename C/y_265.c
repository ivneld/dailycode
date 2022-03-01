#include <stdio.h>

typedef struct AA
{
	char a;
	int b;
	double d;
}AA;

typedef union BB
{
	char a;
	int b;
	double d;
}BB;

int main() {

	puts(" \n C언어 공용체(union) \n");

	printf(" AA = %d byte \n", sizeof(AA));
	printf(" BB = %d byte \n\n", sizeof(BB));

	AA k = { '$',30,3.14 };
	printf(" k ==> %c, %d, %.2lf \n\n", k.a, k.b, k.d);

	BB t;
	t.a = '#';

	printf(" t ==> %c \n", t.a);
	t.b = 50;
	printf(" t ==> %d \n", t.b);
	t.d = 4.555;
	printf(" t ==> %.2lf \n", t.d);

	return 0;
}