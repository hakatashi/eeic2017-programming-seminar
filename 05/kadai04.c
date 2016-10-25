#include <stdio.h>
#include <string.h>
#include <ctype.h>

void uppercase(char*);

int main() {
	char s[] = "hello world";

	uppercase(s);

	printf("%s\n",s);

	return 0;
}

void uppercase(char *s) {
	int i;

	for (i = 0; i < strlen(s); i++) {
		if (islower((unsigned char)s[i])) {
			s[i] = s[i] + 'A' - 'a';
		}
	}
}
