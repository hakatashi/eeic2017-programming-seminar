#include <stdio.h>
#include <math.h>

int main() {
	char c;
	int i;

	while (i++, (c = getchar()) != EOF) {
		if (i % 2 == 0) {
			putchar(c);
		}
	}

	return 0;
}
