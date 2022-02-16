//void 포인터

#include <stdio.h>

int main(void) {
	int a = 100;
	char b = 'M';
	double d = 1.34;

	/*int* ap = &a;
	puts(" \n void 포인터 \n");

	printf(" a = %3d,  &a = %d \n", a, &a);
	printf(" b = %3c,  &b = %d \n", b, &b);
	printf(" d = %.1f,  &a = %d \n", d, &d);

	printf(" *ap = %3d, ap = %d, &ap = %d \n\n", *ap, ap, &ap);*/

	void* p;

	puts(" \n void 포인터 \n");

	p = &a;
	printf(" *p = %3d \n\n", *(int*)p);

	p = &b;
	printf(" *p = %3c \n\n", *(char*)p);

	p = &d;
	printf(" *p = %0.1f \n\n", *(double*)p);

	return 0;
}