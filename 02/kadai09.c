#include <stdio.h>
#include <math.h>
#define LOOP(x, s, n) for(x = s; x <= n; x++)

int is_prime(int);

int main() {
	int i, j, is_found;

	for (i = 4; i <= 1000; i += 2) {
		is_found = 0;

		LOOP(j, 2, i / 2) {
			if (is_prime(j) == 1 && is_prime(i - j) == 1) {
				printf("%d = %d + %d\n", i, j, i - j);
				is_found = 1;
				break;
			}
		}

		if (!is_found) {
			puts("Goldbach broken!");
			break;
		}
	}

	return 0;
}

int is_prime(int n) {
	int i;

	for (i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return 0;
		}
	}

	return 1;
}
