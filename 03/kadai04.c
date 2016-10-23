#include <stdio.h>
#include <stdlib.h>

void factorize(int, int);

int main() {
	int n = 123456789;
	printf("Prime factor of %d\n", n);
	printf("%d = ", n);
	factorize(n, 2);
	return 0;
}

void factorize(int n, int factor) {
	int i;

	for (i = factor; i * i <= n; i++) {
		if (n % i == 0) {
			printf("%d * ", i);
			factorize(n / i, i);
			return;
		}
	}

	printf("%d\n", n);
	return;
}
