#include<stdio.h>
#include<math.h>

int zeller(int,int,int);

int main() {
	int year = 2016, month = 10, day = 5;
	int w;

	w = zeller(year, month, day);

	printf("%d/%d/%d is ", month, day, year);

	switch (w) {
		case 0:
			printf("Sat.\n");
			break;
		case 1:
			printf("Sun.\n");
			break;
		case 2:
			printf("Mon.\n");
			break;
		case 3:
			printf("Tue.\n");
			break;
		case 4:
			printf("Wed.\n");
			break;
		case 5:
			printf("Thurs.\n");
			break;
		case 6:
			printf("Fri.\n");
			break;
	}

	return 0;
}

int zeller(int year, int month, int day) {
	int h, y;

	if (month == 1 || month == 2) {
		year--;
		month += 12;
	}

	h = year / 100;
	y = year % 100;

	return (y + y / 4 + h / 4 - 2 * h + (month + 1) * 13 / 5 + day) % 7;
}
