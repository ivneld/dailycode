//2차원 배열과 포인터

#include <stdio.h>

int main()
{
	char a[3][5];
	int b[3][6];

	char(*ap)[5] = a;
	int(*bp)[6] = b;

	puts(" \n 2차원 배열과 포인터 \n\n");

	printf(" a = %d, a + 1 = %d \n", a, a + 1);
	printf(" ap = %d, ap + 1 = %d \n", ap, ap + 1);

	printf(" b = %d, b + 1 = %d \n", b, b + 1);
	printf(" bp = %d, bp + 1 = %d \n", bp, bp + 1);

	printf(" a = %d byte \n", sizeof(a));
	printf(" ap = %d byte \n\n", sizeof(ap));

	printf(" b = %d byte \n", sizeof(b));
	printf(" bp = %d byte \n\n", sizeof(bp));

	puts(" \n 32bits에서 포인터는 항상 4바이트다. \n\n");

	return 0;
}