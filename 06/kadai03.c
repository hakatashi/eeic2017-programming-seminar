#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv) {
	int i, ptr = 0;
	char read_chr;
	char *reg, *input;

	if (argc < 2) {
		puts("Insufficient arguments");
		return 1;
	}

	input = argv + 1;

	reg = (char *)malloc(sizeof(input));

	for (i = 0; i <= strlen(input); i++) {
		read_chr = input[i];

		if (read_chr == '\0') {
			p
		}
	}

	printf("{{%f, %f}, {%f, %f}}\n", in[0][0], in[0][1], in[1][0], in[1][1]);

	return 0;
}
