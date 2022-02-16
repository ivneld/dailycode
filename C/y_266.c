#include <stdio.h>

int main() {
	char a1 = 'T';
	int b1 = 10;

	char* ap1 = &a1;
	int* bp1 = &b1;

	puts(" \n C¾ğ¾î Æ÷ÀÎÅÍ ¹½ÀÌ ÁßÇåµğ? \n\n");

	printf(" a1 = %2c, &a1 = %d \n", a1, &a1);
	printf(" b1 = %d, &b1 = %d \n\n", b1, &b1);

	printf(" ap1 = %d, *ap1 = %c \n", ap1, *ap1);
	printf(" bp1 = %d, *bp1 = %d \n\n", bp1, *bp1);

	printf(" &a1 = %d, &a1 + 1 = %d \n", &a1, &a1 + 1);
	printf(" ap1 = %d, ap1 + 1 = %d \n\n", ap1, ap1 + 1);

	printf(" &b1 = %d, &b1 + 1 = %d \n", &b1, &b1 + 1);
	printf(" bp1 = %d, bp + 1 = %d \n\n",bp1,bp1+1);
	
	return 0;
}