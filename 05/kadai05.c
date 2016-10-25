#include <stdio.h>
#include <string.h>

int roman2num(char*);

int main() {
	printf("XIV = %d\n", roman2num("XIV"));
	printf("CDXCV = %d\n", roman2num("CDXCV"));
	printf("MCMXLV = %d\n", roman2num("MCMXLV"));
	printf("MMMCMXCIX = %d\n", roman2num("MMMCMXCIX"));

	return 0;
}

int roman2num(char *s) {
	int numtable[256] = {0};
	int sum = 0, i, num;
	int previous_num = 0;

	numtable['I'] = 1;
	numtable['V'] = 5;
	numtable['X'] = 10;
	numtable['L'] = 50;
	numtable['C'] = 100;
	numtable['D'] = 500;
	numtable['M'] = 1000;

	for (i = 0; i < strlen(s); i++) {
		num = numtable[(unsigned char)s[i]];
		sum += num;
		if (previous_num * 5 == num || previous_num * 10 == num) {
			sum -= previous_num * 2;
		}
		previous_num = num;
	}

	return sum;
}
