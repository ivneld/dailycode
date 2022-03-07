#include <stdio.h>

typedef struct _Time {
	int hour;
	int minute;
	int second;
}Time;

Time tSubtract();

int main() {
	int hour, minute, second;
	Time t1, t2, t3;

	scanf("%d %d %d", &t1.hour, &t1.minute, &t1.second);
	scanf("%d %d %d", &t2.hour, &t2.minute, &t2.second);

	t3 = tSubtract(t1, t2);

	printf("%d %d %d", t3.hour, t3.minute, t3.second);

	return 0;
}

Time tSubtract(Time t1, Time t2) {
	Time t3;
	int totSecond1 = t1.hour * 60 * 60 + t1.minute * 60 + t1.second;
	int totSecond2 = t2.hour * 60 * 60 + t2.minute * 60 + t2.second;
	
	t3.hour = (totSecond2 - totSecond1) / 3600;
	t3.minute = (totSecond2 - totSecond1) / 60 - t3.hour * 60;
	t3.second = (totSecond2 - totSecond1) % 60;

	return t3;
}