#include <stdio.h>
#define LOOP(x, n) for(x = 1; x < n; x++)
#define ILOOP(x, n) for(x = 1; x <= n; x++)

int gcd(int, int);

int main() {
	int x, y, z;

	LOOP(y, 1000) ILOOP(x, y) LOOP(z, 1000)
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
