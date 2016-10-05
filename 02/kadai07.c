#include <stdio.h>

int gcd(int, int);

int main() {
	int r;
	int a = 8733;
	int b = 64681;

	r = gcd(a, b);

	printf("gcd(%d, %d) = %d\n", a, b, r);

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
