#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
	char *line = NULL;
	int i;
	size_t size;

	while (getline(&line, &size, stdin) != -1) {
		for (i = 0; i < strlen(line) && !isspace((unsigned char)line[i]); i++) {
			putchar(line[i]);
		}
		putchar('\n');
	}

	return 0;
}
