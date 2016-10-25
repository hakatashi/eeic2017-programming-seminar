#include <stdio.h>
#include <string.h>

void reverse(char*);

int main() {
	char s[] = "hello";
	reverse(s);
	printf("%s\n", s);
	return 0;
}

void reverse(char *s) {
	int i;
	char *a, *b;

	for (i = 0; i * 2 < strlen(s) - 1; i++) {
		a = s + i;
		b = s + strlen(s) - i - 1;
		*a ^= *b ^= *a ^= *b;
	}
}
