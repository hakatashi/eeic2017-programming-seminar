#include <stdio.h>
#define LOOP(x, f, t) for(x = f; x < t; x++)
#define ILOOP(x, f, t) for(x = f; x <= t; x++)

int gcd(int, int);

int main() {
	int x, y, z;

	LOOP(x, 1, 1000) ILOOP(y, x, 1000) LOOP(z, 1, 1000)
		if (x * x + y * y == z * z && gcd(x, y) == 1)
			printf("%d^2 + %d^2 = %d^2\n", x, y, z);

	return 0;
}

int gcd(int a, int b) {
	int temp;

	while (b != 0) {
		temp = b;
		b = a % b;
		a = temp;
	}

	return a;
}
